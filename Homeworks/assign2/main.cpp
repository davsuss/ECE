#include "andgate.h"
#include <QList>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>
using namespace std;
// Your program must do the following (and meet the other requirements for the assignment):
// Step 1: Read in an integer that is the number of two input "AND" gates in the circuit from the text file "circuit.txt"
// Step 2: If there are N "AND" gates, then you will read in N AND gates from "circuit.txt", where the input for the ith gate is
//         Name input1 input2
//         where,
//            Name is a string that must start with AND
//            input1 is an integer, i1, where -1<=i1<i, that specifies input one to this AND gate
//            input2 is an integer, i2, where -1<=i2<i, that specifies input two to this AND gate
//            where each input can either be:
//              an integer, j, which indicates that the input is the jth AND gate, where 0<=j<i (assume an indexing of AND gates from 0 to N-1), or
//              a value of -1, indicating that the input is not yet connected.
//
// At the conclusion of steps 1 & 2, you should have created N "AND" objects (using the andGate type specified in andgate.h) where those
//         objects point to one another as specified in the input file.  All of those "AND" objects (or pointers to those objects) must be in a QList.
//
// Step 3: Read in an input line from "circuit.txt" where that input will either be
//         (a) Eval k
//             where "eval" is a string
//               k is an integer, 0<=k<N,
//             The eval command should cause the output of the kth AND gate in the circuit you have created.
//         (b) Set k j v
//             where "set" is a string
//               k is an integer, 0<=k<N, indicating a gate number
//               j is anust start with AND
//            input1 is an integer, i integer, 1<=j<=2, indicating the input number
//               v is an integer indicating the value of the input, 0 for false, 1 for true
//             The set command should tie the jth input of the kth gate to true or false.
// Step 4: If there is another input line in "circuit.txt", then go back to Step 3.
//
// Step 5: In sorted order, according to gate name, print out the name of each gate and the name of its two inputs
//         If an input is tied to true, then print True,
//         If an input is tied to false, then print False,
//         If an input is unspecified, then print X
//
// An example circuit.txt file has been provided for you along with an example output file whose format you should closely follow.  We will not be checking for
//  exact format matching, but it should be close and the information provided should be the same.
//
// You may assume that the circuit input in "circuit.txt" is formatted as described above, but you cannot assume that the circuit specified can
//         be evaluated; e.g., not all inputs to an AND gate may be connected.  Your program should generate an appropriate message when that occurs.
//
// The program should be case insensitive.
//
// You must use the andgate.h file and follow the guidelines in it exactly.  You should assume that we will compile and run your andgate.h and andgate.cpp files
//   with our main.cpp file (and vice versa).
//
//
// Use the following function to determine which gate is less than another when sorting the gates in the list
bool gateLessThan(andGate *g1,andGate *g2)
{
    return(g1->getName()<g2->getName());
}

int main()
{
    //init
    QList<andGate*> gates;
    QString inputCommand = "";
    int inputArguementOne = 0;
    int inputArguementTwo = 0;
    int inputArguementThree = 0;

    //Opening circuit.txt
    QString path = "circuit.txt";
    QFile input(path);
    input.open(QIODevice::ReadOnly);
    if(!input.isOpen())
    {
        qDebug() << "ERROR: Cannot Open " << path;
        return 0;
    }

    QTextStream stream(&input);

    int numberOfGates;
    stream >> numberOfGates;
    qDebug() << "Number of gates in the circuit is " << numberOfGates;
    for(int x = 0; x < numberOfGates;x++)
    {
        QString name = "";
        andGate* gate = new andGate;
        gate->init();
        int connectionone = 0;
        int connectiontwo = 0;
        stream  >> name ;
        stream >> connectionone;
        stream >> connectiontwo;
        gate->setName(name);
        if(connectionone != -1)
            gate->setInputOne(gates.value(connectionone));

        if(connectiontwo != -1)
            gate->setInputTwo(gates.value(connectiontwo));
        qDebug() << "Read in Gate  " << name << "  with inputs  " << connectionone << " , " << connectiontwo;
        gates.append(gate);

    }

    stream >> inputCommand;
    while(inputCommand != "")
    {
      inputCommand = inputCommand.toUpper();
      if(inputCommand == "EVAL")
      {
        stream >> inputArguementOne;
        qDebug() << "The Output of " <<  gates.value(inputArguementOne)->getName() << " is " <<  (gates.value(inputArguementOne)->eval()?1:0);
      }

      else if(inputCommand == "SET")
      {
        stream >> inputArguementOne;
        stream >> inputArguementTwo;
        stream >> inputArguementThree;
        if(inputArguementTwo == 1)
        {
            gates.value(inputArguementOne)->setInputOne((inputArguementThree != 0));
            qDebug() << "InputOne of gate " << gates.value(inputArguementOne)->getName() << "is set to " <<((inputArguementThree != 0)?1:0);
        }
            else
        {
           gates.value(inputArguementOne)->setInputTwo((inputArguementThree != 0));
           qDebug() << "InputTwo of gate " << gates.value(inputArguementOne)->getName() << "is set to " << ((inputArguementThree != 0)?1:0);
        }
      }

    stream >> inputCommand;
    }
 //Printing the Sorted List
    qDebug() << "Sorted Gate List:";
    int least = 0;
    andGate* leastGate = NULL;
    while(gates.size() > 1)
    {
        least = 0;
        for(int x = 1; x < gates.size() ; x++)
       {

       if(gateLessThan(gates.value(x),gates.value(least)))
           least = x;
       }
        leastGate = gates.takeAt(least);
        qDebug() << leastGate->getName() << "has inputs " << leastGate->getInputOneName() << " , " << leastGate->getInputTwoName();


    }
    leastGate = gates.takeAt(0);
    qDebug() << leastGate->getName() << "has inputs " << leastGate->getInputOneName() << " , " << leastGate->getInputTwoName();

    return 0;
}
