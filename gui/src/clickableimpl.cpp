#include "gui/clickableimpl.h"
GUI_NS_B

MouseData ClickableImpl::mouseData;

bool ClickableImpl::handleClick(
    const sf::Event::MouseButtonEvent& event,
    sf::Event::EventType eventType
) {
    if (isMouseEventInInterior(event)) {
        auto button = event.button;
        switch (eventType){
            case sf::Event::MouseButtonPressed:
                mouseData.setPressed(this, button);
                onMouseButtonPressed(button);
                break;
            case sf::Event::MouseButtonReleased:
                onMouseButtonReleased(button);
                if (mouseData.setReleased(this, button)){
                    onMouseButtonClicked(button);
                }
                break;
        };
        return true;
    }
    return false;
}
GUI_NS_E