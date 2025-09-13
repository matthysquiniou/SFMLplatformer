#pragma once
#include "SoundState.hpp"


void SoundState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        entityManager.handleEvents(e, ctx);
    }
}

void SoundState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
}

void SoundState::draw(sf::RenderWindow& window, GameContext& ctx) {
    entityManager.draw(window, ctx);
}
