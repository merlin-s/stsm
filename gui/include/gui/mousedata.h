#ifndef MOUSEDATA_H_INCLUDED
#define MOUSEDATA_H_INCLUDED

#include <array>

#include "gui/gui.h"
#include "gui/clickable.h"

namespace gui
{
    class MouseData
    {
    public:
        typedef Clickable ClickableT;

        MouseData(){
            clear();
        }
        ~MouseData(){
        }

        void setPressed(
            ClickableT * obj,
            sf::Mouse::Button btn
        ){
            mbtnobj[btn] = obj;
        }
        bool setReleased(
            ClickableT * obj,
            sf::Mouse::Button btn
        ){
            auto & storedobj = mbtnobj[btn];
            if (!storedobj)
                return false;
            if (storedobj == obj){
                storedobj = nullptr;
                return true;
            }
            return false;
        }
        void clear() {
            mbtnobj.fill(nullptr);
        }
    private:
        std::array<ClickableT *, sf::Mouse::Button::ButtonCount> mbtnobj;
    };
}

#endif