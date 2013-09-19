#include <QString>
#include <QtTest>
#include <QObject>
//#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/andgate.cpp"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/andgate.h"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/groundgate.cpp"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/voltagesourcegate.cpp"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/groundgate.h"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/voltagesourcegate.h"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/gate.h"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/gate.cpp"
class testGroundGate : public QObject
{
    Q_OBJECT



private slots:
    void init_data();
    void init();
    void eval();
    void getNumInputs_data();
    void getNumInputs();
    void getInput_data();
    void getInput();
    void setInput_data();
    void setInput();
};

void init_data()
{
    QTest::addColumn<int>("inputNumber");
    QTest::addColumn<int>("expectedNumberOfInputs");

    QTest::newRow("zero inputs") << 0 << 0;
    QTest::newRow("more than zero inputs") << 1 << 0;


}

void init()
{
    QFETCH(int,inputNumber);
    QFETCH(int,expectedNumberOfInputs);
    QObject * parent = new QObject;
    groundGate testGate(parent);
testGate.init(inputNumber);

QCOMPARE(testGate.getNumInputs(),expectedNumberOfInputs);
}

void eval()
{
    groundGate testgate(new QObject);
 testgate.init(0);
//Since this is a ground gate, it should always return false.
 QCOMPARE(testgate.eval(),false);

}

void getInput_data()
{


}

void getInput()
{

}

void setInput_data()
{

}

void setInput()
{

}


QTEST_MAIN(testGroundGate)
#include "testGroundGate.moc"

