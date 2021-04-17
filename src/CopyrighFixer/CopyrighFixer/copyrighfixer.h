//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "CopyrighFixer_global.h"
#include "QString"

inline void initCopyrighFixerResources() { Q_INIT_RESOURCE(CopyrighFixer); }

namespace CopyrighFixer {


bool CopyrighFixer_EXPORT init();

/**
 * @brief The InfoOwner class for collect information about owner.
 */
class CopyrighFixer_EXPORT Owner{

public:

    Owner();

private:

    QString name;
    QString timeRange;

};

};
