//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "owner.h"

namespace CopyrighFixer {
Owner::Owner() {

}

void Owner::setName(const QString &ownerName) {
    name = ownerName;
}

const QString &Owner::getOwnerName() const {
    return name;
}

void Owner::setTimeRange(const QString &interval) {
    timeRange = interval;
}

const QString &Owner::getTimeRange() const {
    return timeRange;
}

};
