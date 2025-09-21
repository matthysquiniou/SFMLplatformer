#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <stdexcept>
#include "GameContext.hpp"

class SoundManager {
public:
    SoundManager(GameContext& ctx) : ctx(ctx) {}

    enum class SoundName : int {
        // UI (0-99)
        PUSHED = 0,
        HOVERED = 1,

        // Gameplay (100-199)
        JUMP = 100,
        ENEMY_DEAD = 101,
        QUICK_STEP = 102,
        STEP = 103,
        BREAK = 104,
        CHECKPOINT_TAKE = 105,
        ELECTRICITY = 106,
        FLY = 107,
        GEM_COLECT = 108,
        LEVEL_COMPLETE = 109,
        PLAYER_DEATH = 110,
        RESPAWN = 111,
        SAW = 112,
        SPIKE = 113,
        STOMP = 114,
        STUN = 115,
        SHOT = 116,

        // Music (200-299)
        BACKGROUND = 200
    };

    void init();

    static void play(SoundName sound, bool noReplay = false);
    static void stop(SoundName sound);

    void updateVolumes();

private:
    GameContext& ctx;

    struct SoundData {
        sf::SoundBuffer buffer;
        sf::Sound sound{ buffer };
        float baseVolume;
    };

    inline static std::unordered_map<SoundName, std::unique_ptr<SoundData>> sounds;

    float getCategoryVolume(SoundName sound);
    void updateVolume(SoundName sound);
};
