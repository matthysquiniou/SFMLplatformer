#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"

class MenuState : public State {
public:

    MenuState() {
        entityManager.addEntity<Button>(EntityFactory::makeBlueButton(
            "LEVELS",
            { 500.f,500.f },
            [](GameContext& ctx) {
                ctx.currentState = GameState::LEVEL_CHOICE;
            })
        );
    }

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

    EntityManager entityManager;
};