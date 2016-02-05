#ifndef QSTR_H_INCLUDED
#define QSTR_H_INCLUDED

#include <QtCore/qstring.h>

inline QString qutf8(const char *utf8str) { return QString::fromUtf8(utf8str); }

#endif
