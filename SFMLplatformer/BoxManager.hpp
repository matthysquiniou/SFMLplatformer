#pragma once
#include <vector>
#include "Box.hpp"
#include "Entity.hpp"

class BoxManager {
public:
    BoxManager(EntityType t, Entity* owner);
    ~BoxManager();

    void addBox(const sf::FloatRect& r, BoxType t);
    void addBox(const sf::FloatRect& r, BoxType t, int observerID);
    void clear();
    void updateBoxesPosition(sf::Vector2f pos);
    void disableBoxType( BoxType boxType );
    void activateBoxType(BoxType boxType);
    void disableBoxObserver(int observerID);
    void activateBoxObserver(int observerID);

    EntityType getType() const;
    Entity* getEntity() const;

    std::vector<Box>& getBoxes();
    const std::vector<Box>& getBoxes() const;

    void draw(sf::RenderWindow& win);

    static std::vector<BoxManager*> allManagers;

private:
    EntityType type;
    Entity* entity;
    std::vector<Box> boxes;
};
