//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef SIGNERTEST_H
#define SIGNERTEST_H
#include "test.h"
#include "testutils.h"
#include "CopyrighFixer/signer.h"

#include <QTest>

class SignerTest: public Test, protected TestUtils {
public:
    SignerTest();
    ~SignerTest();

    void test();
    void testSigner();
};

#endif // SIGNERTEST_H
