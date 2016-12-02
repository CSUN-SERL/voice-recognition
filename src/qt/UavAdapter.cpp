/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UavAdapter.cpp
 * Author: borhan
 *
 * Created on November 29, 2016, 6:46 PM
 */

#include <qt5/QtCore/qtimer.h>

#include "qt/UavAdapter.h"


UavAdapter::UavAdapter():
uav(new gcs::UAVControl(1))
{
    gcs::UIAdapter *ui = gcs::UIAdapter::Instance();
    connect(ui, &gcs::UIAdapter::Arm, this,&UavAdapter::Arm);
    connect(ui, &gcs::UIAdapter::SetWayPoint, this, &UavAdapter::SetWayPoint);
    connect(ui, &gcs::UIAdapter::SetMode, this, &UavAdapter::SetMode);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){ uav->Run(); });
    timer->start(0);
}




UavAdapter::~UavAdapter() {
}

void UavAdapter::run(){
    uav->Run();
}

 void UavAdapter::Arm(int v_id, bool value)
 {
     if(value)
     {
       //uav->Arm(value);
       uav->Takeoff(2);
       //uav->SetWayPoint(0,0,10,0);
       uav->SetPosition(0,0,10,0);

     }
     else
     {
        uav->Land();
        uav->Arm(value);
     }

 }

  void UavAdapter::SetWayPoint(int v_id, int lat, int lng, int alt){
      uav->SetPosition(lat,lng,10,0);
  }

  void UavAdapter::SetMode(int v_id, QString mode){
      uav->SetMode(mode.toStdString());
  }
  void UavAdapter::SetRTL(int v_id){

  }

  void UavAdapter::ScoutBuilding(int quad_id, int num){

  }
  void UavAdapter::PauseMission(int v_id){

  }
  void UavAdapter::ResumeMission(int v_id){

  }
  void UavAdapter::CancelMission(int v_id){

  }
