#include "planetclass.h"
#include "util/qstr.h"

#include <array>

PlanetClass const& PlanetClass::create(Enum pc)
{
    static const PlanetClass pc_array[] =
    {
        Enum::Y,
        Enum::T,
        Enum::M,
        Enum::L,
        Enum::K,
        Enum::J,
        Enum::H,
        Enum::D,
        Enum::G6,
        Enum::G7,
        Enum::G9
    };
    return pc_array[(int)pc];
}

PlanetClass const& PlanetClass::getRandom()
{
    throw "TODO";
}

PlanetClass::PlanetClass(Enum clasz)
:class_(clasz)
{
    switch (class_){
        case Enum::Y:
            designation_ = qutf8("Y");
            description_ = qutf8("\"demon class\" - toxic gases, extreme surface temperatures");
            break;
        case Enum::T:
            designation_ = qutf8("T");
            description_ = qutf8("gas giant");
            break;
        case Enum::M:
            designation_ = qutf8("M");
            description_ = qutf8("nitrogen and oxygen based atmosphere, large areas of surface water, supports humanoid life");
            break;
        case Enum::L:
            designation_ = qutf8("L");
            description_ = qutf8("marginally habitable, oxygen based atmosphere, rough temperatures");
            break;
        case Enum::K:
            designation_ = qutf8("K");
            description_ = qutf8("solid surface, small amounts of surface water, can support humanoid life using supportive technology or terraforming");
            break;
        case Enum::J:
            designation_ = qutf8("J");
            description_ = qutf8("gas giant, atmosphere consisting of gaseous hyrogen compounds and zones varying in temperature and composition.");
            break;
        case Enum::H:
            designation_ = qutf8("H");
            description_ = qutf8("desert planet, unhabitable, geological active, no surface water");
            break;
        case Enum::D:
            designation_ = qutf8("D");
            description_ = qutf8("asteroid or moon, no atmosphere");
            break;
        case Enum::G6:
            designation_ = qutf8("G6");
            description_ = qutf8("gas giant");
            break;
        case Enum::G7:
            designation_ = qutf8("G7");
            description_ = qutf8("gas giant");
            break;
        case Enum::G9:
            designation_ = qutf8("G9");
            description_ = qutf8("gas giant");
            break;
        default: break;
    }
}
