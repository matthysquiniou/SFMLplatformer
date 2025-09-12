#include "SpriteWrapper.hpp"
#include "TextureManager.hpp"

SpriteWrapper::SpriteWrapper(const std::string& path)
    : m_texture(), m_sprite(initSprite(m_texture, path)) {
}

sf::Sprite& SpriteWrapper::get() {
    return m_sprite;
}

const sf::Sprite& SpriteWrapper::get() const {
    return m_sprite;
}

void SpriteWrapper::setTextureRect(const sf::IntRect& rect) {
    m_sprite.setTextureRect(rect);
}

sf::Sprite SpriteWrapper::initSprite(sf::Texture& tex, const std::string& path) {
    return sf::Sprite(TextureManager::get(path));
}