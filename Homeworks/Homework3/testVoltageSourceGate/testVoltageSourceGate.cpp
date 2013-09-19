#include <QString>
#include <QtTest>
class testVoltageSourceGate : public QObject
{
    Q_OBJECT



private slots:
    void init_data();
    void init();
    void eval();
    void getNumInputs_data();
    void getNumInputs();
    void getandsetInput_data();
    void getandsetInput();
};

void eval()
{
 voltageSource testgate;
 testgate.init(0);
//Since this is a voltageSource gate, it should always return false.
 QCOMPARE(testgate.eval(),true);

}

void testVoltageSourceGate::testCase12()
{
    QVERIFY2(true, "Failure");
}

QTEST_MAIN(testVoltageSourceGate)
#include "testVoltageSourceGate.moc"

