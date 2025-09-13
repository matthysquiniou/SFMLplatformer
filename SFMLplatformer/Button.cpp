#include "Button.hpp"
#include <iostream>

Button::Button(std::string t, SpriteComposite s, std::function<void(GameContext&)> action) :
    Entity(std::move(s)),
    onClick(std::move(action)),
    text(getMainFont(), t, 24)
{
    text.setFillColor(sf::Color::White);
    sf::Vector2f textPos = s.getPosition();
    textPos.x += 50.f;
    textPos.y -= 5.5f;
    text.setPosition(textPos);
}

Button::Button(SpriteComposite s, std::function<void(GameContext&)> action) :
    Entity(std::move(s)),
    onClick(std::move(action)),
    text(getMainFont(), "")
{}

void Button::handleEvents(const sf::Event& e, GameContext& ctx) {
    if (const auto* mouseMove = e.getIf<sf::Event::MouseMoved>()) {
        sf::FloatRect spriteBounds = sprite.getGlobalBounds();
        sf::FloatRect unionBounds = spriteBounds;

        if (!text.getString().isEmpty()) {
            sf::FloatRect textBounds = text.getGlobalBounds();
            unionBounds.position.x = std::min(spriteBounds.position.x, textBounds.position.x);
            unionBounds.position.y = std::min(spriteBounds.position.y, textBounds.position.y);
            unionBounds.size.x = std::max(spriteBounds.position.x + spriteBounds.size.x, textBounds.position.x + textBounds.size.x) - unionBounds.position.x;
            unionBounds.size.y = std::max(spriteBounds.position.y + spriteBounds.size.y, textBounds.position.y + textBounds.size.y) - unionBounds.position.y;
        }

        hovered = unionBounds.contains({ (float)mouseMove->position.x, (float)mouseMove->position.y });
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

    if (!text.getString().isEmpty()) {
        window.draw(text);
    }
}