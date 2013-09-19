#ifndef RECIVER_H
#define RECIVER_H
#include <QObject>
#include "counter.h"
#include <QDebug>
class Reciver : public QObject
{
public:
   Reciver();
   int getCount();
public slots:
   void Itterated();

private:
  int m_value;
};

#endif // RECIVER_H
