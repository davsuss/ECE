#include "reciver.h"

Reciver::Reciver()
{
m_value = 0;
}

void Reciver::Itterated()
{
    qDebug() << "Yo Ive been contacted by Counters Dawg";
    m_value++;
}

int Reciver::getCount()
{
    return m_value;
}
