//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "configparser.h"
#include <quasarapp.h>
#include <QFileInfo>


namespace CopyrighFixer {
ConfigParser::ConfigParser() {

}

bool ConfigParser::parseOptions(Config &conf) const {

    QFileInfo pathDirOrFile(".");

    if (QuasarAppUtils::Params::isEndable("sourceDir")) {
        pathDirOrFile.setFile(QuasarAppUtils::Params::getArg("sourceDir"));
    }

    if (!pathDirOrFile.isDir()) {
        QuasarAppUtils::Params::log("The given path does not exist or is not a directory",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }

    QuasarAppUtils::Params::log("Selected source dir :" + pathDirOrFile.absoluteFilePath(),
                                QuasarAppUtils::Info);
    conf.setSourceDir(pathDirOrFile.absoluteFilePath());


    if (!QuasarAppUtils::Params::isEndable("sign")) {
        QuasarAppUtils::Params::log("Not option sign.",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }
    pathDirOrFile.setFile(QuasarAppUtils::Params::getArg("sign"));

    if (!QFileInfo::exists(pathDirOrFile.absoluteFilePath())) {
        QuasarAppUtils::Params::log("The given path does not exist or is not a file signature",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }

    Signature signature;
    bool checkSign = signature.fromJson(pathDirOrFile.absoluteFilePath());
    if (!checkSign) {
        QuasarAppUtils::Params::log("The signature was not parsed",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }
    conf.setSingValue(signature);

    return true;
};

}
