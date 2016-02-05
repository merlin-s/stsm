#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED
#include "gui/gui.h"

#include <type_traits>

/*
* zIndex:
* 0: Background
*
*/

namespace gui {
enum class ZINDEX {
  Z_BACKGROUND,
  Z_HEXFIELD,
  z_HUD_MAINLAYER,
  Z_HUD_TOPLAYER,
  Z_LAYER_COUNT
};

class Drawable {
public:
  Drawable() = default;
  Drawable(const Drawable &) = delete;
  Drawable(Drawable &&) = delete;
  explicit Drawable(ZINDEX z) { zIndex = static_cast<decltype(zIndex)>(z); }
  virtual void draw(sf::RenderTarget &window) = 0;
  virtual ~Drawable(){};

private:
  std::underlying_type<ZINDEX>::type zIndex;
};
}

#endif
