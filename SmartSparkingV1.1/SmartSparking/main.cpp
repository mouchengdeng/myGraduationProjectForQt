#include "loginDialog.h"
#include "startshow.h"
#include <QApplication>
#include "control.h"
#include "startload.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startShow w;
    w.show();
    return a.exec();

}
