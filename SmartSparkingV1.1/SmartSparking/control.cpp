#include "control.h"
#include "setserial.h"


char status_flag=0,payStatus_flag;

int time11=1;    //停车时间
char coming_flag=0,time_delay=0,time_flag=0; //下位机会不断发送coming信号,设置coming_flag变量，只对第一个coming信号起作用，当开锁后清零。
                                 //设置time_delay变量，当进行开锁后，延时10s,才进行计时 time_flag对延时时间进行计数标志位
Control::Control(QWidget *parent) : QWidget(parent)
{
    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::cyan);
    setPalette(p);
//最上面 标题
     titleLabel =new QLabel(tr("智能车位系统"));
     titleLabel->setFont(QFont("Times",18,QFont::Bold));   //设置字体大小  加粗
     titleLabel->setStyleSheet(QString("color:blue"));        //设置字体颜色
     titleLabel->setAlignment(Qt::AlignHCenter);     //设置居中对齐

//中左  提示信息框
     messageLabel=new QLabel(tr("提示信息"));
     messageLabel->setStyleSheet("color:blue");
     messageLabel->setFont(QFont("Times",10,QFont::Bold));
     infoTextEdit=new QTextEdit;
     infoTextEdit->setGeometry(9,9,200,25);
//中右 车位状态 停车时间
     QFont font;
     font.setPointSize(10);
     font.setBold(true);

     SparkingStatusLabel=new QLabel(tr("当前车位状态："));
     SparkingStatusLabel->setStyleSheet("color:blue");
     SparkingStatusLabel->setFont(font);
     SparkingStatusShowQLabel=new QLabel;
    // SparkingStatusShowQLabel->setBaseSize(100,100);
     SparkingStatusShowQLabel->setText("无车");
     SparkingStatusShowQLabel->setStyleSheet("color:blue");
     SparkingStatusShowQLabel->setFont(font);

     StopTimeLabel=new QLabel(tr("停车时间："));  ;
     StopTimeLabel->setStyleSheet("color:blue");
     StopTimeLabel->setFont(font);
     StopTimeLCDNumber=new QLCDNumber;
     StopTimeLCDNumber->setDigitCount(3);
     StopTimeLCDNumber->display(0);
     StopTimeLCDNumber->setBackgroundRole(QPalette::Highlight);
   //  StopTimeLCDNumber->setSegmentStyle(QLCDNumber::Outline);
//最下 控件
     openBtn=new QPushButton(tr("开锁"));
     openBtn->setStyleSheet("color:blue");
     offBtn=new  QPushButton(tr("关锁"));
     offBtn->setStyleSheet("color:blue");
     payBtn=new  QPushButton(tr("缴费"));
     payBtn->setStyleSheet("color:blue");
     connectBtn=new QPushButton(tr("连接串口"));
     connectBtn->setStyleSheet("color:blue");
//布局  中左
     MidLetfVBoxLayout = new QVBoxLayout();
     MidLetfVBoxLayout->setMargin(10);
     MidLetfVBoxLayout->addWidget(messageLabel);
     MidLetfVBoxLayout->addWidget(infoTextEdit);
     MidLetfVBoxLayout->setSpacing(5);
//布局 中右
     MidRightGridLayout=new QGridLayout();
     MidRightGridLayout->addWidget(SparkingStatusLabel,0,0);
     MidRightGridLayout->addWidget(SparkingStatusShowQLabel,0,1);
     MidRightGridLayout->addWidget(StopTimeLabel,1,0);
     MidRightGridLayout->addWidget(StopTimeLCDNumber,1,1);
     MidRightGridLayout->setSpacing(5);
     MidRightGridLayout->setColumnStretch(0,1);
     MidRightGridLayout->setColumnStretch(1,5);
 //布局 中
     MidHBoxLayout=new QHBoxLayout();
     MidHBoxLayout->setMargin(15);
     MidHBoxLayout->setSpacing(10);
     MidHBoxLayout->addLayout(MidLetfVBoxLayout);
     MidHBoxLayout->addLayout(MidRightGridLayout);
 //下 布局
     downHBoxLayout=new QHBoxLayout();
     downHBoxLayout->setMargin(20);
     downHBoxLayout->setSpacing(50);
     downHBoxLayout->addWidget(openBtn);
     downHBoxLayout->addWidget(offBtn);
     downHBoxLayout->addWidget(payBtn);
     downHBoxLayout->addWidget(connectBtn);

 //整体布局
     mainVBoxLayout=new QVBoxLayout (this);
     mainVBoxLayout->addWidget(titleLabel);
     mainVBoxLayout->addLayout(MidHBoxLayout);
     mainVBoxLayout->addLayout(downHBoxLayout);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(doTimeProess()));
    timer->start(1000);
    connect(openBtn,SIGNAL(clicked()),this,SLOT(openFun()));
    connect(offBtn,SIGNAL(clicked()),this,SLOT(offFun()));
    connect(connectBtn,SIGNAL(clicked()),this,SLOT(connectFun()));   //串口配置
    connect(payBtn,SIGNAL(clicked()),this,SLOT(payFun()));

}
void Control::recPayIfo(char flag)
{
   payStatus_flag=flag;  //支付信息标志位
   infoTextEdit->append("缴费成功，祝一路顺风\r\n");


}
Control::~Control()
{

}
QByteArray str;

void Control::openFun()    //开锁命令
{
    if(payStatus_flag==1)
    {
    str[0]=0x78;
    str[1]=0x21;
    str[2]=0xa5;
    set->serial->write(str);
    coming_flag=0;
    infoTextEdit->append("车位已开锁\r\n");
    SparkingStatusShowQLabel->setText("无车");
    StopTimeLCDNumber->display(time11);
    time11=0;
    status_flag=0;
    time_flag=1;
    payStatus_flag=0;
    }
    else
    {
         infoTextEdit->append("请先缴费\r\n");
    }
}

void Control::offFun()   //关锁命令
{
    str[0]=0x78;
    str[1]=0x11;
    str[2]=0xa5;
    set->serial->write(str);
    infoTextEdit->append("车位已关锁\r\n");

}


void Control::payFun()    //缴费信息
{

   /* str[0]=0x78;
    str[1]=0x01;
    str[2]=0xa5;
    set->serial->write(str);
    infoTextEdit->append("请注意您的消费信息，缴费完成才能开锁\r\n");*/
    Pay=new payMoney();
    connect(Pay, SIGNAL(payInfo(char)), this, SLOT(recPayIfo(char)));
    if(status_flag==1)
    Pay->show();

}
QByteArray buf;

void Control::doTimeProess()
{
    char str[11]="parking_ok";

    if(!buf.isEmpty())
    {
        if(coming_flag==0)
        {
        if(buf.contains("coming"))
        {
            if(time_flag==0)
            {
            infoTextEdit->append("车已正确停入，10s之后车锁将自动升起\r\n");
            coming_flag=1;
            status_flag=1;
            SparkingStatusShowQLabel->setText("有车");
            set->serial->write(str);
            }    
        }
        }
        buf.clear();
     }
    if(time_flag==1)   //延时标志位，为了模拟效果真实
        {
        time_delay++;
        if(time_delay>10)
        {
            time_flag=0;
            time_delay=0;
        }
    }
    if((status_flag==1)&&(time_flag==0))
    {
        time11++;
        StopTimeLCDNumber->display(time11);
    }

}

void Control::connectFun()
{
  set =new setSerial();
  set->show();
}

