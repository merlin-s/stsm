#include "gui/hexagon.h"
#include "gui/fontmanager.h"
#include <QString>

GUI_NS_B
const float hexBaseSizeH = 24.f;
const float hexBaseSize = hexBaseSizeH * 2.f;
const float hexRowSize = hexBaseSize * 3.f / 4.f;

const sf::Color ACTIVECOLOR(0,125,255,120);

Hexagon::Hexagon(HexagonStyle style, int x, int y)
:Drawable(ZINDEX::Z_HEXFIELD)
{
    hex.setPoint(0, { 1.0f*hexBaseSizeH, 0.5f*hexBaseSizeH });
    hex.setPoint(1, { 0.0f*hexBaseSizeH, 1.0f*hexBaseSizeH });
    hex.setPoint(2, { -1.0f*hexBaseSizeH, 0.5f*hexBaseSizeH });
    hex.setPoint(3, { -1.0f*hexBaseSizeH, -0.5f*hexBaseSizeH });
    hex.setPoint(4, { 0.0f*hexBaseSizeH, -1.0f*hexBaseSizeH });
    hex.setPoint(5, { 1.0f*hexBaseSizeH, -0.5f*hexBaseSizeH });
    hex.setFillColor(sf::Color::Transparent);
    setStyle(style);
    hex.setOutlineThickness(1.f);
    hex.setOrigin(0.f, 0.f);
    QString q = QString::fromLatin1("%1.%2").arg(x).arg(y);
    sf::String s = q.toLatin1().data();
    text.setString(s);
    text.setFont(FontManager::getFont(FontType::Normal));
    text.setColor(sf::Color::White);
    text.setCharacterSize(10);
}
Hexagon::~Hexagon()
{

}
void Hexagon::setPosition(float x, float y)
{
    hex.setPosition(x, y);
    text.setPosition(x - 10, y);
}
void Hexagon::draw(
    sf::RenderTarget& renderTarget
){
    renderTarget.draw(hex);
    renderTarget.draw(text);

}
bool Hexagon::isMouseEventInInterior(
    const sf::Event::MouseButtonEvent& event
){
    bool inhex = isInHex(event.x, event.y);
    if (inhex && event.button == sf::Mouse::Button::Left) {
    }
    return inhex;
}

void Hexagon::onMouseButtonPressed(sf::Mouse::Button btn){
    if (btn == sf::Mouse::Button::Left){
        if (active) {
            active = false;
            setStyle(HexagonStyle::Normal);
        }
        else {
            active = true;
            setStyle(HexagonStyle::Active);
        }
    }
}
float Hexagon::getBaseSize()
{
    return hexBaseSize;
}

float Hexagon::getRowHeight()
{
    return hexRowSize;
}

void Hexagon::setStyle(HexagonStyle style)
{
    switch (style)
    {
    case HexagonStyle::Normal:
        hex.setOutlineColor(sf::Color::Cyan);
        hex.setFillColor(sf::Color::Transparent);
        break;
    case HexagonStyle::Active:
        hex.setFillColor(ACTIVECOLOR);
        break;
    case HexagonStyle::OutOfBounds:
        hex.setOutlineColor(sf::Color::Red);
        break;
    }
}

bool Hexagon::isInHex(float posx, float posy) const
{
    const auto _center = hex.getPosition();
    const float q2x = fabs(posx - _center.x);
    const float q2y = fabs(posy - _center.y);
    const float h = hexBaseSizeH;
    const float v = h / 2;
    // bounding test (since q2 is in quadrant 2 only 2 tests are needed)
    // finally the dot product can be reduced to this due to the hexagon symmetry
    if (q2x > h || q2y > v * 2)
        return false; 
    return 2 * v * h - v * q2x - h * q2y >= 0;
}
GUI_NS_E