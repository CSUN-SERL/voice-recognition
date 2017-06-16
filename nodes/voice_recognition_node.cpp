
#include <cstdlib>
#include <ros/ros.h>
#include "voice_recognition/VoiceRecognition.h"



using namespace std;

/*
 *
 */
int main(int argc, char** argv) 
{

    ros::init(argc, argv, "voice_recognition");
    VoiceRecognition vr;
    vr.run();

    return 0;
}
