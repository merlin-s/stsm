#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include "gui/drawable.h"
#include "gui/gui.h"

namespace gui {
class HUD : public Drawable {
public:
  HUD();
  virtual void draw(sf::RenderTarget &window) override;
  ~HUD();

private:
};
}

#endif
