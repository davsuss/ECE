#ifndef ANDGATE_H
#define ANDGATE_H
#include "gate.h"
#include "gate.cpp"
#include <QList>
class andGate : public gate
{
public:
    andGate(QObject *parent);
    ~andGate();
    void init(unsigned int numInputs);
    bool eval() const;
    unsigned int getNumInputs() const;
    void setInput(unsigned int inputNum,gatePtrType inGate);
    QString getInputName(unsigned int inputNum) const;

private:
    struct input
    {
      bool isConnected;
      gatePtrType ConnectedGate;
    };
    QList<input> m_inputs;

};

#endif // ANDGATE_H
