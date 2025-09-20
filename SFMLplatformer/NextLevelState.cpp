#pragma once
#include "NextLevelState.hpp"


void NextLevelState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        entityManager.handleEvents(e, ctx);
    }
}

void NextLevelState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
}

void NextLevelState::draw(sf::RenderWindow& window, GameContext& ctx) {
    window.draw(overlay);
    entityManager.draw(window, ctx);
}

void NextLevelState::loadNextLevel(GameContext& ctx) {
    entityManager.clear();

    float viewSizeX = view.getSize().x;
    float viewSizeY = view.getSize().y;
    sf::Vector2f viewCenter = view.getCenter();
    float viewPositionX = view.getCenter().x - (viewSizeX / 2);
    float viewPositionY = view.getCenter().y - (viewSizeY / 2);

    // OVERLAY
    overlay = sf::RectangleShape({ static_cast<float>(viewSizeX) , static_cast<float>(viewSizeY) });
    overlay.setFillColor(sf::Color(128, 128, 128, 150));
    overlay.setPosition({ viewPositionX, viewPositionY });

    // FRAME

    sf::Vector2f frameSize = { viewSizeX * 0.4f, viewSizeY * 0.7f };
    sf::Vector2f framePos = {
        ((viewSizeX - frameSize.x) / 2.f) + viewPositionX,
        ((viewSizeY - frameSize.y) / 2.f) + viewPositionY
    };

    const float tile = 16.f;

    entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_TOP_LEFT), framePos));
    entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_TOP_RIGHT), { framePos.x + frameSize.x - tile, framePos.y }));
    entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_BOTTOM_LEFT), { framePos.x, framePos.y + frameSize.y - tile }));
    entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_BOTTOM_RIGHT), { framePos.x + frameSize.x - tile, framePos.y + frameSize.y - tile }));

    for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_TOP), { x, framePos.y }));
        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_BOTTOM), { x, framePos.y + frameSize.y - tile }));
    }

    for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_LEFT), { framePos.x, y }));
        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_RIGHT), { framePos.x + frameSize.x - tile, y }));
    }

    for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
        for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
            entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_MIDDLE), { x, y }));
        }
    }

    // TITLE 

    sf::Vector2f titlePos = { framePos.x + frameSize.x / 2, framePos.y + (frameSize.y / 5) };

    entityManager.addEntity(EntityFactory::makeText("LEVEL WON", 40, titlePos));

    // BUTTON

    sf::Vector2f buttonPos1 = { framePos.x + frameSize.x / 3, framePos.y + (frameSize.y / 5) * 2 };
    sf::Vector2f buttonPos2 = { framePos.x + frameSize.x / 3, framePos.y + (frameSize.y / 5) * 3 };
    sf::Vector2f buttonPos3 = { framePos.x + frameSize.x / 3, framePos.y + (frameSize.y / 5) * 4 };

    if (ctx.currentLevel != 50)
    {
        entityManager.addEntity(EntityFactory::makeTextButtonYellow(
            "NEXT LEVEL",
            buttonPos1,
            [](GameContext& ctx) {
                ctx.playState->loadLevel(ctx.currentLevel++);
                ctx.currentState = GameState::PLAY;
            },
            view)
        );
    }

    entityManager.addEntity(EntityFactory::makeTextButtonYellow(
        "RESTART",
        buttonPos2,
        [](GameContext& ctx) {
            ctx.playState->loadLevel(ctx.currentLevel);
            ctx.currentState = GameState::PLAY;
        },
        view)
    );

    entityManager.addEntity(EntityFactory::makeTextButtonYellow(
        "LEVELS",
        buttonPos3,
        [this](GameContext& ctx) {
            ctx.currentState = GameState::LEVEL_CHOICE;
            sf::Vector2f size = this->view.getSize();
            this->view.setCenter({ size.x/2.f,size.y/2.f});
        },
        view)
    );
}