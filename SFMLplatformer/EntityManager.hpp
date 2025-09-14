#pragma once
#include <vector>
#include <memory>
#include "Entity.hpp"

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;

public:
    template<typename T, typename... Args>
    T& addEntity(Args&&... args) {
        auto ptr = std::make_shared<T>(std::forward<Args>(args)...);
        entities.push_back(ptr);
        return *ptr;
    }


    void handleEvents(const sf::Event& e, GameContext& ctx);
    void update(float dt, GameContext& ctx);
    void draw(sf::RenderWindow& window, GameContext& ctx);
    void clear();
};
