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
 * @brief The Config class
 */
class CopyrighFixer_EXPORT Config {
public:
    Config();

    /**
     * @brief setSourceDir This method set path to the source directory.
     * @param pathToDir drink to the directory in which the files are to be signed. Example: /path/to/sources/dir
     */
    void setSourceDir(const QString &pathToDir);

    /**
     * @brief setSingValue A method that stores copyright text.
     * @param value Argument that passes the text of the signature.
     */
    void setSingValue(const Signature &value);

    /**
     * @brief setCurrOwn A method that records the name of the  current owner of the code.
     * @param owner An argument that passes the name owner of the code.
     */
    void setCurrOwn(const QString &owner);

    /**
     * @brief getSrcDir Method that allows you to get the path to the directory with files for signature.
     * @return The path to the directory.
     */
    const QString &getSrcDir() const;

    /**
     * @brief getSignVal The method allows you to get the copyright text.
     * @return String copyright description.
     */
    const Signature &getSignVal() const;

    /**
     * @brief getCurrentOwn The method allows you to get the name or list name owner of the code.
     * @return String name current owner.
     */
    const QString &getCurrentOwn() const;

private:
    QString sourceDirPath;
    Signature signValue;
    QString currentOwner;
};

}

#endif // CONFIG_H
