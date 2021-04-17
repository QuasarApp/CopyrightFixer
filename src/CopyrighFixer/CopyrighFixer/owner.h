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
     * @brief setName
     * @param ownerName This is name of the owner.
     */
    void setName(const QString &ownerName);

    /**
     * @brief getOwnerName
     * @return the owner name.
     */
    QString getOwnerName();

    /**
     * @brief setTimeRange
     * @param interval This is a string value indicating the  date of ownership of the file.
     */
    void setTimeRange(const QString &interval);

    /**
     * @brief getTimeRange
     * @return the time interval when the file was modified
     */
    QString getTimeRange();
private:
    QString name;
    QString timeRange;

};

};

#endif // OWNER_H
