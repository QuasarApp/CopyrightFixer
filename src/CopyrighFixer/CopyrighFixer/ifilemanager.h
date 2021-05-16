//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef IFILEHANDLER_H
#define IFILEHANDLER_H

#include "CopyrighFixer_global.h"
#include "CopyrighFixer/sign.h"


namespace CopyrighFixer {

/**
 * @brief The Extensinon enum File extensions for signature.
 */
enum Extensinon {
    /// CPP The CPP file is a source code file written in C++.
    CPP,

    /// HPP The header file containing the development source code written in C ++.
    HPP,

    /// The used for the header of the file, which is referenced by the source code of the document written in C ++.
    H,

    /// The CC file is a source code file written in C++.
    CC,

    /// The Contains JavaScript-based QML source code encoded in UTF-8 format.
    QML,

    /// The PRO files include references to project libraries, assets and source code files, and other files such as application resources.
    PRO,

    /// The source code is written in the TXT file in CMake language.
    TXT,

    /// The PY file contains the source code in python.
    PY,
};

/**
 * @brief The IFileHandler class This is class that handles the source files that need to be signed.
 */
class CopyrighFixer_EXPORT IFileManager {
public:

    /**
     * @brief read This is method be read a copyright singnature from a source file.
     * @param pathToFile The source file path.
     * @param objSign The object signature.
     * @return Returns true if the file was read successfully.
     */
    virtual bool read(const QString &pathToFile, Signature &objSign) = 0;

    /**
     * @brief write This is method be write a new copyright signature into file (replace an old signature).
     * @param pathToFile Path to the file in which to replace the signature.
     * @param objSign The object signature.
     * @return Returns true if the signature is valid.
     */
    virtual bool write(const QString &pathToFile, const Signature &objSign) = 0;

    /**
     * @brief supportsExtensions This method contains a list of file extensions that will be checked against the source files.
     * @return Return A set of the supported extensions.
     */
    virtual Extensinon supportsExtensions() = 0;

    virtual ~IFileManager();
};

};
#endif // IFILEHANDLER_H
