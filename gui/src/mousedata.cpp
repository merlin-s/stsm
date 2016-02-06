#include "mousedata.h"

namespace gui {
MouseData::MouseData() { clear(); }
MouseData::~MouseData() {}

MouseData *MouseData::instance() {
  static std::unique_ptr<MouseData> ptr;
  if (!ptr)
    ptr.reset(new MouseData());
  return &*ptr;
}

void MouseData::setPressed(ClickableT *obj, sf::Mouse::Button btn) {
  mbtnobj[btn] = obj;
}
bool MouseData::setReleased(ClickableT *obj, sf::Mouse::Button btn) {
  if (!mbtnobj[btn])
    return false;
  if (mbtnobj[btn] == obj) {
    mbtnobj[btn] = nullptr;
    return true;
  }
  return false;
}
void MouseData::clear() { mbtnobj.fill(nullptr); }
}
