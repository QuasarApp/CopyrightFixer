//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <time.h>
#include "CopyrighFixer/sign.h"
#include "signtest.h"

SignTest::SignTest() {

}

SignTest::~SignTest() {

}

void SignTest::test() {
    testJsonObj();
}

CopyrighFixer::Signature SignTest::generateRandomSign(QString& filename) const {

    int unixTime = time(0);

    CopyrighFixer::Owner ownerObj;
    ownerObj.setName("QuasarApp");
    ownerObj.setTimePoint(unixTime);

    QMap<int, CopyrighFixer::Owner> OwnerMap;
    OwnerMap.insert(ownerObj.getTimePoint(), ownerObj);

    CopyrighFixer::Signature sign_toJson;
    sign_toJson.setLicenseTitle("Copyright (C) 2020-2021 QuasarApp.");
    sign_toJson.setMessage("Distributed under the lgplv3 software license, see the accompany.");
    sign_toJson.setMapOwners(OwnerMap);
    sign_toJson.toJson(filename);

    return sign_toJson;
}

void SignTest::testJsonObj() {
    QString filename = "signature.json";

    // Generating a randomly populated signature object.
    CopyrighFixer::Signature baseSign = generateRandomSign(filename);

    QVERIFY(baseSign.toJson(filename));
    QVERIFY(baseSign.isValid());
    
    CopyrighFixer::Signature signFromFile;

    // After initialise the Signature object should be invalid.
    QVERIFY(!signFromFile.isValid());

    QVERIFY(signFromFile.fromJson(filename));

    QVERIFY(signFromFile == baseSign);

}
