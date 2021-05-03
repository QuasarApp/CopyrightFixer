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
    QString filename = "signature.json";

    CopyrighFixer::Sign baseSign = generateRandomSign();
    
    QVERIFY(baseSign.toJson(filename));
    
    QVERIFY(baseSign.isValid());
    
    CopyrighFixer::Sign signFromFile;
    QVERIFY(signFromFile.fromJson(filename));
    
    QVERIFY(signFromFile == baseSign);


}
