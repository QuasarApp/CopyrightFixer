//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <quasarapp.h>
#include <iostream>
#include <CopyrighFixer/worker.h>

using namespace CopyrighFixer;


int main(int argc, char *argv[]) {

    Worker *worker = new Worker();

    if (!QuasarAppUtils::Params::parseParams(argc, argv)) {
        worker->printHelp();
        return 1;
    }

    if (QuasarAppUtils::Params::isEndable("h") || QuasarAppUtils::Params::isEndable("help")) {
        worker->printHelp();
        return 0;
    }

    return 0;
}
