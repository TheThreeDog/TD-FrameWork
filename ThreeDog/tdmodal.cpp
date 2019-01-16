/**************************************************************
 * File Name   : tdmodal.cpp
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

#include "tdmodal.h"
TDModal::TDModal(QString title,QWidget *parent)
    :QDialog(parent)
{
    //设置本窗体隐藏边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAutoFillBackground(true);
    //设置此窗体模态
    this->setModal(true);
    //    设置内部控件阴影效果
    //    this->initShadow();
    this->resize(550,480);

    //初始化界面
    initInterface(title);

    //设置背景色
    //  this->setTitleColor(QColor("#000000"));
    //  this->setArticleColor(QColor("#000000"));
    //  this->setFooterColor(QColor("#000000"));
    show_title = true;
}

void TDModal::initInterface(QString title)
{

    //标题区域
    m_pTitleWidget = new QWidget(this);
    m_pTitleWidget->setObjectName("m_pTitleWidget");
    m_pTitleWidget->resize(this->width(),50);
    m_pTitleWidget->setFixedHeight(50);
    m_pTitleWidget->setStyleSheet("QWidget#m_pTitleWidget{"
                                  "background:#F3F8FD;"
                                  "border-style:solid;"
                                  "border-width:0px,1px,0px,0px;"
                                  "border-color:#DFDFDF;"
                                  "margin:6px 6px 0px 6px;"
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
                                    "background:#FFFFFF;"
                                    "border-style:solid;"
                                    "border-width:0px 0px 1px 0px;"
                                    "border-color:#DFDFDF;"
                                    "margin:0px 6px 0px 6px;"
                                    "}");
    m_pArticleHLayout = new QHBoxLayout;
    m_pArticleWidget->setLayout(m_pArticleHLayout);
    m_pArticleHLayout->setContentsMargins(40,20,40,30);



    //底部区域
    m_pFooterWidget = new QWidget(this);
    m_pFooterHLayout = new QHBoxLayout;
    m_pFooterWidget->setLayout(m_pFooterHLayout);
    m_pFooterWidget->setFixedHeight(85);
    m_pFooterWidget->setObjectName("m_pFooterWidget");
    m_pFooterWidget->setStyleSheet("QWidget#m_pFooterWidget{"
                                   "background:#FFFFFF;"
                                   "border-style:solid;"
                                   "border-width:0px 0px 1px 0px;"
                                   "border-color:#DFDFDF;"
                                   "margin:0px 6px 6px 6px;"
                                   "}");
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
    m_pMainLayout->setSpacing(0);

    this->setLayout(m_pMainLayout);
}

void TDModal::initShadow()
{
    //设置内部控件的的阴影效果
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(3, 3);
    shadow_effect->setColor(QColor("#DFDFDF"));
    shadow_effect->setBlurRadius(5);
    this->setGraphicsEffect(shadow_effect);

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
    //改变标题区域颜色
}

void TDModal::setArticleColor(QColor col)
{
    //改变内容区域颜色
    QString styleStr = QString("QWidget#m_pArticleWidget{"
                               "background:%1;"
                               "border-style:solid;"
                               "border-width:0px 0px 1px 0px;"
                               "border-color:#DFDFDF;"
                               "margin:0px 6px 0px 6px;"
                               "}").arg(col.name());
    m_pArticleWidget->setStyleSheet(styleStr);
}

void TDModal::setFooterColor(QColor col)
{
    //改变下部区域颜色
    QString styleStr = QString("QWidget#m_pFooterWidget{"
                               "background:%1;"
                               "border-style:solid;"
                               "border-width:0px 0px 1px 0px;"
                               "border-color:#DFDFDF;"
                               "margin:0px 6px 6px 6px;"
                               "}").arg(col.name());
    m_pFooterWidget->setStyleSheet(styleStr);
}

void TDModal::setButtonText(const QString &leftText, const QString &rightText)
{
    m_pOKBtn->setText(leftText);
    m_pCancleBtn->setText(rightText);
}

void TDModal::setOKBtnText(const QString &text)
{
    this->m_pOKBtn->setText(text);
}

void TDModal::setCancleBtnText(const QString &text)
{
    this->m_pCancleBtn->setText(text);
}

void TDModal::paintEvent(QPaintEvent *event)
{
    // 绘制边框阴影
    QPainter painter(this);
    QColor color(0, 0, 0, 0);
    for(int i=0; i<6; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(6-i, 6-i, this->width()-(6-i)*2, this->height()-(6-i)*2);
        color.setAlpha(50 - i*10);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void TDModal::resizeEvent(QResizeEvent *e)
{
    //重设大小事件， 重设窗体的大小时，要加上阴影边框的大小
    this->resize(e->size().width()+18,e->size().height());
}

TDModal::~TDModal()
{

}


