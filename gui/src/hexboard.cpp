#include "hexboard.h"

GUI_NS_B
HexBoard::HexBoard()
:Drawable(ZINDEX::Z_HEXFIELD)
{
}
HexBoard::~HexBoard()
{
}

HexBoard::chunk_ptr_t HexBoard::initChunk() const
{
    std::unique_ptr<chunk_t> c(new chunk_t());
    c->resize(HEXBOARD_CHUNK_SIZE * HEXBOARD_CHUNK_SIZE);
    return std::move(c);
}

HexBoard::chunk_t& HexBoard::getChunk(chunk_key_t key)
{
    const auto & it = chunkMap.find(key);
    if (it != chunkMap.end()){
        return *it->second;
    } else {
        auto c = std::move(initChunk());
        chunk_t * ptr = c.get();
        chunkMap.emplace(key, std::move(c));
        return *ptr;
    }
}
Hexagon& HexBoard::getHex(hex_coordinate_t x, hex_coordinate_t y)
{
    hex_coordinate_t cx = x / HEXBOARD_CHUNK_SIZE;
    hex_coordinate_t cy = y / HEXBOARD_CHUNK_SIZE;
    hex_coordinate_t hx = x % HEXBOARD_CHUNK_SIZE;
    hex_coordinate_t hy = y % HEXBOARD_CHUNK_SIZE;
    chunk_t& c = getChunk({ cx, cy });
    const auto idx = hx + hy*HEXBOARD_CHUNK_SIZE;
    if (idx >= 0 && idx <= c.size()) {
        auto & hex = c[idx];
        if (!hex){
            hex.reset(new Hexagon(HexagonStyle::Normal, HEXBOARD_CHUNK_SIZE*cx + hx, HEXBOARD_CHUNK_SIZE*cy + hy));
        }
        return *hex;
    }
    else {
        runtime_assert(false, "invalid hexagon index");
        throw std::runtime_error("");
    }

}
void HexBoard::setScrollPos(float x, float y)
{
    baseScrollX = x;
    baseScrollY = y;
}

float HexBoard::getScrollX() const
{
    return baseScrollX;
}
float HexBoard::getScrollY() const
{
    return baseScrollY;
}

void HexBoard::draw(sf::RenderTarget& renderTarget){
    currentSet.clear();
    const auto wsz = renderTarget.getSize();
    const float aspectRatio = 4.f / 3.f;
    const float hexSize = Hexagon::getBaseSize() / zoomLevel;
    const float hexRowSize = Hexagon::getRowHeight();
    const float fyoffset = (baseScrollY / hexSize);
    const float fxoffset = (baseScrollX / hexSize);
    const hex_coordinate_t yoffset = fyoffset;
    const hex_coordinate_t xoffset = fxoffset;
    const float fyoffsetdiff = hexRowSize * (fyoffset - float(yoffset));
    const float fxoffsetdiff = hexRowSize * (fxoffset - float(xoffset));
    const hex_coordinate_t xcount = 0.091f + wsz.x / hexSize;
    const hex_coordinate_t ycount = 0.091f + (wsz.y * aspectRatio) / hexSize;
    for (hex_coordinate_t y = 0; y < ycount; ++y)
    {
        const bool isEvenRow = (yoffset + y) % 2 == 0;
        const float fy = (hexSize*0.75f) * (y + 0.5f);
        for (hex_coordinate_t x = 0; x < xcount; ++x)
        {
            const float fxEven = hexSize * (x + 0.5f);
            const float fxUneven = hexSize * (x + 1.0f);
            const float fx = isEvenRow ? fxEven : fxUneven;
            Hexagon& hex = HexBoard::getHex(x - xoffset, y - yoffset);
            hex.setPosition(fx + fxoffsetdiff, fy + fyoffsetdiff);
            hex.draw(renderTarget);
            currentSet.emplace_back(&hex);
        }
    }
}
bool HexBoard::handleClick(
    const sf::Event::MouseButtonEvent & event,
    sf::Event::EventType eventType
){
    for (Hexagon * hex : currentSet) {
        if (hex->handleClick(event, eventType)) {
            break;
        }
    }
    return false;
}
GUI_NS_E
