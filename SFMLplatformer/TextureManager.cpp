#include "TextureManager.hpp"

sf::Texture& TextureManager::get(const std::string& path) {
    auto& cache = getInstance().m_cache;
    auto it = cache.find(path);
    if (it == cache.end()) {
        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(path)) {
            throw std::runtime_error("Erreur: impossible de charger " + path);
        }
        texture->setSmooth(true);
        it = cache.emplace(path, std::move(texture)).first;
    }
    return *it->second;
}

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}