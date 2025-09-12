#pragma once
#include "LevelChoiceState.hpp"


void LevelChoiceState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    //TODO
    if (event->is<sf::Event::KeyPressed>()) {
        ctx.currentState = GameState::MENU;
    }
}

void LevelChoiceState::update(float dt, GameContext& ctx) {
    //TODO
}

void LevelChoiceState::draw(sf::RenderWindow& window, GameContext& ctx) {
    //TODO
    window.clear(sf::Color::Cyan);
}
