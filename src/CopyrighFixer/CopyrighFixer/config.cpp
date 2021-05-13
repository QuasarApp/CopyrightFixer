//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "config.h"

namespace CopyrighFixer {
Config::Config() {

}

void Config::setSourceDir(const QString &pathToDir) {
    _sourceDirPath = pathToDir;
}

void Config::setSingValue(const Signature &value) {
    _signValue = value;
}

const QString &Config::getSrcDir() const {
    return _sourceDirPath;
}

const Signature &Config::getSignVal() const {
    return _signValue;
}

}

