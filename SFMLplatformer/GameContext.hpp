#pragma once
#include "GameState.hpp"
#include <memory>

class MenuState;
class PlayState;
class PauseState;
class SoundState;
class LevelChoiceState;
class NextLevelState;

struct GameContext {
    GameState currentState = GameState::MENU;

    //TODO
    float musicVolume = 100.f;
    float interfaceVolume = 100.f;
    float sfxVolume = 100.f;

    int currentLevel = 0;
    int score = 0; //TODO

    std::unique_ptr<MenuState> menuState;
    std::unique_ptr<PlayState> playState;
    std::unique_ptr<PauseState> pauseState;
    std::unique_ptr<SoundState> soundState;
    std::unique_ptr<LevelChoiceState> levelChoiceState;
    std::unique_ptr<NextLevelState> nextLevelState;
};
