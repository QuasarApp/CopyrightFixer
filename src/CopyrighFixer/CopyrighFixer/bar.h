#ifndef BAR_H
#define BAR_H

#include <QString>
#include <iostream>

class Bar
{
public:
    Bar();
    QString bar = "Hello WORLD!";

QString foo(){
    return this->bar;
}

};

#endif // BAR_H
