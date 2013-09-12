#include "orgate.h"

orGate::orGate(QObject *parent) : gate(parent)
{

}



orGate::~orGate()
{
}

 bool orGate::eval()
{
    return false;
}

 void orGate::init(unsigned int numInputs)
 {
    setInitialized();
 }

 unsigned int orGate::getNumInputs()
 {

 }

 void orGate::setInput(unsigned int inputNum,gatePtrType inGate)
 {

 }

 QString orGate::getInputName(unsigned int inputNum) const
 {

 }
