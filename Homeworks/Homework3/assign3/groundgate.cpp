#include "groundgate.h"


groundGate::groundGate(QObject *parent) : gate(parent)
{

}



groundGate::~groundGate()
{
}

 bool groundGate::eval() const
{
     Q_ASSERT(getInitialized());
    return false;
}

 void groundGate::init(unsigned int numInputs)
 {
    setInitialized();
   setName("False");
 }

 unsigned int groundGate::getNumInputs() const
 {
     Q_ASSERT(getInitialized());
     return 0;

 }

 void groundGate::setInput(unsigned int inputNum,gatePtrType inGate)
 {
    Q_ASSERT(getInitialized());
 }

 QString groundGate::getInputName(unsigned int inputNum) const
 {
    Q_ASSERT(getInitialized());
     return "False";
 }
