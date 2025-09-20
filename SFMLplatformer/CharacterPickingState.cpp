#pragma once
#include "CharacterPickingState.hpp"

void CharacterPickingState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        entityManager.handleEvents(e, ctx);
    }
}

void CharacterPickingState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
}

void CharacterPickingState::draw(sf::RenderWindow& window, GameContext& ctx) {
    entityManager.draw(window, ctx);
}
