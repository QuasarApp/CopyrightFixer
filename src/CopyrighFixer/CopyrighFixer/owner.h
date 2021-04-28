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
    void setTimePoint(const QString &interval);

    /**
     * @brief getTimeRange The method changes the timestamp of the usage.
     * @return the time interval when the file was modified
     */
    const QString& getTimePoint() const;

private:
    QString _name;
    int _timePoint;

};

};

#endif // OWNER_H
