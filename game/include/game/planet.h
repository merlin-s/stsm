#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

#include <QtCore/qobject.h>

#include "planetclass.h"

class Planet
{
public:
    QString getName() const;
    PlanetClass getClass() const;
private:
    QString name_;
    PlanetClass class_;
};

#endif