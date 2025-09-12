#pragma once
#include "PauseState.hpp"


void PauseState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    //TODO
    if (event->is<sf::Event::KeyPressed>()) {
        ctx.currentState = GameState::SOUND;
    }
}

void PauseState::update(float dt, GameContext& ctx) {
    //TODO
}

void PauseState::draw(sf::RenderWindow& window, GameContext& ctx) {
    //TODO
    window.clear(sf::Color::Yellow);
}
