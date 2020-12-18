#include "systemcheck.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemCheck w;
    w.show();
    return a.exec();
}
