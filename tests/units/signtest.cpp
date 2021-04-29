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

    CopyrighFixer::Owner ownerObj;
    ownerObj.setName("QuasarApp");
    ownerObj.setTimePoint(QDateTime::currentMSecsSinceEpoch());

    QMap<int, CopyrighFixer::Owner> OwnerMap;
    OwnerMap.insert(ownerObj.getTimePoint(), ownerObj);

    CopyrighFixer::Signature sign_toJson;
    sign_toJson.setLicenseTitle("Copyright (C) 2020-2021 QuasarApp.");
    sign_toJson.setMessage("Distributed under the lgplv3 software license, see the accompany.");
    sign_toJson.setMapOwners(OwnerMap);
    sign_toJson.toJson(filename);

    CopyrighFixer::Signature sign_fromJson;
    sign_fromJson.fromJson(filename);

    QVERIFY(sign_fromJson.isValid() == sign_toJson.isValid());
}
