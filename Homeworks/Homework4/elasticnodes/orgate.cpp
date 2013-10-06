#include "orgate.h"

orGate::orGate(QObject *parent) : gate(parent)
{

}

orGate::~orGate()
{

}

void orGate::init(const QString &gateName)
{
    setInitialized();
    setName(gateName);
}

unsigned int orGate::getNumInputs() const
{
   Q_ASSERT(getInitialized());
    return m_inputs.size();
}
void orGate::setInput(gatePtrType inGate)
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
         case logicTrue:
            if(level != logicTrue)
            {
            setGateOutput(logicTrue);
            emit outputChanged();
            }
            return;
         case logicFalse:
            break;
         }



    }
    if(level != logicFalse)
    {
        setGateOutput(logicFalse);
        emit outputChanged();
    }
    ///////////////////////////
    return;


}

QString orGate::getInputName(unsigned int inputNum) const
{
   Q_ASSERT(getInitialized());
    return m_inputs[inputNum]->getName();
}

void orGate::receiveInputChanged()
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
         case logicTrue:
            if(level != logicTrue)
            {
            setGateOutput(logicTrue);
            emit outputChanged();
            }
            return;
         case logicFalse:
            break;
         }



    }
    if(level != logicFalse)
    {
        setGateOutput(logicFalse);
        emit outputChanged();
    }
    ///////////////////////////
    return;
}

void orGate::inputDestroyed()
{
    Q_ASSERT(getInitialized());
    for(unsigned int x = 0; x < getNumInputs(); x++)
    {
        if(m_inputs[x].isNull())
         {
            m_inputs.removeAt(x);
            break;
         }
    }

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
         case logicTrue:
            if(level != logicTrue)
            {
            setGateOutput(logicTrue);
            emit outputChanged();
            }
            return;
         case logicFalse:
            break;
         }



    }
    if(level != logicFalse)
    {
        setGateOutput(logicFalse);
        emit outputChanged();
    }
    ///////////////////////////
}
