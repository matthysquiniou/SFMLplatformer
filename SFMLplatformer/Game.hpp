#pragma once
#include <SFML/Graphics.hpp>
#include "GameContext.hpp"
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "PauseState.hpp"
#include "SoundState.hpp"
#include "LevelChoiceState.hpp"

class Game {
public:
    Game() {
        sf::Vector2u windowSize = { 1280, 720 };
        window = sf::RenderWindow(sf::VideoMode(windowSize), "Platformer");
        window.setVerticalSyncEnabled(true);
        ctx.menuState = std::make_unique<MenuState>(windowSize);
        ctx.playState = std::make_unique<PlayState>();
        ctx.pauseState = std::make_unique<PauseState>();
        ctx.soundState = std::make_unique<SoundState>(windowSize);
        ctx.levelChoiceState = std::make_unique<LevelChoiceState>(windowSize);
    }

    void run();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    GameContext ctx;

    void handleEvents();
    void update(float dt);
    void draw();
};