/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VR.h
 * Author: davidsabzanov
 *
 * Created on March 2, 2017, 10:08 PM
 */

#ifndef VR_H
#define VR_H
#include <QObject>

class VR : public QObject {
    Q_OBJECT
public:
    VR();
    VR(const VR& orig);
    virtual ~VR();
    
    
public slots:
    void Listen();
private:
    

};

#endif /* VR_H */

