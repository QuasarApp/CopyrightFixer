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

void Owner::fromJson(const QJsonObject &objJs) {
    _name = objJs.value("name").toString();
    _timePoint = objJs.value("timePoint").toInt();
}

void Owner::toJson(QJsonObject &objJs) const {

    objJs["name"] = _name;
    objJs["timePoint"] = _timePoint;

    return objJs;
}

bool Owner::isValid() const {
    if (_name.size() != 0 && _timePoint > 0) {
        return true;
    }

    return _name.size() && _timePoint > 0 && _timePoint <= time(0);
}

CopyrighFixer_EXPORT bool operator== (const Owner &o1, const Owner &o2) {
    return (o1._name == o2._name &&
            o1._timePoint == o2._timePoint);
}

};
