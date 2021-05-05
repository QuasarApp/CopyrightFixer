//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "configparser.h"
#include <quasarapp.h>


namespace CopyrighFixer {
ConfigParser::ConfigParser() {

}

bool ConfigParser::parseOptions(Config &conf) const {

    if (QuasarAppUtils::Params::isEndable("sourceDir")) {
        conf.setSourceDir(QuasarAppUtils::Params::getArg("sourceDir"));
    } else {
        QuasarAppUtils::Params::log("Error: Not option sourceDir.",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }

    if (QuasarAppUtils::Params::isEndable("sign")) {
        Signature signature;
        conf.setSingValue(signature);
    }
    else {
        QuasarAppUtils::Params::log("Error: Not option sign.",
                                    QuasarAppUtils::VerboseLvl::Error);
        return false;
    }

    if (QuasarAppUtils::Params::isEndable("currentOwner")) {
        conf.setCurrOwn(QuasarAppUtils::Params::getArg("currentOwner"));
    } else {
        QuasarAppUtils::Params::log("Warning: Not option currentOwner.",
                                    QuasarAppUtils::VerboseLvl::Warning);
    }

    return true;
};

}
