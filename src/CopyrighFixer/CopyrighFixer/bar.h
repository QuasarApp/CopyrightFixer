#ifndef BAR_H
#define BAR_H

#include "CopyrighFixer_global.h"
#include <QString>
#include <iostream>

namespace CopyrighFixer  {
/**
 * @brief The Bar class acts as a test case, which
 * outputs the Hello world!
 */

class CopyrighFixer_EXPORT Bar
{
public:
    Bar();

 /**
 * @brief foo Method that returns Hello world
 * @return QString messsage
 */
QString foo() const;

};

}

#endif // BAR_H
