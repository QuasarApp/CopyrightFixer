//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef SIGNTEST_H
#define SIGNTEST_H
#include "test.h"
#include "testutils.h"
#include "CopyrighFixer/sign.h"

#include <QTest>

class SignTest: public Test, protected TestUtils {
public:
    SignTest();
    ~SignTest();

    void test();
    CopyrighFixer::Signature generateRandomSign(QString& filename) const;
    void testJsonObj();
};

#endif // SIGNTEST_H
