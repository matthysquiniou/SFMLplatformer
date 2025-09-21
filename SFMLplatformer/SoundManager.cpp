#include "SoundManager.hpp"

void SoundManager::init() {
    auto load = [](SoundName name, const std::string& file, float volume) {
        SoundData data;
        if (!data.buffer.loadFromFile(file))
            throw std::runtime_error("Impossible de charger " + file);
        data.sound.setBuffer(data.buffer);
        data.baseVolume = volume;
        sounds[name] = std::move(data);
        updateVolume(name);
        };

    // UI
    load(SoundName::Click, "assets/sound/ui_click.wav", 50.f);
    load(SoundName::Hover, "assets/sound/ui_hover.wav", 30.f);

    // Gameplay
    load(SoundName::Destruction, "assets/sound/destruction.wav", 10.f);
    load(SoundName::Explosion, "assets/sound/explosion.wav", 10.f);
    load(SoundName::Hit, "assets/sound/hit.wav", 10.f);
    load(SoundName::Rocket, "assets/sound/rocket.wav", 1.5f);
    load(SoundName::Swoosh, "assets/sound/swoosh.wav", 60.f);

    // Music
    load(SoundName::Background, "assets/sound/background.mp3", 2.f);
    sounds[SoundName::Background].sound.setLooping(true);

    initialized = true;
}

void SoundManager::play(SoundName sound, bool loop) {
    if (!initialized)
        throw std::runtime_error("SoundManager non initialisé !");
    sounds[sound].sound.setLooping(loop);
    sounds[sound].sound.play();
}

void SoundManager::stop(SoundName sound) {
    if (!initialized)
        throw std::runtime_error("SoundManager non initialisé !");
    sounds[sound].sound.stop();
}

float SoundManager::getCategoryVolume(SoundName sound) {
    int id = static_cast<int>(sound);
    if (id < 100) return uiVolume;
    if (id < 200) return gameplayVolume;
    return musicVolume;
}

void SoundManager::updateVolume(SoundName sound) {
    float categoryFactor = getCategoryVolume(sound) / 100.f;
    float masterFactor = masterVolume / 100.f;
    sounds[sound].sound.setVolume(sounds[sound].baseVolume * categoryFactor * masterFactor);
}

void SoundManager::setMasterVolume(float v) {
    masterVolume = v;
    for (auto& [name, data] : sounds) updateVolume(name);
}
void SoundManager::setUiVolume(float v) {
    uiVolume = v;
    for (auto& [name, data] : sounds)
        if (static_cast<int>(name) < 100) updateVolume(name);
}
void SoundManager::setGameplayVolume(float v) {
    gameplayVolume = v;
    for (auto& [name, data] : sounds)
        if (static_cast<int>(name) >= 100 && static_cast<int>(name) < 200) updateVolume(name);
}
void SoundManager::setMusicVolume(float v) {
    musicVolume = v;
    for (auto& [name, data] : sounds)
        if (static_cast<int>(name) >= 200 && static_cast<int>(name) < 300) updateVolume(name);
}
