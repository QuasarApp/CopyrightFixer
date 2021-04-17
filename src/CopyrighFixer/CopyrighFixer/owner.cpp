#include "owner.h"

namespace CopyrighFixer {
    Owner::Owner()
    {

    }

    void Owner::setName(const QString &ownerName) {
        Owner::name = ownerName;
    }

    QString Owner::getOwnerName()
    {
        return Owner::name;
    }

    void Owner::setTimeRange(const QString &interval) {
        timeRange = interval;
    }

    QString Owner::getTimeRange()
    {
        return Owner::timeRange;
    }

};
