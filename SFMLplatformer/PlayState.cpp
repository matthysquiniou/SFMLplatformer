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
    entityManager.draw(window, ctx, view);
    window.draw(score);
}

void PlayState::loadLevel(unsigned int level, int character) {
    entityManager.clear();

    level--;

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
    float blockSize = 16.f;
    sf::FloatRect bounds1 = { {-1000.f,-1000.f},{16000.f,2000.f} };
    auto addPlatform1 = [&](float px, float py, int count, bool makeVisual)
        {
            loadPlatform(bounds1,
                { px, py },
                count,
                assetPath(AssetID::PLATFORM_GRASS_1_TOP_LEFT),
                assetPath(AssetID::PLATFORM_GRASS_1_TOP),
                assetPath(AssetID::PLATFORM_GRASS_1_TOP_RIGHT),
                makeVisual,
                assetPath(AssetID::PLATFORM_GRASS_1_MIDDLE_LEFT),
                assetPath(AssetID::PLATFORM_GRASS_1_MIDDLE),
                assetPath(AssetID::PLATFORM_GRASS_1_MIDDLE_RIGHT)
            );
        };

    switch (levelBase)
    {
    case 0:
        loadBackgroundAndBounds(bounds1, assetPath(AssetID::BG_YELLOW));

        addPlatform1(0.f, 0.f, 20, true);
        addPlatform1(40.f * blockSize, 0.f * blockSize, 10, true);
        addPlatform1(30.f * blockSize, 10.f * blockSize, 30, true);
        addPlatform1(80.f * blockSize, 20.f * blockSize, 40, true);
        addPlatform1(120.f * blockSize, 25.f * blockSize, 5, true);
        addPlatform1(130.f * blockSize, 25.f * blockSize, 5, true);
        addPlatform1(140.f * blockSize, 25.f * blockSize, 5, true);
        addPlatform1(150.f * blockSize, 25.f * blockSize, 5, true);
        addPlatform1(160.f * blockSize, 25.f * blockSize, 5, true);
        addPlatform1(170.f * blockSize, 25.f * blockSize, 5, true);
        addPlatform1(180.f * blockSize, 25.f * blockSize, 5, true);
        addPlatform1(230.f * blockSize, 0.f * blockSize, 5, true);
        addPlatform1(210.f * blockSize, 10.f * blockSize, 40, true);
        addPlatform1(270.f * blockSize, 0.f * blockSize, 3, true);
        addPlatform1(290.f * blockSize, 0.f * blockSize, 3, true);
        addPlatform1(310.f * blockSize, 0.f * blockSize, 3, true);
        addPlatform1(330.f * blockSize, 0.f * blockSize, 3, true);
        addPlatform1(350.f * blockSize, 0.f * blockSize, 3, true);
        addPlatform1(370.f * blockSize, 0.f * blockSize, 3, true);
        addPlatform1(400.f * blockSize, 10.f * blockSize, 3, true);
        addPlatform1(430.f * blockSize, 20.f * blockSize, 3, true);
        addPlatform1(460.f * blockSize, 30.f * blockSize, 3, true);
        addPlatform1(495.f * blockSize, 15.f * blockSize, 5, true);
        addPlatform1(480.f * blockSize, 30.f * blockSize, 30, true);
        addPlatform1(520.f * blockSize, 20.f * blockSize, 20, true);
        addPlatform1(550.f * blockSize, 10.f * blockSize, 20, true);
        addPlatform1(580.f * blockSize, 0.f * blockSize, 20, true);
        addPlatform1(610.f * blockSize, -10.f * blockSize, 20, true);
        addPlatform1(680.f * blockSize, -20.f * blockSize, 5, true);
        addPlatform1(640.f * blockSize, -10.f * blockSize, 50, true);
        addPlatform1(710.f * blockSize, -10.f * blockSize, 2, true);
        addPlatform1(720.f * blockSize, -10.f * blockSize, 2, true);
        addPlatform1(730.f * blockSize, -10.f * blockSize, 2, true);
        addPlatform1(740.f * blockSize, -10.f * blockSize, 2, true);
        addPlatform1(750.f * blockSize, -10.f * blockSize, 2, true);
        addPlatform1(760.f * blockSize, -10.f * blockSize, 2, true);
        addPlatform1(800.f * blockSize, 20.f * blockSize, 20, true);
        addPlatform1(830.f * blockSize, 5.f * blockSize, 5, true);

        entityManager.addEntity(EntityFactory::makeGem({ 121.f * blockSize, 23.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 123.f * blockSize, 23.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 125.f * blockSize, 23.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeGem({ 170.f * blockSize, 23.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 172.f * blockSize, 23.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 174.f * blockSize, 23.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeGem({ 290.f * blockSize, -2.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 292.f * blockSize, -2.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeGem({ 350.f * blockSize, -2.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 352.f * blockSize, -2.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeGem({ 480.f * blockSize, 28.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 482.f * blockSize, 28.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 484.f * blockSize, 28.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 486.f * blockSize, 28.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 488.f * blockSize, 28.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 490.f * blockSize, 28.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeGem({ 550.f * blockSize, 8.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 552.f * blockSize, 8.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 554.f * blockSize, 8.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 556.f * blockSize, 8.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeGem({ 670.f * blockSize, -12.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 672.f * blockSize, -12.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 674.f * blockSize, -12.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 676.f * blockSize, -12.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeGem({ 760.f * blockSize, -12.f * blockSize }, 3));
        entityManager.addEntity(EntityFactory::makeGem({ 762.f * blockSize, -12.f * blockSize }, 3));

        entityManager.addEntity(EntityFactory::makeCheckpoint2({ 230.f * blockSize, -3.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeCheckpoint2({ 495.f * blockSize, 12.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeCup({ 830.f * blockSize, 1.f * blockSize }));

        loadPlayer(character, { 50.f,-75.f });
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
    float blockSize = 16.f;

    switch (levelObj)
    {
    case 0:
        entityManager.addEntity(EntityFactory::makeEnemyCactus({ 35.f * blockSize, 5.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeEnemyCactus({ 490.f * blockSize, 25.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeEnemyCactus({ 650.f * blockSize, -5.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeEnemyCactus({ 810.f * blockSize, 15.f * blockSize }));
        break;
    case 1:
        entityManager.addEntity(EntityFactory::makeTrap({ 139.f * blockSize, 22.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 140.f * blockSize, 22.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 141.f * blockSize, 22.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 142.f * blockSize, 22.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 143.f * blockSize, 22.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 144.f * blockSize, 22.f * blockSize }, Trap::SPIKE, false));

        entityManager.addEntity(EntityFactory::makeTrap({ 459.f * blockSize, 27.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 460.f * blockSize, 27.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 461.f * blockSize, 27.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 462.f * blockSize, 27.f * blockSize }, Trap::SPIKE, false));

        entityManager.addEntity(EntityFactory::makeTrap({ 729.f * blockSize, -13.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 730.f * blockSize, -13.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 731.f * blockSize, -13.f * blockSize }, Trap::SPIKE, false));
        break;
    case 2:
        entityManager.addEntity(EntityFactory::makeTrap({ 209.f * blockSize, 7.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 210.f * blockSize, 7.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 211.f * blockSize, 7.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 212.f * blockSize, 7.f * blockSize }, Trap::SPIKE, false));

        entityManager.addEntity(EntityFactory::makeTrap({ 349.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 350.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 351.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 352.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));

        entityManager.addEntity(EntityFactory::makeTrap({ 679.f * blockSize, -23.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 680.f * blockSize, -23.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 681.f * blockSize, -23.f * blockSize }, Trap::SPIKE, false));
        break;
    case 3:
        entityManager.addEntity(EntityFactory::makeEnemyBarrel({ 85.f * blockSize, 15.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeEnemyBarrel({ 525.f * blockSize, 15.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeEnemyBarrel({ 615.f * blockSize, -5.f * blockSize }));
        break;
    case 4:
        entityManager.addEntity(EntityFactory::makeTrap({ 170.f * blockSize, 22.f * blockSize }, Trap::SAW, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 370.f * blockSize, -3.f * blockSize }, Trap::SAW, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 720.f * blockSize, -13.f * blockSize }, Trap::SAW, false));
        break;
    case 5:
        entityManager.addEntity(EntityFactory::makeTrap({ 123.f * blockSize, 22.f * blockSize }, Trap::ELECTRICITY, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 290.f * blockSize, -3.f * blockSize }, Trap::ELECTRICITY, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 550.f * blockSize, 7.f * blockSize }, Trap::ELECTRICITY, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 740.f * blockSize, -13.f * blockSize }, Trap::ELECTRICITY, false));
        break;
    case 6:
        entityManager.addEntity(EntityFactory::makeTrap({ 329.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 330.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 331.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 332.f * blockSize, -3.f * blockSize }, Trap::SPIKE, false));

        entityManager.addEntity(EntityFactory::makeTrap({ 519.f * blockSize, 17.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 520.f * blockSize, 17.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 521.f * blockSize, 17.f * blockSize }, Trap::SPIKE, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 522.f * blockSize, 17.f * blockSize }, Trap::SPIKE, false));
        break;
    case 7:
        entityManager.addEntity(EntityFactory::makeTrap({ 123.f * blockSize, 22.f * blockSize }, Trap::ELECTRICITY, false));
        entityManager.addEntity(EntityFactory::makeTrap({ 740.f * blockSize, -13.f * blockSize }, Trap::ELECTRICITY, false));
        break;
    case 8:
        entityManager.addEntity(EntityFactory::makeEnemyBarrel({ 525.f * blockSize, 15.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeEnemyCactus({ 220.f * blockSize, 5.f * blockSize }));
        break;
    case 9:
        entityManager.addEntity(EntityFactory::makeEnemyCactus({ 50.f * blockSize, 5.f * blockSize }));
        entityManager.addEntity(EntityFactory::makeEnemyCactus({ 500.f * blockSize, 25.f * blockSize }));
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    case 16:
        break;
    case 17:
        break;
    case 18:
        break;
    case 19:
        break;
    case 20:
        break;
    case 21:
        break;
    case 22:
        break;
    case 23:
        break;
    case 24:
        break;
    case 25:
        break;
    case 26:
        break;
    case 27:
        break;
    case 28:
        break;
    case 29:
        break;
    case 30:
        break;
    case 31:
        break;
    case 32:
        break;
    case 33:
        break;
    case 34:
        break;
    case 35:
        break;
    case 36:
        break;
    case 37:
        break;
    case 38:
        break;
    case 39:
        break;
    case 40:
        break;
    case 41:
        break;
    case 42:
        break;
    case 43:
        break;
    case 44:
        break;
    case 45:
        break;
    case 46:
        break;
    case 47:
        break;
    case 48:
        break;
    case 49:
        break;
    default:
        break;
    }

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

void PlayState::loadBlocLine(std::string path, float blockSize, int blockNumber, sf::Vector2f startPos, bool isX) {
    if (isX)
    {
        for (int i = 0; i < blockNumber; i++) {
            entityManager.addEntity(EntityFactory::makePlatform({ i * blockSize + startPos.x, startPos.y }, path));
        }
    }
    else {
        for (int i = 0; i < blockNumber; i++) {
            entityManager.addEntity(EntityFactory::makePlatform({ startPos.x, i * blockSize + startPos.y }, path));
        }
    }
}

void PlayState::loadVisualLine(std::string path, float blockSize, int blockNumber, sf::Vector2f startPos, bool isX) {
    if (isX)
    {
        for (int i = 0; i < blockNumber; i++) {
            entityManager.addEntity(EntityFactory::makeVisual(path, { i * blockSize + startPos.x, startPos.y }));
        }
    }
    else {
        for (int i = 0; i < blockNumber; i++) {
            entityManager.addEntity(EntityFactory::makeVisual(path, { startPos.x, i * blockSize + startPos.y }));
        }
    }
}

void PlayState::loadBackgroundAndBounds(sf::FloatRect rect, std::string path) {
    for (float x = rect.position.x - (rect.size.x / 2); x < (rect.position.x + rect.size.x * 1.5f); x += 64.f)
    {
        for (float y = rect.position.y - (rect.size.y / 2); y < (rect.position.y + rect.size.y * 1.5f); y += 64.f)
        {
            entityManager.addEntity(EntityFactory::makeVisual(path, { x, y }));
        }
    }

    entityManager.setWorldBounds(rect);
}

void PlayState::loadPlatform(
    sf::FloatRect bounds,
    sf::Vector2f startPos,
    int blockNumber,
    std::string pathStart,
    std::string pathMiddle,
    std::string pathEnd,
    bool loadVisual,
    std::string pathVStart,
    std::string pathVMiddle,
    std::string pathVEnd
) {
    float blockSize = 16.f;

    entityManager.addEntity(EntityFactory::makePlatform({ startPos.x, startPos.y }, pathStart));

    loadBlocLine(pathMiddle, blockSize, blockNumber, { startPos.x + blockSize, startPos.y });

    entityManager.addEntity(EntityFactory::makePlatform({ startPos.x + blockNumber * blockSize, startPos.y }, pathEnd));

    if (!loadVisual) return;

    for (float y = startPos.y + blockSize; y < bounds.position.y + bounds.size.y; y += blockSize) {
        entityManager.addEntity(EntityFactory::makeVisual(pathVStart, { startPos.x, y }));
        loadVisualLine(pathVMiddle, blockSize, blockNumber, { startPos.x + blockSize, y });
        entityManager.addEntity(EntityFactory::makeVisual(pathVEnd, { startPos.x + blockNumber * blockSize, y }));
    }
}