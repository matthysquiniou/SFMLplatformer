#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <stdexcept>

class SoundManager {
public:
    enum class SoundName : int {
        // UI (0-99)
        Click = 0,
        Hover = 1,

        // Gameplay (100-199)
        Destruction = 100,
        Explosion = 101,
        Hit = 102,
        Rocket = 103,
        Swoosh = 104,

        // Music (200-299)
        Background = 200
    };

    static void init();

    static void play(SoundName sound, bool loop = false);
    static void stop(SoundName sound);

    // Réglages utilisateur
    static void setMasterVolume(float v);     // 0–100
    static void setUiVolume(float v);         // 0–100
    static void setGameplayVolume(float v);   // 0–100
    static void setMusicVolume(float v);      // 0–100

private:
    struct SoundData {
        sf::SoundBuffer buffer;
        sf::Sound sound{ buffer };
        float baseVolume; // le volume “par défaut” défini au chargement
    };

    inline static std::unordered_map<SoundName, SoundData> sounds;
    inline static bool initialized = false;

    // volumes courants (facteur global)
    inline static float masterVolume = 100.f;
    inline static float uiVolume = 100.f;
    inline static float gameplayVolume = 100.f;
    inline static float musicVolume = 100.f;

    static float getCategoryVolume(SoundName sound);
    static void updateVolume(SoundName sound);
};
