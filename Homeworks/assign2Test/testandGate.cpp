
#include <QtTest/QtTest>
#include <QDebug>
#include "/home/david/Documents/Git Projects/ECE/Homeworks/assign2/andgate.cpp"
class TestandGate: public QObject
{
    Q_OBJECT
private:

private slots:
    void init();

    //A Test for both setName and getName since the tests are identical and the functions are inter-dependent
    void Name_data();
    void Name();

    //A Test for both setInputOne() and setInputTwo() since the tests are identical
    void setInput_data();
    void setInput();



    void eval_data();
    void eval();


};
void TestandGate::init()
{
 andGate InitTest;

 InitTest.init();
 QVERIFY(InitTest.getName() == "");


}



void TestandGate::Name_data()
{
    QTest::addColumn<QString>("newName");
    QTest::addColumn<QString>("expectedName");
    QTest::newRow("standard test") << "MyAndGate" << "MyAndGate";
    QTest::newRow("Empty String") << "" << "";

}
void TestandGate::Name()
{
    andGate and1;
    QFETCH(QString, newName);
    QFETCH(QString, expectedName);
    and1.setName(newName);
    QCOMPARE(and1.getName(), expectedName);
}

void TestandGate::setInput_data()
{
/*

For a Connection:
Code "": Nothing Connected
Code "true": True Connected
Case "false": False Connected
Code "and{2 or 3}": And Gate Connected
    for example and2 for and gate named and2


*/
QTest::addColumn<QString>("CurrentConnection");
QTest::addColumn<QString>("NewConnection");
QTest::addColumn<QString>("expected");
QTest::newRow("Connecting Boolean with unconnected input") << "" << "false" << "false";
QTest::newRow("Connecting AndGate with unconnected input") << "" << "and2"<< "and2";
QTest::newRow("Connecting Boolean with previous Boolean Value") << "false" << "true" << "true";
QTest::newRow("Connecting AndGate with previous Boolean Value") << "false" << "and2" << "and2";
QTest::newRow("Connecting Boolean with previous AndGate Value") << "and2" << "false" << "and2";

}
void TestandGate::eval_data()
{
/*

 For a Connection:
Code "": Nothing Connected
Code "true": True Connected
Case "false": False Connected
Code "and{1 - 3}": And Gate Connected
    for example and2 for and gate named and2

 */
    QTest::addColumn<QString>("andGate1Connection1");
    QTest::addColumn<QString>("andGate1Connection2");
    QTest::addColumn<QString>("andGate2Connection1");
    QTest::addColumn<QString>("andGate2Connection2");
    QTest::addColumn<QString>("andGate3Connection1");
    QTest::addColumn<QString>("andGate3Connection2");
    QTest::addColumn<QString>("expectedResult");

    QTest::newRow("AND gate with unconnected inputs") << "" << "" << "" << "" << "" << "" << "false";
    QTest::newRow("AND gate with 1 connected bool") << "false" << ""  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate with 2 connected bools (true and true)") << "true" << "true" << "" << "" << "" << "" << "true";
    QTest::newRow("AND gate with 2 connected bools (true and false)") << "true" << "false"  << "" << "" << "" << "" <<"false";

    QTest::newRow("AND gate with 1 connected ANDGATE(unconnected) and one unset input") << "" << "" << "" << "" << "" << "" << "false";
    QTest::newRow("AND gate with 1 connected ANDGATE(unconnected) and true") << "false" << ""  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate with 1 connected ANDGATE(unconnected) and false") << "true" << "true" << "" << "" << "" << "" << "true";
    QTest::newRow("AND gate with 1 connected ANDGATE(true/unconnected) and one unset input") << "true" << "false"  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate with 1 connected ANDGATE(true/unconnected) and true") << "false" << ""  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate with 1 connected ANDGATE(true/unconnected) and false") << "true" << "true" << "" << "" << "" << "" << "true";
    QTest::newRow("AND gate with 1 connected ANDGATE(true/false) and one unset input") << "true" << "false"  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate with 1 connected ANDGATE(true/true) and true") << "false" << ""  << "" << "" << "" << "" <<"true";
    QTest::newRow("AND gate with 1 connected ANDGATE(true/false) and false") << "true" << "true" << "" << "" << "" << "" << "true";

    QTest::newRow("AND gate with 2 connected ANDGATE(true/false) and ANDGATE(unconnected)") << "true" << "false"  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate with 2 connected ANDGATE(true/false) and ANDGATE()") << "false" << ""  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate with 2 connected ANDGATE(true/false) and ANDGATE()") << "true" << "true" << "" << "" << "" << "" << "true";


}

void TestandGate::eval()
{
andGate and1;
andGate and2;
andGate and3;

//Test Case 1: Evaluating an Unconnected AND gate
QCOMPARE(and1.eval(),false);


//Test Case 2: Evaluating an AND gate with one attached boolean and an unconnected input
and1.setInputOne(true);
QCOMPARE(and1.eval(),false);







}
QTEST_MAIN(TestandGate)
#include "testandGate.moc"

