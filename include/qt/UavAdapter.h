/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UavAdapter.h
 * Author: borhan
 *
 * Created on November 29, 2016, 6:46 PM
 */

#ifndef UAVADAPTER_H
#define UAVADAPTER_H
#include <QObject>
#include <QTimer>

#include <vehicle/uav_control.h>

class UavAdapter:public QObject {
    Q_OBJECT
public:
    UavAdapter();
    virtual ~UavAdapter();
    void run();
    public slots:
        void Arm(int v_id, bool value);
        void SetWayPoint(int v_id, int lat, int lng, int alt=0);
        void SetMode(int v_id, QString mode);
        void SetRTL(int v_id);


        void ScoutBuilding(int quad_id, int num);
        void PauseMission(int v_id);
        void ResumeMission(int v_id);
        void CancelMission(int v_id);

private:
    gcs::UAVControl* uav;
    QTimer * timer;

};

#endif /* UAVADAPTER_H */
