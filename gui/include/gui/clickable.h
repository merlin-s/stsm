#ifndef CLICKABLE_H_INCLUDED
#define CLICKABLE_H_INCLUDED

#include "gui.h"

namespace gui {
class Clickable {
public:
  Clickable() = default;
  virtual ~Clickable(){};
  Clickable(Clickable const &) = delete;
  Clickable &operator=(Clickable const &) = delete;

  bool handleClick(const sf::Event::MouseButtonEvent &event,
                   sf::Event::EventType eventType);

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
