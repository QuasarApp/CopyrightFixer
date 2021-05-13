//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "config.h"
#include "configparser.h"
#include "signer.h"
#include "worker.h"
#include <quasarapp.h>


namespace CopyrighFixer {

Worker::Worker() {
    _conf = new Config;
    _confParser =  new ConfigParser;
    _subscriber = new Signer;
}

Worker::~Worker() {
    delete _conf;
    delete _confParser;
    delete _subscriber;
}

bool Worker::run() {

    if (!_confParser->parseOptions(*_conf)) {
        return false;
    }

    if (!_subscriber->checkSign(*_conf)) {
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
