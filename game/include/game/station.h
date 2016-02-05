#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED

#include <QtCore/qobject.h>

class Station {
  Q_PROPERTY(StationType stationType);
  Q_PROPERTY(QString designation);
};

#endif
