#include <QDebug>
#include "andgate.h"

// Your method implementations should be in this file

/*!
  \class andGate
  \brief Representation of an AND logic gate

  More information goes here
*/
void andGate::init()
{
    m_name = "";
    m_inputOne.ConnectedAnd = NULL;
    m_inputOne.ConnectedBool = false;
    m_inputOne.isConnected = false;


    m_inputTwo.ConnectedAnd = NULL;
    m_inputTwo.ConnectedBool = false;
    m_inputTwo.isConnected = false;
}

QString andGate::getName() const
{
    return m_name;
}
void andGate::setName(const QString & name)
{
    m_name = name;
}
QString andGate::getInputOneName() const
{
    if(m_inputOne.ConnectedAnd != NULL)
        return m_inputOne.ConnectedAnd->getName();
    return m_inputOne.ConnectedBool?"True":"False";
}
QString andGate::getInputTwoName() const
{
    if(m_inputTwo.ConnectedAnd != NULL)
        return m_inputTwo.ConnectedAnd->getName();
    return m_inputTwo.ConnectedBool?"True":"False";
}




void andGate::setInputOne(andGate *inputOne)
{
 m_inputOne.isConnected = true;
 m_inputOne.ConnectedAnd = inputOne;
}
void andGate::setInputTwo(andGate *inputTwo)
{
m_inputTwo.isConnected = true;
m_inputTwo.ConnectedAnd = inputTwo;
}
void andGate::setInputOne(bool inputOne)
{
    if(m_inputOne.isConnected && m_inputOne.ConnectedAnd != NULL)
    {
        qDebug() << "WARNING: Input One of gate \" " << m_name << "\" is already set to \"" << m_inputOne.ConnectedAnd->getName() << "\" : Cannot set to a boolean value";
        return;
    }
    m_inputOne.isConnected = true;
    m_inputOne.ConnectedBool = inputOne;
}

void andGate::setInputTwo(bool inputTwo)
{
    if(m_inputTwo.isConnected && m_inputTwo.ConnectedAnd != NULL)
    {
        qDebug() << "WARNING: Input Two of gate \" " << m_name << "\" is already set to \"" << m_inputTwo.ConnectedAnd->getName() << "\" : Cannot set to a boolean value";
        return;
    }
    m_inputTwo.isConnected = true;
    m_inputTwo.ConnectedBool = inputTwo;
}

bool andGate::eval() const
{
  bool inputOneValue = false;
  bool inputTwoValue = false;


  if(!m_inputOne.isConnected)
  {
      qDebug() << "WARNING: Cannot evaluate gate  " << m_name << "Input One is not specified.  Value returned will be meaningless.";

  }
  else
  {
      if(m_inputOne.ConnectedAnd != NULL)
          inputOneValue = m_inputOne.ConnectedAnd->eval();
      else
          inputOneValue = m_inputOne.ConnectedBool;
  }
  if(!m_inputTwo.isConnected)
  {
      qDebug() << "WARNING: Cannot evaluate gate  " << m_name << "Input Two is not specified.  Value returned will be meaningless.";
  }
  else
  {
      if(m_inputTwo.ConnectedAnd != NULL)
          inputTwoValue = m_inputTwo.ConnectedAnd->eval();
      else
          inputTwoValue = m_inputTwo.ConnectedBool;
  }
  return inputOneValue && inputTwoValue;
}
