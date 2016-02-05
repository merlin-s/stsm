#ifndef HEXBOARD_H_INCLUDED
#define HEXBOARD_H_INCLUDED
#include "gui.h"
#include "hexagon.h"
#include "mousedata.h"

#include <list>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

namespace gui {
const unsigned HEXBOARD_CHUNK_SIZE = 100;
typedef int hex_coordinate_t;
class HexBoard : public Drawable {
public:
  HexBoard();
  ~HexBoard();
  Hexagon &getHex(hex_coordinate_t x, hex_coordinate_t y);
  void draw(sf::RenderTarget &renderTarget) override;
  bool handleClick(const sf::Event::MouseButtonEvent &event,
                   sf::Event::EventType eventType);
  void setScrollPos(float x, float y);
  float getScrollX() const;
  float getScrollY() const;

private:
  using chunk_t = std::vector<std::unique_ptr<Hexagon>>;
  using chunk_ptr_t = std::unique_ptr<chunk_t>;
  using chunk_key_t = std::pair<hex_coordinate_t, hex_coordinate_t>;
  using chunk_map_t = std::unordered_map<chunk_key_t, chunk_ptr_t, pairhash>;

  chunk_map_t chunkMap;
  std::vector<Hexagon *> currentSet;
  float zoomLevel = 1.f;
  float baseScrollX = 0.f;
  float baseScrollY = 0.f;

private:
  chunk_ptr_t initChunk() const;
  chunk_t &getChunk(chunk_key_t key);
};
}

#endif
