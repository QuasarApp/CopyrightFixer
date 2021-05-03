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
    _name = ownerName;
}

const QString &Owner::getOwnerName() const {
    return _name;
}

void Owner::setTimePoint(int interval) {
    _timePoint = interval;
}

int Owner::getTimePoint() const {
    return _timePoint;
}

void Owner::fromjson(const QJsonObject &objJs) {
    if (objJs.contains("name") && objJs.value("name").isString()) {
         _name = objJs.value("name").toString();
    }

    if (objJs.contains("timePoint")) {
        _timePoint = objJs.value("timePoint").toInt();
    }
}

const QJsonObject &Owner::toJson(QJsonObject &objJs) const {

    objJs["name"] = _name;
    objJs["timePoint"] = _timePoint;

    return objJs;
}

bool Owner::isValid() const {
    if (_name.size() != 0 && _timePoint > 0) {
        return true;
    }

    return false;
}

};
