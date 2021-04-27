//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "sign.h"
#include "owner.h"
#include <quasarapp.h>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonDocument>


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

bool Signature::fromJson() {

}

bool Signature::toJson() const {

    QJsonArray lstObjown;
    QJsonObject objOwner;
    for (const Owner &obj:  qAsConst(_ownersList)) {
        objOwner["timePoint"] = obj.getTimeRange();
        objOwner["name"] = obj.getOwnerName();
        lstObjown.append(objOwner);
    }

    QJsonObject signJson;
    signJson["ownersList"] = lstObjown;
    signJson["license"] = _licenseTitle;
    signJson["licenseText"] = _customMessage;

    QByteArray jsonDoc;
    jsonDoc = QJsonDocument(signJson).toJson();

    QFile file;
    file.setFileName(filenameJson);
    if (!file.open(QIODevice::WriteOnly)) {
        QuasarAppUtils::Params::log("NO write access for json file.");
        return 0;
    }

    file.write(jsonDoc);
    file.close();

    return 1;
}

}














