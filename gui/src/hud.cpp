#include "gui/hud.h"

namespace gui {

HUD::HUD() : Drawable(ZINDEX::z_HUD_MAINLAYER) {}

HUD::~HUD() {}

void HUD::draw(sf::RenderTarget &window) {}
}
