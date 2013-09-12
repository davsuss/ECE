
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

    //A Test for both setInputOne() and setInputTwo() since the tests are identical, also for getInputOne (Two) since they are inter-dependent
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

void TestandGate::setInput()
{
    andGate and1;
    andGate and2;
    and2.init();
    and1.init();
    and1.setName("and1");
    and2.setName("and2");
    QFETCH(QString, CurrentConnection);
    QFETCH(QString, NewConnection);
    QFETCH(QString, expected);
    if(CurrentConnection =="true")
        and1.setInputOne(true);
    else if(CurrentConnection =="false")
        and1.setInputOne(false);
    else if(CurrentConnection =="and2")
        and1.setInputOne(&and2);

    if(CurrentConnection =="true")
        and1.setInputTwo(true);
    else if(CurrentConnection =="false")
        and1.setInputTwo(false);
    else if(CurrentConnection =="and2")
        and1.setInputTwo(&and2);

    if(NewConnection =="true")
        and1.setInputOne(true);
    else if(NewConnection =="false")
        and1.setInputOne(false);
    else if(NewConnection =="and2")
        and1.setInputOne(&and2);

    if(NewConnection =="true")
        and1.setInputTwo(true);
    else if(NewConnection =="false")
        and1.setInputTwo(false);
    else if(NewConnection =="and2")
        and1.setInputTwo(&and2);




    QCOMPARE(and1.getInputOneName().toLower(),expected);
}

void TestandGate::eval_data()
{
//Eval Test, eval will be called in and1 and expectedresult is the expected output of that function.

/*

 For a Connection:
Code "": Nothing Connected
Code "true": True Connected
Case "false": False Connected
Code "and{1 - 3}": And Gate Connected, but Not itself(and1 cannot connect to and1)
    for example and2 for and gate named and2

 */
    QTest::addColumn<QString>("andGate1Connection1");
    QTest::addColumn<QString>("andGate1Connection2");
    QTest::addColumn<QString>("andGate2Connection1");
    QTest::addColumn<QString>("andGate2Connection2");
    QTest::addColumn<QString>("andGate3Connection1");
    QTest::addColumn<QString>("andGate3Connection2");
    QTest::addColumn<QString>("expectedResult");

    QTest::newRow("AND gate 1 with unconnected inputs") << "" << "" << "" << "" << "" << "" << "false";
    QTest::newRow("AND gate 1 with 1 connected bool") << "false" << ""  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate 1 with 2 connected bools (true and true)") << "true" << "true" << "" << "" << "" << "" << "true";
    QTest::newRow("AND gate 1 with 2 connected bools (true and false)") << "true" << "false"  << "" << "" << "" << "" <<"false";

    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(unconnected) and one unset input") << "and2" << "" << "" << "" << "" << "" << "false";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(unconnected) and true") << "and2" << "true"  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(unconnected) and false") << "and2" << "false" << "" << "" << "" << "" << "false";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(true/unconnected) and one unset input") << "and2" << ""  << "true" << "" << "" << "" <<"false";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(true/unconnected) and true") << "and2" << "true"  << "true" << "" << "" << "" <<"false";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(true/unconnected) and false") << "and2" << "false" << "true" << "" << "" << "" << "false";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(true/false) and one unset input") << "and2" << ""  << "true" << "false" << "" << "" <<"false";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(true/true) and true") << "and2" << "true"  << "true" << "true" << "" << "" <<"true";
    QTest::newRow("AND gate 1 with 1 connected ANDGATE2(true/false) and false") << "and2" << "true" << "true" << "false" << "" << "" << "false";

    QTest::newRow("AND gate 1 with 2 connected ANDGATE2(unconnected) and ANDGATE3(unconnected)") << "and2" << "and3"  << "" << "" << "" << "" <<"false";
    QTest::newRow("AND gate 1 with 2 connected ANDGATE2(true/true) and ANDGATE3(true/true)") << "and2" << "and3"  << "true" << "true" << "true" << "true" <<"true";
    QTest::newRow("AND gate 1 with 2 connected ANDGATE2(true/false) and ANDGATE3(true/false)") << "and2" << "and3" << "true" << "false" << "true" << "false" << "false";
    QTest::newRow("AND gate 1 with 2 connected ANDGATE2(true/unconnected) and ANDGATE3(true/true)") << "and2" << "and3" << "true" << "" << "true" << "true" << "false";
    QTest::newRow("AND gate 1 with 2 connected ANDGATE2(unconnected) and ANDGATE3(true/true)") << "and2" << "and3" << "" << "" << "true" << "true" << "false";
}

void TestandGate::eval()
{
//init
  QFETCH(QString,andGate1Connection1);
  QFETCH(QString,andGate1Connection2);
  QFETCH(QString,andGate2Connection1);
  QFETCH(QString,andGate2Connection2);
  QFETCH(QString,andGate3Connection1);
  QFETCH(QString,andGate3Connection2);
  QFETCH(QString,expectedResult);

andGate and1;
andGate and2;
andGate and3;

and1.init();
and2.init();
and3.init();
and1.setName("and1");
and2.setName("and2");
and3.setName("and3");



//parsing inputs for and1
if(andGate1Connection1 != "" && andGate1Connection2 != "")
{
    if(andGate1Connection1 =="true")
        and1.setInputOne(true);
    else if(andGate1Connection1 =="false")
        and1.setInputOne(false);
    else if(andGate1Connection1 =="and2")
        and1.setInputOne(&and2);
    else if(andGate1Connection1 =="and3")
        and1.setInputOne(&and3);

    if(andGate1Connection2 =="true")
        and1.setInputTwo(true);
    else if(andGate1Connection2 =="false")
        and1.setInputTwo(false);
    else if(andGate1Connection2 =="and2")
        and1.setInputTwo(&and2);
    else if(andGate1Connection2 =="and3")
        and1.setInputTwo(&and3);
    else
        qDebug() << "Incorrect Test Input";
}
//parsing inputs for and2
if(andGate2Connection1 != "" && andGate2Connection2 != "")
{
    if(andGate2Connection1 =="true")
        and2.setInputOne(true);
    else if(andGate2Connection1 =="false")
        and2.setInputOne(false);
    else if(andGate2Connection1 =="and3")
        and2.setInputOne(&and3);

    if(andGate2Connection2 =="true")
        and2.setInputTwo(true);
    else if(andGate2Connection2 =="false")
        and2.setInputTwo(false);
    else if(andGate2Connection2 =="and3")
        and2.setInputTwo(&and3);
    else
        qDebug() << "Incorrect Test Input";
}
//parsing inputs for and3
if(andGate3Connection1 != "" && andGate3Connection2 != "")
{
    if(andGate3Connection1 =="true")
        and3.setInputOne(true);
    else if(andGate3Connection1 =="false")
        and3.setInputOne(false);
    else if(andGate3Connection1 =="and2")
        and3.setInputOne(&and2);
     else
        qDebug() << "Incorrect Test Input";

    if(andGate3Connection2 =="true")
        and3.setInputTwo(true);
    else if(andGate3Connection2 =="false")
        and3.setInputTwo(false);
    else if(andGate3Connection2 =="and2")
        and3.setInputTwo(&and2);
    else
        qDebug() << "Incorrect Test Input";
}
QString result = and1.eval()?"true":"false";

QCOMPARE(result,expectedResult);



}
QTEST_MAIN(TestandGate)
#include "testandGate.moc"

