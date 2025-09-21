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
    load(SoundName::ENEMY_DEAD, assetPath(AssetID::SOUND_ENEMY_DEAD), 10.f);
    load(SoundName::QUICK_STEP, assetPath(AssetID::SOUND_QUICK_STEP), 10.f);
    sounds[SoundName::QUICK_STEP]->sound.setLooping(true);
    load(SoundName::STEP, assetPath(AssetID::SOUND_STEP), 5.f);
    sounds[SoundName::STEP]->sound.setLooping(true);
    load(SoundName::BREAK, assetPath(AssetID::SOUND_BREAK), 10.f);
    load(SoundName::CHECKPOINT_TAKE, assetPath(AssetID::SOUND_CHECKPOINT_TAKE), 10.f);
    load(SoundName::ELECTRICITY, assetPath(AssetID::SOUND_ELECTRICITY), 10.f);
    load(SoundName::FLY, assetPath(AssetID::SOUND_FLY), 10.f);
    sounds[SoundName::FLY]->sound.setLooping(true);
    load(SoundName::GEM_COLECT, assetPath(AssetID::SOUND_GEM_COLECT), 10.f);
    load(SoundName::LEVEL_COMPLETE, assetPath(AssetID::SOUND_LEVEL_COMPLETE), 10.f);
    load(SoundName::PLAYER_DEATH, assetPath(AssetID::SOUND_PLAYER_DEATH), 10.f);
    load(SoundName::RESPAWN, assetPath(AssetID::SOUND_RESPAWN), 10.f);
    load(SoundName::SAW, assetPath(AssetID::SOUND_SAW), 10.f);
    load(SoundName::SPIKE, assetPath(AssetID::SOUND_SPIKE), 10.f);
    load(SoundName::STOMP, assetPath(AssetID::SOUND_STOMP), 10.f);
    load(SoundName::STUN, assetPath(AssetID::SOUND_STUN), 10.f);
    load(SoundName::SHOT, assetPath(AssetID::SOUND_SHOT), 10.f);

    // Music
    load(SoundName::BACKGROUND, assetPath(AssetID::SOUND_MUSIC), 3.f);
    sounds[SoundName::BACKGROUND]->sound.setLooping(true);
}

void SoundManager::play(SoundName sound,bool noReplay) {
    if (sounds[sound]->sound.getStatus() == sf::SoundSource::Status::Playing && (sounds[sound]->sound.isLooping() || noReplay)) return;
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
