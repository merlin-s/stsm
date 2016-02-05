#ifndef IMGLOADER_H_DEFINED
#define IMGLOADER_H_DEFINED
#include "gui.h"
#include <string>
#include <unordered_map>

namespace gui {
class TextureCache {
public:
  static sf::Sprite getSprite(const char *name);

private:
  static std::unordered_map<std::string, sf::Texture> mtexCache;
};
}

#endif
