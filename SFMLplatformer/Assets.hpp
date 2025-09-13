#pragma once
#include <string>
#include <iostream>

enum class AssetID {

    // FONT
    MAIN_FONT,

    // BACKGROUND
    BG_BLUE,
    BG_ORANGE,
    BG_GREY,
    BG_GREEN,
    BG_PURPLE,
    BG_YELLOW,

    // BUTTON
    BUTTON_BLUE_UP,
    BUTTON_BLUE_DOWN,
    BUTTON_PINK_UP,
    BUTTON_PINK_DOWN,
    BUTTON_ORANGE_UP,
    BUTTON_ORANGE_DOWN,
    BUTTON_GREEN_UP,
    BUTTON_GREEN_DOWN,
    BUTTON_RED_UP,
    BUTTON_RED_DOWN,
    BUTTON_YELLOW_UP,
    BUTTON_YELLOW_DOWN,

    // LEVEL BUTTON
    BUTTON_LEVEL_1_UP,
    BUTTON_LEVEL_1_DOWN,
    BUTTON_LEVEL_2_UP,
    BUTTON_LEVEL_2_DOWN,
    BUTTON_LEVEL_3_UP,
    BUTTON_LEVEL_3_DOWN,
    BUTTON_LEVEL_4_UP,
    BUTTON_LEVEL_4_DOWN,
    BUTTON_LEVEL_5_UP,
    BUTTON_LEVEL_5_DOWN,
    BUTTON_LEVEL_6_UP,
    BUTTON_LEVEL_6_DOWN,
    BUTTON_LEVEL_7_UP,
    BUTTON_LEVEL_7_DOWN,
    BUTTON_LEVEL_8_UP,
    BUTTON_LEVEL_8_DOWN,
    BUTTON_LEVEL_9_UP,
    BUTTON_LEVEL_9_DOWN,
    BUTTON_LEVEL_10_UP,
    BUTTON_LEVEL_10_DOWN,
    BUTTON_LEVEL_11_UP,
    BUTTON_LEVEL_11_DOWN,
    BUTTON_LEVEL_12_UP,
    BUTTON_LEVEL_12_DOWN,
    BUTTON_LEVEL_13_UP,
    BUTTON_LEVEL_13_DOWN,
    BUTTON_LEVEL_14_UP,
    BUTTON_LEVEL_14_DOWN,
    BUTTON_LEVEL_15_UP,
    BUTTON_LEVEL_15_DOWN,
    BUTTON_LEVEL_16_UP,
    BUTTON_LEVEL_16_DOWN,
    BUTTON_LEVEL_17_UP,
    BUTTON_LEVEL_17_DOWN,
    BUTTON_LEVEL_18_UP,
    BUTTON_LEVEL_18_DOWN,
    BUTTON_LEVEL_19_UP,
    BUTTON_LEVEL_19_DOWN,
    BUTTON_LEVEL_20_UP,
    BUTTON_LEVEL_20_DOWN,
    BUTTON_LEVEL_21_UP,
    BUTTON_LEVEL_21_DOWN,
    BUTTON_LEVEL_22_UP,
    BUTTON_LEVEL_22_DOWN,
    BUTTON_LEVEL_23_UP,
    BUTTON_LEVEL_23_DOWN,
    BUTTON_LEVEL_24_UP,
    BUTTON_LEVEL_24_DOWN,
    BUTTON_LEVEL_25_UP,
    BUTTON_LEVEL_25_DOWN,
    BUTTON_LEVEL_26_UP,
    BUTTON_LEVEL_26_DOWN,
    BUTTON_LEVEL_27_UP,
    BUTTON_LEVEL_27_DOWN,
    BUTTON_LEVEL_28_UP,
    BUTTON_LEVEL_28_DOWN,
    BUTTON_LEVEL_29_UP,
    BUTTON_LEVEL_29_DOWN,
    BUTTON_LEVEL_30_UP,
    BUTTON_LEVEL_30_DOWN,
    BUTTON_LEVEL_31_UP,
    BUTTON_LEVEL_31_DOWN,
    BUTTON_LEVEL_32_UP,
    BUTTON_LEVEL_32_DOWN,
    BUTTON_LEVEL_33_UP,
    BUTTON_LEVEL_33_DOWN,
    BUTTON_LEVEL_34_UP,
    BUTTON_LEVEL_34_DOWN,
    BUTTON_LEVEL_35_UP,
    BUTTON_LEVEL_35_DOWN,
    BUTTON_LEVEL_36_UP,
    BUTTON_LEVEL_36_DOWN,
    BUTTON_LEVEL_37_UP,
    BUTTON_LEVEL_37_DOWN,
    BUTTON_LEVEL_38_UP,
    BUTTON_LEVEL_38_DOWN,
    BUTTON_LEVEL_39_UP,
    BUTTON_LEVEL_39_DOWN,
    BUTTON_LEVEL_40_UP,
    BUTTON_LEVEL_40_DOWN,
    BUTTON_LEVEL_41_UP,
    BUTTON_LEVEL_41_DOWN,
    BUTTON_LEVEL_42_UP,
    BUTTON_LEVEL_42_DOWN,
    BUTTON_LEVEL_43_UP,
    BUTTON_LEVEL_43_DOWN,
    BUTTON_LEVEL_44_UP,
    BUTTON_LEVEL_44_DOWN,
    BUTTON_LEVEL_45_UP,
    BUTTON_LEVEL_45_DOWN,
    BUTTON_LEVEL_46_UP,
    BUTTON_LEVEL_46_DOWN,
    BUTTON_LEVEL_47_UP,
    BUTTON_LEVEL_47_DOWN,
    BUTTON_LEVEL_48_UP,
    BUTTON_LEVEL_48_DOWN,
    BUTTON_LEVEL_49_UP,
    BUTTON_LEVEL_49_DOWN,
    BUTTON_LEVEL_50_UP,
    BUTTON_LEVEL_50_DOWN,


