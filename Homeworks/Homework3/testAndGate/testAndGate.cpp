#include <QString>
#include <QtTest/QTest>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QPointer>
#include "andgate.h"
#include "andgate.cpp"
#include "gate.h"
#include "gate.cpp"
#include "voltagesourcegate.h"
#include "voltagesourcegate.cpp"
#include "groundgate.h"
class testAndGate : public QObject
{
Q_OBJECT
private slots:
    void init2_data();
    void init2();
//    void eval_data();
//    void eval();
//    void getNumInputs_data();
//    void getNumInputs();
//    void getInputName_data();
//    void getInputName();
//    void setInput_data();
//    void setInput();
};
void testAndGate::init2_data()
{
    QTest::addColumn<int>("inputNumber");
    QTest::addColumn<unsigned int>("expectedNumberOfInputs");

    QTest::newRow("zero inputs") << 0 << 0;
    QTest::newRow("more than zero inputs") << 1 << 0;

}
void testAndGate::init2()
{
    QFETCH(int,inputNumber);
    QFETCH(unsigned int,expectedNumberOfInputs);
//    QObject * parent = new QObject;
//    andGate testGate(parent);
//    testGate.init(inputNumber);

//QCOMPARE(testGate.getNumInputs(),expectedNumberOfInputs);
}
//void testAndGate::eval_data()
//{
//    QTest::addColumn<QString>("input1BoolValue");
//    QTest::addColumn<QString>("input2BoolValue");
//    QTest::addColumn<QString>("expectedValue");

//    QTest::newRow("True/True") << "true" << "true" << "true";
//    QTest::newRow("True/False") << "true" << "false" << "false";
//    QTest::newRow("False/False") << "false" << "false" << "false";
//    QTest::newRow("Nothing/True") << "" << "true" << "false";
//}
//void testAndGate::eval()
//{
////    QFETCH(QString,input1BoolValue);
////    QFETCH(QString,input2BoolValue);
////    QFETCH(QString,expectedValue);
////    voltageSourceGate source(new QObject);
////    groundGate ground(new QObject);
////    andGate testGate(new QObject);
////    testGate.init(2);
////    source.init(0);
////    ground.init(0);
////    if(input1BoolValue.contains("false",Qt::CaseInsensitive))
////    {
////        testGate.setInput(0,&ground);
////    }
////    else if(input1BoolValue.contains("true",Qt::CaseInsensitive))
////    {
////        testGate.setInput(0,&source);
////    }

////    if(input2BoolValue.contains("false",Qt::CaseInsensitive))
////    {
////        testGate.setInput(1,&ground);
////    }
////    else if(input2BoolValue.contains("true",Qt::CaseInsensitive))
////    {
////        testGate.setInput(1,&source);
////    }
////    QString result = testGate.eval()?"True":"False";
////    QCOMPARE(result,expectedValue);

////}
////void testAndGate::getInputName_data()
////{
////    QTest::addColumn<int>("input1Value");
////    QTest::addColumn<int>("expectedInputName");

////    QTest::newRow("True") << "True" << "True";
////    QTest::newRow("False") << "False" << "False";
////    QTest::newRow("Not Connected") << "" << "Not Connected";
//}


//void testAndGate::getInputName()
//{
//    groundGate ground(new QObject);
//    voltageSourceGate voltageSource(new QObject);
//    andGate testGate(new QObject);
//    testGate.init(2);
//    ground.init(0);
//    voltageSource.init(0);

//    QFETCH(QString,input1Value);
//    QFETCH(QString,expectedInputName);

//    if(input1Value.contains("false",Qt::CaseInsensitive))
//    {
//        testGate.setInput(0,&ground);
//    }
//    else if(input1Value.contains("true",Qt::CaseInsensitive))
//    {
//        testGate.setInput(0,&voltageSource);
//    }

//    QCOMPARE(testGate.getInputName(0),expectedInputName);

//}


//void testAndGate::setInput_data()
//{
//    QTest::addColumn<int>("input1Value");
//    QTest::addColumn<int>("expectedInputName");

//    QTest::newRow("True") << "True" << "True";
//    QTest::newRow("False") << "False" << "False";
//    QTest::newRow("Not Connected") << "" << "Not Connected";
//}

//void testAndGate::setInput()
//{
//    groundGate ground(new QObject);
//    voltageSourceGate voltageSource(new QObject);
//    andGate testGate(new QObject);
//    testGate.init(2);
//    ground.init(0);
//    voltageSource.init(0);

//    QFETCH(QString,input1Value);
//    QFETCH(QString,expectedInputName);

//    if(input1Value.contains("false",Qt::CaseInsensitive))
//    {
//        testGate.setInput(0,&ground);
//    }
//    else if(input1Value.contains("true",Qt::CaseInsensitive))
//    {
//        testGate.setInput(0,&voltageSource);
//    }

//    QCOMPARE(testGate.getInputName(0),expectedInputName);

//}


//void testAndGate::getNumInputs_data()
//{
//    QTest::addColumn<int>("inputNumber");
//    QTest::addColumn<unsigned int>("expectedNumberOfInputs");

//    QTest::newRow("zero inputs") << 0 << 0;
//    QTest::newRow("more than zero inputs") << 1 << 0;
//}

//void testAndGate::getNumInputs()
//{
//    QFETCH(int,inputNumber);
//    QFETCH(unsigned int,expectedNumberOfInputs);
//    QObject * parent = new QObject;
//    andGate testGate(parent);
//    testGate.init(inputNumber);

//QCOMPARE(testGate.getNumInputs(),expectedNumberOfInputs);
//}


QTEST_MAIN(testAndGate)
#include "testAndGate.moc"

