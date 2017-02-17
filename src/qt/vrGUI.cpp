/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   vrGUI.cpp
 * Author: davidsabzanov
 *
 * Created on November 23, 2016, 1:35 PM
 */

#include "qt/vrGUI.h"
#include <qt/ui_adapter.h>

namespace gcs {

    vrGUI::vrGUI() {
        widget.setupUi(this);
        
        UIAdapter * ui = UIAdapter::Instance();
        connect(ui, &UIAdapter::NotifyOperator,
                this, &vrGUI::OnOutputReceived);
    }

    vrGUI::~vrGUI() {}
    
    void vrGUI::OnOutputReceived(QString s) {
        widget.label->setText(s);
    }

}
