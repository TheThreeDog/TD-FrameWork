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
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include "ThreeDog/tdpushbutton.h"

class TDModal:public QDialog
{
    Q_OBJECT
public:
    explicit TDModal(QString title = "模态窗体",QWidget *parent = 0);
    void initInterface(QString title);                  //初始化界面
    void initShadow();                                  //初始化阴影效果
    void setTitleVisible(bool b);                       //设置标题是否可见
    void setTitle(const QString & text);                //设置标题
    void setTitleColor(QColor col);                     //设置标题区域背景色
    void setArticleColor(QColor col);                   //设置内容区域背景色
    void setFooterColor(QColor col);                    //设置底部区域背景色
    void setButtonText(const QString &leftText,const QString &rightText);
                                                        //设置按钮文字
    void setOKBtnText(const QString &text);             //设置确认按钮的文字
    void setCancleBtnText(const QString& text);         //设置取消按钮的文字
    ~TDModal();
protected:
    void paintEvent(QPaintEvent * event);
    void resizeEvent(QResizeEvent * e);


    bool            show_title;
    QWidget *       m_pTitleWidget;         //标题区域
    QLabel *        m_pTitleLabel;          //标题文字
    QWidget *       m_pArticleWidget;       //内容区域
    QWidget *       m_pFooterWidget;        //底部区域
    QHBoxLayout *   m_pTopHLayout;          //顶部区域水平布局
    QHBoxLayout *   m_pArticleHLayout;      //内容区域水平布局
    QHBoxLayout *   m_pFooterHLayout;       //底部区域水平布局
    QVBoxLayout *   m_pMainLayout;          //整体垂直布局
    QPushButton *   m_pOKBtn;               //成功按钮
    QPushButton *   m_pCancleBtn;           //取消按钮
    TDPushButton *  m_pCloseBtn;            //关闭按钮


private:

};

#endif  //TDMODAL
