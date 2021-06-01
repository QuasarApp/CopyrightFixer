//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "ifilemanager.h"


namespace CopyrighFixer {

bool IFileManager::isSupport(const Extension &curExt) const {
    return supportsExtensions() & curExt;
}

Extension IFileManager::toExtension(const QString &curExt) const {

    if (".cpp" == curExt) {
        return Extension::CPP;
    }

    if (".hpp" == curExt) {
        return  Extension::HPP;
    }

    if (".h" == curExt) {
        return  Extension::H;
    }

    if (".cc" == curExt) {
        return  Extension::CC;
    }

    if (".qml" == curExt) {
        return  Extension::QML;
    }

    if (".pro" == curExt) {
        return  Extension::PRO;
    }

    if (".txt" == curExt) {
        return  Extension::TXT;
    }

    if (".py" == curExt) {
        return  Extension::PY;
    }

    return Extension::UNDEFINED;
}

IFileManager::~IFileManager() {

}

};
