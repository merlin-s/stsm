#ifndef CLICKABLEIMPL_H_INCLUDED
#define CLICKABLEIMPL_H_INCLUDED

#include "gui/gui.h"
#include "gui/mousedata.h"

namespace gui {
    class ClickableImpl : public Clickable {
    public:
        virtual ~ClickableImpl() = 0;
        bool handleClick(
            const sf::Event::MouseButtonEvent& event,
            sf::Event::EventType eventType
            );
    protected:
    private:
        static MouseData mouseData;
    };
}
#endif
