#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include "gui/gui.h"
#include "gui/drawable.h"

namespace gui
{
    class HUD : public Drawable
    {
    public:
        HUD();
        virtual void draw(sf::RenderTarget& window) override;
        ~HUD();
    private:
    };
}

#endif