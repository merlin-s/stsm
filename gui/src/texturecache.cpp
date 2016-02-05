#include "texturecache.h"
GUI_NS_B
std::unordered_map<std::string, sf::Texture> TextureCache::mtexCache;
sf::Sprite TextureCache::getSprite(const char *name) {
  auto it = mtexCache.find(name);
  if (it == std::end(mtexCache)) {
    const static std::string basepath = "res/tex/";
    sf::Texture &t = mtexCache[name];
    auto path = basepath + name;
    bool loaded = t.loadFromFile(path);
    runtime_assert(loaded, std::string("failed to load file ") + path);
    return sf::Sprite(t);
  }
  return sf::Sprite(mtexCache[name]);
}
GUI_NS_E
