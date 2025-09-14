#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"

class PlayState : public State {
public:
    PlayState(sf::Vector2u windowSize) : windowSize(windowSize) {}

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

    void loadLevel(unsigned int level);

private:
    void loadLevelBase(unsigned int levelBase);

    void loadLevelObj(unsigned int levelObj);

    EntityManager entityManager;

    sf::Vector2u windowSize;
};
