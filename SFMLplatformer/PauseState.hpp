#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"
#include "PlayState.hpp"

class PauseState : public State {
public:
    PauseState(sf::View& view) : view(view) {}

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

    void loadPause();

private:

    EntityManager entityManager;

    sf::RectangleShape overlay;

    sf::View& view;
};