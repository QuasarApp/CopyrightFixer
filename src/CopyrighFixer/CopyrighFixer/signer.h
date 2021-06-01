//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef SIGNER_H
#define SIGNER_H

#include "CopyrighFixer_global.h"
#include "config.h"

namespace CopyrighFixer {

class IFileManager;

/**
 * @brief The Signer class
 */
class CopyrighFixer_EXPORT Signer {
public:
    Signer();

    /**
     * @brief checkSign The method that add copyright to all sources files.
     * @param objConf This is a configuration object.
     */
    bool checkSign(const Config &objConf);

    /**
     * @brief searchFileByExt The method that searches for files with the desired extension.
     * @param extension This is the file extension to search.
     * @return Returns a pointer to the FileManager of the found extension, or nullptr if the file extension was not found.
     */
    IFileManager *searchFileByExt(const QString &extension);

private:
    QList<IFileManager*> _fileManager;

};

}


#endif // SIGNER_H
