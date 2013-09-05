#include <QtTest/QtTest>
#include "profFunc.h"
#include <string>
#include <QDebug>
using namespace std;
//int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString);
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

    QTest::newRow("Test 1") << 10 << "Virginia Tech" << 10 << "b         " <<  "Virginia T" << 10;
    QTest::newRow("Test 2") << 0 << QString() << 10 << "b         " << "b         " << 0;
    QTest::newRow("Test 3") << 10 << "Virginia Tech" << 0 <<QString() << QString() << 0;
}

void TestprofFunc::testProfFunc()
{
    QFETCH(int, sourceStringLen);
    QFETCH(QString, sourceString);
    QFETCH(int, destStringLen);
    QFETCH(QString, destString);


    QFETCH(QString, resultDestString);
    QFETCH(int, expectedResult);

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
