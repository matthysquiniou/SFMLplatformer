#pragma once
#include "Entity.hpp"
#include "Button.hpp"
#include "Text.hpp"

class EntityFactory {
public:
    static Text makeText(std::string text, unsigned int size, sf::Vector2f pos);

    static Entity makeVisual(const std::string& path, sf::Vector2f pos);

    static Button makeTextButtonBlue(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick);

    static Button makeTextButtonOrange(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick);

    static Button makeTextButtonGreen(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick);

    static Button makeLevelButton(unsigned int level, sf::Vector2f pos);
};
