#pragma once
#include "SoundState.hpp"


void SoundState::handleEvents(std::optional<sf::Event> event, GameContext& ctx) {
    if (event.has_value()) {
        const sf::Event& e = *event;
        entityManager.handleEvents(e, ctx);
    }
}

void SoundState::update(float dt, GameContext& ctx) {
    entityManager.update(dt, ctx);
    master.setString("MASTER : " + std::to_string(static_cast<int>(ctx.masterVolume)));
    music.setString("MUSIC : "+std::to_string(static_cast<int>(ctx.musicVolume)));
    sfx.setString("SFX : " + std::to_string(static_cast<int>(ctx.sfxVolume)));
    interface.setString("INTERFACE : " + std::to_string(static_cast<int>(ctx.interfaceVolume)));
}

void SoundState::draw(sf::RenderWindow& window, GameContext& ctx) {
    entityManager.draw(window, ctx);
    window.draw(master);
    window.draw(music);
    window.draw(sfx);
    window.draw(interface);
}
