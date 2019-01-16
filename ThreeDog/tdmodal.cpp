/**************************************************************
 * File Name   : tdmodal.cpp
 * Author      : ThreeDog
 * Date        : Mon Jan 14 20:21:26 2019
 * Description :
 *
 **************************************************************/

#include "tdmodal.h"
TDModal::TDModal(QString title,QWidget *parent)
    :QDialog(parent)
{
    //设置本窗体隐藏边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置此窗体模态
    this->setModal(true);
    this->resize(550,480);

    //设置背景色
    setBackgroundColor(Qt::white);
    show_title = true;

    //初始化界面
    initInterface(title);
    this->setTitleVisible(false);


}

void TDModal::initInterface(QString title)
{
    //标题区域
    m_pTitleWidget = new QWidget(this);
    m_pTitleWidget->setObjectName("m_pTitleWidget");
    m_pTitleWidget->resize(this->width(),50);
    m_pTitleWidget->setFixedHeight(50);
    setTitleColor(QColor("#F3F8FD"));
    QPalette p;
    p.setColor(QPalette::Background,QColor("#F3F8FD"));
    m_pTitleWidget->setStyleSheet("QWidget#m_pTitleWidget{"
                                  "background:#F3F8FD;"
                                  "border-style:solid;"
                                  "border-width:0px;"
                                  "border-color:#DFDFDF;"
                                  "}");
    m_pTopHLayout = new QHBoxLayout;
    m_pTitleWidget->setLayout(m_pTopHLayout);
    m_pTitleLabel = new QLabel(title,m_pTitleWidget);//标题
    m_pTitleLabel->resize(64,50);
    m_pTitleLabel->setStyleSheet("font-size:16px;"\
                                 "font-family:微软雅黑;"\
                                 "color:rgba(38,38,38,1);"\
                                 "line-height:21px;");
    m_pTopHLayout->addWidget(m_pTitleLabel);
    m_pTopHLayout->addStretch(5);
    m_pCloseBtn = new TDPushButton(":/img/index/close_normal.png",":/img/index/close_hover.png",":/img/index/close_normal.png",m_pTitleWidget);
    m_pTopHLayout->addWidget(m_pCloseBtn);
    m_pTopHLayout->setContentsMargins(40,0,40,0);
    m_pTitleWidget->setLayout(m_pTopHLayout);

    //内容区域
    m_pArticleWidget = new QWidget(this);
    m_pArticleWidget->setObjectName("m_pArticleWidget");
    m_pArticleWidget->setStyleSheet("QWidget#m_pArticleWidget{"
                                  "border-style:solid;"
                                  "border-width:0px 0px 1px 0px;"
                                  "border-color:#DFDFDF;"
                                  "}");
    m_pArticleHLayout = new QHBoxLayout;
    m_pArticleWidget->setLayout(m_pArticleHLayout);
    m_pArticleHLayout->setContentsMargins(40,20,40,30);

    //底部区域
    m_pFooterWidget = new QWidget(this);
    m_pFooterHLayout = new QHBoxLayout;
    m_pFooterWidget->setLayout(m_pFooterHLayout);
    m_pFooterWidget->setFixedHeight(85);
    m_pFooterHLayout->setContentsMargins(40,20,40,30);

    m_pOKBtn = new QPushButton("确定",m_pFooterWidget);
    m_pCancleBtn = new QPushButton("取消",m_pFooterWidget);
    m_pFooterHLayout->addStretch();
    m_pFooterHLayout->addWidget(m_pOKBtn);
    m_pFooterHLayout->addWidget(m_pCancleBtn);
    m_pFooterHLayout->setSpacing(20);


    m_pMainLayout = new QVBoxLayout;
    m_pMainLayout->addWidget(m_pTitleWidget);
    m_pMainLayout->addWidget(m_pArticleWidget);
    m_pMainLayout->addWidget(m_pFooterWidget);
    m_pMainLayout->setMargin(0);

    this->setLayout(m_pMainLayout);
    this->setObjectName("model");
    this->setStyleSheet("QWidget#model{"
                      "border-style:solid;"
                      "border-width:0px;"
                      "border-color:#DFDFDF;"
                      "}"
                      );
}

void TDModal::setTitleVisible(bool b)
{
    show_title = b;
    //显示标题栏
    if(b){
        this->m_pTitleWidget->show();
    }else{
        this->m_pTitleWidget->hide();
    }

}

void TDModal::setTitle(const QString &text)
{
    //设置标题
    this->m_pTitleLabel->setText(text);
}

void TDModal::setTitleColor(QColor col)
{
    QPalette p;
    p.setColor(QPalette::Background,col);
    m_pTitleWidget->setPalette(p);
}

void TDModal::setBackgroundColor(QColor col)
{
    QPalette p;
    p.setColor(QPalette::Background,col);
    this->setPalette(p);
}

TDModal::~TDModal()
{

}
