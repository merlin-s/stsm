#include "gui/clickable.h"
#include "gui/mousedata.h"

#include <cassert>

namespace gui {

bool Clickable::handleClick(const sf::Event::MouseButtonEvent &event,
                            sf::Event::EventType eventType) {
  if (isMouseEventInInterior(event)) {
    auto button = event.button;
    switch (eventType) {
    case sf::Event::MouseButtonPressed:
      MouseData::instance()->setPressed(this, button);
      onMouseButtonPressed(button);
      break;
    case sf::Event::MouseButtonReleased:
      onMouseButtonReleased(button);
      if (MouseData::instance()->setReleased(this, button)) {
        onMouseButtonClicked(button);
      }
      break;
    default:
      assert(!"Unhandled Enum Value");
    };
    return true;
  }
  return false;
}
}
