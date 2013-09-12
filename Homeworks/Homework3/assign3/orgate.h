#ifndef ORGATE_H
#define ORGATE_H
#include "gate.h"
class orGate : public gate
{
public:
    orGate(QObject *parent);
    ~orGate();
    void init(unsigned int numInputs);
    bool eval();
    unsigned int getNumInputs();
    void setInput(unsigned int inputNum,gatePtrType inGate);
    QString getInputName(unsigned int inputNum) const;
};

#endif // ORGATE_H
