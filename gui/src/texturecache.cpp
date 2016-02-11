#include "texturecache.h"

#include <string>
#include <map>

using namespace std;

namespace {
const static string texture_dir = "res/tex/";
map<string, sf::Texture> mtexCache;
}

namespace gui {
sf::Sprite TextureCache::getSprite(const char* name)
{
    auto it = mtexCache.find(name);
    if (it == end(mtexCache)) {
        sf::Texture& t = mtexCache[name];
        auto path = texture_dir + name;
        bool loaded = t.loadFromFile(path);
        runtime_assert(loaded, string("failed to load file ") + path);
        return sf::Sprite(t);
    }
    return sf::Sprite(mtexCache[name]);
}
}
