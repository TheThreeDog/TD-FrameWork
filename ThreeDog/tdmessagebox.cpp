/**************************************************************
 * File Name   : tdmessagebox.cpp
 * Author      : ThreeDog 
 * Date        : Thu Jan 17 10:32:02 2019
 * Description : 
 *
 **************************************************************/

#include "tdmessagebox.h"

QString TDMessageBox::s_sOkBtnText = "确认";
QString TDMessageBox::s_sCancleBtnText = "取消";

int TDMessageBox::information(const QString &info,QWidget * parent)
{
    TDMessageBox * t = new TDMessageBox(0,info,"消息",parent);
    t->show();
    return t->exec();
}

int TDMessageBox::question(const QString &info,QWidget * parent)
{
    TDMessageBox * t = new TDMessageBox(1,info,"询问",parent);

    t->show();
    return t->exec();
}

int TDMessageBox::warning(const QString &info,QWidget * parent)
{
    TDMessageBox * t = new TDMessageBox(2,info,"警告",parent);
    t->show();
    return t->exec();
}

void TDMessageBox::setBtnText(const QString & text1, const QString & text2)
{
    s_sOkBtnText = text1;
    s_sCancleBtnText = text2;
}

TDMessageBox::~TDMessageBox()
{

}

void TDMessageBox::okBtnClicked()
{
    this->done(QMessageBox::Yes);
    this->close();
}

void TDMessageBox::cancleBtnClicked()
{
    this->done(QMessageBox::No);
    this->close();
}

TDMessageBox::TDMessageBox(const int type, const QString &text, const QString & title,QWidget * parent)
    :TDModal(title,parent)
{
    this->setWindowTitle(title);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //标题栏不可见
    this->setTitleVisible(false);
    m_pArticleWidget->setStyleSheet("QWidget#m_pArticleWidget{"
                                  "background:#FFFFFF;"
                                  "border-style:solid;"
                                  "border-width:0px,0px,0px,0px;"
                                  "border-color:#DFDFDF;"
                                  "margin:6px 6px 0px 6px;"
                                  "}");
    this->resize(403,243);
    m_pTextLabel = new QLabel(this);
    m_pTextLabel->setStyleSheet("font-size:14px;"\
                                "font-family:微软雅黑;"\
                                "color:#262626;"\
                                "line-height:19px;");

    //去掉按钮左侧的弹簧
    m_pFooterHLayout->takeAt(m_pFooterHLayout->stretch(0));
    if(type == 0){//消息框
        m_pMsgIcon = new TDWidget(":/img/index/info_icon.png",this);
        m_pFooterHLayout->removeWidget(m_pCancleBtn);
        m_pCancleBtn->close();
        m_pOKBtn->setText(s_sOkBtnText);
    }else if(type == 1){//提问框
        m_pMsgIcon = new TDWidget(":/img/index/question_icon.png",this);
        m_pOKBtn->setText(s_sOkBtnText);
        m_pCancleBtn->setText(s_sCancleBtnText);
    }else if(type == 2){//错误框
        m_pMsgIcon = new TDWidget(":/img/index/error_icon.png",this);
        m_pFooterHLayout->removeWidget(m_pCancleBtn);
        m_pCancleBtn->close();
        m_pOKBtn->setText(s_sOkBtnText);
    }
    m_pMsgIcon->setMoveEnable(false);
    m_pMsgIcon->setAutoMask();
    //将两个控件水平布局，居中显示
    QHBoxLayout  * h1 = new QHBoxLayout;
    h1->addStretch(2);
    h1->addWidget(m_pMsgIcon,1);
    h1->addStretch(2);
    QHBoxLayout  * h2 = new QHBoxLayout;
    h2->addStretch(2);
    h2->addWidget(m_pTextLabel,1);
    h2->addStretch(2);
    m_pArticleVLayout->addLayout(h1,8);
    m_pArticleVLayout->addLayout(h2,2);
    m_pArticleVLayout->setSpacing(0);
    m_pArticleVLayout->setContentsMargins(40,40,40,10);
    m_pFooterHLayout->setContentsMargins(40,10,40,30);
    m_pTextLabel->setText(text);

    //关联按钮点击的操作
    connect(m_pOKBtn,SIGNAL(clicked(bool)),this,SLOT(okBtnClicked()));
    connect(m_pCancleBtn,SIGNAL(clicked(bool)),this,SLOT(cancleBtnClicked()));
}
