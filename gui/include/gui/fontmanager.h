#ifndef FONTMANAGER_H_INCLUDED
#define FONTMANAGER_H_INCLUDED
#include "gui/gui.h"

namespace gui
{
    enum class FontType : int
    {
        Normal = 0,
        Count
    };
    class FontManager
    {
    public:
        static void init();
        static sf::Font& getFont(FontType);
    };
}
#endif