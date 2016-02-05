#include "texturecache.h"
GUI_NS_B
std::unordered_map<std::string, sf::Texture> TextureCache::mtexCache;
sf::Sprite TextureCache::getSprite(const char *name) {
  auto it = mtexCache.find(name);
  if (it == std::end(mtexCache)) {
    const static std::string basepath = "res/tex/";
    sf::Texture &t = mtexCache[name];
    bool loaded = t.loadFromFile(basepath + name);
    runtime_assert(loaded, std::string("failed to load file ") + name);
    return sf::Sprite(t);
  }
  return sf::Sprite(mtexCache[name]);
}
GUI_NS_E
