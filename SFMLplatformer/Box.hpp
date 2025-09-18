#pragma once
#include <SFML/Graphics.hpp>

enum class BoxType { Collision, Hurt, Hit };

struct Box {
    sf::FloatRect rect;
    sf::FloatRect relativeRect;
    BoxType type;
    bool active = true;
};
