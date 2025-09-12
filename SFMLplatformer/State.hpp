#pragma once
#include "GameContext.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

class State {
public:
    virtual void handleEvents(std::optional<sf::Event> event, GameContext& ctx) = 0;
    virtual void update(float dt, GameContext& ctx) = 0;
    virtual void draw(sf::RenderWindow& window, GameContext& ctx) = 0;

    virtual ~State() = default;
};