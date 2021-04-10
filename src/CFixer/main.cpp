//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <CopyrighFixer/bar.h>
#include <iostream>


int main(int argc, char *argv[]) {

    QString var;
    CopyrighFixer::Bar example_variable_class;
    var = example_variable_class.foo();

    std::cout << var.toStdString();

    return 0;
}
