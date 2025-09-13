#include "Game.hpp"

void Game::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        handleEvents();
        update(dt);
        draw();
    }
}

void Game::handleEvents() {
    while (auto event = window.pollEvent()) {
        const sf::Event& e = *event;
        if (e.is<sf::Event::Closed>()) {
            window.close();
        }
        
        switch (ctx.currentState) {
        case GameState::MENU:
            ctx.menuState->handleEvents(event, ctx);
            break;

        case GameState::PLAY:
            ctx.playState->handleEvents(event, ctx);
            break;

        case GameState::PAUSE:
            ctx.pauseState->handleEvents(event, ctx);
            break;

        case GameState::SOUND:
            ctx.soundState->handleEvents(event, ctx);
            break;

        case GameState::LEVEL_CHOICE:
            ctx.levelChoiceState->handleEvents(event, ctx);
            break;

        default:
            break;
        }
    }
}

void Game::update(float dt) {
    switch (ctx.currentState) {
    case GameState::MENU:
        ctx.menuState->update(dt, ctx);
        break;

    case GameState::PLAY:
        ctx.playState->update(dt, ctx);
        break;

    case GameState::PAUSE:
        ctx.pauseState->update(dt, ctx);
        break;

    case GameState::SOUND:
        ctx.soundState->update(dt, ctx);
        break;

    case GameState::LEVEL_CHOICE:
        ctx.levelChoiceState->update(dt, ctx);
        break;

    case GameState::EXIT:
        window.close();
        break;

    default:
        break;
    }
}

void Game::draw() {
    window.clear();

    switch (ctx.currentState) {
    case GameState::MENU:
        ctx.menuState->draw(window, ctx);
        break;

    case GameState::PLAY:
        ctx.playState->draw(window, ctx);
        break;

    case GameState::PAUSE:
        ctx.pauseState->draw(window, ctx);
        break;

    case GameState::SOUND:
        ctx.soundState->draw(window, ctx);
        break;

    case GameState::LEVEL_CHOICE:
        ctx.levelChoiceState->draw(window, ctx);
        break;

    default:
        break;
    }

    window.display();
}