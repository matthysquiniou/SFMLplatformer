#pragma once
#include "PauseState.hpp"


void PauseState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;

        if (e.is<sf::Event::KeyPressed>())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                ctx.currentState = GameState::PLAY;
                return;
            }
        }

        entityManager.handleEvents(e, ctx);
    }
}

void PauseState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
}

void PauseState::draw(sf::RenderWindow& window, GameContext& ctx) {
    window.draw(overlay);
    entityManager.draw(window, ctx);
}
