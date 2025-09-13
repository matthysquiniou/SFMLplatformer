#pragma once
#include "LevelChoiceState.hpp"


void LevelChoiceState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        entityManager.handleEvents(e, ctx);
    }
}

void LevelChoiceState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
}

void LevelChoiceState::draw(sf::RenderWindow& window, GameContext& ctx) {
    entityManager.draw(window, ctx);
}
