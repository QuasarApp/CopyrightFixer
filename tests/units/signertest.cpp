//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "signertest.h"
#include <QDebug>

SignerTest::SignerTest() {

}

SignerTest::~SignerTest() {

}

void SignerTest::test() {
    testSigner();
}

void SignerTest::testSigner() {
    qWarning() << "The SignerTest class is not implemented"
    QVERIFY(true);
}
