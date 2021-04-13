//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <quasarapp.h>

int main(int argc, char *argv[]) {
    QuasarAppUtils::Params::parseParams(argc, argv);

    if (QuasarAppUtils::Params::isEndable("h")){
        QuasarAppUtils::Help::Charters help = {
            {
                "Part 0 General", {
                    {"-sourceDir", "This arrgument sets path to the source directory. By default it is sourceDir = PWD"},
                    {"-sign", "This argument sets path to the sign patern. This is a required argument"},
                    {"-currentOwner", "This argument sets name of the current owner of the code."},
                }
            }
        };
        QuasarAppUtils::Params::showHelp(help);

        exit(0);
    }

    return 0;
}
