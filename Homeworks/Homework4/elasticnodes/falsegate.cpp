#include "falsegate.h"

falseGate::falseGate(QObject *parent) : gate(parent)
{


}

falseGate::~falseGate()
{

}

void falseGate::init(const QString &gateName)
{
    setInitialized();
    setName("False");
    setGateOutput(logicFalse);
}

unsigned int falseGate::getNumInputs() const
{
    Q_ASSERT(getInitialized());
    return 0;
}
void falseGate::setInput(gatePtrType inGate)
{
     Q_ASSERT(getInitialized());
     return;
}

QString falseGate::getInputName(unsigned int inputNum) const
{
    Q_ASSERT(getInitialized());
    return "";
}
void falseGate::receiveInputChanged()
{
    Q_ASSERT(getInitialized());
}

void falseGate::inputDestroyed()
{
    Q_ASSERT(getInitialized());
}
