#pragma once
#include "SpriteComposite.hpp"
#include "GameContext.hpp"
#include "Box.hpp"

enum class EntityType { Player, Enemy, Platform, Entity };

class Entity {

protected:
    SpriteComposite sprite;

public:
    Entity() : sprite{} {}
    Entity(SpriteComposite s) : sprite(std::move(s)) {}
    virtual ~Entity() = default;

    virtual void doCollision() {}

    virtual void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {}
    virtual EntityType getType() { return EntityType::Entity; }

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