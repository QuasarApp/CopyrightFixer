//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <quasarapp.h>

int main(int argc, char *argv[]) {

    if (!QuasarAppUtils::Params::parseParams(argc, argv)) {
        QuasarAppUtils::Params::log("wrong parametrs", QuasarAppUtils::Warning);
        exit(0);

    }

    return 0;
}
