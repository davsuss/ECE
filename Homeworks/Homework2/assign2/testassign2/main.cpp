#include <QCoreApplication>
#include <QtTest/QtTest>
#include <string>
#include <QDebug>
#include "andgate.h"
//David Sussman
//Class: TestprofFunc
//Description: Testing class


//#include "profFunc.h"

using namespace std;

//
class TestAndGate: public QObject
{
    Q_OBJECT

private slots:
    void testProfFunc_data();
    void testProfFunc();
};

void TestprofFunc::testProfFunc_data()
{



}

void TestprofFunc::testProfFunc()
{

}

QTEST_MAIN(TestprofFunc)
#include "testproffunc.moc"

