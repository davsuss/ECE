#include <QCoreApplication>
#include "counter.h"
#include "reciver.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Counter objecta;
    Counter objectb;
     QObject::connect(objecta,objecta.Itterated(),objectb,objectb.Itterated());
     objecta.Itterated();
    return a.exec();
}
