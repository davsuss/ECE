#ifndef VOLTAGESOURCEGATE_H
#define VOLTAGESOURCEGATE_H
#include "gate.h"
class voltageSourceGate : public gate
{
public:
    voltageSourceGate(QObject* pointer);
    ~voltageSourceGate();
    void init(unsigned int numInputs);
    bool eval() const;
    unsigned int getNumInputs() const;
    void setInput(unsigned int inputNum,gatePtrType inGate);
    QString getInputName(unsigned int inputNum) const;
};

#endif // VOLTAGESOURCEGATE_H
