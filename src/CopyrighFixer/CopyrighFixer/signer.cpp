//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "signer.h"
#include "CopyrighFixer/ifilemanager.h"
#include <QDir>
#include <quasarapp.h>

namespace CopyrighFixer {
Signer::Signer() {

}

bool Signer::checkSign(const Config &objConf) {    

    Config currConfig = objConf;

    QDir currentFolder(currConfig.getSrcDir());
    currentFolder.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

    QFileInfoList folderItems(currentFolder.entryInfoList());

    for (auto i_file: folderItems) {

        if (i_file.isDir()) {

            currConfig.setSourceDir(i_file.filePath());
            checkSign(currConfig);

        } else {

            IFileManager *currFM = searchFileByExt(i_file.suffix());
            Signature signFromFile;
            Signature resultSign;

            if (currFM == nullptr) {
                return false;
            }

            if (!currFM->read(i_file.filePath(), signFromFile)) {
                return false;
            }

            resultSign = mergeSign(currConfig.getSignVal(), signFromFile);

            if (!currFM->write(i_file.filePath(), resultSign)) {
                return false;
            }
        }
    }

    return true;
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
        return fileSign;
    }

    Signature signForSing = fileSign;
    if (userSign.getMapOwn().cbegin().value().getOwnerName() == signForSing.getMapOwn().cbegin().value().getOwnerName()) {

        QMap<int, CopyrighFixer::Owner> mapOwners = signForSing.getMapOwn();
        mapOwners.remove(fileSign.getMapOwn().cbegin().key());
        mapOwners.insert(userSign.getMapOwn().cbegin().key(),
                         userSign.getMapOwn().cbegin().value());
        signForSing.setMapOwners(mapOwners);

        return signForSing;

    }

    if (userSign.getMapOwn().cbegin().value().getOwnerName() != signForSing.getMapOwn().cbegin().value().getOwnerName()) {

        QMap<int, CopyrighFixer::Owner> mapOwners = signForSing.getMapOwn();
        mapOwners.insert(userSign.getMapOwn().cbegin().key(),
                         userSign.getMapOwn().cbegin().value());
        signForSing.setMapOwners(mapOwners);

        return signForSing;

    }

    return fileSign;

}

IFileManager *Signer::searchFileByExt(const QString &extension) {

    for (auto itemFM: _fileManager) {

        if (itemFM && itemFM->isSupport(itemFM->toExtension(extension))) {
            return itemFM;
        }

    }
    return nullptr;
}

}
