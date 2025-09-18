#pragma once
#include "Entity.hpp"
#include <functional>

class Button : public Entity {
public:
    Button(std::string t, SpriteComposite s, std::function<void(GameContext&)> action, sf::View& view);
    Button(SpriteComposite s, std::function<void(GameContext&)> action, sf::View& view);

    void handleEvents(const sf::Event& e, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

private:
    sf::Text text;
    sf::Vector2f viewOffset;

    std::function<void(GameContext&)> onClick;
    bool hovered = false;

};
