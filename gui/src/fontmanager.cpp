#include "gui/fontmanager.h"

#include <map>

namespace gui {
namespace {
const char *fontnames[] = {"res/fonts/arial.ttf"};
std::map<FontType, sf::Font> fontmap;
}

void FontManager::init() {
  for (int i = 0; i < static_cast<int>(FontType::Count); ++i) {
    sf::Font f;
    if (!f.loadFromFile(fontnames[i])) {
      runtime_assert(false, "failed to load font");
    }
    fontmap[FontType(i)] = f;
  }
}
sf::Font &FontManager::getFont(FontType fonttype) { return fontmap[fonttype]; }
}
