#ifndef SYSTEMCHECK_H
#define SYSTEMCHECK_H
#include <QRegExp>
#include <QMainWindow>
#include <QMessageLogger>
#include <QProcess>
#include <QDebug>
#include <QtMath>
QT_BEGIN_NAMESPACE
namespace Ui { class SystemCheck; }
QT_END_NAMESPACE

class SystemCheck : public QMainWindow
{
    Q_OBJECT

public:
    SystemCheck(QWidget *parent = nullptr);
    ~SystemCheck();

private:
    Ui::SystemCheck *ui;
protected:
    float uptime();
    float cpustate();

};
#endif // SYSTEMCHECK_H
