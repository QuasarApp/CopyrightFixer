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
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonValue>
#include <QByteArray>
#include <QJsonDocument>


namespace CopyrighFixer {
Signature::Signature() {

}

void Signature::setMapOwners(const QMap<int, Owner> &objOwner) {
    _ownersMap = objOwner;
}

void Signature::setLicenseTitle(const QString &strTitle) {
    _licenseTitle = strTitle;
}

void Signature::setMessage(const QString &strMsg) {
    _customMessage = strMsg;
}

const QMap<int, Owner> &Signature::getMapOwn() const {
    return _ownersMap;
}

const QString &Signature::getLicenseTitle() const {
    return _licenseTitle;
}

const QString &Signature::getMessage() const {
    return _customMessage;
}

bool Signature::fromJson(const QString &pathToFile) {

    QFileInfo signFile(pathToFile);
    if (signFile.exists() && signFile.isFile()) {

        QFile file(pathToFile);
        if (!file.open(QIODevice::ReadOnly)) {
            QuasarAppUtils::Params::log("Json file couldn't be opened/found");
            return false;
        }

        QByteArray byteSignFile(file.readAll());
        file.close();

        QJsonDocument jsDoc(QJsonDocument::fromJson(byteSignFile));
        if (jsDoc.isNull()) {
            QuasarAppUtils::Params::log("Failed to create JSON doc.");
            return false;
        }
        if (!jsDoc.isObject()) {
            QuasarAppUtils::Params::log("JSON is not an object.");
            return false;
        }

        QJsonObject jsObj = jsDoc.object();
        if (jsObj.isEmpty()) {
            QuasarAppUtils::Params::log("JSON object is empty.");
            return false;
        }

        Owner ownObj;
        QJsonArray ownLst(jsObj.value("ownersList").toArray());
        for (auto itemLst = ownLst.cbegin(); itemLst != ownLst.end(); ++itemLst) {
            ownObj.fromjson(itemLst->toObject());
            _ownersMap.insert(itemLst->toObject().value("timePoint").toInt(), ownObj);
        }

        _licenseTitle = jsObj.value("license").toString();
        _customMessage = jsObj.value("licenseText").toString();

        return true;

    } else {
        return false;
    }

}

bool Signature::toJson(QString &pathToFile) const {

    QFileInfo checkFile(pathToFile);
    if (checkFile.exists() && checkFile.isFile()) {
        QFile::remove(pathToFile);
    }


    QJsonArray lstObjown;
    QJsonObject objOwner;
    for (auto obj = _ownersMap.cbegin(); obj != _ownersMap.end(); ++obj) {
        objOwner["timePoint"] = obj.value().getTimePoint();
        objOwner["name"] = obj.value().getOwnerName();

        lstObjown.append(objOwner);
    }

    QJsonObject signJson;
    signJson["ownersList"] = lstObjown;
    signJson["license"] = _licenseTitle;
    signJson["licenseText"] = _customMessage;

    QByteArray jsonDoc;
    jsonDoc = QJsonDocument(signJson).toJson();

    QFile saveFile(pathToFile);
    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QuasarAppUtils::Params::log("NO write access for json file.");
        return 0;
    }

    saveFile.write(jsonDoc);
    saveFile.close();

    return true;
}

bool Signature::isValid() const {
    if (_licenseTitle.size() != 0 || _customMessage != 0) {
        return true;
    }

    if (_ownersMap.cbegin().key() > 0 && _ownersMap.cbegin().value().isValid()) {
        return true;
    }

    return false;
}

}
