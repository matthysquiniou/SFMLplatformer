#pragma once
#include <memory>
#include "Entity.hpp"
#include "Button.hpp"
#include "Text.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "EnemyCactus.hpp"
#include "EnemyTv.hpp"
#include "EnemyBarrel.hpp"
#include "EnemyFlyer.hpp"

class EntityFactory {
public:
    static std::shared_ptr <Text> makeText(std::string text, unsigned int size, sf::Vector2f pos);

    static std::shared_ptr <Entity> makeVisual(const std::string& path, sf::Vector2f pos);

    static std::shared_ptr <Button> makeTextButtonBlue(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick, sf::View& view);

    static std::shared_ptr <Button> makeTextButtonOrange(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick, sf::View& view);

    static std::shared_ptr <Button> makeTextButtonGreen(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick, sf::View& view);

    static std::shared_ptr <Button> makeTextButtonGrey(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick, sf::View& view);

    static std::shared_ptr <Button> makeTextButtonYellow(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick, sf::View& view);

    static std::shared_ptr <Button> makeLevelButton(unsigned int level, sf::Vector2f pos, sf::View& view);

    static std::shared_ptr<Player> makePlayer1(sf::Vector2f pos, sf::View& view);

    static std::shared_ptr<Player> makePlayer2(sf::Vector2f pos, sf::View& view);

    static std::shared_ptr<Player> makePlayer3(sf::Vector2f pos, sf::View& view);

    static std::shared_ptr<Platform> makePlatform(sf::Vector2f pos, const std::string& path, bool hasColision = true, sf::FloatRect box = { {0.f,0.f},{16.f,16.f} }, bool flipX = false, bool flipY = false);

    static std::shared_ptr<EnemyCactus> makeEnemyCactus(sf::Vector2f pos);

    static std::shared_ptr<EnemyTv> makeEnemyTv(sf::Vector2f pos);

    static std::shared_ptr<EnemyBarrel> makeEnemyBarrel(sf::Vector2f pos);

    static std::shared_ptr<EnemyFlyer> makeEnemyFlyer(sf::Vector2f pos);
};
