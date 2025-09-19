#pragma once
#include <SFML/Graphics.hpp>

enum class BoxType { Collision, Hurt, Hit, CollisionObserver };

struct Box {
    sf::FloatRect rect;
    sf::FloatRect relativeRect;
    BoxType type;
    bool active = true;
    int observerID = -1;
};
