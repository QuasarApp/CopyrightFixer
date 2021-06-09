//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <time.h>
#include "signer.h"
#include "CopyrighFixer/ifilemanager.h"
#include <QDir>
#include <quasarapp.h>

namespace CopyrighFixer {
Signer::Signer() {

}


bool Signer::processSign(const QString &pathToFile, const Config &objConf) const {

    QDir currentFolder(pathToFile);
    currentFolder.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

    QFileInfoList folderItems(currentFolder.entryInfoList());

    for (auto i_file: folderItems) {

        if (i_file.isDir()) {
            processSign(i_file.filePath(), objConf);
        }

        IFileManager *currFM = searchFileByExt(i_file.suffix());
        Signature signFromFile;
        Signature resultSign;

        if (currFM == nullptr) {
            return false;
        }

        if (!currFM->read(i_file.filePath(), signFromFile)) {
            return false;
        }

        resultSign = mergeSign(objConf.getSignVal(), signFromFile);

        if (!currFM->write(i_file.filePath(), resultSign)) {
            return false;
        }
    }

    return true;
}

bool Signer::checkSign(const Config &objConf) {

    if (!processSign(objConf.getSrcDir(), objConf)) {
        return false;
    }

    return true;
}

const Signature Signer::upgradeOwner(const Signature &signConf, const Signature &fileSign) const {

    int unixTime = time(0);

    Signature signForSing = fileSign;
    QMap<int, CopyrighFixer::Owner> mapOwnersFile = signForSing.getMapOwn();
    mapOwnersFile.remove(fileSign.getMapOwn().cbegin().key());

    CopyrighFixer::Owner newOwner;
    newOwner.setName(signConf.getMapOwn().cbegin().value().getOwnerName());
    newOwner.setTimePoint(unixTime);

    mapOwnersFile.insert(unixTime, newOwner);
    signForSing.setMapOwners(mapOwnersFile);

    return signForSing;

}

const Signature Signer::appendOwner(const Signature &signConf, const Signature &fileSign) const {

    int unixTime = time(0);

    Signature signForSing = fileSign;
    QMap<int, CopyrighFixer::Owner> mapOwnersFile = signForSing.getMapOwn();

    CopyrighFixer::Owner newOwners;
    newOwners.setName(signConf.getMapOwn().cbegin().value().getOwnerName());
    newOwners.setTimePoint(unixTime);

    mapOwnersFile.insert(unixTime, newOwners);
    signForSing.setMapOwners(mapOwnersFile);

    return signForSing;
}

const Signature Signer::mergeSign(const Signature &userSign, const Signature &fileSign) const {

    if (!fileSign.isValid()) {
        return userSign;
    }

    if (userSign.getLicenseTitle() != fileSign.getLicenseTitle()) {
        QuasarAppUtils::Params::log("The signature in the file is different from the config signature.",
                                    QuasarAppUtils::VerboseLvl::Warning);
        return fileSign;
    }

    if (userSign.getMapOwn().size() > 1) {
        QuasarAppUtils::Params::log("Config signature contains more owners.",
                                    QuasarAppUtils::VerboseLvl::Warning);
        return upgradeOwner(userSign, fileSign);
    }

    if (userSign.getMapOwn().cbegin().value().getOwnerName() == fileSign.getMapOwn().cbegin().value().getOwnerName()) {
        return upgradeOwner(userSign, fileSign);
    }

    if (userSign.getMapOwn().cbegin().value().getOwnerName() != fileSign.getMapOwn().cbegin().value().getOwnerName()) {
        return appendOwner(userSign, fileSign);
    }

    return fileSign;

}

IFileManager *Signer::searchFileByExt(const QString &extension) const {

    for (auto itemFM: _fileManager) {

        if (itemFM && itemFM->isSupport(itemFM->toExtension(extension))) {
            return itemFM;
        }
    }
    return nullptr;
}

}
