#if _MSC_BUILD
#pragma execution_character_set("utf-8")
#endif
/***************************************************
* Program Assigment : 自定义工具栏按钮类
* File Name: tdtoolbar.h
* Author : ThreeDog
* Date : 2016/12/28
* Description: 自定义工具栏类，继承自自定义复选框，几乎没有改动，只是
*           去除了复选框的右控件，可以通过信号和槽或者回调函数实现功能。
*
* **************************************************/

#ifndef TDTOOLBAR_H
#define TDTOOLBAR_H
#include "tdcheckbox.h"

class TDToolbar : public TDCheckbox
{
    Q_OBJECT
public:
    explicit TDToolbar(QWidget *parent);
    explicit TDToolbar(const QString pic_che,const QString pic_non,QWidget *parent = 0);

    void setColor(const QColor &col_che,const QColor &col_non);
    ~TDToolbar();
protected:
    void mousePressEvent(QMouseEvent *e);
public slots:
    void setMouseChangeEnable(bool b);      // 设置点击可触发状态改变。
    void changeState(bool b);               // 改变其状态。
private:
    bool mouseChangeEnable;                 //标识状态是否可由鼠标改变
};

#endif // TDTOOLBAR_H
