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

bool ConfigParserTest::initValidConf() const {

    QStringList lstOpt = {"-sourceDir", ".", "-sign", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    QList<bool> checkList = {testParserConf.parseOptions(testConfig),
                             testConfig.getSignVal().isValid()};

    return std::all_of(checkList.cbegin(), checkList.cend(), [](bool val){return val;});
}

bool ConfigParserTest::initUnvalidSrcKey() const {
    QStringList lstOpt = {"-source", ".", "-sign", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    return testParserConf.parseOptions(testConfig);
}

bool ConfigParserTest::initUnvalidSrcVal() const {

    QStringList lstOpt = {"-sourceDir", "./ParserProj", "-sign", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    return testParserConf.parseOptions(testConfig);
}

bool ConfigParserTest::initUnvalidSignKey() const {
    QStringList lstOpt = {"-sourceDir", ".", "-signa", "testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    return testParserConf.parseOptions(testConfig);
}

bool ConfigParserTest::initUnvalidSignVal() const {
    QStringList lstOpt = {"-sourceDir", ".", "-sign", "/home/testSign.json"};
    QuasarAppUtils::Params::parseParams(lstOpt);

    CopyrighFixer::Config testConfig;
    CopyrighFixer::ConfigParser testParserConf;

    return testParserConf.parseOptions(testConfig);
}

void ConfigParserTest::testParsOpt() {

    QString testFileSign = "testSign.json";
    generateRandomSign(testFileSign);

    QVERIFY(initValidConf());
    QuasarAppUtils::Params::clearParsedData();

    QVERIFY(!initUnvalidSrcKey());
    QVERIFY(initUnvalidSrcVal());
    QuasarAppUtils::Params::clearParsedData();

    QVERIFY(!initUnvalidSignKey());
    QVERIFY(!initUnvalidSignVal());

    QFile::remove(testFileSign);

}
