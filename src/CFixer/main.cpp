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
                "!!!HELP!!!", {
                    {"-sourceDir", "/path/sources"},
                    {"-sign", "/path/to/copyright/file"},
                    {"-currentOwner", "QuasraApp"},
                }
            }
        };
        QuasarAppUtils::Params::showHelp(help);

        exit(0);
    }

//    if (!QuasarAppUtils::Params::parseParams(argc, argv)) {
//        QuasarAppUtils::Params::log("wrong parametrs", QuasarAppUtils::Warning);

//        QuasarAppUtils::Help::Charters help = {
//            {
//                "Pard 0 General", {
//                    {"-sourceDir", "/path/sources"},
//                    {"-sign", "/path/to/copyright/file"},
//                    {"-currentOwner", "QuasraApp"},
//                }
//            }
//        };
//        QuasarAppUtils::Params::showHelp(help);

//        exit(0);
//    }

    return 0;
}
