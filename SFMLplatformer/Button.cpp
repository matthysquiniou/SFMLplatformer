#include "Button.hpp"
#include <iostream>

Button::Button(std::string t, SpriteComposite s, std::function<void(GameContext&)> action) :
    Entity(std::move(s)),
    onClick(std::move(action)),
    text(getMainFont(), t, 24)
{
    text.setFillColor(sf::Color::White);
    sf::Vector2f textPos = s.getPosition();
    textPos.x += 20.f;
    textPos.y -= 5.5f;
    text.setPosition(textPos);
}

void Button::handleEvents(const sf::Event& e, GameContext& ctx) {
    if (const auto* mouseMove = e.getIf<sf::Event::MouseMoved>()) {
        sf::FloatRect bounds = sprite.getGlobalBounds();
        hovered = bounds.contains({ (float)mouseMove->position.x, (float)mouseMove->position.y }) || text.getGlobalBounds().contains({ (float)mouseMove->position.x, (float)mouseMove->position.y });
    }

    if (hovered && e.is<sf::Event::MouseButtonPressed>()) {
        onClick(ctx);
    }
}

void Button::update(float dt, GameContext& ctx) {
    if (hovered) {
        sprite.setVisible(0, false);
        sprite.setVisible(1, true);
    } else {
        sprite.setVisible(0, true);
        sprite.setVisible(1, false);
    }
}

void Button::draw(sf::RenderWindow& window, GameContext& ctx) {
    window.draw(sprite);

    window.draw(text);
}