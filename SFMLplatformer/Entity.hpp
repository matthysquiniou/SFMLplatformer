#pragma once
#include "SpriteComposite.hpp"
#include "GameContext.hpp"

class Entity {
protected:
    SpriteComposite sprite;

public:
    Entity() : sprite{} {}
    Entity(SpriteComposite s) : sprite(std::move(s)) {}
    virtual ~Entity() = default;

    virtual void handleEvents(const sf::Event& e, GameContext& ctx) {}
    virtual void update(float dt, GameContext& ctx) {
        if (sprite.isAnimationGoing())
        {
            sprite.update(dt);
        }
    }
    virtual void draw(sf::RenderWindow& window, GameContext& ctx) {
        window.draw(sprite);
    }

    SpriteComposite& getSprite() { return sprite; }
};