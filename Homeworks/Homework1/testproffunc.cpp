//David Sussman
//Class: TestprofFunc
//Description: Testing class which tests,
//int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString);
#include <QtTest/QtTest>
#include "profFunc.h"
#include <string>
#include <QDebug>
using namespace std;

//
class TestprofFunc: public QObject
{
    Q_OBJECT

private slots:
    void testProfFunc_data();
    void testProfFunc();
};

void TestprofFunc::testProfFunc_data()
{
    //Function Inputs
    QTest::addColumn<int>("sourceStringLen");
    QTest::addColumn<QString>("sourceString");
    QTest::addColumn<int>("destStringLen");
    QTest::addColumn<QString>("destString");

    //Expected Results
    QTest::addColumn<QString>("resultDestString");
    QTest::addColumn<int>("expectedResult");

    QTest::newRow("Larger Source") << 13 << "Virginia Tech" << 10 << "          " <<  "Virginia T" << 10;
    QTest::newRow("Larger Destination") << 8 << "Virginia" << 10 << "          " <<  "Virginia  " << 8;
    QTest::newRow("Same Size") << 8 << "Virginia" << 8 << "        " <<  "Virginia" << 8;
    QTest::newRow("Empty Source") << 0 << QString() << 10 << "          " << "          " << 0;
    QTest::newRow("Empty Destination") << 10 << "Virginia Tech" << 0 <<QString() << QString() << 0;

}

void TestprofFunc::testProfFunc()
{
    //Fetching Data
    QFETCH(int, sourceStringLen);
    QFETCH(QString, sourceString);
    QFETCH(int, destStringLen);
    QFETCH(QString, destString);
    QFETCH(QString, resultDestString);
    QFETCH(int, expectedResult);

    //Setting QString to const char* and char*
    string sourceCString = sourceString.toStdString();
    const char *source = sourceCString.c_str();

    char* dest;
    string destCString = destString.toStdString();
    dest = new char [destCString.size()+1];
    strcpy( dest, destCString.c_str() );


    int result = profFunc(sourceStringLen,source,destStringLen,dest);
    QCOMPARE(result,expectedResult);
    QCOMPARE(QString::fromUtf8(dest),resultDestString);
}

QTEST_MAIN(TestprofFunc)
#include "testproffunc.moc"
