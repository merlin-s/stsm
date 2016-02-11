#ifndef IMGLOADER_H_DEFINED
#define IMGLOADER_H_DEFINED
#include "gui.h"

namespace gui {
class TextureCache {
public:
  static sf::Sprite getSprite(const char *name);
};
}

#endif
