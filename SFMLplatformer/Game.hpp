#pragma once
#include <SFML/Graphics.hpp>
#include "GameContext.hpp"
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "PauseState.hpp"
#include "SoundState.hpp"
#include "LevelChoiceState.hpp"
#include "NextLevelState.hpp"
#include "CharacterPickingState.hpp"
#include "SoundManager.hpp"

class Game {
public:
    Game(): soundManager(ctx) {
        sf::Vector2u windowSize = { 1280, 720 };
        window = sf::RenderWindow(sf::VideoMode(windowSize), "Platformer");
        window.setVerticalSyncEnabled(true);

        view = sf::View({ static_cast<float>(windowSize.x / 2), static_cast<float>(windowSize.y / 2) }, { static_cast<float>(windowSize.x), static_cast<float>(windowSize.y) });

        ctx.menuState = std::make_unique<MenuState>(windowSize, view);
        ctx.playState = std::make_unique<PlayState>(windowSize, view);
        ctx.pauseState = std::make_unique<PauseState>(view);
        ctx.soundState = std::make_unique<SoundState>(windowSize, view);
        ctx.levelChoiceState = std::make_unique<LevelChoiceState>(windowSize, view);
        ctx.nextLevelState = std::make_unique<NextLevelState>(view);
        ctx.characterPickingState = std::make_unique<CharacterPickingState>(windowSize, view);

        soundManager.init();

        SoundManager::play(SoundManager::SoundName::BACKGROUND);
    }
    void run();

private:
    sf::RenderWindow window;
    sf::View view;
    sf::Clock clock;
    SoundManager soundManager;
    GameContext ctx;

    void handleEvents();
    void update(float dt);
    void draw();
};