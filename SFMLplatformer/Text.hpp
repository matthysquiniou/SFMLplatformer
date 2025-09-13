#pragma once
#include "Entity.hpp"
#include "Assets.hpp"

class Text : public Entity {

public:
    Text(std::string t, unsigned int size, sf::Vector2f pos);

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

private:
    sf::Text text;
};
