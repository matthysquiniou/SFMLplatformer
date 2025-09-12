#pragma once
#include <string>
#include <iostream>

enum class AssetID {

    // FONT
    MAIN_FONT,

    // BUTTON
    BUTTON_BLUE_UP,
    BUTTON_BLUE_DOWN

};

inline const std::string& assetPath(AssetID id) {

    // FONT 
    static const std::string MAIN_FONT_PATH = "Minecraft.ttf";

    // BUTTON
    static const std::string BUTTON_BLUE_UP_PATH = "assets/5 GUI/Buttons/Button_01.png";
    static const std::string BUTTON_BLUE_DOWN_PATH = "assets/5 GUI/Buttons/Button_02.png";

    switch (id) {

        // FONT
    case AssetID::MAIN_FONT:   return MAIN_FONT_PATH;

        // BUTTON
    case AssetID::BUTTON_BLUE_UP:   return BUTTON_BLUE_UP_PATH;
    case AssetID::BUTTON_BLUE_DOWN: return BUTTON_BLUE_DOWN_PATH;

    }

    static const std::string EMPTY = "";
    return EMPTY;
}

inline const sf::Font& getMainFont() {
    static sf::Font font;
    static bool loaded = false;

    if (!loaded) {
        if (!font.openFromFile(assetPath(AssetID::MAIN_FONT))) {
            std::cerr << "Impossible de charger la police principale\n";
        }
        loaded = true;
    }

    return font;
}
