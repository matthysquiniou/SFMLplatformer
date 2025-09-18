#include "BoxManager.hpp"
#include <SFML/Graphics.hpp>

std::vector<BoxManager*> BoxManager::allManagers;

BoxManager::BoxManager(EntityType t, Entity* owner)
    : type(t), entity(owner) {
    allManagers.push_back(this);
}

BoxManager::~BoxManager() {
    auto it = std::find(allManagers.begin(), allManagers.end(), this);
    if (it != allManagers.end())
        allManagers.erase(it);
}

void BoxManager::addBox(const sf::FloatRect& r, BoxType t) {
    boxes.push_back(Box{ {{0.f,0.f}, r.size }, r, t, true});
}

void BoxManager::clear() {
    boxes.clear();
}

void BoxManager::updateBoxesPosition(sf::Vector2f pos) {
    for (auto& box : boxes) {
        box.rect.position.x = pos.x + box.relativeRect.position.x;
        box.rect.position.y = pos.y + box.relativeRect.position.y;
    }
}


EntityType BoxManager::getType() const { return type; }
Entity* BoxManager::getEntity() const { return entity; }

std::vector<Box>& BoxManager::getBoxes() { return boxes; }
const std::vector<Box>& BoxManager::getBoxes() const { return boxes; }

void BoxManager::draw(sf::RenderWindow& win) {
    for (auto& b : boxes) {
        sf::RectangleShape shape;
        shape.setPosition({ b.rect.position.x, b.rect.position.y });
        shape.setSize({ b.rect.size.x, b.rect.size.y });
        shape.setFillColor(sf::Color::Transparent);

        switch (b.type) {
        case BoxType::Collision: shape.setOutlineColor(sf::Color::Blue); break;
        case BoxType::Hurt:      shape.setOutlineColor(sf::Color::Green); break;
        case BoxType::Hit:       shape.setOutlineColor(sf::Color::Red); break;
        }
        shape.setOutlineThickness(1.f);
        win.draw(shape);
    }
}
