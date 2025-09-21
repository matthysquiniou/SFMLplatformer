#include "EntityManager.hpp"
#include "Player.hpp"
#include "PlayState.hpp"

void EntityManager::handleEvents(const sf::Event& e, GameContext& ctx) {
    for (auto& entity : entities) entity->handleEvents(e, ctx);
}

void EntityManager::update(float dt, GameContext& ctx) {
    for (auto& entity : entities) {
        if (worldBounds.has_value()) {
            auto pos = entity->getSprite().getPosition();
            if (!worldBounds->contains(pos)) {
                if (auto player = std::dynamic_pointer_cast<Player>(entity)) {
                    player->respawn();
                }
                else {
                    entity->deleteIt = true;
                }
            }
        }
        entity->update(dt, ctx);
    }
    entities.erase(
        std::remove_if(entities.begin(), entities.end(),
            [](auto& e) { return e->deleteIt; }),
        entities.end()
    );
}

void EntityManager::draw(sf::RenderWindow& window, GameContext& ctx) {
    for (auto& entity : entities) {
	    entity->draw(window, ctx);
    }
}

void EntityManager::clear() {
    entities.clear();
    worldBounds.reset();
}
