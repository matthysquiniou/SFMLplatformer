#include "Text.hpp"

Text::Text(std::string t, unsigned int size, sf::Vector2f pos) :
    text(getMainFont(), t, size)
{
    text.setFillColor(sf::Color::White);
    sf::FloatRect bounds = text.getGlobalBounds();
    pos.x -= bounds.size.x / 2;
    pos.y -= bounds.size.y / 2;
    text.setPosition(pos);
}

void Text::draw(sf::RenderWindow& window, GameContext& ctx) {
    window.draw(text);
}