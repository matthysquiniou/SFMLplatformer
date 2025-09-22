#include "EntityManager.hpp"
#include "Player.hpp"
#include "PlayState.hpp"

void EntityManager::handleEvents(const sf::Event& e, GameContext& ctx) {
    for (auto& entity : entities) entity->handleEvents(e, ctx);
}


void EntityManager::update(float dt, GameContext& ctx) {
    const bool hasWorldBounds = worldBounds.has_value();

    for (auto& entity : entities) {
        if (hasWorldBounds) {
            auto pos = entity->getSprite().getPosition();
            if (!worldBounds->contains(pos)) {
                if (auto player = std::dynamic_pointer_cast<Player>(entity)) {
                    player->respawn();
                }
                else if (!entity->isVisual) {
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

void EntityManager::draw(sf::RenderWindow& window, GameContext& ctx,sf::View& view) {
    sf::FloatRect viewRect = getViewRect(view);

    for (auto& entity : entities) {
        sf::Vector2f pos = entity->getSprite().getPosition();

        if (!viewRect.contains(pos)) continue;

        entity->draw(window, ctx);
    }
}

void EntityManager::clear() {
    entities.clear();
    worldBounds.reset();
}

sf::FloatRect EntityManager::getViewRect(sf::View& view) {
    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();
    return {
        { center.x - (size.x / 2.f) - 64.f,center.y - (size.y / 2.f) - 64.f},
        { size.x + 128.f,size.y + 128.f }
    };
}