    //INTERFACE
    GREEN_FRAME_TOP_LEFT,
    GREEN_FRAME_TOP,
    GREEN_FRAME_TOP_RIGHT,
    GREEN_FRAME_LEFT,
    GREEN_FRAME_MIDDLE,
    GREEN_FRAME_RIGHT,
    GREEN_FRAME_BOTTOM_LEFT,
    GREEN_FRAME_BOTTOM,
    GREEN_FRAME_BOTTOM_RIGHT,
    GREEN_BAR_LEFT,
    GREEN_BAR_MIDDLE,
    GREEN_BAR_RIGHT,

    GRAY_FRAME_TOP_LEFT,
    GRAY_FRAME_TOP,
    GRAY_FRAME_TOP_RIGHT,
    GRAY_FRAME_LEFT,
    GRAY_FRAME_MIDDLE,
    GRAY_FRAME_RIGHT,
    GRAY_FRAME_BOTTOM_LEFT,
    GRAY_FRAME_BOTTOM,
    GRAY_FRAME_BOTTOM_RIGHT,
    GRAY_BAR_LEFT,
    GRAY_BAR_MIDDLE,
    GRAY_BAR_RIGHT,

    BRICK_FRAME_TOP_LEFT,
    BRICK_FRAME_TOP,
    BRICK_FRAME_TOP_RIGHT,
    BRICK_FRAME_LEFT,
    BRICK_FRAME_MIDDLE,
    BRICK_FRAME_RIGHT,
    BRICK_FRAME_BOTTOM_LEFT,
    BRICK_FRAME_BOTTOM,
    BRICK_FRAME_BOTTOM_RIGHT,
    BRICK_BAR_LEFT,
    BRICK_BAR_MIDDLE,
    BRICK_BAR_RIGHT,

    WARN_FRAME_TOP_LEFT,
    WARN_FRAME_TOP,
    WARN_FRAME_TOP_RIGHT,
    WARN_FRAME_LEFT,
    WARN_FRAME_MIDDLE,
    WARN_FRAME_RIGHT,
    WARN_FRAME_BOTTOM_LEFT,
    WARN_FRAME_BOTTOM,
    WARN_FRAME_BOTTOM_RIGHT,
    WARN_BAR_LEFT,
    WARN_BAR_MIDDLE,
    WARN_BAR_RIGHT,
};

