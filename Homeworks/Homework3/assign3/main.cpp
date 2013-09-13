#include <QPointer>
#include <QMap>
#include <QDebug>
#include <QString>
#include <QFile>
#include "gate.h"
#include "andgate.h"
#include "orgate.h"
// Your program must do the following (and meet the other requirements for the assignment):
// Step 1: Read in an integer that is the number of logic gates in the circuit from the text file "circuit.txt"
// Step 2: If there are N logic gates, then you will read in N logic gates from "circuit.txt", where the input for the ith gate is
//         Name NumberOfInputs
//         where,
//            Name is a string that must start with either AND or OR
//            NumberOfInputs is an integer (> 0) that indicates how many inputs this gate has
//
// At the conclusion of steps 1 & 2, you should have created N logic objects (using the andGate type specified in andgate.h).
// All of those logic gate objects (or pointers to those objects) must be in a QMap.
//
// Step 3: Read in an input line from "circuit.txt" where that input will either be
//         (a) Eval gateName
//             where,
//               "eval" is a string
//               gateName is a string that is the name of the gate to be evaluated.
//             The eval command should cause the output of the kth AND gate in the circuit you have created.
//         (b) Connect gateName inputNum inputGateName
//             where "connect" is a string
//               gateName is a string that is the name of the gate whose input is being connected
//               inputNum is an integer, indicating which input of gateName is to be connected
//               inputGateName is a string that is either
//               (a) "True" (case sensitive) indicating that the input is true
//               (b) "False" (case sensitive) indicating that the input is false
//               (c) inputGateName giving the name of the gate to be connected as the input to GateName
//
// Step 4: If there is another input line in "circuit.txt", then go back to Step 3.
//
// Step 5: In sorted order, according to gate name, print out the name of each gate and the name of its inputs
//         If an input is tied to true, then print True,
//         If an input is tied to false, then print False,
//         If an input is unspecified, then print "NotConnected" (see getInputName() in gate.h)
//
// An example circuit.txt file has been provided for you along with an example output file whose format you should closely follow.  We will not be checking for
//  exact format matching, but it should be close and the information provided should be the same.
//
// You may assume that the circuit input in "circuit.txt" is formatted as described above, but you cannot assume that the circuit specified can
//         be evaluated; e.g., not all inputs to a logic gate may be connected.  Your program should generate an appropriate message when that occurs.
//
// The program should be case insensitive with the exception of gate names (which are case sensitive).
//
// You must use the gate.h and gate.cpp files and follow the guidelines in those exactly.  Your logic gate objects must use classes that are derived
//   from the gate class in gate.h.  You should create your implementation in a way that allows my main.cpp to call your classes and your main.cpp to
//   call my classes.  The only modification necessary would be the names of the derived classes for logic gate objects that must be instantiated in
//   main.cpp.
//
// Use the QPointer mechanism of Qt as discussed in class for pointers to gate objects (see gate.h).
//
// Every logic gate object that you create will be derived from the "gate" class which is derived from QObject.  You must pass a pointer to an
//   object that will serve as the parent of every logic gate object that you create in your main.cpp program.  When that parent object is destroyed,
//   then it will automatically free all of its child objects (see discussion of QObject in your text).
//

int main()
{
    QFile input("circuit.txt");
    Qmap
    input.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&input);
    if(!input.isOpen())
     {
        qDebug() << "ERROR: file cannot be opened";
        return -1;
     }
    int numofGates = 0;
    inStream >> numofGates;
    qDebug() << "Number of gates in the circuit is " << numofGates;

    for(int x = 0 ; x < numofGates; x++)
    {
       QString gateName;
       int NumberOfInputs;
       inStream >> gateName >> NumberofInputs;

       if(gateName.left(2).compare("or",Qt::CaseInsensitive))
       {
           orGate gate(new QString);
           gate.init(NumberOfInputs);
           gate.setName(gateName);


       }
       else if(gateName.left(3).compare("and",Qt::CaseInsensitive))
       {
           andGate gate(new QString);
           gate.init(NumberOfInputs);
           gate.setName(gateName);

       }

    }

    return 0;
}
