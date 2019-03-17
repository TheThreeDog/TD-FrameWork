#if _MSC_BUILD
#pragma execution_character_set("utf-8")
#endif
/***************************************************
* Program Assigment : 自定义工具栏按钮类
* File Name: tdtoolbar.cpp
* Author : ThreeDog
* Date : 2016/12/28
* Description: 自定义工具栏类，继承自自定义复选框，几乎没有改动，只是
*           去除了复选框的右控件，可以通过信号和槽或者回调函数实现功能。
*
* **************************************************/

#include "tdtoolbar.h"
#include <QMainWindow>
TDToolbar::TDToolbar(QWidget *parent)
    :TDCheckbox(parent,NULL)
{
    this->setText("");
    mouseChangeEnable = true;
}

TDToolbar::TDToolbar(const QString pic_che,const QString pic_non, QWidget *parent)
    :TDCheckbox(pic_che,pic_non,parent,NULL)
{
    this->setText("");
    mouseChangeEnable = true;
}

void TDToolbar::setColor(const QColor &col_che, const QColor &col_non)
{
    TDCheckbox::setColor(col_che,col_non);
}

TDToolbar::~TDToolbar()
{

}

void TDToolbar::mousePressEvent(QMouseEvent *e)
{
    //如果按钮可以触发，才进行触发调用
    if(mouseChangeEnable){
        TDCheckbox::mousePressEvent(e);
    }

}

void TDToolbar::setMouseChangeEnable(bool b)
{
    this->mouseChangeEnable = b;
}

void TDToolbar::changeState(bool b)
{
    this->setChecked(b);
}