inline const std::string& assetPath(AssetID id) {

    // FONT 
    static const std::string MAIN_FONT_PATH = "Minecraft.ttf";

    // BACKGROUND
    static const std::string BG_BLUE_PATH = "assets/2 Locations/Backgrounds/1.png";
    static const std::string BG_ORANGE_PATH = "assets/2 Locations/Backgrounds/2.png";
    static const std::string BG_GREY_PATH = "assets/2 Locations/Backgrounds/3.png";
    static const std::string BG_GREEN_PATH = "assets/2 Locations/Backgrounds/4.png";
    static const std::string BG_PURPLE_PATH = "assets/2 Locations/Backgrounds/5.png";
    static const std::string BG_YELLOW_PATH = "assets/2 Locations/Backgrounds/6.png";

    // BUTTON
    static const std::string BUTTON_BLUE_UP_PATH = "assets/5 GUI/Buttons/Button_01.png";
    static const std::string BUTTON_BLUE_DOWN_PATH = "assets/5 GUI/Buttons/Button_02.png";
    static const std::string BUTTON_PINK_UP_PATH = "assets/5 GUI/Buttons/Button_03.png";
    static const std::string BUTTON_PINK_DOWN_PATH = "assets/5 GUI/Buttons/Button_04.png";
    static const std::string BUTTON_ORANGE_UP_PATH = "assets/5 GUI/Buttons/Button_07.png";
    static const std::string BUTTON_ORANGE_DOWN_PATH = "assets/5 GUI/Buttons/Button_08.png";
    static const std::string BUTTON_GREEN_UP_PATH = "assets/5 GUI/Buttons/Button_09.png";
    static const std::string BUTTON_GREEN_DOWN_PATH = "assets/5 GUI/Buttons/Button_10.png";
    static const std::string BUTTON_RED_UP_PATH = "assets/5 GUI/Buttons/Button_15.png";
    static const std::string BUTTON_RED_DOWN_PATH = "assets/5 GUI/Buttons/Button_16.png";
    static const std::string BUTTON_YELLOW_UP_PATH = "assets/5 GUI/Buttons/Button_17.png";
    static const std::string BUTTON_YELLOW_DOWN_PATH = "assets/5 GUI/Buttons/Button_18.png";

    // LEVEL BUTTON
    static const std::string BUTTON_LEVEL_1_UP_PATH = "assets/5 GUI/Levels/1/1_01.png";
    static const std::string BUTTON_LEVEL_1_DOWN_PATH = "assets/5 GUI/Levels/2/2_01.png";
    static const std::string BUTTON_LEVEL_2_UP_PATH = "assets/5 GUI/Levels/1/1_02.png";
    static const std::string BUTTON_LEVEL_2_DOWN_PATH = "assets/5 GUI/Levels/2/2_02.png";
    static const std::string BUTTON_LEVEL_3_UP_PATH = "assets/5 GUI/Levels/1/1_03.png";
    static const std::string BUTTON_LEVEL_3_DOWN_PATH = "assets/5 GUI/Levels/2/2_03.png";
    static const std::string BUTTON_LEVEL_4_UP_PATH = "assets/5 GUI/Levels/1/1_04.png";
    static const std::string BUTTON_LEVEL_4_DOWN_PATH = "assets/5 GUI/Levels/2/2_04.png";
    static const std::string BUTTON_LEVEL_5_UP_PATH = "assets/5 GUI/Levels/1/1_05.png";
    static const std::string BUTTON_LEVEL_5_DOWN_PATH = "assets/5 GUI/Levels/2/2_05.png";
    static const std::string BUTTON_LEVEL_6_UP_PATH = "assets/5 GUI/Levels/1/1_06.png";
    static const std::string BUTTON_LEVEL_6_DOWN_PATH = "assets/5 GUI/Levels/2/2_06.png";
    static const std::string BUTTON_LEVEL_7_UP_PATH = "assets/5 GUI/Levels/1/1_07.png";
    static const std::string BUTTON_LEVEL_7_DOWN_PATH = "assets/5 GUI/Levels/2/2_07.png";
    static const std::string BUTTON_LEVEL_8_UP_PATH = "assets/5 GUI/Levels/1/1_08.png";
    static const std::string BUTTON_LEVEL_8_DOWN_PATH = "assets/5 GUI/Levels/2/2_08.png";
    static const std::string BUTTON_LEVEL_9_UP_PATH = "assets/5 GUI/Levels/1/1_09.png";
    static const std::string BUTTON_LEVEL_9_DOWN_PATH = "assets/5 GUI/Levels/2/2_09.png";
    static const std::string BUTTON_LEVEL_10_UP_PATH = "assets/5 GUI/Levels/1/1_10.png";
    static const std::string BUTTON_LEVEL_10_DOWN_PATH = "assets/5 GUI/Levels/2/2_10.png";
    static const std::string BUTTON_LEVEL_11_UP_PATH = "assets/5 GUI/Levels/1/1_11.png";
    static const std::string BUTTON_LEVEL_11_DOWN_PATH = "assets/5 GUI/Levels/2/2_11.png";
    static const std::string BUTTON_LEVEL_12_UP_PATH = "assets/5 GUI/Levels/1/1_12.png";
    static const std::string BUTTON_LEVEL_12_DOWN_PATH = "assets/5 GUI/Levels/2/2_12.png";
    static const std::string BUTTON_LEVEL_13_UP_PATH = "assets/5 GUI/Levels/1/1_13.png";
    static const std::string BUTTON_LEVEL_13_DOWN_PATH = "assets/5 GUI/Levels/2/2_13.png";
    static const std::string BUTTON_LEVEL_14_UP_PATH = "assets/5 GUI/Levels/1/1_14.png";
    static const std::string BUTTON_LEVEL_14_DOWN_PATH = "assets/5 GUI/Levels/2/2_14.png";
    static const std::string BUTTON_LEVEL_15_UP_PATH = "assets/5 GUI/Levels/1/1_15.png";
    static const std::string BUTTON_LEVEL_15_DOWN_PATH = "assets/5 GUI/Levels/2/2_15.png";
    static const std::string BUTTON_LEVEL_16_UP_PATH = "assets/5 GUI/Levels/1/1_16.png";
    static const std::string BUTTON_LEVEL_16_DOWN_PATH = "assets/5 GUI/Levels/2/2_16.png";
    static const std::string BUTTON_LEVEL_17_UP_PATH = "assets/5 GUI/Levels/1/1_17.png";
    static const std::string BUTTON_LEVEL_17_DOWN_PATH = "assets/5 GUI/Levels/2/2_17.png";
    static const std::string BUTTON_LEVEL_18_UP_PATH = "assets/5 GUI/Levels/1/1_18.png";
    static const std::string BUTTON_LEVEL_18_DOWN_PATH = "assets/5 GUI/Levels/2/2_18.png";
    static const std::string BUTTON_LEVEL_19_UP_PATH = "assets/5 GUI/Levels/1/1_19.png";
    static const std::string BUTTON_LEVEL_19_DOWN_PATH = "assets/5 GUI/Levels/2/2_19.png";
    static const std::string BUTTON_LEVEL_20_UP_PATH = "assets/5 GUI/Levels/1/1_20.png";
    static const std::string BUTTON_LEVEL_20_DOWN_PATH = "assets/5 GUI/Levels/2/2_20.png";
    static const std::string BUTTON_LEVEL_21_UP_PATH = "assets/5 GUI/Levels/1/1_21.png";
    static const std::string BUTTON_LEVEL_21_DOWN_PATH = "assets/5 GUI/Levels/2/2_21.png";
    static const std::string BUTTON_LEVEL_22_UP_PATH = "assets/5 GUI/Levels/1/1_22.png";
    static const std::string BUTTON_LEVEL_22_DOWN_PATH = "assets/5 GUI/Levels/2/2_22.png";
    static const std::string BUTTON_LEVEL_23_UP_PATH = "assets/5 GUI/Levels/1/1_23.png";
    static const std::string BUTTON_LEVEL_23_DOWN_PATH = "assets/5 GUI/Levels/2/2_23.png";
    static const std::string BUTTON_LEVEL_24_UP_PATH = "assets/5 GUI/Levels/1/1_24.png";
    static const std::string BUTTON_LEVEL_24_DOWN_PATH = "assets/5 GUI/Levels/2/2_24.png";
    static const std::string BUTTON_LEVEL_25_UP_PATH = "assets/5 GUI/Levels/1/1_25.png";
    static const std::string BUTTON_LEVEL_25_DOWN_PATH = "assets/5 GUI/Levels/2/2_25.png";
    static const std::string BUTTON_LEVEL_26_UP_PATH = "assets/5 GUI/Levels/1/1_26.png";
    static const std::string BUTTON_LEVEL_26_DOWN_PATH = "assets/5 GUI/Levels/2/2_26.png";
    static const std::string BUTTON_LEVEL_27_UP_PATH = "assets/5 GUI/Levels/1/1_27.png";
    static const std::string BUTTON_LEVEL_27_DOWN_PATH = "assets/5 GUI/Levels/2/2_27.png";
    static const std::string BUTTON_LEVEL_28_UP_PATH = "assets/5 GUI/Levels/1/1_28.png";
    static const std::string BUTTON_LEVEL_28_DOWN_PATH = "assets/5 GUI/Levels/2/2_28.png";
    static const std::string BUTTON_LEVEL_29_UP_PATH = "assets/5 GUI/Levels/1/1_29.png";
    static const std::string BUTTON_LEVEL_29_DOWN_PATH = "assets/5 GUI/Levels/2/2_29.png";
    static const std::string BUTTON_LEVEL_30_UP_PATH = "assets/5 GUI/Levels/1/1_30.png";
    static const std::string BUTTON_LEVEL_30_DOWN_PATH = "assets/5 GUI/Levels/2/2_30.png";
    static const std::string BUTTON_LEVEL_31_UP_PATH = "assets/5 GUI/Levels/1/1_31.png";
    static const std::string BUTTON_LEVEL_31_DOWN_PATH = "assets/5 GUI/Levels/2/2_31.png";
    static const std::string BUTTON_LEVEL_32_UP_PATH = "assets/5 GUI/Levels/1/1_32.png";
    static const std::string BUTTON_LEVEL_32_DOWN_PATH = "assets/5 GUI/Levels/2/2_32.png";
    static const std::string BUTTON_LEVEL_33_UP_PATH = "assets/5 GUI/Levels/1/1_33.png";
    static const std::string BUTTON_LEVEL_33_DOWN_PATH = "assets/5 GUI/Levels/2/2_33.png";
    static const std::string BUTTON_LEVEL_34_UP_PATH = "assets/5 GUI/Levels/1/1_34.png";
    static const std::string BUTTON_LEVEL_34_DOWN_PATH = "assets/5 GUI/Levels/2/2_34.png";
    static const std::string BUTTON_LEVEL_35_UP_PATH = "assets/5 GUI/Levels/1/1_35.png";
    static const std::string BUTTON_LEVEL_35_DOWN_PATH = "assets/5 GUI/Levels/2/2_35.png";
    static const std::string BUTTON_LEVEL_36_UP_PATH = "assets/5 GUI/Levels/1/1_36.png";
    static const std::string BUTTON_LEVEL_36_DOWN_PATH = "assets/5 GUI/Levels/2/2_36.png";
    static const std::string BUTTON_LEVEL_37_UP_PATH = "assets/5 GUI/Levels/1/1_37.png";
    static const std::string BUTTON_LEVEL_37_DOWN_PATH = "assets/5 GUI/Levels/2/2_37.png";
    static const std::string BUTTON_LEVEL_38_UP_PATH = "assets/5 GUI/Levels/1/1_38.png";
    static const std::string BUTTON_LEVEL_38_DOWN_PATH = "assets/5 GUI/Levels/2/2_38.png";
    static const std::string BUTTON_LEVEL_39_UP_PATH = "assets/5 GUI/Levels/1/1_39.png";
    static const std::string BUTTON_LEVEL_39_DOWN_PATH = "assets/5 GUI/Levels/2/2_39.png";
    static const std::string BUTTON_LEVEL_40_UP_PATH = "assets/5 GUI/Levels/1/1_40.png";
    static const std::string BUTTON_LEVEL_40_DOWN_PATH = "assets/5 GUI/Levels/2/2_40.png";
    static const std::string BUTTON_LEVEL_41_UP_PATH = "assets/5 GUI/Levels/1/1_41.png";
    static const std::string BUTTON_LEVEL_41_DOWN_PATH = "assets/5 GUI/Levels/2/2_41.png";
    static const std::string BUTTON_LEVEL_42_UP_PATH = "assets/5 GUI/Levels/1/1_42.png";
    static const std::string BUTTON_LEVEL_42_DOWN_PATH = "assets/5 GUI/Levels/2/2_42.png";
    static const std::string BUTTON_LEVEL_43_UP_PATH = "assets/5 GUI/Levels/1/1_43.png";
    static const std::string BUTTON_LEVEL_43_DOWN_PATH = "assets/5 GUI/Levels/2/2_43.png";
    static const std::string BUTTON_LEVEL_44_UP_PATH = "assets/5 GUI/Levels/1/1_44.png";
    static const std::string BUTTON_LEVEL_44_DOWN_PATH = "assets/5 GUI/Levels/2/2_44.png";
    static const std::string BUTTON_LEVEL_45_UP_PATH = "assets/5 GUI/Levels/1/1_45.png";
    static const std::string BUTTON_LEVEL_45_DOWN_PATH = "assets/5 GUI/Levels/2/2_45.png";
    static const std::string BUTTON_LEVEL_46_UP_PATH = "assets/5 GUI/Levels/1/1_46.png";
    static const std::string BUTTON_LEVEL_46_DOWN_PATH = "assets/5 GUI/Levels/2/2_46.png";
    static const std::string BUTTON_LEVEL_47_UP_PATH = "assets/5 GUI/Levels/1/1_47.png";
    static const std::string BUTTON_LEVEL_47_DOWN_PATH = "assets/5 GUI/Levels/2/2_47.png";
    static const std::string BUTTON_LEVEL_48_UP_PATH = "assets/5 GUI/Levels/1/1_48.png";
    static const std::string BUTTON_LEVEL_48_DOWN_PATH = "assets/5 GUI/Levels/2/2_48.png";
    static const std::string BUTTON_LEVEL_49_UP_PATH = "assets/5 GUI/Levels/1/1_49.png";
    static const std::string BUTTON_LEVEL_49_DOWN_PATH = "assets/5 GUI/Levels/2/2_49.png";
    static const std::string BUTTON_LEVEL_50_UP_PATH = "assets/5 GUI/Levels/1/1_50.png";
    static const std::string BUTTON_LEVEL_50_DOWN_PATH = "assets/5 GUI/Levels/2/2_50.png";

    //INTERFACE
    static const std::string GREEN_FRAME_TOP_LEFT = "assets/5 GUI/Interface/Tile_01.png";
    static const std::string GREEN_FRAME_TOP = "assets/5 GUI/Interface/Tile_02.png";
    static const std::string GREEN_FRAME_TOP_RIGHT = "assets/5 GUI/Interface/Tile_03.png";
    static const std::string GREEN_FRAME_LEFT = "assets/5 GUI/Interface/Tile_14.png";
    static const std::string GREEN_FRAME_MIDDLE = "assets/5 GUI/Interface/Tile_15.png";
    static const std::string GREEN_FRAME_RIGHT = "assets/5 GUI/Interface/Tile_16.png";
    static const std::string GREEN_FRAME_BOTTOM_LEFT = "assets/5 GUI/Interface/Tile_27.png";
    static const std::string GREEN_FRAME_BOTTOM = "assets/5 GUI/Interface/Tile_28.png";
    static const std::string GREEN_FRAME_BOTTOM_RIGHT = "assets/5 GUI/Interface/Tile_29.png";
    static const std::string GREEN_BAR_LEFT = "assets/5 GUI/Interface/Tile_11.png";
    static const std::string GREEN_BAR_MIDDLE = "assets/5 GUI/Interface/Tile_12.png";
    static const std::string GREEN_BAR_RIGHT = "assets/5 GUI/Interface/Tile_13.png";

    static const std::string GRAY_FRAME_TOP_LEFT = "assets/5 GUI/Interface/Tile_06.png";
    static const std::string GRAY_FRAME_TOP = "assets/5 GUI/Interface/Tile_07.png";
    static const std::string GRAY_FRAME_TOP_RIGHT = "assets/5 GUI/Interface/Tile_08.png";
    static const std::string GRAY_FRAME_LEFT = "assets/5 GUI/Interface/Tile_19.png";
    static const std::string GRAY_FRAME_MIDDLE = "assets/5 GUI/Interface/Tile_20.png";
    static const std::string GRAY_FRAME_RIGHT = "assets/5 GUI/Interface/Tile_21.png";
    static const std::string GRAY_FRAME_BOTTOM_LEFT = "assets/5 GUI/Interface/Tile_32.png";
    static const std::string GRAY_FRAME_BOTTOM = "assets/5 GUI/Interface/Tile_33.png";
    static const std::string GRAY_FRAME_BOTTOM_RIGHT = "assets/5 GUI/Interface/Tile_34.png";
    static const std::string GRAY_BAR_LEFT = "assets/5 GUI/Interface/Tile_24.png";
    static const std::string GRAY_BAR_MIDDLE = "assets/5 GUI/Interface/Tile_25.png";
    static const std::string GRAY_BAR_RIGHT = "assets/5 GUI/Interface/Tile_26.png";

    static const std::string BRICK_FRAME_TOP_LEFT = "assets/5 GUI/Interface/Tile_40.png";
    static const std::string BRICK_FRAME_TOP = "assets/5 GUI/Interface/Tile_41.png";
    static const std::string BRICK_FRAME_TOP_RIGHT = "assets/5 GUI/Interface/Tile_42.png";
    static const std::string BRICK_FRAME_LEFT = "assets/5 GUI/Interface/Tile_53.png";
    static const std::string BRICK_FRAME_MIDDLE = "assets/5 GUI/Interface/Tile_54.png";
    static const std::string BRICK_FRAME_RIGHT = "assets/5 GUI/Interface/Tile_55.png";
    static const std::string BRICK_FRAME_BOTTOM_LEFT = "assets/5 GUI/Interface/Tile_66.png";
    static const std::string BRICK_FRAME_BOTTOM = "assets/5 GUI/Interface/Tile_67.png";
    static const std::string BRICK_FRAME_BOTTOM_RIGHT = "assets/5 GUI/Interface/Tile_68.png";
    static const std::string BRICK_BAR_LEFT = "assets/5 GUI/Interface/Tile_37.png";
    static const std::string BRICK_BAR_MIDDLE = "assets/5 GUI/Interface/Tile_38.png";
    static const std::string BRICK_BAR_RIGHT = "assets/5 GUI/Interface/Tile_39.png";

    static const std::string WARN_FRAME_TOP_LEFT = "assets/5 GUI/Interface/Tile_45.png";
    static const std::string WARN_FRAME_TOP = "assets/5 GUI/Interface/Tile_46.png";
    static const std::string WARN_FRAME_TOP_RIGHT = "assets/5 GUI/Interface/Tile_47.png";
    static const std::string WARN_FRAME_LEFT = "assets/5 GUI/Interface/Tile_58.png";
    static const std::string WARN_FRAME_MIDDLE = "assets/5 GUI/Interface/Tile_59.png";
    static const std::string WARN_FRAME_RIGHT = "assets/5 GUI/Interface/Tile_60.png";
    static const std::string WARN_FRAME_BOTTOM_LEFT = "assets/5 GUI/Interface/Tile_71.png";
    static const std::string WARN_FRAME_BOTTOM = "assets/5 GUI/Interface/Tile_72.png";
    static const std::string WARN_FRAME_BOTTOM_RIGHT = "assets/5 GUI/Interface/Tile_73.png";
    static const std::string WARN_BAR_LEFT = "assets/5 GUI/Interface/Tile_50.png";
    static const std::string WARN_BAR_MIDDLE = "assets/5 GUI/Interface/Tile_51.png";
    static const std::string WARN_BAR_RIGHT = "assets/5 GUI/Interface/Tile_52.png";

    switch (id) {

        // FONT
    case AssetID::MAIN_FONT:   return MAIN_FONT_PATH;

        // BACKGROUND
    case AssetID::BG_BLUE:   return BG_BLUE_PATH;
    case AssetID::BG_ORANGE:   return BG_ORANGE_PATH;
    case AssetID::BG_GREY:   return BG_GREY_PATH;
    case AssetID::BG_GREEN:   return BG_GREEN_PATH;
    case AssetID::BG_PURPLE:   return BG_PURPLE_PATH;
    case AssetID::BG_YELLOW:   return BG_YELLOW_PATH;

        // BUTTON
    case AssetID::BUTTON_BLUE_UP:   return BUTTON_BLUE_UP_PATH;
    case AssetID::BUTTON_BLUE_DOWN: return BUTTON_BLUE_DOWN_PATH;
    case AssetID::BUTTON_PINK_UP:   return BUTTON_PINK_UP_PATH;
    case AssetID::BUTTON_PINK_DOWN: return BUTTON_PINK_DOWN_PATH;
    case AssetID::BUTTON_ORANGE_UP:   return BUTTON_ORANGE_UP_PATH;
    case AssetID::BUTTON_ORANGE_DOWN: return BUTTON_ORANGE_DOWN_PATH;
    case AssetID::BUTTON_GREEN_UP:   return BUTTON_GREEN_UP_PATH;
    case AssetID::BUTTON_GREEN_DOWN: return BUTTON_GREEN_DOWN_PATH;
    case AssetID::BUTTON_RED_UP:   return BUTTON_RED_UP_PATH;
    case AssetID::BUTTON_RED_DOWN: return BUTTON_RED_DOWN_PATH;
    case AssetID::BUTTON_YELLOW_UP:   return BUTTON_YELLOW_UP_PATH;
    case AssetID::BUTTON_YELLOW_DOWN: return BUTTON_YELLOW_DOWN_PATH;

        // LEVEL BUTTON
    case AssetID::BUTTON_LEVEL_1_UP:   return BUTTON_LEVEL_1_UP_PATH;
    case AssetID::BUTTON_LEVEL_1_DOWN: return BUTTON_LEVEL_1_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_2_UP:   return BUTTON_LEVEL_2_UP_PATH;
    case AssetID::BUTTON_LEVEL_2_DOWN: return BUTTON_LEVEL_2_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_3_UP:   return BUTTON_LEVEL_3_UP_PATH;
    case AssetID::BUTTON_LEVEL_3_DOWN: return BUTTON_LEVEL_3_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_4_UP:   return BUTTON_LEVEL_4_UP_PATH;
    case AssetID::BUTTON_LEVEL_4_DOWN: return BUTTON_LEVEL_4_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_5_UP:   return BUTTON_LEVEL_5_UP_PATH;
    case AssetID::BUTTON_LEVEL_5_DOWN: return BUTTON_LEVEL_5_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_6_UP:   return BUTTON_LEVEL_6_UP_PATH;
    case AssetID::BUTTON_LEVEL_6_DOWN: return BUTTON_LEVEL_6_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_7_UP:   return BUTTON_LEVEL_7_UP_PATH;
    case AssetID::BUTTON_LEVEL_7_DOWN: return BUTTON_LEVEL_7_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_8_UP:   return BUTTON_LEVEL_8_UP_PATH;
    case AssetID::BUTTON_LEVEL_8_DOWN: return BUTTON_LEVEL_8_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_9_UP:   return BUTTON_LEVEL_9_UP_PATH;
    case AssetID::BUTTON_LEVEL_9_DOWN: return BUTTON_LEVEL_9_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_10_UP:  return BUTTON_LEVEL_10_UP_PATH;
    case AssetID::BUTTON_LEVEL_10_DOWN:return BUTTON_LEVEL_10_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_11_UP:  return BUTTON_LEVEL_11_UP_PATH;
    case AssetID::BUTTON_LEVEL_11_DOWN:return BUTTON_LEVEL_11_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_12_UP:  return BUTTON_LEVEL_12_UP_PATH;
    case AssetID::BUTTON_LEVEL_12_DOWN:return BUTTON_LEVEL_12_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_13_UP:  return BUTTON_LEVEL_13_UP_PATH;
    case AssetID::BUTTON_LEVEL_13_DOWN:return BUTTON_LEVEL_13_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_14_UP:  return BUTTON_LEVEL_14_UP_PATH;
    case AssetID::BUTTON_LEVEL_14_DOWN:return BUTTON_LEVEL_14_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_15_UP:  return BUTTON_LEVEL_15_UP_PATH;
    case AssetID::BUTTON_LEVEL_15_DOWN:return BUTTON_LEVEL_15_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_16_UP:  return BUTTON_LEVEL_16_UP_PATH;
    case AssetID::BUTTON_LEVEL_16_DOWN:return BUTTON_LEVEL_16_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_17_UP:  return BUTTON_LEVEL_17_UP_PATH;
    case AssetID::BUTTON_LEVEL_17_DOWN:return BUTTON_LEVEL_17_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_18_UP:  return BUTTON_LEVEL_18_UP_PATH;
    case AssetID::BUTTON_LEVEL_18_DOWN:return BUTTON_LEVEL_18_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_19_UP:  return BUTTON_LEVEL_19_UP_PATH;
    case AssetID::BUTTON_LEVEL_19_DOWN:return BUTTON_LEVEL_19_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_20_UP:  return BUTTON_LEVEL_20_UP_PATH;
    case AssetID::BUTTON_LEVEL_20_DOWN:return BUTTON_LEVEL_20_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_21_UP:  return BUTTON_LEVEL_21_UP_PATH;
    case AssetID::BUTTON_LEVEL_21_DOWN:return BUTTON_LEVEL_21_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_22_UP:  return BUTTON_LEVEL_22_UP_PATH;
    case AssetID::BUTTON_LEVEL_22_DOWN:return BUTTON_LEVEL_22_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_23_UP:  return BUTTON_LEVEL_23_UP_PATH;
    case AssetID::BUTTON_LEVEL_23_DOWN:return BUTTON_LEVEL_23_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_24_UP:  return BUTTON_LEVEL_24_UP_PATH;
    case AssetID::BUTTON_LEVEL_24_DOWN:return BUTTON_LEVEL_24_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_25_UP:  return BUTTON_LEVEL_25_UP_PATH;
    case AssetID::BUTTON_LEVEL_25_DOWN:return BUTTON_LEVEL_25_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_26_UP:  return BUTTON_LEVEL_26_UP_PATH;
    case AssetID::BUTTON_LEVEL_26_DOWN:return BUTTON_LEVEL_26_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_27_UP:  return BUTTON_LEVEL_27_UP_PATH;
    case AssetID::BUTTON_LEVEL_27_DOWN:return BUTTON_LEVEL_27_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_28_UP:  return BUTTON_LEVEL_28_UP_PATH;
    case AssetID::BUTTON_LEVEL_28_DOWN:return BUTTON_LEVEL_28_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_29_UP:  return BUTTON_LEVEL_29_UP_PATH;
    case AssetID::BUTTON_LEVEL_29_DOWN:return BUTTON_LEVEL_29_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_30_UP:  return BUTTON_LEVEL_30_UP_PATH;
    case AssetID::BUTTON_LEVEL_30_DOWN:return BUTTON_LEVEL_30_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_31_UP:  return BUTTON_LEVEL_31_UP_PATH;
    case AssetID::BUTTON_LEVEL_31_DOWN:return BUTTON_LEVEL_31_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_32_UP:  return BUTTON_LEVEL_32_UP_PATH;
    case AssetID::BUTTON_LEVEL_32_DOWN:return BUTTON_LEVEL_32_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_33_UP:  return BUTTON_LEVEL_33_UP_PATH;
    case AssetID::BUTTON_LEVEL_33_DOWN:return BUTTON_LEVEL_33_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_34_UP:  return BUTTON_LEVEL_34_UP_PATH;
    case AssetID::BUTTON_LEVEL_34_DOWN:return BUTTON_LEVEL_34_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_35_UP:  return BUTTON_LEVEL_35_UP_PATH;
    case AssetID::BUTTON_LEVEL_35_DOWN:return BUTTON_LEVEL_35_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_36_UP:  return BUTTON_LEVEL_36_UP_PATH;
    case AssetID::BUTTON_LEVEL_36_DOWN:return BUTTON_LEVEL_36_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_37_UP:  return BUTTON_LEVEL_37_UP_PATH;
    case AssetID::BUTTON_LEVEL_37_DOWN:return BUTTON_LEVEL_37_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_38_UP:  return BUTTON_LEVEL_38_UP_PATH;
    case AssetID::BUTTON_LEVEL_38_DOWN:return BUTTON_LEVEL_38_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_39_UP:  return BUTTON_LEVEL_39_UP_PATH;
    case AssetID::BUTTON_LEVEL_39_DOWN:return BUTTON_LEVEL_39_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_40_UP:  return BUTTON_LEVEL_40_UP_PATH;
    case AssetID::BUTTON_LEVEL_40_DOWN:return BUTTON_LEVEL_40_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_41_UP:  return BUTTON_LEVEL_41_UP_PATH;
    case AssetID::BUTTON_LEVEL_41_DOWN:return BUTTON_LEVEL_41_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_42_UP:  return BUTTON_LEVEL_42_UP_PATH;
    case AssetID::BUTTON_LEVEL_42_DOWN:return BUTTON_LEVEL_42_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_43_UP:  return BUTTON_LEVEL_43_UP_PATH;
    case AssetID::BUTTON_LEVEL_43_DOWN:return BUTTON_LEVEL_43_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_44_UP:  return BUTTON_LEVEL_44_UP_PATH;
    case AssetID::BUTTON_LEVEL_44_DOWN:return BUTTON_LEVEL_44_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_45_UP:  return BUTTON_LEVEL_45_UP_PATH;
    case AssetID::BUTTON_LEVEL_45_DOWN:return BUTTON_LEVEL_45_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_46_UP:  return BUTTON_LEVEL_46_UP_PATH;
    case AssetID::BUTTON_LEVEL_46_DOWN:return BUTTON_LEVEL_46_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_47_UP:  return BUTTON_LEVEL_47_UP_PATH;
    case AssetID::BUTTON_LEVEL_47_DOWN:return BUTTON_LEVEL_47_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_48_UP:  return BUTTON_LEVEL_48_UP_PATH;
    case AssetID::BUTTON_LEVEL_48_DOWN:return BUTTON_LEVEL_48_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_49_UP:  return BUTTON_LEVEL_49_UP_PATH;
    case AssetID::BUTTON_LEVEL_49_DOWN:return BUTTON_LEVEL_49_DOWN_PATH;
    case AssetID::BUTTON_LEVEL_50_UP:  return BUTTON_LEVEL_50_UP_PATH;
    case AssetID::BUTTON_LEVEL_50_DOWN:return BUTTON_LEVEL_50_DOWN_PATH;

        //INTERFACE
    case AssetID::GREEN_FRAME_TOP_LEFT:     return GREEN_FRAME_TOP_LEFT;
    case AssetID::GREEN_FRAME_TOP:          return GREEN_FRAME_TOP;
    case AssetID::GREEN_FRAME_TOP_RIGHT:    return GREEN_FRAME_TOP_RIGHT;
    case AssetID::GREEN_FRAME_LEFT:         return GREEN_FRAME_LEFT;
    case AssetID::GREEN_FRAME_MIDDLE:       return GREEN_FRAME_MIDDLE;
    case AssetID::GREEN_FRAME_RIGHT:        return GREEN_FRAME_RIGHT;
    case AssetID::GREEN_FRAME_BOTTOM_LEFT:  return GREEN_FRAME_BOTTOM_LEFT;
    case AssetID::GREEN_FRAME_BOTTOM:       return GREEN_FRAME_BOTTOM;
    case AssetID::GREEN_FRAME_BOTTOM_RIGHT: return GREEN_FRAME_BOTTOM_RIGHT;
    case AssetID::GREEN_BAR_LEFT:           return GREEN_BAR_LEFT;
    case AssetID::GREEN_BAR_MIDDLE:         return GREEN_BAR_MIDDLE;
    case AssetID::GREEN_BAR_RIGHT:          return GREEN_BAR_RIGHT;

    case AssetID::GRAY_FRAME_TOP_LEFT:     return GRAY_FRAME_TOP_LEFT;
    case AssetID::GRAY_FRAME_TOP:          return GRAY_FRAME_TOP;
    case AssetID::GRAY_FRAME_TOP_RIGHT:    return GRAY_FRAME_TOP_RIGHT;
    case AssetID::GRAY_FRAME_LEFT:         return GRAY_FRAME_LEFT;
    case AssetID::GRAY_FRAME_MIDDLE:       return GRAY_FRAME_MIDDLE;
    case AssetID::GRAY_FRAME_RIGHT:        return GRAY_FRAME_RIGHT;
    case AssetID::GRAY_FRAME_BOTTOM_LEFT:  return GRAY_FRAME_BOTTOM_LEFT;
    case AssetID::GRAY_FRAME_BOTTOM:       return GRAY_FRAME_BOTTOM;
    case AssetID::GRAY_FRAME_BOTTOM_RIGHT: return GRAY_FRAME_BOTTOM_RIGHT;
    case AssetID::GRAY_BAR_LEFT:           return GRAY_BAR_LEFT;
    case AssetID::GRAY_BAR_MIDDLE:         return GRAY_BAR_MIDDLE;
    case AssetID::GRAY_BAR_RIGHT:          return GRAY_BAR_RIGHT;

    case AssetID::BRICK_FRAME_TOP_LEFT:     return BRICK_FRAME_TOP_LEFT;
    case AssetID::BRICK_FRAME_TOP:          return BRICK_FRAME_TOP;
    case AssetID::BRICK_FRAME_TOP_RIGHT:    return BRICK_FRAME_TOP_RIGHT;
    case AssetID::BRICK_FRAME_LEFT:         return BRICK_FRAME_LEFT;
    case AssetID::BRICK_FRAME_MIDDLE:       return BRICK_FRAME_MIDDLE;
    case AssetID::BRICK_FRAME_RIGHT:        return BRICK_FRAME_RIGHT;
    case AssetID::BRICK_FRAME_BOTTOM_LEFT:  return BRICK_FRAME_BOTTOM_LEFT;
    case AssetID::BRICK_FRAME_BOTTOM:       return BRICK_FRAME_BOTTOM;
    case AssetID::BRICK_FRAME_BOTTOM_RIGHT: return BRICK_FRAME_BOTTOM_RIGHT;
    case AssetID::BRICK_BAR_LEFT:           return BRICK_BAR_LEFT;
    case AssetID::BRICK_BAR_MIDDLE:         return BRICK_BAR_MIDDLE;
    case AssetID::BRICK_BAR_RIGHT:          return BRICK_BAR_RIGHT;

    case AssetID::WARN_FRAME_TOP_LEFT:     return WARN_FRAME_TOP_LEFT;
    case AssetID::WARN_FRAME_TOP:          return WARN_FRAME_TOP;
    case AssetID::WARN_FRAME_TOP_RIGHT:    return WARN_FRAME_TOP_RIGHT;
    case AssetID::WARN_FRAME_LEFT:         return WARN_FRAME_LEFT;
    case AssetID::WARN_FRAME_MIDDLE:       return WARN_FRAME_MIDDLE;
    case AssetID::WARN_FRAME_RIGHT:        return WARN_FRAME_RIGHT;
    case AssetID::WARN_FRAME_BOTTOM_LEFT:  return WARN_FRAME_BOTTOM_LEFT;
    case AssetID::WARN_FRAME_BOTTOM:       return WARN_FRAME_BOTTOM;
    case AssetID::WARN_FRAME_BOTTOM_RIGHT: return WARN_FRAME_BOTTOM_RIGHT;
    case AssetID::WARN_BAR_LEFT:           return WARN_BAR_LEFT;
    case AssetID::WARN_BAR_MIDDLE:         return WARN_BAR_MIDDLE;
    case AssetID::WARN_BAR_RIGHT:          return WARN_BAR_RIGHT;
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
