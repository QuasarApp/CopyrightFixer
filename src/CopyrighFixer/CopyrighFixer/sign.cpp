//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "sign.h"
#include "owner.h"

namespace CopyrighFixer {
Signature::Signature() {

}

void Signature::setlistOwners(const QList<Owner> &objOwner) {
    _ownersList = objOwner;
}

void Signature::setLicenseTitle(const QString &strTitle) {
    _licenseTitle = strTitle;
}

void Signature::setMessage(const QString &strMsg) {
    _customMessage = strMsg;
}

const QList<Owner> &Signature::getLstOwn() const {
    return _ownersList;
}

const QString &Signature::getLicenseTitle() const {
    return _licenseTitle;
}

const QString &Signature::getMessage() const {
    return _customMessage;
}

}
