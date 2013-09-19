#ifndef ORGATE_H
#define ORGATE_H
#include "gate.h"
class orGate : public gate
{
public:
    orGate(QObject *parent);
    ~orGate();
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

#endif // ORGATE_H
