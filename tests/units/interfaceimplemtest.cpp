//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "interfaceimplemtest.h"

InterfaceImplemTest::InterfaceImplemTest() {

}

InterfaceImplemTest::~InterfaceImplemTest() {

}

void InterfaceImplemTest::test() {
    testIntesfaceImplem();
}

void InterfaceImplemTest::testReadSign() {
    QVERIFY(true);
}

void InterfaceImplemTest::testWriteSign() {
    QVERIFY(true);
}

void InterfaceImplemTest::testIntesfaceImplem() {
    testReadSign();
    testWriteSign();
}
