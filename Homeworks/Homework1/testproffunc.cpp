#include <QtTest/QtTest>

class TestprofFunc: public QObject
{
    Q_OBJECT

private slots:
    void toUpper_data();
    void toUpper();
};

void TestprofFunc::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void TestprofFunc::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

QTEST_MAIN(TestprofFunc)
#include "testproffunc.moc"
