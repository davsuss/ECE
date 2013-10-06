#include "andgate.h"

andGate::andGate(QObject *parent) : gate(parent)
{

}

andGate::~andGate()
{

}

void andGate::init(const QString &gateName)
{
    setInitialized();
    setName(gateName);
}

unsigned int andGate::getNumInputs() const
{
   Q_ASSERT(getInitialized());
    return m_inputs.size();
}
void andGate::setInput(gatePtrType inGate)
{
    Q_ASSERT(getInitialized());
    LogicLevel level = getGateOutput();
    m_inputs << inGate;
    connect(inGate,SIGNAL(destroyed()),this,SLOT(inputDestroyed()));
    connect(inGate,SIGNAL(outputChanged()),this,SLOT(receiveInputChanged()));
    //Recalculate Logical Value
    for(unsigned int x= 0 ; x < getNumInputs(); x++)
    {
        switch (m_inputs[x]->getGateOutput())
         {
         case logicUndefined:
            if(level != logicUndefined)
            {
            setGateOutput(logicUndefined);
            emit outputChanged();
            }
            return;
         case logicFalse:
            if(level != logicFalse)
            {
            setGateOutput(logicFalse);
            emit outputChanged();
            }
            return;
         case logicTrue:
            break;
         }



    }
    if(level != logicTrue)
    {
        setGateOutput(logicTrue);
        emit outputChanged();
    }
    ///////////////////////////
    return;


}

QString andGate::getInputName(unsigned int inputNum) const
{
   Q_ASSERT(getInitialized());
    return m_inputs[inputNum]->getName();
}

void andGate::receiveInputChanged()
{
    Q_ASSERT(getInitialized());
    LogicLevel level = getGateOutput();
    //Recalculate Logical Value
    if(getNumInputs() == 0)
    {
        if(level != logicUndefined)
        {
         setGateOutput(logicUndefined);
         emit outputChanged();
        }
        return;
    }
    for(unsigned int x= 0 ; x < getNumInputs(); x++)
    {
        switch (m_inputs[x]->getGateOutput())
         {
         case logicUndefined:
            if(level != logicUndefined)
            {
            setGateOutput(logicUndefined);
            emit outputChanged();
            }
            return;
         case logicFalse:
            if(level != logicFalse)
            {
            setGateOutput(logicFalse);
            emit outputChanged();
            }
            return;
         case logicTrue:
            break;
         }



    }
    if(level != logicTrue)
    {
        setGateOutput(logicTrue);
        emit outputChanged();
    }
    ///////////////////////////
    return;
}

void andGate::inputDestroyed()
{
    Q_ASSERT(getInitialized());
    for(unsigned int x = 0; x < getNumInputs(); x++)
    {
        if(m_inputs[x].isNull())
            m_inputs.removeAt(x);
    }
    //Recalculate Logical Value
    LogicLevel level = getGateOutput();
    if(getNumInputs() == 0)
    {
        if(level != logicUndefined)
        {
         setGateOutput(logicUndefined);
         emit outputChanged();
        }
        return;
    }
    for(unsigned int x= 0 ; x < getNumInputs(); x++)
    {
        switch (m_inputs[x]->getGateOutput())
         {
         case logicUndefined:
            if(level != logicUndefined)
            {
            setGateOutput(logicUndefined);
            emit outputChanged();
            }
            return;
         case logicFalse:
            if(level != logicFalse)
            {
            setGateOutput(logicFalse);
            emit outputChanged();
            }
            return;
         case logicTrue:
            break;
         }



    }
    if(level != logicTrue)
    {
        setGateOutput(logicTrue);
        emit outputChanged();
    }
    ///////////////////////////
}
