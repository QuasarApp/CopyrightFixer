//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <time.h>
#include "signertest.h"
#include <QDebug>

SignerTest::SignerTest() {

}

SignerTest::~SignerTest() {

}

void SignerTest::test() {
    testSigner();
}

CopyrighFixer::Signature SignerTest::genSign(const QString licen,
                                             const QString nOwn,
                                             int tP) const {

    CopyrighFixer::Owner ownerObj;
    ownerObj.setName(nOwn);
    ownerObj.setTimePoint(tP);

    QMap<int, CopyrighFixer::Owner> OwnerMap;
    OwnerMap.insert(tP, ownerObj);

    CopyrighFixer::Signature signTest;
    signTest.setLicenseTitle(licen);
    signTest.setMessage("Distributed under the lgplv3 software license, see the accompany.");
    signTest.setMapOwners(OwnerMap);

    return signTest;
}

CopyrighFixer::Signature SignerTest::genSign(QList<SignerTest::dataOwns> numOwns, const QString licen) const {

    QMap<int, CopyrighFixer::Owner> OwnerMap;
    for (auto itemOwn: numOwns) {
        CopyrighFixer::Owner ownerObj;
        ownerObj.setName(itemOwn.name);
        ownerObj.setTimePoint(itemOwn.timePoint);

        OwnerMap.insert(itemOwn.timePoint, ownerObj);
    }

    CopyrighFixer::Signature signTest;
    signTest.setLicenseTitle(licen);
    signTest.setMessage("Distributed under the lgplv3 software license, see the accompany.");
    signTest.setMapOwners(OwnerMap);

    return signTest;
}


QList<SignerTest::Signers> SignerTest::lstSing() const {

    int unixTime = time(0);
    // 1
    // The case when the signatures in the config and the file match.
    SignerTest::Signers equalSign;
    equalSign.signFormConf = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);
    equalSign.signFormFile = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);
    equalSign.signAfterMerge = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", unixTime);

    // 2
    // The Different licenses.
    SignerTest::Signers signDiffLic;
    signDiffLic.signFormConf = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);
    signDiffLic.signFormFile = genSign("MIT License Copyright (C) 2019-2020 QuasarApp.", "QuasarApp", 1622657022);
    signDiffLic.signAfterMerge = genSign("MIT License Copyright (C) 2019-2020 QuasarApp.", "QuasarApp", 1622657022);

    // 3
    // The Different owners.
    SignerTest::Signers signDiffOwn;
    signDiffOwn.signFormConf = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1700000000);
    signDiffOwn.signFormFile = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarAppSdfdf", 1622657022);
    signDiffOwn.signAfterMerge = genSign({{"QuasarAppSdfdf", 1622657022},
                                          {"QuasarApp", unixTime}},
                                         "MIT License Copyright (C) 2020-2021 QuasarApp.");

    // 4
    // The equal owners.
    SignerTest::Signers signEqualOwn;
    signEqualOwn.signFormConf = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1700000000);
    signEqualOwn.signFormFile = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);
    signEqualOwn.signAfterMerge = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", unixTime);


    // 5
    // The signature is missing from the file.
    SignerTest::Signers signMissingInFile;
    signMissingInFile.signFormConf = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);
    signMissingInFile.signFormFile = genSign();
    signMissingInFile.signAfterMerge = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);

    // 6
    // Here are no owners in the file.
    SignerTest::Signers signMissOwnInFile;
    signMissOwnInFile.signFormConf = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);
    signMissOwnInFile.signFormFile = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.");
    signMissOwnInFile.signAfterMerge = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1622657022);

    // 7
    // Generating multiple owners config.
    QList<SignerTest::dataOwns> lstOwnsForConf = {
        {"QuasarApp", unixTime},
        {"QuasarApp1", unixTime+1},
        {"QuasarApp2", unixTime+2}
    };

    // The number of owners differs.
    SignerTest::Signers signDiffNumOwnConf;
    signDiffNumOwnConf.signFormConf = genSign(lstOwnsForConf, "MIT License Copyright (C) 2020-2021 QuasarApp.");
    signDiffNumOwnConf.signFormFile = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1700000000);
    signDiffNumOwnConf.signAfterMerge = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", unixTime);

    // 8
    // Generating multiple owners file.
    QList<SignerTest::dataOwns> lstOwnsForFile = {
        {"QuasarApp", unixTime},
        {"QuasarApp1", unixTime+1},
        {"QuasarApp2", unixTime+2},
        {"QuasarApp3", unixTime+3}
    };

    // The number of owners differs.
    SignerTest::Signers signDiffNumOwnFile;
    signDiffNumOwnFile.signFormConf = genSign("MIT License Copyright (C) 2020-2021 QuasarApp.", "QuasarApp", 1700000000);
    signDiffNumOwnFile.signFormFile = genSign(lstOwnsForFile, "MIT License Copyright (C) 2020-2021 QuasarApp.");
    signDiffNumOwnFile.signAfterMerge = genSign(lstOwnsForFile, "MIT License Copyright (C) 2020-2021 QuasarApp.");

    return {equalSign, signDiffLic, signDiffOwn, signEqualOwn, signMissingInFile, signMissOwnInFile, signDiffNumOwnConf};

}

void SignerTest::testMergeSign() const {

    QList<SignerTest::Signers> dfd = lstSing();

    for (auto itemSign: lstSing()) {

        CopyrighFixer::Signer resSign;
        CopyrighFixer::Signature mergeSignUF = resSign.mergeSign(itemSign.signFormConf,
                                                                 itemSign.signFormFile);

        QVERIFY(mergeSignUF == itemSign.signAfterMerge);

    }

}

void SignerTest::testCheckSign() const {
    qWarning() << "The SignerTest class is not implemented";
    QVERIFY(true);
}

void SignerTest::testSigner() {

    testMergeSign();
    testCheckSign();

}
