//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef SIGN_H
#define SIGN_H

#include "CopyrighFixer_global.h"
#include "CopyrighFixer/owner.h"
#include <QMap>


namespace CopyrighFixer {

/**
 * @brief The Signature class adds a copyright signature to each file based on the collected owner information.
 * ### Structure of the json file.
 * @code{json}
    {
        "license": "lgplv3.",
        "licenseText": "Distributed under the lgplv3 software license, see the accompany.",
        "ownersList": [
            {
                "name": "QuasarApp",
                "timePoint": 1620149717
            }
        ]
    }
 * @endcode
 */
class CopyrighFixer_EXPORT Signature {
public:
    Signature();

    /**
     * @brief setlistOwners The method generates a list of owners.
     * @param objOwner This is a structure with information about the owner.
     */
    void setMapOwners(const QMap<int, Owner> &objOwner);

    /**
     * @brief setLicenseTitle The method sets the copyright message.
     * @param strTitle A string that contains copyright information.
     */
    void setLicenseTitle(const QString &strTitle);

    /**
     * @brief setMessage Method adds custom message.
     * @param strMsg Meaningful message with complementary information.
     */
    void setMessage(const QString &strMsg);

    /**
     * @brief getLstOwn The method allows you to get the current list of owners.
     * @return List of owners with full information.
     */
    const QMap<int, Owner>& getMapOwn() const;

    /**
     * @brief getLicenseTitle Allows you to get a license description.
     * @return A string with license title.
     */
    const QString& getLicenseTitle() const;

    /**
     * @brief getMessage The method retutns a custom message with additional information.
     * @return Custom message.
     */
    const QString& getMessage() const;

    /**
     * @brief fromJson Reads data from json file.
     * @return True if everything is correct, otherwise false.
     */
    bool fromJson(const QString &pathToFile);

    /**
     * @brief toJson Converts the QJsonDocument to an file JSON.
     * @return Returns true if the object exists and is filled correctly, otherwise false.
     */
    bool toJson(QString &pathToFile) const;

    /**
     * @brief isValid Checks if an object is initialized.
     * @return Returns true if object is initialized.
     */
    bool isValid() const;

    /**
     * @brief operator == Comparison operator overloading method
     * @param c1 Left value.
     * @param c2 Right value.
     * @return Returns true if they are equal.
     */
    CopyrighFixer_EXPORT friend bool operator== (const Signature &c1, const Signature &c2);

private:
    QMap<int, Owner> _ownersMap;
    QString _licenseTitle = "";
    QString _customMessage = "";

};

}

#endif // SIGN_H
