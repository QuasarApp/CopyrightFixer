//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef CONFIGPARSERTEST_H
#define CONFIGPARSERTEST_H
#include "test.h"
#include "testutils.h"
#include "CopyrighFixer/sign.h"

#include <QTest>

class ConfigParserTest: public Test, protected TestUtils {
public:
    ConfigParserTest();
    ~ConfigParserTest();

    void test();
    void testParseConf() const;
    CopyrighFixer::Signature generateRandomSign(QString& filename) const;
    void testSrcKey() const;
    void testSrcPath() const;
    void testSignKey() const;
    void testSignPath() const;
    void testParsOpt();

};

#endif // CONFIGPARSERTEST_H
