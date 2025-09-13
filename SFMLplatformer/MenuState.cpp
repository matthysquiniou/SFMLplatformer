#pragma once
#include "MenuState.hpp"

void MenuState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        entityManager.handleEvents(e, ctx);
    }
}

void MenuState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
}

void MenuState::draw(sf::RenderWindow& window, GameContext& ctx) {
    entityManager.draw(window, ctx);
}
