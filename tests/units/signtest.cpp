//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "CopyrighFixer/sign.h"
#include "signtest.h"

SignTest::SignTest() {

}

SignTest::~SignTest() {

}

void SignTest::test() {
    testJsonObj();
}

void SignTest::testJsonObj() {
    CopyrighFixer::Signature sign_fromJson;
    CopyrighFixer::Signature sign_toJson;

    QVERIFY(sign_fromJson.fromJson() == sign_toJson.toJson());
}
