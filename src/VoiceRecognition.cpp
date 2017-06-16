/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   VoiceRecognition.cpp
 * Author: borhan
 *
 * Created on November 29, 2016, 8:16 PM
 */

#include <boost/algorithm/string.hpp>
#include <cstdlib>
#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <voce.h>
#include <voice_recognition/VoiceRecognition.h>

VoiceRecognition::VoiceRecognition() 
{



}

VoiceRecognition::~VoiceRecognition() 
{
    voce::destroy();
}

void VoiceRecognition::run() 
{
    //Nodehandle and publisher
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("voice_recognition", 1000);

    //Getting path for voce init
    std::string path = ros::package::getPath("voice_recognition");
    path.append("/resources");
    std::cout << path << std::endl;

    //Get Voce library path
    //Uses "VOCE_DIR" enviromental path
    std::string voce_lib = std::getenv("VOCE_DIR");
    voce_lib.append("/lib");

    voce::init(voce_lib, false, true, path, "islurp");

    std::cout << "Voice initialize" << std::endl;


    std::cout << "R unning" << std::endl;
    
    bool quit = false;
    bool started = false;
    
    while (!quit) 
    {

        while (voce::getRecognizerQueueSize() > 0) 
        {
            std::string s = voce::popRecognizedString();

            // Check if the string contains 'quit'.
            if (std::string::npos != s.rfind("quit")) 
            {
                quit = true;
                return;
            }

            if (s == "end voice") 
            {
                started = false;
                std::cout << "Voice Recognition stopped!" << std::endl;
                break;

            } else if (s == "start") 
            {
                std::cout << "Voice Recognition started!" << std::endl;
                started = true;

            } else if (started) 
            {
                
                //Set to uppercase for publishing
                boost::to_upper(s);
                std::cout << "TEST: " << s << std::endl;

                //Create and publish recognized String to "voice_recognition_output"
                std_msgs::String msg = s;
                pub.publish(msg);

                std::cout << "You said ----------: " << s << std::endl;

            }

        }

    }

}
