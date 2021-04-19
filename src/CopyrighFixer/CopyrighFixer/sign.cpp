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
    ownersList = objOwner;
}

void Signature::setLicenseTitle(const QString &strTitle) {
    licenseTitle = strTitle;
}

void Signature::setMessage(const QString &strMsg) {
    customMessage = strMsg;
}

const QList<Owner> &Signature::getLstOwn() const {
    return ownersList;
}

const QString &Signature::getLicenseTitle() const {
    return licenseTitle;
}

const QString &Signature::getMessage() const {
    return customMessage;
}

}
