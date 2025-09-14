#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"
#include "PlayState.hpp"

class PauseState : public State {
public:
    PauseState(sf::Vector2u windowSize) {

        // OVERLAY
        overlay = sf::RectangleShape({ static_cast<float>(windowSize.x) , static_cast<float>(windowSize.y) });
        overlay.setFillColor(sf::Color(128, 128, 128, 150));

        // FRAME

        sf::Vector2f frameSize = { windowSize.x * 0.4f, windowSize.y * 0.7f };
        sf::Vector2f framePos = {
            (windowSize.x - frameSize.x) / 2.f,
            (windowSize.y - frameSize.y) / 2.f
        };

        const float tile = 16.f;

        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_TOP_LEFT), framePos));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_TOP_RIGHT), { framePos.x + frameSize.x - tile, framePos.y }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_BOTTOM_LEFT), { framePos.x, framePos.y + frameSize.y - tile }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_BOTTOM_RIGHT), { framePos.x + frameSize.x - tile, framePos.y + frameSize.y - tile }));

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_TOP), { x, framePos.y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_BOTTOM), { x, framePos.y + frameSize.y - tile }));
        }

        for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_LEFT), { framePos.x, y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_RIGHT), { framePos.x + frameSize.x - tile, y }));
        }

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
                entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::WARN_FRAME_MIDDLE), { x, y }));
            }
        }

        // TITLE 

        sf::Vector2f titlePos = { framePos.x + frameSize.x / 2, framePos.y + (frameSize.y / 5) };

        entityManager.addEntity<Text>(EntityFactory::makeText("PAUSED", 40, titlePos));

        // BUTTON

        sf::Vector2f buttonPos1 = { framePos.x + frameSize.x / 3, framePos.y + (frameSize.y / 5) * 2 };
        sf::Vector2f buttonPos2 = { framePos.x + frameSize.x / 3, framePos.y + (frameSize.y / 5) * 3 };
        sf::Vector2f buttonPos3 = { framePos.x + frameSize.x / 3, framePos.y + (frameSize.y / 5) * 4 };

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonYellow(
            "RESUME",
            buttonPos1,
            [](GameContext& ctx) {
                ctx.currentState = GameState::PLAY;
            })
        );

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonYellow(
            "RESTART",
            buttonPos2,
            [](GameContext& ctx) {
                ctx.playState->loadLevel(ctx.currentLevel);
                ctx.currentState = GameState::PLAY;
            })
        );

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonYellow(
            "LEVELS",
            buttonPos3,
            [](GameContext& ctx) {
                ctx.currentState = GameState::LEVEL_CHOICE;
            })
        );
    }

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

private:

    EntityManager entityManager;

    sf::RectangleShape overlay;
};