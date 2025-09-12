#include "EntityManager.hpp"

void EntityManager::handleEvents(const sf::Event& e, GameContext& ctx) {
    for (auto& entity : entities) entity->handleEvents(e, ctx);
}

void EntityManager::update(float dt, GameContext& ctx) {
    for (auto& entity : entities) entity->update(dt, ctx);
}

void EntityManager::draw(sf::RenderWindow& window, GameContext& ctx) {
    for (auto& entity : entities) {
	    entity->draw(window, ctx);
    }
}

void EntityManager::clear() {
    entities.clear();
}
