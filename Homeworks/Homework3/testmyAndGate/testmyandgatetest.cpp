
#include <QtTest>
#include <QString>
//#include "gate.h"
//#include "gate.cpp"
class TestmyAndGateTest : public QObject
{
    Q_OBJECT
    
public:
    TestmyAndGateTest();
    
private slots:
    void testCase1();
};

TestmyAndGateTest::TestmyAndGateTest()
{
}

void TestmyAndGateTest::testCase1()
{

    QVERIFY2(true, "Failure");
}

QTEST_MAIN(TestmyAndGateTest)
#include "testmyandgatetest.moc"
