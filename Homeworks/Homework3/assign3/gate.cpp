#include <QDebug>
#include "gate.h"

// Define the constant used when returning the name for an input that is not connected
const QString gate::NotConnected = "NotConnected";

gate::gate(QObject *parent) :
    QObject(parent), isInitialized(false)
{
}

gate::~gate()
{
    Q_ASSERT(getInitialized());
}

void gate::setName(const QString &name) {
    Q_ASSERT(getInitialized());
    m_name = name;
}

QString gate::getName() const {
    Q_ASSERT(getInitialized());
    return(m_name);
}
