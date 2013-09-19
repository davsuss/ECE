#ifndef GROUNDGATE_H
#define GROUNDGATE_H
#include "gate.h"
class groundGate : public gate
{
public:
    groundGate(QObject* pointer);
    ~groundGate();
    void init(unsigned int numInputs);
    bool eval() const;
    unsigned int getNumInputs() const;
    void setInput(unsigned int inputNum,gatePtrType inGate);
    QString getInputName(unsigned int inputNum) const;
};

#endif // GROUNDGATE_H
