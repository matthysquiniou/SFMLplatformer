#pragma once
#include "Entity.hpp"
#include "Button.hpp"

class EntityFactory {
public:
    static Button makeBlueButton(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick);

    static Entity makeBackground(const std::string& path);
};
