#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"

class MenuState : public State {
public:

    MenuState(sf::Vector2u windowSize) {

        // BACKGROUND

        for (float x = 0.f; x < windowSize.x; x+=64.f)
        {
            for (float y = 0.f; y < windowSize.y; y += 64.f)
            {
                entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BG_ORANGE), { x, y }));
            }
        }

        // FRAME

        sf::Vector2f frameSize = { 400.f,450.f };
        sf::Vector2f framePos = {
            (windowSize.x - frameSize.x) / 2.f,
            (windowSize.y - frameSize.y) / 2.f
        };

        const float tile = 16.f;

        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_TOP_LEFT), framePos));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_TOP_RIGHT), { framePos.x + frameSize.x - tile, framePos.y }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_BOTTOM_LEFT), { framePos.x, framePos.y + frameSize.y - tile }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_BOTTOM_RIGHT), { framePos.x + frameSize.x - tile, framePos.y + frameSize.y - tile }));

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_TOP), { x, framePos.y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_BOTTOM), { x, framePos.y + frameSize.y - tile }));
        }

        for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_LEFT), { framePos.x, y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_RIGHT), { framePos.x + frameSize.x - tile, y }));
        }

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
                entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BRICK_FRAME_MIDDLE), { x, y }));
            }
        }

        // TITLE 

        sf::Vector2f titlePos = { framePos.x + frameSize.x / 2, framePos.y + (frameSize.y / 7) };

        entityManager.addEntity<Text>(EntityFactory::makeText("PLATFORMER", 40, titlePos));

        // BUTTONS

        sf::Vector2f buttonPos1 = { framePos.x + 100.f, framePos.y + (frameSize.y / 5) * 2 };
        sf::Vector2f buttonPos2 = { framePos.x + 100.f, framePos.y + (frameSize.y / 5) * 3 };
        sf::Vector2f buttonPos3 = { framePos.x + 100.f, framePos.y + (frameSize.y / 5) * 4 };

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonOrange(
            "LEVELS",
            buttonPos1,
            [](GameContext& ctx) {
               ctx.currentState = GameState::LEVEL_CHOICE;
            })
        );

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonOrange(
            "SOUND",
            buttonPos2,
            [](GameContext& ctx) {
                ctx.currentState = GameState::SOUND;
            })
        );

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonOrange(
            "EXIT",
            buttonPos3,
            [](GameContext& ctx) {
                ctx.currentState = GameState::EXIT;
            })
        );
       
    }

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

    EntityManager entityManager;
};