#include <QString>
#include <QtTest>
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/andgate.cpp"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/groundgate.cpp"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/voltagesourcegate.cpp"
#include "/home/david/Documents/Git Projects/ECE/Homeworks/Homework3/assign3/gate.cpp"
class testOrGate : public QObject
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





QTEST_MAIN(testOrGate)
#include "testOrGate.moc"

