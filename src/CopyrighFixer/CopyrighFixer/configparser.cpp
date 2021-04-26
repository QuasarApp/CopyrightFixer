//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "configparser.h"
#include <quasarapp.h>
#include <iostream>


namespace CopyrighFixer {
ConfigParser::ConfigParser() {

}

const Config ConfigParser::parseOptions(const Config &conf) const {

    Config configOption = conf;

    if (QuasarAppUtils::Params::isEndable("sourceDir")) {
        configOption.setSourceDir(QuasarAppUtils::Params::getArg("sourceDir"));
    } else {
        std::cout << "Warning: Not option sourceDir" << std::endl;
    }

    if (QuasarAppUtils::Params::isEndable("sign")) {
        Signature *signature = new Signature;
        configOption.setSingValue(*signature);
//        configOption.setSingValue(QuasarAppUtils::Params::getArg("sign"));
    }
    else {
        std::cout << "Warning: Not option sign" << std::endl;
    }

    if (QuasarAppUtils::Params::isEndable("currentOwner")) {
        configOption.setCurrOwn(QuasarAppUtils::Params::getArg("currentOwner"));
    } else {
        std::cout << "Warning: Not option currentOwner" << std::endl;
    }

    return configOption;
};


}
