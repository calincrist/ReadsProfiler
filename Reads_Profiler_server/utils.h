#ifndef UTILS_H
#define UTILS_H

#include <QDebug>
#include <QString>

class Utils
{
public:
    Utils();

    static const char* qtStringToChar(QString text);
    static QString charToQtString(char *text);

};

#endif // UTILS_H
