#pragma once
#include <vector>
#include <memory>
#include <optional>
#include "Entity.hpp"

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::optional<sf::FloatRect> worldBounds; 

public:
    void setWorldBounds(const sf::FloatRect& bounds) { worldBounds = bounds; }
    void addEntity(std::shared_ptr<Entity> e) {
        entities.push_back(e);
    }

    void handleEvents(const sf::Event& e, GameContext& ctx);
    void update(float dt, GameContext& ctx);
    void draw(sf::RenderWindow& window, GameContext& ctx);
    void clear();
};
