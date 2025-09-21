#include "SoundManager.hpp"
#include "Assets.hpp"

void SoundManager::init() {
    auto load = [](SoundName name, const std::string& file, float volume) {
        auto data = std::make_unique<SoundData>();
        if (!data->buffer.loadFromFile(file))
            throw std::runtime_error("Impossible de charger " + file);
        data->baseVolume = volume;
        data->sound.setVolume(volume);
        sounds[name] = std::move(data);
        };

    // UI
    load(SoundName::PUSHED, assetPath(AssetID::SOUND_UI_PUSHED), 10.f);
    load(SoundName::HOVERED, assetPath(AssetID::SOUND_UI_HOVERED), 5.f);

    // Gameplay
    load(SoundName::JUMP, assetPath(AssetID::SOUND_JUMP), 10.f);

    // Music
    load(SoundName::BACKGROUND, assetPath(AssetID::SOUND_MUSIC), 3.f);
    sounds[SoundName::BACKGROUND]->sound.setLooping(true);
}

void SoundManager::play(SoundName sound) {
    sounds[sound]->sound.play();
}

void SoundManager::stop(SoundName sound) {
    sounds[sound]->sound.stop();
}

float SoundManager::getCategoryVolume(SoundName sound) {
    int id = static_cast<int>(sound);
    if (id < 100) return ctx.interfaceVolume;
    if (id < 200) return ctx.sfxVolume;
    return ctx.musicVolume;
}

void SoundManager::updateVolume(SoundName sound) {
    float categoryFactor = getCategoryVolume(sound) / 10.f;
    float masterFactor = ctx.masterVolume / 10.f;
    sounds[sound]->sound.setVolume(sounds[sound]->baseVolume * categoryFactor * masterFactor);
}

void SoundManager::updateVolumes() {
    for (auto& s : sounds) {
        updateVolume(s.first);
    }
}
