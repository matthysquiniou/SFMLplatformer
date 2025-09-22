#pragma once
#include "State.hpp"
#include "EntityManager.hpp"
#include "EntityFactory.hpp"
#include "Collision.hpp"
#include "Assets.hpp"

class PlayState : public State {
public:
    PlayState(sf::Vector2u windowSize, sf::View& view) : windowSize(windowSize), view(view), score(getMainFont(), "0", 24) {}

    void handleEvents(std::optional<sf::Event> event, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

    void loadLevel(unsigned int level, int character);

private:
    void loadLevelBase(unsigned int levelBase, int character);

    void loadLevelObj(unsigned int levelObj);

    void loadPlayer(int character, sf::Vector2f pos);

    void loadBlocLine(std::string path, float blockSize,int blockNumber, sf::Vector2f startPos, bool isX = true);

    void loadPlatform(
        sf::FloatRect bounds,
        sf::Vector2f startPos,
        int blockNumber,
        std::string pathStart,
        std::string pathMiddle,
        std::string pathEnd,
        bool loadVisual = false,
        std::string pathVStart = "",
        std::string pathVMiddle = "",
        std::string pathVEnd = ""
    );

    void loadVisualLine(std::string path, float blockSize, int blockNumber, sf::Vector2f startPos, bool isX = true);

    void loadBackgroundAndBounds(sf::FloatRect rect, std::string path);

    EntityManager entityManager;

    sf::Vector2u windowSize;

    sf::View& view;

    sf::Text score;
};
