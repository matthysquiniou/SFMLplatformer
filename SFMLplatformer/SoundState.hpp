#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"

class SoundState : public State {
public:
    SoundState(sf::Vector2u windowSize) {
        // BACKGROUND

        for (float x = 0.f; x < windowSize.x; x += 64.f)
        {
            for (float y = 0.f; y < windowSize.y; y += 64.f)
            {
                entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BG_GREY), { x, y }));
            }
        }

        // FRAME

        sf::Vector2f frameSize = { windowSize.x * 0.4f, windowSize.y * 0.7f };
        sf::Vector2f framePos = {
            (windowSize.x - frameSize.x) / 2.f,
            (windowSize.y - frameSize.y) / 2.f
        };

        const float tile = 16.f;

        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_TOP_LEFT), framePos));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_TOP_RIGHT), { framePos.x + frameSize.x - tile, framePos.y }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_BOTTOM_LEFT), { framePos.x, framePos.y + frameSize.y - tile }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_BOTTOM_RIGHT), { framePos.x + frameSize.x - tile, framePos.y + frameSize.y - tile }));

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_TOP), { x, framePos.y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_BOTTOM), { x, framePos.y + frameSize.y - tile }));
        }

        for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_LEFT), { framePos.x, y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_RIGHT), { framePos.x + frameSize.x - tile, y }));
        }

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
                entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_MIDDLE), { x, y }));
            }
        }

        // TITLE 

        sf::Vector2f titlePos = { framePos.x + frameSize.x / 2, framePos.y + 50.f };

        entityManager.addEntity<Text>(EntityFactory::makeText("SOUND", 40, titlePos));

        // RETURN MENU BUTTON

        sf::Vector2f returnMenuPos = { framePos.x + 50.f, framePos.y + 50.f };

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonGreen(
            "MENU",
            returnMenuPos,
            [](GameContext& ctx) {
                ctx.currentState = GameState::MENU;
            })
        );

        //TODO :: make buttons to change sound value and display the value 
        // music / interface / gameplay 
    }

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

    EntityManager entityManager;
};
