//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "signer.h"
#include "CopyrighFixer/ifilemanager.h"
#include <QDir>

namespace CopyrighFixer {
Signer::Signer() {

}

bool Signer::checkSign(const Config &objConf) {    

    Config currConfig = objConf;

    QDir currentFolder(currConfig.getSrcDir());
    currentFolder.setFilter(QDir::Dirs | QDir::Files);

    QFileInfoList folderItems(currentFolder.entryInfoList());

    for (auto i_file: folderItems) {

        if (i_file.fileName() == "." || i_file.fileName() == "..") {
            continue;
        }

        if (!i_file.isDir()) {

            IFileManager *currFM = searchFileByExt(i_file.suffix());
            Signature objSing = currConfig.getSignVal();

            if (currFM == nullptr) {
                return false;
            }

            bool valRead = currFM->read(i_file.filePath(), objSing);
            if (!valRead) {
                return false;
            }

            currConfig.setSingValue(objSing);

            bool valWrite = currFM->write(i_file.filePath(), objSing);
            if (!valWrite) {
                return false;
            }

        } else {
            currConfig.setSourceDir(i_file.filePath());
            checkSign(currConfig);
        }
    }

    return true;
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
