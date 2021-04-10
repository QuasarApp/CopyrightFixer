//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#include "cfixertest.h"
#include <CopyrighFixer/bar.h>
#include <QString>


ExampleTest::ExampleTest() {

}

ExampleTest::~ExampleTest() {

}

void ExampleTest::test() {
    QVERIFY(true);
    testFoo();
}

void ExampleTest::testFoo() {
    CopyrighFixer::Bar bar;
    QVERIFY(bar.foo() == "Hello WORLD!");
}
