#include "systemcheck.h"
#include "ui_systemcheck.h"
#include <QMessageLogger>
SystemCheck::SystemCheck(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SystemCheck)
{
    uptime();
    cpustate();
    ui->setupUi(this);
}

SystemCheck::~SystemCheck()
{
    delete ui;
}

float SystemCheck::uptime()
{
    QProcess uptimeIn;
    double runtime,freetime;
    uptimeIn.start("cat /proc/uptime");
    if(!uptimeIn.waitForFinished())
    qDebug()<<"finished failed"<<endl;
    QString line = uptimeIn.readAllStandardOutput();
    QStringList list = line.split(QRegExp("\\s{1,}"));
    if (!list.isEmpty()) {
            runtime = list.at(0).toDouble();
            freetime = list.at(1).toDouble();
        }
    int time = qFloor(runtime);
    int ss = time % 60;
    int MM = (time % 3600) / 60;
    int hh = (time % 86400) / 3600;
    int dd = time / 86400;

    QString runTimeout = QString(tr("设备已运行: %1天, %2:%3:%4"))
                .arg(dd, 0, 'f', 0, QLatin1Char(' '))
                .arg(hh, 2, 'f', 0, QLatin1Char('0'))
                .arg(MM, 2, 'f', 0, QLatin1Char('0'))
                .arg(ss, 2, 'f', 0, QLatin1Char('0'));
     qInfo()<<runTimeout;
     //qInfo()<<freetime;
}
float SystemCheck::cpustate()
{
    QProcess cpustateIn;
    double cpuAll,cpuFree;
    cpustateIn.start("cat /proc/stat");
    if(!cpustateIn.waitForFinished())
    qDebug()<<"finished failed"<<endl;
    QString line = cpustateIn.readAllStandardOutput();
    if (!line.isNull()) {
    QStringList list = line.split(QRegExp("\\s{1,}"));
    for (auto v = list.begin() + 1; v != list.end(); ++v)
         cpuAll += (*v).toLong();
         cpuFree = list.at(4).toLong();
    }
    float a = ((0-cpuAll) - (cpuFree-0))*100/ cpuAll;
     qInfo()<<a;
     qInfo()<<cpuFree;
}
float SystemCheck::memstate()
{
    QProcess memstateIn;
    double memory,swap;
    memstateIn.start("cat /proc/meminfo");
    if(!memstateIn.waitForFinished())
    qDebug()<<"finished failed"<<endl;
    QString line = memstateIn.readAllStandardOutput();
    long buff[16] = {0};
       for (int i = 0; i <= 15; ++i) {
           QString line = line.readLine();
           QStringList list = line.split(QRegExp("\\s{1,}"));
           buff[i] = list.at(1).toLong();

       }
    if (!line.isNull()) {
    QStringList list = line.split(QRegExp("\\s{1,}"));
    for (auto v = list.begin() + 1; v != list.end(); ++v)
         cpuAll += (*v).toLong();
         cpuFree = list.at(4).toLong();
    }
    float a = ((0-cpuAll) - (cpuFree-0))*100/ cpuAll;
     qInfo()<<a;
     qInfo()<<cpuFree;
}
