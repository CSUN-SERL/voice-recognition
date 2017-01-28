
#include <cstdlib>
#include <ros/ros.h>
#include "qt/UavAdapter.h"
#include "qt/VoiceRecognition.h"

#include <QApplication>
#include <QThread>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

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

    return app.exec();
}
