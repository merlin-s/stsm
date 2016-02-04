#ifndef PLANETCLASS_H_INCLUDED
#define PLANETCLASS_H_INCLUDED

#include <QtCore/qobject.h>

class PlanetClass
{
public:
    enum class Enum : unsigned
    {
        FIRST,
        Y = FIRST,
        T,
        M, //supports life
        L, //supports life
        K, //maybe supports life
        J,
        H, //desert
        D,
        G6,
        G7,
        G9,
        LAST = G9,
        COUNT = LAST + 1
    };
    static PlanetClass const& create(Enum pc);
    static PlanetClass const& getRandom();
    QString getDesignation() const { return designation_; }
    QString getDescription() const { return description_; }
private:
    PlanetClass(Enum clasz);
    PlanetClass(PlanetClass&) = delete;
    PlanetClass(PlanetClass&&) = default;
    PlanetClass& operator=(PlanetClass const &) = delete;
    PlanetClass& operator=(PlanetClass &&) = default;
    Enum class_;
    QString designation_;
    QString description_;
};

#endif
