#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>
class Counter : public QObject
{
public:
    Counter();
signals:
    void Itterated();
};

#endif // COUNTER_H
