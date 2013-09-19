#include "voltagesourcegate.h"

voltageSourceGate::voltageSourceGate(QObject *parent) : gate(parent)
{

}



voltageSourceGate::~voltageSourceGate()
{

}

 bool voltageSourceGate::eval() const
{
     Q_ASSERT(getInitialized());
    return true;
}

 void voltageSourceGate::init(unsigned int numInputs)
 {
    setInitialized();
    setName("True");
 }

 unsigned int voltageSourceGate::getNumInputs() const
 {
     Q_ASSERT(getInitialized());
     return 0;

 }

 void voltageSourceGate::setInput(unsigned int inputNum,gatePtrType inGate)
 {
    Q_ASSERT(getInitialized());
 }

 QString voltageSourceGate::getInputName(unsigned int inputNum) const
 {
    Q_ASSERT(getInitialized());
     return "True";
 }
