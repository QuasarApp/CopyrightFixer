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
#include <QFileInfo>

namespace CopyrighFixer {

class IFileManager;

/**
 * @brief The Signer class
 */
class CopyrighFixer_EXPORT Signer {
public:
    Signer();

    bool processSign(const QString &pathToFile, const Config &objConf) const;

    /**
     * @brief checkSign The method that add copyright to all sources files.
     * @param objConf This is a configuration object.
     */
    bool checkSign(const Config &objConf);

    /**
     * @brief mergeSign The method compares two signatures and merges into one.
     * @param userSign The signature that is pulled from the configuration.
     * @param fileSign The signature that is read from the file.
     * @return Returns the signature for signing a filereturn false;.
     */
    const Signature mergeSign(const Signature &userSign, const Signature &fileSign) const;

    /**
     * @brief searchFileByExt The method that searches for files with the desired extension.
     * @param extension This is the file extension to search.
     * @return Returns a pointer to the FileManager of the found extension, or nullptr if the file extension was not found.
     */
    IFileManager *searchFileByExt(const QString &extension) const;

private:
    QList<IFileManager*> _fileManager;

    /**
     * @brief upgradeOwner
     * @param signConf The signature that is pulled from the configuration.
     * @param fileSign The signature that is read from the file.
     * @return Returns a signature with the last owner updated.
     */
    const Signature upgradeOwner(const Signature &signConf, const Signature &fileSign) const;

    /**
     * @brief appendOwner
     * @param signConf The signature that is pulled from the configuration.
     * @param fileSign The signature that is read from the file.
     * @return Returns a signature with the most recently updated owner list.
     */
    const Signature appendOwner(const Signature &signConf, const Signature &fileSign) const;
};

}


#endif // SIGNER_H
