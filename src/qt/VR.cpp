/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VR.cpp
 * Author: davidsabzanov
 * 
 * Created on March 2, 2017, 10:08 PM
 */

#include <voce/voce.h>
#include "myVoce/CommandParser.h"
#include <unistd.h>
#include "qt/VR.h"
#include <ros/package.h>
#include <qt/ui_adapter.h>

bool quit, started;

VR::VR() {
    

    quit = false;
    started = false;
}


void VR::Listen() {
    std::string path = ros::package::getPath("voice_recognition");
    path.append("/resources");
    std::cout << path << std::endl;
    
    voce::init("/opt/voce/lib", false, true, path, "islurp");

    std::cout << "Voice initialize" << std::endl;
    
    
    while (!quit)
    {
        // Normally, applications would do application-specific things 
        // here.  For this sample, we'll just sleep for a little bit.

        usleep(200);

        while (voce::getRecognizerQueueSize() > 0)
        {
                    
            std::string s = voce::popRecognizedString();
                        
                        
            // Check if the string contains 'quit'.
            if (std::string::npos != s.rfind("quit"))
            {
                quit = true;
                break;
            }
          
            if (s == "end voice")
            {
                started = false;
                std::cout << "Voice Recognition stopped!"<< std::endl;
                break;
                
            }
            else if (s == "start voice")
            {
                std::cout << "Voice Recognition started!"<< std::endl;
                started = true;
            }
            else if (started)
            {
                
                
                 boost::to_upper(s);
                 
                 

                 std::cout << "TEST: " << s << std::endl;

                 CommandParser p;
                 p.parse(s);
                 

                std::cout << "You said ----------: " << s << std::endl;
            } 
            //voce::synthesize(s);
                        
        }//while (voce::getRecognizerQueueSize() > 0)
    }//while (!quit))

    voce::destroy();
}

VR::VR(const VR& orig) {
}

VR::~VR() {
}

