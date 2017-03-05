
#include <cstdlib>
#include <ros/ros.h>
#include "qt/UavAdapter.h"
#include "qt/VoiceRecognition.h"
#include <vehicle/uav_control.h>

#include <QApplication>
#include <QThread>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

//    ros::init(argc, argv, "uav_control_test");
//   gcs::UAVControl quad1{2000};
//
//
////    lcar_msgs::TargetGlobal target_pt;
////    target_pt.target.latitude = 47.3977255;
////    target_pt.target.longitude = 8.5456603;
////    target_pt.target.altitude = 10;
//
//   lcar_msgs::TargetLocal target_pt; 
//   target_pt.target.position.x = 0;
//   target_pt.target.position.y = 0;
//   target_pt.target.position.z = 2;
//
//   target_pt.radius = 2;
//
//   quad1.Arm(true);
//   quad1.ScoutBuilding(target_pt);
//
//   ros::Rate loop_rate(10); //10Hz 
//   while(ros::ok())
//   {
//       quad1.Run();
//       ros::spinOnce();
//       loop_rate.sleep();
//   }

    
    QApplication app(argc, argv);

    ros::init(argc, argv, "gcs");
    VoiceRecognition vr;

    QThread thread;
    vr.moveToThread(&thread);
    QObject::connect(&thread, &QThread::started, &vr, &VoiceRecognition::run);
    thread.start();

    ros::AsyncSpinner spinner(0);
    spinner.start();
            
    UavAdapter uav;

//   return 0;
    return app.exec();
}