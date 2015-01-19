#include "utils.h"

Utils::Utils()
{
}

const char* Utils::qtStringToChar(QString text)
{
    QByteArray ba = text.toLatin1();
    const char *c_str = ba.data();

    return c_str;
}

QString Utils::charToQtString(char *text)
{
    return QString(QLatin1String(text));

}
