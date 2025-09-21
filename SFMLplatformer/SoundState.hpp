#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"
#include "Assets.hpp"

class SoundState : public State {
public:
    SoundState(sf::Vector2u windowSize, sf::View& view) :
        master(getMainFont(), "", 24),
        music(getMainFont(), "", 24),
        sfx(getMainFont(), "", 24),
        interface(getMainFont(), "", 24)
    {
        // BACKGROUND

        for (float x = 0.f; x < windowSize.x; x += 64.f)
        {
            for (float y = 0.f; y < windowSize.y; y += 64.f)
            {
                entityManager.addEntity(EntityFactory::makeVisual(assetPath(AssetID::BG_GREY), { x, y }));
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

        entityManager.addEntity(EntityFactory::makeText("SOUND", 40, titlePos));

        // RETURN MENU BUTTON

        sf::Vector2f buttonMenuPos = { framePos.x + (frameSize.x / 13)*5, framePos.y + (frameSize.y / 7) * 6 };

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "MENU",
            buttonMenuPos,
            [](GameContext& ctx) {
                ctx.currentState = GameState::MENU;
            },
            view)
        );

        // BUTTON SOUND

        sf::Vector2f buttonMaster1 = { framePos.x + frameSize.x / 5, framePos.y + (frameSize.y / 7) * 2 };
        sf::Vector2f buttonMaster2 = { framePos.x + (frameSize.x / 5) * 4, framePos.y + (frameSize.y / 7) * 2 };

        sf::Vector2f buttonMusic1 = { framePos.x + frameSize.x / 5, framePos.y + (frameSize.y / 7) * 3 };
        sf::Vector2f buttonMusic2 = { framePos.x + (frameSize.x / 5) * 4, framePos.y + (frameSize.y / 7) * 3 };

        sf::Vector2f buttonSFX1 = { framePos.x + frameSize.x / 5, framePos.y + (frameSize.y / 7) * 4 };
        sf::Vector2f buttonSFX2 = { framePos.x + (frameSize.x / 5) * 4, framePos.y + (frameSize.y / 7) * 4 };

        sf::Vector2f buttonInterface1 = { framePos.x + frameSize.x / 5, framePos.y + (frameSize.y / 7) * 5 };
        sf::Vector2f buttonInterface2 = { framePos.x + (frameSize.x / 5) * 4, framePos.y + (frameSize.y / 7) * 5 };

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonMaster1,
            [](GameContext& ctx) {
                if (ctx.masterVolume > 0.f) ctx.masterVolume--;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonMaster2,
            [](GameContext& ctx) {
                if (ctx.masterVolume < 10.f) ctx.masterVolume++;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonMusic1,
            [](GameContext& ctx) {
                if (ctx.musicVolume > 0.f) ctx.musicVolume--;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonMusic2,
            [](GameContext& ctx) {
                if (ctx.musicVolume < 10.f) ctx.musicVolume++;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonSFX1,
            [](GameContext& ctx) {
                if (ctx.sfxVolume > 0.f) ctx.sfxVolume--;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonSFX2,
            [](GameContext& ctx) {
                if (ctx.sfxVolume < 10.f) ctx.sfxVolume++;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonInterface1,
            [](GameContext& ctx) {
                if (ctx.interfaceVolume > 0.f) ctx.interfaceVolume--;
            },
            view)
        );

        entityManager.addEntity(EntityFactory::makeTextButtonGrey(
            "",
            buttonInterface2,
            [](GameContext& ctx) {
                if (ctx.interfaceVolume < 10.f) ctx.interfaceVolume++;
            },
            view)
        );

        sf::Vector2f masterPos = { framePos.x + (frameSize.x / 2) - 60.f, framePos.y + (frameSize.y / 7) * 2 - 7.f };
        sf::Vector2f musicPos = { framePos.x + (frameSize.x / 2) - 55.f, framePos.y + (frameSize.y / 7) * 3 - 7.f };
        sf::Vector2f SFXPos = { framePos.x + (frameSize.x / 2) - 40.f, framePos.y + (frameSize.y / 7) * 4 - 7.f };
        sf::Vector2f interfacePos = { framePos.x + (frameSize.x / 2) - 90.f, framePos.y + (frameSize.y / 7) * 5 - 7.f };

        master.setPosition(masterPos);
        music.setPosition(musicPos);
        sfx.setPosition(SFXPos);
        interface.setPosition(interfacePos);
    }

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

private:

    EntityManager entityManager;

    sf::Text master;

    sf::Text music;

    sf::Text sfx;

    sf::Text interface;
};
