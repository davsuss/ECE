#ifndef GATE_H
#define GATE_H
#include <QDebug>
#include <QObject>
#include <QString>
#include <QPointer>

// This class acts as an interface to logic gate objects.  The public methods defined below
// are the only methods that will be called by programs that use "gate" objects.  You will define
// classes that inherit the gate class; these derived classes are responsible for defining methods
// that override the virtual methods defined in the "gate" class below. The gate class is not meant
// to be instantiated (i.e., you'll never create an object of type "gate"); for that reason, it has no public
// constructor.  Classes that directly inherit the "gate" class should, however, invoke the protected constructor
// for the "gate" class. Here is an example of how to do that for a class "mygate" that inherits "gate":
// myGate::myGate(QObject *parent) :
//    gate(parent)
// {
// }
//
// Some specific guidelines for this assignment:
// (1) You may not change anything in gate.h or gate.cpp.
// (2) Do not override/redefine any method that is not virtual in gate.h
// (3) You must declare a public constructor for any class that will be instantianted as an object.  See the example above
//     for how your constructor must be structured.
// (4) You must define a destructor for each derived class.
// (5) You must override every virtual method defined below in your derived types.
//     (a) the compiler will force this for "pure virtual" methods (i.e., those that have a "= 0" at the end).
//     (b) the compiler won't force you to have one for the destructor, but it is required on this assignment.
// (6) You must not define any additional public methods in your derived classes.  The "gate" class serves as the
//     definition of the API to be used by calling programs.
//
// You will create four derived classes called andGate, orGate, falseGate, trueGate\]'
//   and they must be in the files andgate.h, orgate.h falsegate.h truegate.h (with matching .cpp implementations)
// Expect that I will use these and include these in my main.cpp.
// You may declare other derived classes, but your code must work, assuming that my main.cpp includes only those four
//   *.h files and that I replace your main.cpp file in your project with my main.cpp file.
//
// We will use the QPointer mechanism rather than directly use pointers
class gate; // need this "forward" definition
typedef QPointer<gate> gatePtrType;

// The possible states of the output of a gate
enum LogicLevel {logicTrue, logicFalse, logicUndefined};

class gate : public QObject
{
Q_OBJECT
public:
    // Must be called prior to using an object of a class derived from gate
    //  the argument is the name of the gate which the init() function should set
    virtual void init(const QString &gateName) = 0;

    // Returns the logic value output by this gate given the state of its current inputs
    // Note: If any of the inputs to a gate are logicUndefined, then getGateOutput
    //       must return logicUndefined
    LogicLevel getGateOutput() const;

    // Return the number of inputs connected to this gate
    virtual unsigned int getNumInputs() const = 0;

    // Add an input to this gate
    //   inGate MUST point to a gate and may not be NULL
    virtual void setInput(gatePtrType inGate) = 0;

    // Returns the name of one of the input gates, where the current inputs are numbered 0 to getNumInputs()-1
    virtual QString getInputName(unsigned int inputNum) const = 0;

    // Destructor
    virtual ~gate();

    // Returns the name of the gate
    QString getName() const;

signals:
    // Must be emitted whenever the output of the gate has changed (and only then)
    void outputChanged();

protected slots:
    // Should be called when an input to this gate has been changed
    virtual void receiveInputChanged() = 0;

    // Should be called when one of the gates that is an input to this gate has been destroyed
    //   Hint: meant to be connected to the QObject destroyed() signal of gates that are inputs to this one
    virtual void inputDestroyed() = 0;

protected:
    // constructor, can only be called by derived classes
    explicit gate(QObject *parent = 0);

    // set the name of the gate (meant to be called by the init() function of derived classes)
    void setName(const QString &name);

    // set the logic level of the gate's output -- must only be called when the output has been changed
    void setGateOutput(LogicLevel output);

    // These are used to determine whether or not the init() method has been called.  This is done by
    // setting the private member "isInitialized" to false in the "gate" constructor.  You can then use
    // these functions in derived classes by (a) calling setInitialized() in the init() routine defined
    // for the derived class, and (b) using a Q_ASSERT(getInitialized) in every routine other than
    // the constructor and init() in the derived class.  In this way, the code will fail if any routine is
    // called without calling init().  You must use this mechanism in your code.
    bool getInitialized() const {return isInitialized;};
    void setInitialized() {isInitialized = true;};

private:
    // the name of the gate
    QString m_name;

    // see comments above for the get/setInitialized methods
    bool isInitialized;

    // Stores the output of the gate
    LogicLevel m_gateOutput;
};

#endif // GATE_H
