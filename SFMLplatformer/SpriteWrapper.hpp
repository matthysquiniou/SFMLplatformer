#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>

class SpriteWrapper {
public:
    explicit SpriteWrapper(const std::string& path);

    sf::Sprite& get();
    const sf::Sprite& get() const;

    void setTextureRect(const sf::IntRect& rect);

private:
    static sf::Sprite initSprite(sf::Texture& tex, const std::string& path);

    sf::Texture m_texture;
    sf::Sprite  m_sprite;
};