#include "andgate.h"
andGate::andGate(QObject *parent) : gate(parent)
{

}


andGate::~andGate()
{
    Q_ASSERT(getInitialized());
    int limit = getNumInputs();
    for(int x = 0; x < limit;x++)
    {
        m_inputs[x].ConnectedGate = NULL;
        m_inputs.removeAt(x);
    }
}

 bool andGate::eval() const
{
     Q_ASSERT(getInitialized());
     bool result = true;
     for(int x = 0; x < m_inputs.size(); x++)
     {
         if(m_inputs[x].isConnected)
         {
           result = result && m_inputs[x].ConnectedGate->eval();

         }
         else
         {
             qDebug() << "ERROR: Cannot evaluate gate" << getName() << " " << ":" << " Input " << x << " is not specified." << " Value returned will be meaningless.";
              result = result && false;
         }
     }
     return result;
}

 void andGate::init(unsigned int numInputs)
 {
    setInitialized();
    for(unsigned int x  = 0; x < numInputs;x++)
    {
    input newinput;
    newinput.ConnectedGate = NULL;
    newinput.isConnected = false;
    m_inputs.append(newinput);
    }
 }

 unsigned int andGate::getNumInputs() const
 {
     Q_ASSERT(getInitialized());
     return m_inputs.size();
 }

 void andGate::setInput(unsigned int inputNum,gatePtrType inGate)
 {
Q_ASSERT(getInitialized());
     m_inputs[inputNum].isConnected = true;
     m_inputs[inputNum].ConnectedGate = inGate;
 }

 QString andGate::getInputName(unsigned int inputNum) const
 {
     Q_ASSERT(getInitialized());

     if(m_inputs[inputNum].isConnected && m_inputs[inputNum].ConnectedGate != NULL)
         return m_inputs[inputNum].ConnectedGate->getName();

    return gate::NotConnected;
 }

