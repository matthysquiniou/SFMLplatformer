#include "Button.hpp"
#include "Assets.hpp"
#include "SoundManager.hpp"

Button::Button(std::string t, SpriteComposite s, std::function<void(GameContext&)> action, sf::View& view) :
    Entity(std::move(s)),
    onClick(std::move(action)),
    text(getMainFont(), t, 24)
{
    text.setFillColor(sf::Color::White);
    sf::Vector2f textPos = s.getPosition();
    textPos.x += 50.f;
    textPos.y -= 5.5f;
    text.setPosition(textPos);
    viewOffset = { view.getCenter().x - (view.getSize().x / 2), view.getCenter().y - (view.getSize().y / 2) };
}

Button::Button(SpriteComposite s, std::function<void(GameContext&)> action, sf::View& view) :
    Entity(std::move(s)),
    onClick(std::move(action)),
    text(getMainFont(), "")
{
    viewOffset = { view.getCenter().x - (view.getSize().x/2), view.getCenter().y - (view.getSize().y / 2) };
}

void Button::handleEvents(const sf::Event& e, GameContext& ctx) {
    if (const auto* mouseMove = e.getIf<sf::Event::MouseMoved>()) {
        sf::FloatRect spriteBounds = sprite.getGlobalBounds();
        sf::FloatRect unionBounds = spriteBounds;

        if (!text.getString().isEmpty()) {
            sf::FloatRect textBounds = text.getGlobalBounds();
            unionBounds.position.x = std::min(spriteBounds.position.x - viewOffset.x, textBounds.position.x - viewOffset.x);
            unionBounds.position.y = std::min(spriteBounds.position.y - viewOffset.y, textBounds.position.y - viewOffset.y);
            unionBounds.size.x = std::max(spriteBounds.position.x - viewOffset.x + spriteBounds.size.x, textBounds.position.x - viewOffset.x + textBounds.size.x) - unionBounds.position.x;
            unionBounds.size.y = std::max(spriteBounds.position.y - viewOffset.y + spriteBounds.size.y, textBounds.position.y - viewOffset.y + textBounds.size.y) - unionBounds.position.y;
        }
        bool previousHover = hovered;
        hovered = unionBounds.contains({ (float)mouseMove->position.x, (float)mouseMove->position.y });
        if (previousHover != hovered && hovered)
        {
            SoundManager::play(SoundManager::SoundName::HOVERED);
        }
    }

    if (hovered && e.is<sf::Event::MouseButtonPressed>()) {
        onClick(ctx);
        SoundManager::play(SoundManager::SoundName::PUSHED);
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