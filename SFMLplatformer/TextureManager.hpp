#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include <string>

class TextureManager {
public:
    static sf::Texture& get(const std::string& path);

private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_cache;

    static TextureManager& getInstance();
};
