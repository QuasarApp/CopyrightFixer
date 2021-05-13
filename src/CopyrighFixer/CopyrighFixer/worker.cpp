//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "config.h"
#include "configparser.h"
#include "worker.h"
#include <quasarapp.h>


namespace CopyrighFixer {

Worker::Worker() {
    conf_ = new Config;
    confParser_ =  new ConfigParser;
    subscriber_ = new Signer;
}

Worker::~Worker() {
    delete conf_;
    delete confParser_;
    delete subscriber_;
}

bool Worker::run() {

    if (!confParser_->parseOptions(*conf_)) {
        return false;
    }

    if (!subscriber_->checkSign(*conf_)) {
        return false;
    }

    return true;
}

void Worker::printHelp() const {

    QuasarAppUtils::Help::Charters help = {
        {
            "Part 0 General", {
                {"h or help", "These arguments represent a helper call that describes the functionality of each method"},
                {"-sourceDir path/to/source/dir", "This arrgument sets path to the source directory. By default it is sourceDir = PWD"},
                {"-sign path/to/sign/file", "This argument sets path to the sign patern. This is a required argument"},
                {"-currentOwner ownerName", "This argument sets name of the current owner of the code."},
            }
        }
    };

    help += QuasarAppUtils::Params::getparamsHelp();

    QuasarAppUtils::Params::showHelp(help);

}

};
