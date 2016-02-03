#ifndef CREWMAN_H_INCLUDED
#define CREWMAN_H_INCLUDED

#include <QtCore/qobject.h>
#include "planet.h"

class CrewMan// : public QObject
{
public:
    QString getName() const { return name_; }
    QString getRace() const { return race_; }
    Planet const& getPlanet() const { return planet_;  }
    unsigned getAge() const { return age_; }
private:
    QString name_;
    QString race_;
    Planet planet_;
    unsigned age_;
};


#endif