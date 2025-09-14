#pragma once
#include "PlayState.hpp"

void PlayState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        
        if (e.is<sf::Event::KeyPressed>())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                ctx.currentState = GameState::PAUSE;
                return;
            }
        }

        entityManager.handleEvents(e, ctx);
    }
}

void PlayState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
}

void PlayState::draw(sf::RenderWindow& window, GameContext& ctx) {
    entityManager.draw(window, ctx);
}

void PlayState::loadLevel(unsigned int level) {
    entityManager.clear();

    int levelBase = level / 10;
    int levelAdds = level % 10;

    loadLevelBase(levelBase);
    while (levelAdds>=0)
    {
        loadLevelObj(levelBase * 10 + levelAdds);
        levelAdds--;
    }
}

void PlayState::loadLevelBase(unsigned int levelBase) {
    switch (levelBase)
    {
    case 0:
        entityManager.addEntity<Player>(EntityFactory::makePlayer1({ 100.f,500.f }));
        break;
    case 1:
        entityManager.addEntity<Player>(EntityFactory::makePlayer1({ 100.f,500.f }));
        break;
    case 2:
        entityManager.addEntity<Player>(EntityFactory::makePlayer1({ 100.f,500.f }));
        break;
    case 3:
        entityManager.addEntity<Player>(EntityFactory::makePlayer1({ 100.f,500.f }));
        break;
    case 4:
        entityManager.addEntity<Player>(EntityFactory::makePlayer1({ 100.f,500.f }));
        break;
    default:
        break;
    }
}

void PlayState::loadLevelObj(unsigned int levelObj) {

}