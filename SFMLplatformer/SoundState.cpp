#pragma once
#include "SoundState.hpp"


void SoundState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    //TODO
    if (event->is<sf::Event::KeyPressed>()) {
        ctx.currentState = GameState::LEVEL_CHOICE;
    }
}

void SoundState::update(float dt, GameContext& ctx) {
    //TODO
}

void SoundState::draw(sf::RenderWindow& window, GameContext& ctx) {
    //TODO
    window.clear(sf::Color::Red);
}
