#include "EntityFactory.hpp"
#include "Assets.hpp"

Button EntityFactory::makeBlueButton(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick) {
    SpriteComposite sprite;
    sprite.addChild(assetPath(AssetID::BUTTON_BLUE_UP), false);
    sprite.addChild(assetPath(AssetID::BUTTON_BLUE_DOWN), false);
    sprite.setVisible(1, false);
    sprite.setPosition(pos);

    return Button(text, std::move(sprite), std::move(onClick));
}

Entity EntityFactory::makeBackground(const std::string& path) {
    SpriteComposite sprite;
    sprite.addChild(path, false);
    return Entity(std::move(sprite));
}
