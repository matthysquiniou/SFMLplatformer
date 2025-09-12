#pragma once
#include "State.hpp"

class LevelChoiceState : public State {
public:
    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;
};