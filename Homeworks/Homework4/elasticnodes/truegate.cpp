#include "truegate.h"
trueGate::trueGate(QObject *parent) : gate(parent)
{


}

trueGate::~trueGate()
{

}

void trueGate::init(const QString &gateName)
{
    setInitialized();
    setName("True");
    setGateOutput(logicTrue);
}

unsigned int trueGate::getNumInputs() const
{
    Q_ASSERT(getInitialized());
    return 0;
}
void trueGate::setInput(gatePtrType inGate)
{
     Q_ASSERT(getInitialized());
     return;
}

QString trueGate::getInputName(unsigned int inputNum) const
{
    Q_ASSERT(getInitialized());
    return "";
}
void trueGate::receiveInputChanged()
{
    Q_ASSERT(getInitialized());
}

void trueGate::inputDestroyed()
{
    Q_ASSERT(getInitialized());
}

