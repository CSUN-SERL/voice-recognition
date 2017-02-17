/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vrGUI.h
 * Author: davidsabzanov
 *
 * Created on November 23, 2016, 1:35 PM
 */

#ifndef _VRGUI_H
#define _VRGUI_H

#include "ui_vrGUI.h"

namespace gcs {

    class vrGUI : public QWidget {
        Q_OBJECT
    public:
        vrGUI();
        virtual ~vrGUI();
        
    public slots:
        void OnOutputReceived(QString s);
    private:
        Ui::vrGUI widget;
    };
    
}

#endif /* _VRGUI_H */
