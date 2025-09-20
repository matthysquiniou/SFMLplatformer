#include "EntityManager.hpp"

void EntityManager::handleEvents(const sf::Event& e, GameContext& ctx) {
    for (auto& entity : entities) entity->handleEvents(e, ctx);
}

void EntityManager::update(float dt, GameContext& ctx) {
    for (auto& entity : entities) {
        if (entity->deleteIt)
        {
            entities.erase(
                std::remove_if(entities.begin(), entities.end(),
                    [](auto& e) { return e->deleteIt; }),
                entities.end()
            );
            return;
        }
        entity->update(dt, ctx);
    }
}

void EntityManager::draw(sf::RenderWindow& window, GameContext& ctx) {
    for (auto& entity : entities) {
	    entity->draw(window, ctx);
    }
}

void EntityManager::clear() {
    entities.clear();
}
