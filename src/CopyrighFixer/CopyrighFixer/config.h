//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef CONFIG_H
#define CONFIG_H

#include "CopyrighFixer_global.h"
#include "CopyrighFixer/sign.h"
#include <QString>


namespace CopyrighFixer {

/**
 * @brief The Config class collects information about the current session
 */
class CopyrighFixer_EXPORT Config {
public:
    Config();

    /**
     * @brief setSourceDir This method sets path to the source directory.
     * @param pathToDir Path to the directory in which the files are to be signed. Example: /path/to/sources/dir
     */
    void setSourceDir(const QString &pathToDir);

    /**
     * @brief setSingValue This method sets a new value of the signatura.
     * @param value it is an object with a signature.
     */
    void setSingValue(const Signature &value);

    /**
     * @brief getSrcDir This method return the path to the directory with files for signature.
     * @return The path to the directory.
     */
    const QString &getSrcDir() const;

    /**
     * @brief getSignVal This method return objecte with a copyright.
     * @return Objecte This is a new signature object.
     */
    const Signature &getSignVal() const;

private:
    QString _sourceDirPath;
    Signature _signValue;
};

}

#endif // CONFIG_H
