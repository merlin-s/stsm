#ifndef HEXAGON_H_INCLUDED
#define HEXAGON_H_INCLUDED

#include "gui/clickableimpl.h"
#include "gui/drawable.h"

namespace gui {
enum class HexagonStyle { Normal, Active, OutOfBounds, Count };
class Hexagon : public gui::ClickableImpl, public Drawable {
public:
  Hexagon(HexagonStyle style, int x, int y);
  Hexagon(const Hexagon &) = delete;
  Hexagon(Hexagon &&) = delete;
  ~Hexagon();
  void setPosition(float x, float y);
  void draw(sf::RenderTarget &renderTarget) override;

  static float getBaseSize();
  static float getRowHeight();

  bool isActive() const { return active; }
  void setActive(bool setactive) { active = setactive; }

protected:
  void onMouseButtonPressed(sf::Mouse::Button btn) override;
  bool
  isMouseEventInInterior(const sf::Event::MouseButtonEvent &event) override;

private:
  void setStyle(HexagonStyle);
  bool isInHex(float x, float y) const;

  sf::ConvexShape hex = sf::ConvexShape(6u);
  sf::Text text;
  bool active = false;
};
}

#endif
