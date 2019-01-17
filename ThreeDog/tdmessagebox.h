/**************************************************************
 * File Name   : tdmessagebox.h
 * Author      : ThreeDog
 * Date        : Thu Jan 17 10:32:02 2019
 * Description : 消息框控件， 直接弹出模态窗体+提示信息，参数为提示信息
 *      1、消息框
 *      2、告警框 & 错误框
 *      3、提问框
 *
 **************************************************************/
#ifndef _TDMESSAGEBOX_H_ 
#define _TDMESSAGEBOX_H_
#include "ThreeDog/tdwidget.h"
#include "ThreeDog/tdmodal.h"
#include <QMessageBox>

class TDMessageBox:public TDModal
{
    Q_OBJECT
public:
    static int information(const QString &info,QWidget * parent = 0);
    static int question(const QString & info,QWidget * parent = 0);
    static int warning(const QString & info,QWidget * parent = 0);
    static void setBtnText(const QString & text1,const QString & text2);
    ~TDMessageBox();
public slots:
    void okBtnClicked();
    void cancleBtnClicked();
private:
    explicit TDMessageBox(const int type, const QString &text,const QString & title,QWidget * parent = 0);
    TDWidget * m_pMsgIcon;
    QLabel * m_pTextLabel;
    static QString s_sOkBtnText;
    static QString s_sCancleBtnText;

};

#endif  //TDMESSAGEBOX
