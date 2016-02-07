#include "texturecache.h"

namespace {
const static std::string texture_dir = "res/tex/";
}

namespace gui {
std::unordered_map<std::string, sf::Texture> TextureCache::mtexCache;
sf::Sprite TextureCache::getSprite(const char *name) {
  auto it = mtexCache.find(name);
  if (it == std::end(mtexCache)) {
    sf::Texture &t = mtexCache[name];
    auto path = texture_dir + name;
    bool loaded = t.loadFromFile(path);
    runtime_assert(loaded, std::string("failed to load file ") + path);
    return sf::Sprite(t);
  }
  return sf::Sprite(mtexCache[name]);
}
}
