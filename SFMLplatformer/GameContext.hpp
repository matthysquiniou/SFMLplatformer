#pragma once
#include "GameState.hpp"
#include <memory>

class MenuState;
class PlayState;
class PauseState;
class SoundState;
class LevelChoiceState;
class NextLevelState;
class CharacterPickingState;

struct GameContext {
    GameState currentState = GameState::MENU;

    float masterVolume = 10.f;
    float musicVolume = 10.f;
    float interfaceVolume = 10.f;
    float sfxVolume = 10.f;

    int character = 1;
    int currentLevel = 0;
    int score = 0;

    std::unique_ptr<MenuState> menuState;
    std::unique_ptr<PlayState> playState;
    std::unique_ptr<PauseState> pauseState;
    std::unique_ptr<SoundState> soundState;
    std::unique_ptr<LevelChoiceState> levelChoiceState;
    std::unique_ptr<NextLevelState> nextLevelState;
    std::unique_ptr<CharacterPickingState> characterPickingState;
};
