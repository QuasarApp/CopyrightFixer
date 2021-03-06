//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <QtTest>
#include "cfixertest.h"
#include "signtest.h"
#include "signertest.h"
#include "configparsertest.h"
#include "interfaceimplemtest.h"

// Use This macros for initialize your own test classes.
// Check exampletests
#define TestCase(name, testClass) \
    void name() { \
        initTest(new testClass()); \
    }

/**
 * @brief The tstMain class - this is main test class
 */
class tstMain : public QObject
{
    Q_OBJECT

public:
    tstMain();

    ~tstMain();

private slots:

    // BEGIN TESTS CASES
    TestCase(exampleTest, ExampleTest);
    TestCase(signTest, SignTest);
    TestCase(signerTest, SignerTest);
    TestCase(configParserTest, ConfigParserTest)
    TestCase(interfaceImplemTest, InterfaceImplemTest)
    // END TEST CASES

private:

    /**
     * @brief initTest This method prepare @a test for run in the QApplication loop.
     * @param test are input test case class.
     */
void initTest(Test* test);

    QList<Test*> _tests;
    QCoreApplication *_app = nullptr;

};

/**
 * @brief tstMain::tstMain
 * init all availabel units for testsing
 */
tstMain::tstMain() {

    // init xample unit test
    int argc =0;
    char * argv[] = {nullptr};

    _app = new QCoreApplication(argc, argv);
    QCoreApplication::setApplicationName("testCopyrighFixer");
    QCoreApplication::setOrganizationName("QuasarApp");

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    QDir(path).removeRecursively();

}

tstMain::~tstMain() {
    _app->exit(0);
    delete _app;
}

void tstMain::initTest(Test *test) {
    QTimer::singleShot(0, this, [this, test]() {
        test->test();
        delete test;
        _app->exit(0);
    });

    _app->exec();
}

QTEST_APPLESS_MAIN(tstMain)

#include "tstMain.moc"
