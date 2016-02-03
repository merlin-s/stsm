#ifndef STATION_TYPE_H_INCLUDED
#define STATION_TYPE_H_INCLUDED

#include <QtCore/qobject.h>
#include <QtCore/qlist.h>

#include "shiptype.h"

class StationType
{
public:
    QString getName() const {
        return name_;
    }
    QList<ShipType> const& getProduceableShipTypes() const {
        return produceableShipTypes_;
    }
    unsigned getDockingPorts() const {
        return dockingPorts_;
    };
private:
    QString name_;
    QList<ShipType> produceableShipTypes_;
    unsigned dockingPorts_;
};

#endif