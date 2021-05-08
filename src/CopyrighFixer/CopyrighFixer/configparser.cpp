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

    if (QuasarAppUtils::Params::isEndable("sourceDir")) {

        QFileInfo srcDir(QuasarAppUtils::Params::getArg("sourceDir"));
        if (srcDir.isDir()) {

            conf.setSourceDir(QuasarAppUtils::Params::getArg("sourceDir"));

        } else {
            QuasarAppUtils::Params::log("The given path does not exist or is not a directory",
                                        QuasarAppUtils::VerboseLvl::Error);
            conf.setSourceDir(".");
        }
    } else {
        QuasarAppUtils::Params::log("Error: Not option sourceDir.",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }

    if (QuasarAppUtils::Params::isEndable("sign")) {
        if (QFileInfo::exists(QuasarAppUtils::Params::getArg("sign"))) {

            Signature signature;
            bool checkSign = signature.fromJson(QuasarAppUtils::Params::getArg("sign"));
            if (checkSign) {
                conf.setSingValue(signature);
            } else {
                QuasarAppUtils::Params::log("Error: The signature was not parsed",
                                            QuasarAppUtils::VerboseLvl::Error);
                return false;
            }

        } else {
            QuasarAppUtils::Params::log("The given path does not exist or is not a file signature",
                                        QuasarAppUtils::VerboseLvl::Error);
            return false;
        }
    }
    else {
        QuasarAppUtils::Params::log("Error: Not option sign.",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }

<<<<<<< HEAD
=======

>>>>>>> ffc8cde82c8bb1d3a11bd32b7766e47cbe5e9f78
    return true;
};

}
