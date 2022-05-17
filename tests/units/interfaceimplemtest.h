//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef INTERFACEIMPLEMTEST_H
#define INTERFACEIMPLEMTEST_H
#include "test.h"
#include "testutils.h"
#include "CopyrighFixer/interfaceimplem.h"

#include <QTest>

class InterfaceImplemTest: public Test, protected TestUtils {
public:
    InterfaceImplemTest();
    ~InterfaceImplemTest();

    void test();

    void testReadSign();
    void testWriteSign();
    void testIntesfaceImplem();
};

#endif // INTERFACEIMPLEMTEST_H
