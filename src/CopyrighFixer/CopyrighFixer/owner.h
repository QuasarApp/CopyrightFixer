//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef OWNER_H
#define OWNER_H

#include "CopyrighFixer_global.h"
#include <QString>
#include <QJsonObject>

namespace CopyrighFixer{

/**
 * @brief The Owner class for collect information about owner.
 */
class CopyrighFixer_EXPORT Owner
{
public:
    Owner();
    /**
     * @brief setName The method will save the name of the owner who last used it
     * @param ownerName This is name of the owner.
     */
    void setName(const QString &ownerName);

    /**
     * @brief getOwnerName The method allows you to get information about the owner.
     * @return the owner name.
     */
    const QString& getOwnerName() const;

    /**
     * @brief setTimeRange A method that allows you to set the time interval for using a file.
     * @param interval This is a string value indicating the  date of ownership of the file.
     */
    void setTimePoint(int interval);

    /**
     * @brief getTimeRange The method changes the timestamp of the usage.
     * @return the time interval when the file was modified
     */
    int getTimePoint() const;

    /**
     * @brief fromjson Reads data from json file.
     * @param objJs It's object json that contains information about the owner.
     */
    void fromJson(const QJsonObject &objJs);

    /**
     * @brief toJson This method that converts object Owner to json object.
     * @param objJs It's object json - container.
     * @return Returns a json object with owner a information.
     */
    const QJsonObject &toJson(QJsonObject &objJs) const;

    /**
     * @brief isValid Checks if an object is initialized.
     * @return Returns true if object is initialized.
     */
    bool isValid() const;

    /**
     * @brief operator == Comparison operator overloading method
     * @param o1 Left value.
     * @param o2 Right value.
     * @return Returns true if they are equal.
     */
    CopyrighFixer_EXPORT friend bool operator== (const Owner &o1, const Owner &o2);

private:
    QString _name = "";
    int _timePoint = 1;

};

};

#endif // OWNER_H
