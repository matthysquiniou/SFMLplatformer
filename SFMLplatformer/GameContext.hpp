#pragma once
#include "GameState.hpp"
#include <memory>

class MenuState;
class PlayState;
class PauseState;
class SoundState;
class LevelChoiceState;

struct GameContext {
    GameState currentState = GameState::MENU;

    float musicVolume = 100.f;
    float interfaceVolume = 100.f;
    float sfxVolume = 100.f;

    int currentLevel = 0;
    int score = 0; // hmmge pour l'instant
    int lives = 3; // hmmge pour l'instant

    std::unique_ptr<MenuState> menuState;
    std::unique_ptr<PlayState> playState;
    std::unique_ptr<PauseState> pauseState;
    std::unique_ptr<SoundState> soundState;
    std::unique_ptr<LevelChoiceState> levelChoiceState;
};
