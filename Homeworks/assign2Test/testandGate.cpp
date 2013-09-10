
#include <QtTest/QtTest>
#include <QDebug>
#include "/home/david/Documents/Git Projects/ECE/Homeworks/assign2/andgate.h"
class TestandGate: public QObject
{
    Q_OBJECT
private:
    void testsetup();
    void testcleanup();
    andGate and1;
    andGate and2;
    andGate and3;
private slots:
    void init();

    void getName_data();
    void getName();

    void setName_data();
    void setName();

    void setInputOne_data();
    void setInputOne();

    void setInputTwo_data();
    void setInputTwo();

    void eval_data();
    void eval();


};
void TestandGate::init()
{

}

void TestandGate::testsetup()
{

}

void TestandGate::getName_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");
    QTest::newRow("all lower") << "hello" << "HELLO";
}

void TestandGate::getName()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

void TestandGate::setName_data()
{


}
void TestandGate::setName()
{


}
void TestandGate::setInputOne_data()
{


}
void TestandGate::setInputOne()
{

}
void TestandGate::setInputTwo_data()
{

}
void TestandGate::setInputTwo()
{

}
void TestandGate::eval_data()
{

}
void TestandGate::eval()
{}
QTEST_MAIN(TestandGate)
#include "testandGate.moc"
