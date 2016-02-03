#pragma once
#include "gui.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
namespace gui
{
    class SplashScreen
    {
    public:
        void Show(sf::RenderWindow& window);
    };
}