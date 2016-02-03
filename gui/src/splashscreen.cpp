#include "splashscreen.h"
#include "texturecache.h"

GUI_NS_B
void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
    sf::Sprite sprite = TextureCache::getSprite("splashscreen.png");

    renderWindow.draw(sprite);
    renderWindow.display();

    sf::Event event;
    while (true)
    {
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::KeyPressed
                || event.type == sf::Event::EventType::MouseButtonPressed
                || event.type == sf::Event::EventType::Closed)
            {
                return;
            }
        }
    }
}
GUI_NS_E