#ifndef CLICKABLE_H_INCLUDED
#define CLICKABLE_H_INCLUDED

#include "gui.h"

namespace gui {
class Clickable {
public:
  virtual ~Clickable(){};

protected:
  virtual bool
  isMouseEventInInterior(const sf::Event::MouseButtonEvent &event) = 0;
  virtual void onMouseButtonPressed(sf::Mouse::Button) {}
  virtual void onMouseButtonReleased(sf::Mouse::Button) {}

  virtual void onMouseButtonClicked(sf::Mouse::Button) {}
  virtual void onMouseButtonDoubleClicked(sf::Mouse::Button) {}
};
}
#endif
