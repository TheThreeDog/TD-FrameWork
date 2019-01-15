/**************************************************************
 * File Name   : tdmodal.h
 * Author      : ThreeDog
 * Date        : Mon Jan 14 20:21:26 2019
 * Description : 模态框，不显示边框
 *      默认显示自封装的标题栏和关闭退出最小化的按钮，
 *  模态框从上到下依次是：
 *      1、标题栏， 包括标题和关闭按钮。默认显示， 可以控制是否显示。
 *      2、内容区， 包括显示的内容
 *      3、底部按钮、默认包括两个、确认和返回。要求文字可以设定，按钮可以扩展
 *
 *  默认全部是白色，各部分颜色可以设置
 *
 **************************************************************/
#ifndef _TDMODAL_H_
#define _TDMODAL_H_
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class TDModal:public QWidget
{
public:
    explicit TDModal(QWidget *parent = 0);
    ~TDModal();
private:
    bool show_title;
    QWidget * m_pTitleWidget;       //标题区域
    QLabel * m_pTitleLabel;         //标题文字
    QWidget * m_pArticleWidget;     //内容区域
    QWidget * m_pFooterWidget;      //
    QHBoxlayout *
    QPushButton * m_pOKBtn;         //成功按钮
    QPushButton * m_pCancleBtn;     //取消按钮
};

#endif  //TDMODAL
