#pragma once
#include <vector>
#include <memory>
#include "Entity.hpp"

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;

public:
    void addEntity(std::shared_ptr<Entity> e) {
        entities.push_back(e);
    }

    void handleEvents(const sf::Event& e, GameContext& ctx);
    void update(float dt, GameContext& ctx);
    void draw(sf::RenderWindow& window, GameContext& ctx);
    void clear();
};
