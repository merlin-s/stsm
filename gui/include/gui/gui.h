#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#include "util/debug.h"
#include <SFML/Graphics.hpp>
#include <cstdint>

namespace gui {
using RelType = float;
using RelRect = sf::Rect<RelType>;
using AbsType = int32_t;
using AbsRect = sf::Rect<AbsType>;
}

#endif
