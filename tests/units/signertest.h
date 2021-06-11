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

    struct dataOwns{
        QString name;
        int timePoint;
    };

    struct Signers {
        CopyrighFixer::Signature signFormConf;
        CopyrighFixer::Signature signFormFile;
        CopyrighFixer::Signature signAfterMerge;
    };

    CopyrighFixer::Signature genSign(const QString licen = "",
                                     const QString nOwn = "",
                                     int tP = 0) const;
    CopyrighFixer::Signature genSign(QList<dataOwns> numOwns, const QString licen = "") const;

    QList<Signers> lstSing() const;
    void testMergeSign() const;
    void testCheckSign() const;
    void testSigner();
};

#endif // SIGNERTEST_H
