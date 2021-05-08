//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef WORKER_H
#define WORKER_H

#include "CopyrighFixer_global.h"
#include "config.h"
#include "signer.h"
#include "configparser.h"


namespace CopyrighFixer {

/**
 * @brief The Worker class will be control all work process.
 */
class CopyrighFixer_EXPORT Worker {

public:
    Worker(Config *conf = nullptr,
           ConfigParser *confParser = nullptr,
           Signer *subscriber = nullptr);
    ~Worker() {
        delete conf_;
        delete confParser_;
        delete subscriber_;
    };

    /**
     * @brief run It is main method for control of all parsing process.
     * @return Returns false if the program terminates with an error.

     */
    bool run();

    /**
     * @brief printHelp Display infotmation about the arguments and how to use them.
     */
    void printHelp() const;

protected:
    Config *conf_;
    ConfigParser *confParser_;
    Signer *subscriber_;

};

}

#endif // WORKER_H
