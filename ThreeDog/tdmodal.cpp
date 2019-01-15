/**************************************************************
 * File Name   : tdmodal.cpp
 * Author      : ThreeDog 
 * Date        : Mon Jan 14 20:21:26 2019
 * Description : 
 *
 **************************************************************/

#include "tdmodal.h"
TDModal::TDModal(QWidget *parent)
    :QWidget(parent)
{
    QPalette p;
    p.setColor(QPalette::Background,Qt::white);
    this->setPalette(p);
    show_title = true;
}

TDModal::~TDModal()
{

}
