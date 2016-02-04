#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#include "util/debug.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <unordered_set>

#define GUI_NS_B namespace gui {
#define GUI_NS_E }

namespace gui
{
    typedef float Type;
    typedef sf::Rect<Type> Rect;
    struct pairhash {
        template <typename T, typename U>
        std::size_t operator()(const std::pair<T, U> &x) const {
            return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        }
    };
}

#endif
