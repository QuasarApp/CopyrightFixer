//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef INTERFACEIMPLEM_H
#define INTERFACEIMPLEM_H

#include "CopyrighFixer_global.h"
#include "CopyrighFixer/ifilemanager.h"


namespace CopyrighFixer {


class CopyrighFixer_EXPORT InterfaceImplem: public IFileManager {
public:
    InterfaceImplem();

    bool read(const QString &pathToFile, Signature &objSign);

    bool write(const QString &pathToFile, const Signature &objSign);

    Extension supportsExtensions() const;

};

};

#endif // INTERFACEIMPLEM_H
