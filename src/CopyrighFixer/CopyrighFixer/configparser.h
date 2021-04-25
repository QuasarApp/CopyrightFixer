//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include "CopyrighFixer_global.h"
#include "config.h"

namespace CopyrighFixer {

/**
 * @brief The ConfigParser class that parse the settings received at the input of the program.
 */
class ConfigParser {
public:
    ConfigParser();

    /**
     * @brief parseOptions This a method that will parse all input options.
     * @return The config object.
     */
    const Config parseOptions(const Config &conf) const;

};

}


#endif // CONFIGPARSER_H
