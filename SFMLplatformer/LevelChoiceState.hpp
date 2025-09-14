#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"

class LevelChoiceState : public State {
public:
    LevelChoiceState(sf::Vector2u windowSize) {
        // BACKGROUND

        for (float x = 0.f; x < windowSize.x; x += 64.f)
        {
            for (float y = 0.f; y < windowSize.y; y += 64.f)
            {
                entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::BG_GREEN), { x, y }));
            }
        }

        // FRAME

        sf::Vector2f frameSize = { windowSize.x * 0.8f, windowSize.y * 0.8f };
        sf::Vector2f framePos = {
            (windowSize.x - frameSize.x) / 2.f,
            (windowSize.y - frameSize.y) / 2.f
        };

        const float tile = 16.f;

        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_TOP_LEFT), framePos));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_TOP_RIGHT), { framePos.x + frameSize.x - tile, framePos.y }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_BOTTOM_LEFT), { framePos.x, framePos.y + frameSize.y - tile }));
        entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_BOTTOM_RIGHT), { framePos.x + frameSize.x - tile, framePos.y + frameSize.y - tile }));
        
        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_TOP), { x, framePos.y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_BOTTOM), { x, framePos.y + frameSize.y - tile }));
        }

        for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_LEFT), { framePos.x, y }));
            entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_RIGHT), { framePos.x + frameSize.x - tile, y }));
        }

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
                entityManager.addEntity<Entity>(EntityFactory::makeVisual(assetPath(AssetID::GREEN_FRAME_MIDDLE), { x, y }));
            }
        }

        // TITLE 

        sf::Vector2f titlePos = { framePos.x + frameSize.x / 2, framePos.y + 50.f };

        entityManager.addEntity<Text>(EntityFactory::makeText("LEVELS", 40, titlePos));

        // RETURN MENU BUTTON

        sf::Vector2f returnMenuPos = { framePos.x + 50.f, framePos.y + 50.f };

        entityManager.addEntity<Button>(EntityFactory::makeTextButtonGreen(
            "MENU",
            returnMenuPos,
            [](GameContext& ctx) {
                ctx.currentState = GameState::MENU;
            })
        );

        // LEVEL BUTTON

        const int totalLevels = 50;
        const int buttonsPerRow = 10;

        const float buttonSpacingY = (frameSize.y - (titlePos.y - framePos.y)) / ((totalLevels / buttonsPerRow) + 1);
        const float buttonSpacingX = frameSize.x / (buttonsPerRow + 1);

        sf::Vector2f startLevelButtonPos = { framePos.x + buttonSpacingX, titlePos.y + buttonSpacingY };

        for (int i = 1; i <= totalLevels; ++i) {
            int row = (i - 1) / buttonsPerRow;
            int col = (i - 1) % buttonsPerRow;

            sf::Vector2f buttonPos = {
                startLevelButtonPos.x + col * buttonSpacingX,
                startLevelButtonPos.y + row * buttonSpacingY
            };

            entityManager.addEntity<Button>(
                EntityFactory::makeLevelButton(i, buttonPos)
            );
        }

    }

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

private:
    EntityManager entityManager;
};