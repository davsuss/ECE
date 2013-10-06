#include "gate.h"

#ifndef ORGATE_H
#define ORGATE_H

class orGate : public gate
{
public:
    orGate(QObject *);

    // Must be called prior to using an object of a class derived from gate
    //  the argument is the name of the gate which the init() function should set
    void init(const QString &gateName);

    // Return the number of inputs connected to this gate
    unsigned int getNumInputs() const;

    // Add an input to this gate
    //   inGate MUST point to a gate and may not be NULL
    void setInput(gatePtrType inGate);

    // Returns the name of one of the input gates, where the current inputs are numbered 0 to getNumInputs()-1
    QString getInputName(unsigned int inputNum) const;

    // Destructor
    ~orGate();

public slots:
    // Should be called when an input to this gate has been changed
    void receiveInputChanged();

    // Should be called when one of the gates that is an input to this gate has been destroyed
    void inputDestroyed();

private:
    QList<gatePtrType> m_inputs; // list of input_pins in the andGate
};
#endif // ORGATE_H
