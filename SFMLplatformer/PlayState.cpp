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
    score.setString(std::to_string(ctx.score));

    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewSize = view.getSize();

    score.setPosition({ viewCenter.x - (viewSize.x/2) + 20,viewCenter.y - (viewSize.y / 2) + 20 });
}

void PlayState::draw(sf::RenderWindow& window, GameContext& ctx) {
    entityManager.draw(window, ctx);
    window.draw(score);
}

void PlayState::loadLevel(unsigned int level, int character) {
    entityManager.clear();

    int levelBase = level / 10;
    int levelAdds = level % 10;

    loadLevelBase(levelBase, character);
    while (levelAdds>=0)
    {
        loadLevelObj(levelBase * 10 + levelAdds);
        levelAdds--;
    }
}

void PlayState::loadLevelBase(unsigned int levelBase, int character) {
    switch (levelBase)
    {
    case 0:
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
        
        // entityManager.addEntity(EntityFactory::makeEnemyCanon({ 350.f,350.f }, entityManager));

        entityManager.addEntity(EntityFactory::makeCheckpoint2({ 1000.f,500.f }));

        entityManager.addEntity(EntityFactory::makeFragilePlatform({ 300.f,300.f }));

        entityManager.addEntity(EntityFactory::makeGem({ 300.f,280.f }, 1));
        entityManager.addEntity(EntityFactory::makeGem({ 320.f,280.f }, 2));
        entityManager.addEntity(EntityFactory::makeGem({ 340.f,280.f }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 360.f,280.f }, 4));
        entityManager.addEntity(EntityFactory::makeGem({ 380.f,280.f }, 5));
        entityManager.addEntity(EntityFactory::makeGem({ 400.f,280.f }, 6));

        entityManager.addEntity(EntityFactory::makeCup({ 400.f,380.f }));

        entityManager.addEntity(EntityFactory::makeTrap({ 400.f,330.f },Trap::ELECTRICITY,true));

        loadPlayer(character, { 100.f,500.f });

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

void PlayState::loadPlayer(int character,sf::Vector2f pos) {
    switch (character)
    {
    case 1:
        entityManager.addEntity(EntityFactory::makePlayer1(pos, view));
        break;
    case 2:
        entityManager.addEntity(EntityFactory::makePlayer2(pos, view));
        break;
    case 3:
        entityManager.addEntity(EntityFactory::makePlayer3(pos, view));
        break;
    default:
        break;
    }
}