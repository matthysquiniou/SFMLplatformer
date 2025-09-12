#pragma once
#include "PlayState.hpp"

void PlayState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    //TODO
    if (event->is<sf::Event::KeyPressed>()) {
        ctx.currentState = GameState::PAUSE;
    }
}

void PlayState::update(float dt, GameContext& ctx) {
    //TODO
}

void PlayState::draw(sf::RenderWindow& window, GameContext& ctx) {
    //TODO
    window.clear(sf::Color::Magenta);
}
