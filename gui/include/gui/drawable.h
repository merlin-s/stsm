#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED
#include "gui/gui.h"

/*
* zIndex:
* 0: Background
*
*/

namespace gui
{
    enum class ZINDEX
    {
        Z_BACKGROUND,
        Z_HEXFIELD,
        z_HUD_MAINLAYER,
        Z_HUD_TOPLAYER,
        Z_LAYER_COUNT
    };

    class Drawable {
    public:
        Drawable(const Drawable&) = delete;
        Drawable(Drawable&&) = delete;
        Drawable(ZINDEX z){
            zIndex = z;
        }
        virtual void draw(sf::RenderTarget& window) = 0;
        virtual ~Drawable() {};
    private:
        ZINDEX zIndex;
    };
}

#endif
