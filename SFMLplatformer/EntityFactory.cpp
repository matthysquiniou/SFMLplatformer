#include "EntityFactory.hpp"
#include "Assets.hpp"

Text EntityFactory::makeText(std::string text, unsigned int size, sf::Vector2f pos) {
    return Text(text, size, pos);
}

Entity EntityFactory::makeVisual(const std::string& path, sf::Vector2f pos) {
    SpriteComposite sprite;
    sprite.addChild(path, false);
    return Entity(std::move(sprite), pos);
}

Button EntityFactory::makeTextButtonBlue(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick) {
    SpriteComposite sprite;
    sprite.addChild(assetPath(AssetID::BUTTON_BLUE_UP), false);
    sprite.addChild(assetPath(AssetID::BUTTON_BLUE_DOWN), false);
    sprite.setVisible(1, false);
    sprite.setPosition(pos);

    return Button(text, std::move(sprite), onClick);
}

Button EntityFactory::makeTextButtonOrange(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick) {
    SpriteComposite sprite;
    sprite.addChild(assetPath(AssetID::BUTTON_ORANGE_UP), false);
    sprite.addChild(assetPath(AssetID::BUTTON_ORANGE_DOWN), false);
    sprite.setVisible(1, false);
    sprite.setPosition(pos);

    return Button(text, std::move(sprite), onClick);
}

Button EntityFactory::makeTextButtonGreen(std::string text, sf::Vector2f pos, std::function<void(GameContext&)> onClick) {
    SpriteComposite sprite;
    sprite.addChild(assetPath(AssetID::BUTTON_GREEN_UP), false);
    sprite.addChild(assetPath(AssetID::BUTTON_GREEN_DOWN), false);
    sprite.setVisible(1, false);
    sprite.setPosition(pos);

    return Button(text, std::move(sprite), onClick);
}

Button EntityFactory::makeLevelButton(unsigned int level, sf::Vector2f pos) {
    SpriteComposite sprite;

    switch (level)
    {
    case 1:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_1_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_1_DOWN), false);
        break;
    case 2:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_2_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_2_DOWN), false);
        break;
    case 3:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_3_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_3_DOWN), false);
        break;
    case 4:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_4_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_4_DOWN), false);
        break;
    case 5:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_5_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_5_DOWN), false);
        break;
    case 6:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_6_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_6_DOWN), false);
        break;
    case 7:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_7_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_7_DOWN), false);
        break;
    case 8:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_8_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_8_DOWN), false);
        break;
    case 9:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_9_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_9_DOWN), false);
        break;
    case 10:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_10_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_10_DOWN), false);
        break;
    case 11:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_11_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_11_DOWN), false);
        break;
    case 12:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_12_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_12_DOWN), false);
        break;
    case 13:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_13_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_13_DOWN), false);
        break;
    case 14:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_14_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_14_DOWN), false);
        break;
    case 15:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_15_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_15_DOWN), false);
        break;
    case 16:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_16_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_16_DOWN), false);
        break;
    case 17:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_17_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_17_DOWN), false);
        break;
    case 18:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_18_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_18_DOWN), false);
        break;
    case 19:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_19_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_19_DOWN), false);
        break;
    case 20:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_20_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_20_DOWN), false);
        break;
    case 21:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_21_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_21_DOWN), false);
        break;
    case 22:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_22_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_22_DOWN), false);
        break;
    case 23:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_23_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_23_DOWN), false);
        break;
    case 24:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_24_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_24_DOWN), false);
        break;
    case 25:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_25_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_25_DOWN), false);
        break;
    case 26:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_26_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_26_DOWN), false);
        break;
    case 27:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_27_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_27_DOWN), false);
        break;
    case 28:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_28_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_28_DOWN), false);
        break;
    case 29:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_29_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_29_DOWN), false);
        break;
    case 30:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_30_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_30_DOWN), false);
        break;
    case 31:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_31_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_31_DOWN), false);
        break;
    case 32:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_32_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_32_DOWN), false);
        break;
    case 33:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_33_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_33_DOWN), false);
        break;
    case 34:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_34_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_34_DOWN), false);
        break;
    case 35:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_35_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_35_DOWN), false);
        break;
    case 36:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_36_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_36_DOWN), false);
        break;
    case 37:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_37_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_37_DOWN), false);
        break;
    case 38:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_38_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_38_DOWN), false);
        break;
    case 39:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_39_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_39_DOWN), false);
        break;
    case 40:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_40_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_40_DOWN), false);
        break;
    case 41:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_41_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_41_DOWN), false);
        break;
    case 42:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_42_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_42_DOWN), false);
        break;
    case 43:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_43_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_43_DOWN), false);
        break;
    case 44:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_44_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_44_DOWN), false);
        break;
    case 45:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_45_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_45_DOWN), false);
        break;
    case 46:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_46_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_46_DOWN), false);
        break;
    case 47:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_47_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_47_DOWN), false);
        break;
    case 48:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_48_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_48_DOWN), false);
        break;
    case 49:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_49_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_49_DOWN), false);
        break;
    case 50:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_50_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_50_DOWN), false);
        break;
    default:
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_1_UP), false);
        sprite.addChild(assetPath(AssetID::BUTTON_LEVEL_1_DOWN), false);
        break;
    }


    sprite.setVisible(1, false);
    sprite.setPosition(pos);

    return Button(
        std::move(sprite),
        [level](GameContext& ctx) {
            ctx.currentState = GameState::PLAY;
            ctx.currentLevel = level;
        });

}