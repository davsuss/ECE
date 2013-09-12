#include "andgate.h"

andGate::andGate(QObject *parent) : gate(parent)
{

}
andGate::~andGate()
{
}

  bool andGate::eval() const
{
    return false;
}

  void andGate::init(unsigned int numInputs)
 {
    setInitialized();
    //sets numInputs number of unconnected inputs for the andGate
    for(unsigned int x  = 0; x < numInputs;x++)
    {
    input newinput;
    newinput.ConnectedAND = NULL;
    newinput.ConnectedBoolean = false;
    newinput.isConnected = false;
    m_inputs.append(newinput);
    }
 }

  unsigned int andGate::getNumInputs() const
 {


 }

  void andGate::setInput(unsigned int inputNum,gatePtrType inGate)
 {

 }

  QString andGate::getInputName(unsigned int inputNum) const
 {
      Q_ASSERT(getInitialized());
      if(!m_inputs[inputNum].isConnected);
          return gate::NotConnected;

      if(m_inputs[inputNum].ConnectedAND != NULL)
          return m_inputs[inputNum].ConnectedAND->getName();

      return QString::number(m_inputs[inputNum].ConnectedBoolean);





 }
