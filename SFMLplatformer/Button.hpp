#pragma once
#include "Entity.hpp"
#include "Assets.hpp"
#include <functional>

class Button : public Entity {
    std::function<void(GameContext&)> onClick;
    bool hovered = false;


public:
    Button(std::string t, SpriteComposite s, std::function<void(GameContext&)> action);

    void handleEvents(const sf::Event& e, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

private:
    sf::Text text;
};
