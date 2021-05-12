//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "configparsertest.h"
#include <quasarapp.h>
#include "CopyrighFixer/config.h"
#include "CopyrighFixer/configparser.h"

ConfigParserTest::ConfigParserTest() {

}

ConfigParserTest::~ConfigParserTest() {

}

void ConfigParserTest::test() {
    testParsOpt();
}

CopyrighFixer::Signature ConfigParserTest::generateRandomSign(QString& filename) const {

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

void ConfigParserTest::testParseConf() const {
    QStringList lstOpt = {"-sourceDir", ".", "-sign", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    // This condition returns true if the parameters were parsed without error
    // because the input parameters were specified as valid.
    QVERIFY(testParserConf.parseOptions(testConfig));

    // This condition returns true if signature that in Config have been parsed without error,
    // because the input parameters were specified as valid.
    QVERIFY(testConfig.getSignVal().isValid());
}

void ConfigParserTest::testSrcKey() const {
    QStringList lstOpt = {"-source", ".", "-sign", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    // This condition returns true in any case, even if the
    // sourceDir key is not present in the parameter list or is not written correctly.
    QVERIFY(testParserConf.parseOptions(testConfig));
}

void ConfigParserTest::testSrcPath() const {
    QStringList lstOpt = {"-sourceDir", "./ParserProj", "-sign", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    // This condition checks for the correct path to the sourceDir key.
    // Should return false, because the path to lstOpt is not correct.
    QVERIFY(!testParserConf.parseOptions(testConfig));
}

void ConfigParserTest::testSignKey() const {
    QStringList lstOpt = {"-sourceDir", ".", "-signa", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    // This condition checks for the presence and validity of the sign
    // parameter. If it is entered incorrectly or is missing return false.
    QVERIFY(!testParserConf.parseOptions(testConfig));
}

void ConfigParserTest::testSignPath() const {
    QStringList lstOpt = {"-sourceDir", ".", "-sign", "/home/testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    // This condition checks for the validity of the path to file
    // signature. After checking, the file is missing and returns false
    // because lstOpt specifies a non-existing file path.
    QVERIFY(!testParserConf.parseOptions(testConfig));

}

void ConfigParserTest::testParsOpt() {

    QString testFileSign = "testSign.json";

    // Initialization of a signature with random parameters.
    generateRandomSign(testFileSign);

    testParseConf();
    QuasarAppUtils::Params::clearParsedData();

    testSrcKey();
    testSrcPath();
    QuasarAppUtils::Params::clearParsedData();

    testSignKey();
    testSignPath();
    QuasarAppUtils::Params::clearParsedData();

    QFile::remove(testFileSign);

}
