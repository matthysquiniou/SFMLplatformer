#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"

class CharacterPickingState : public State {
public:
    CharacterPickingState(sf::Vector2u windowSize, sf::View& view) {
        // BACKGROUND

        for (float x = 0.f; x < windowSize.x; x += 64.f)
        {
            for (float y = 0.f; y < windowSize.y; y += 64.f)
            {
                entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::BG_PURPLE), { x, y }));
            }
        }

        // FRAME

        sf::Vector2f frameSize = { windowSize.x * 0.4f, windowSize.y * 0.7f };
        sf::Vector2f framePos = {
            (windowSize.x - frameSize.x) / 2.f,
            (windowSize.y - frameSize.y) / 2.f
        };

        const float tile = 16.f;

        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_TOP_LEFT), framePos));
        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_TOP_RIGHT), { framePos.x + frameSize.x - tile, framePos.y }));
        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_BOTTOM_LEFT), { framePos.x, framePos.y + frameSize.y - tile }));
        entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_BOTTOM_RIGHT), { framePos.x + frameSize.x - tile, framePos.y + frameSize.y - tile }));

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_TOP), { x, framePos.y }));
            entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_BOTTOM), { x, framePos.y + frameSize.y - tile }));
        }

        for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
            entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_LEFT), { framePos.x, y }));
            entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_RIGHT), { framePos.x + frameSize.x - tile, y }));
        }

        for (float x = framePos.x + tile; x < framePos.x + frameSize.x - tile; x += tile) {
            for (float y = framePos.y + tile; y < framePos.y + frameSize.y - tile; y += tile) {
                entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::GRAY_FRAME_MIDDLE), { x, y }));
            }
        }

        // TITLE 

        sf::Vector2f titlePos = { framePos.x + frameSize.x / 2, framePos.y + (frameSize.y / 6) };

        entityManager.addEntity(EntityFactory::makeText("CHARACTER PICKING", 40, titlePos));

        // RETURN MENU BUTTON

        sf::Vector2f buttonMenuPos = { framePos.x + (frameSize.x / 13)*5, framePos.y + (frameSize.y / 6) * 5 };

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "MENU",
            buttonMenuPos,
            [](GameContext& ctx) {
                ctx.currentState = GameState::MENU;
            },
            view)
        );

        // BUTTON PICK

        sf::Vector2f buttonPick1 = { framePos.x + frameSize.x / 5, framePos.y + (frameSize.y / 6) * 3 };
        sf::Vector2f buttonPick2 = { framePos.x + (frameSize.x / 5) * 4, framePos.y + (frameSize.y / 6) * 3 };


        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonPick1,
            [](GameContext& ctx) {
                ctx.character = (ctx.character + 1) % 3 + 1;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonPick2,
            [](GameContext& ctx) {
                ctx.character = ctx.character % 3 + 1;
            },
            view)
        );

        sf::Vector2f characterPos = { framePos.x + (frameSize.x / 2) - 16.f, framePos.y + (frameSize.y / 6) * 3 };

        entityManager.addEntity(EntityFactory::makeCharacterPickingEntity(1, characterPos));
        entityManager.addEntity(EntityFactory::makeCharacterPickingEntity(2, characterPos));
        entityManager.addEntity(EntityFactory::makeCharacterPickingEntity(3, characterPos));

    }

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

private:

    EntityManager entityManager;
};
