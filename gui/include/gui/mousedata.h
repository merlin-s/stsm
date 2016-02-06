#ifndef MOUSEDATA_H_INCLUDED
#define MOUSEDATA_H_INCLUDED

#include <array>

#include "gui/clickable.h"
#include "gui/gui.h"

namespace gui {
class MouseData {
public:
  typedef Clickable ClickableT;

  MouseData();
  ~MouseData();
  static MouseData *instance();

  void setPressed(ClickableT *obj, sf::Mouse::Button btn);
  bool setReleased(ClickableT *obj, sf::Mouse::Button btn);
  void clear();

private:
  std::array<ClickableT *, sf::Mouse::Button::ButtonCount> mbtnobj;
};
}

#endif
