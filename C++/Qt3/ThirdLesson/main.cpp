#include "third.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Third w;
    w.show();

    return a.exec();
}
