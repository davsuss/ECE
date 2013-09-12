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
// (2) Do not override setName() or getName() -- these aren't virtual.
// (3) You must declare a public constructor for any class that will be instantianted as an object.  See the example above
//     for how your constructor must be structured.
// (4) You must define a destructor for each derived class.
// (5) You must override every virtual method defined below in your derived types.
//     (a) the compiler will force this for "pure virtual" methods (i.e., those that have a "= 0" at the end).
//     (b) the compiler won't force you to have one for the destructor, but it is required on this assignment.
// (6) You must not define any additional public methods in your derived classes.  The "gate" class serves as the
//     definition of the API to be used by calling programs.
//
// We will use the QPointer mechanism rather than directly use pointers
class gate; // need this "forward" definition
typedef QPointer<gate> gatePtrType;

class gate : public QObject
{
Q_OBJECT
public:
    // Must be called prior to using an object of a class derived from gate
    //   the argument numInputs determines how many inputs the gate will have
    virtual void init(unsigned int numInputs) = 0;

    // Evaluate the output of this gate
    //   Works the same way as in assignment #2, including the warning message
    virtual bool eval() const = 0;

    // Return the number of inputs this gate accepts
    virtual unsigned int getNumInputs() const = 0;

    // Set one of the inputs of this gate to another gate
    //   Unlike assignment #2:
    //   (1) you may set the input of a gate that has already been set
    //   (2) This routine will not print any warning messages.
    //   (3) Inputs are numbered starting from 0.  So if there are two inputs, then they are numbered 0 and 1
    virtual void setInput(unsigned int inputNum,gatePtrType inGate) = 0;

    // Returns the name of one of the input gates; if the input hasn't been connected, then it returns gate::NotConnected
    virtual QString getInputName(unsigned int inputNum) const = 0;
    static const QString NotConnected; // the value for this is defined in the implementation file for this class

    // Destructor
    virtual ~gate();

    // The following are public methods whose implementations are common to classes derived from this class
    //   Because of that, we don't make them virtual
    //   These routines are used to set and get the name of the gate
    void setName(const QString &name);
    QString getName() const;

signals:
    // none for this assignment
public slots:
    // none for this assignment

protected:
    // constructor, can only be called by derived classes
    explicit gate(QObject *parent = 0);

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
};

#endif // GATE_H
