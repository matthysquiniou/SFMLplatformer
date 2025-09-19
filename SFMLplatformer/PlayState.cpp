#pragma once
#include "PlayState.hpp"
#include "PauseState.hpp"

void PlayState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        
        if (e.is<sf::Event::KeyPressed>())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                ctx.pauseState->loadPause();
                ctx.currentState = GameState::PAUSE;
                return;
            }
        }

        entityManager.handleEvents(e, ctx);
    }
}

void PlayState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
    Collision::processAll();
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
        entityManager.addEntity(EntityFactory::makePlayer1({ 100.f,500.f },view));
        for (int i = 0; i < 60; i++) {
            entityManager.addEntity(EntityFactory::makePlatform({ i * 16.f, 550.f }, assetPath(AssetID::PLATFORM_FULL_METAL_1_1)));
        }

        for (int i = 60; i < 150; i++) {
            entityManager.addEntity(EntityFactory::makePlatform({ i * 16.f, 550.f }, assetPath(AssetID::PLATFORM_FULL_METAL_1_1)));
        }

        for (int i = 0; i < 6; i++) {
            entityManager.addEntity(EntityFactory::makePlatform({ 200.f + i * 16.f, 450.f }, assetPath(AssetID::PLATFORM_FULL_METAL_1_1)));
        }

        for (int j = 0; j < 12; j++) {
            entityManager.addEntity(EntityFactory::makePlatform({ 600.f, 534.f - j * 16.f }, assetPath(AssetID::PLATFORM_FULL_METAL_1_1)));
        }
        
        entityManager.addEntity(EntityFactory::makeEnemyFlyer({ 350.f,350.f }));
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}

void PlayState::loadLevelObj(unsigned int levelObj) {

}