#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

enum class AssetID {

    // FONT
    MAIN_FONT,

    // SOUND
    SOUND_UI_PUSHED,
    SOUND_UI_HOVERED,
    SOUND_JUMP,
    SOUND_MUSIC,

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
    BUTTON_GREY_UP,
    BUTTON_GREY_DOWN,
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

    // PLATFORM TILES
    PLATFORM_GRASS_1_TOP_LEFT,
    PLATFORM_GRASS_1_TOP,
    PLATFORM_GRASS_1_TOP_RIGHT,
    PLATFORM_GRASS_1_MIDDLE_LEFT,
    PLATFORM_GRASS_1_MIDDLE,
    PLATFORM_GRASS_1_MIDDLE_RIGHT,
    PLATFORM_GRASS_1_BOTTOM_LEFT,
    PLATFORM_GRASS_1_BOTTOM,
    PLATFORM_GRASS_1_BOTTOM_RIGHT,
    PLATFORM_GRASS_1_INSIDE_TOP_LEFT,
    PLATFORM_GRASS_1_INSIDE_TOP_RIGHT,
    PLATFORM_GRASS_1_INSIDE_BOTTOM_LEFT,
    PLATFORM_GRASS_1_INSIDE_BOTTOM_RIGHT,

    PLATFORM_GRASS_2_TOP_LEFT,
    PLATFORM_GRASS_2_TOP,
    PLATFORM_GRASS_2_TOP_RIGHT,
    PLATFORM_GRASS_2_MIDDLE_LEFT,
    PLATFORM_GRASS_2_MIDDLE,
    PLATFORM_GRASS_2_MIDDLE_RIGHT,
    PLATFORM_GRASS_2_BOTTOM_LEFT,
    PLATFORM_GRASS_2_BOTTOM,
    PLATFORM_GRASS_2_BOTTOM_RIGHT,
    PLATFORM_GRASS_2_INSIDE_TOP_LEFT,
    PLATFORM_GRASS_2_INSIDE_TOP_RIGHT,
    PLATFORM_GRASS_2_INSIDE_BOTTOM_LEFT,
    PLATFORM_GRASS_2_INSIDE_BOTTOM_RIGHT,

    PLATFORM_BLOCK_1_TOP_LEFT,
    PLATFORM_BLOCK_1_TOP,
    PLATFORM_BLOCK_1_TOP_RIGHT,
    PLATFORM_BLOCK_1_MIDDLE_LEFT,
    PLATFORM_BLOCK_1_MIDDLE,
    PLATFORM_BLOCK_1_MIDDLE_RIGHT,
    PLATFORM_BLOCK_1_BOTTOM_LEFT,
    PLATFORM_BLOCK_1_BOTTOM,
    PLATFORM_BLOCK_1_BOTTOM_RIGHT,
    PLATFORM_BLOCK_1_INSIDE_TOP_LEFT,
    PLATFORM_BLOCK_1_INSIDE_TOP_RIGHT,
    PLATFORM_BLOCK_1_INSIDE_BOTTOM_LEFT,
    PLATFORM_BLOCK_1_INSIDE_BOTTOM_RIGHT,

    PLATFORM_BLOCK_2_TOP_LEFT,
    PLATFORM_BLOCK_2_TOP,
    PLATFORM_BLOCK_2_TOP_RIGHT,
    PLATFORM_BLOCK_2_MIDDLE_LEFT,
    PLATFORM_BLOCK_2_MIDDLE,
    PLATFORM_BLOCK_2_MIDDLE_RIGHT,
    PLATFORM_BLOCK_2_BOTTOM_LEFT,
    PLATFORM_BLOCK_2_BOTTOM,
    PLATFORM_BLOCK_2_BOTTOM_RIGHT,
    PLATFORM_BLOCK_2_INSIDE_TOP_LEFT,
    PLATFORM_BLOCK_2_INSIDE_TOP_RIGHT,
    PLATFORM_BLOCK_2_INSIDE_BOTTOM_LEFT,
    PLATFORM_BLOCK_2_INSIDE_BOTTOM_RIGHT,

    PLATFORM_METAL_1_TOP_LEFT,
    PLATFORM_METAL_1_TOP,
    PLATFORM_METAL_1_TOP_RIGHT,
    PLATFORM_METAL_1_MIDDLE_LEFT,
    PLATFORM_METAL_1_MIDDLE,
    PLATFORM_METAL_1_MIDDLE_RIGHT,
    PLATFORM_METAL_1_BOTTOM_LEFT,
    PLATFORM_METAL_1_BOTTOM,
    PLATFORM_METAL_1_BOTTOM_RIGHT,
    PLATFORM_METAL_1_INSIDE_TOP_LEFT,
    PLATFORM_METAL_1_INSIDE_TOP_RIGHT,
    PLATFORM_METAL_1_INSIDE_BOTTOM_LEFT,
    PLATFORM_METAL_1_INSIDE_BOTTOM_RIGHT,

    PLATFORM_METAL_2_TOP_LEFT,
    PLATFORM_METAL_2_TOP,
    PLATFORM_METAL_2_TOP_RIGHT,
    PLATFORM_METAL_2_MIDDLE_LEFT,
    PLATFORM_METAL_2_MIDDLE,
    PLATFORM_METAL_2_MIDDLE_RIGHT,
    PLATFORM_METAL_2_BOTTOM_LEFT,
    PLATFORM_METAL_2_BOTTOM,
    PLATFORM_METAL_2_BOTTOM_RIGHT,
    PLATFORM_METAL_2_INSIDE_TOP_LEFT,
    PLATFORM_METAL_2_INSIDE_TOP_RIGHT,
    PLATFORM_METAL_2_INSIDE_BOTTOM_LEFT,
    PLATFORM_METAL_2_INSIDE_BOTTOM_RIGHT,

    PLATFORM_FULL_GREEN_H_BAR_LEFT,
    PLATFORM_FULL_GREEN_H_BAR,
    PLATFORM_FULL_GREEN_H_BAR_RIGHT,
    PLATFORM_FULL_GREEN_V_BAR_TOP,
    PLATFORM_FULL_GREEN_V_BAR,
    PLATFORM_FULL_GREEN_V_BAR_BOTTOM,
    PLATFORM_FULL_GREEN_1_1,
    PLATFORM_FULL_GREEN_2_2_TOP_LEFT,
    PLATFORM_FULL_GREEN_2_2_TOP_RIGHT,
    PLATFORM_FULL_GREEN_2_2_BOTTOM_LEFT,
    PLATFORM_FULL_GREEN_2_2_BOTTOM_RIGHT,

    PLATFORM_FULL_METAL_H_BAR_LEFT,
    PLATFORM_FULL_METAL_H_BAR,
    PLATFORM_FULL_METAL_H_BAR_RIGHT,
    PLATFORM_FULL_METAL_V_BAR_TOP,
    PLATFORM_FULL_METAL_V_BAR,
    PLATFORM_FULL_METAL_V_BAR_BOTTOM,
    PLATFORM_FULL_METAL_1_1,
    PLATFORM_FULL_METAL_2_2_TOP_LEFT,
    PLATFORM_FULL_METAL_2_2_TOP_RIGHT,
    PLATFORM_FULL_METAL_2_2_BOTTOM_LEFT,
    PLATFORM_FULL_METAL_2_2_BOTTOM_RIGHT,

    PLATFORM_MINI_1_LEFT,
    PLATFORM_MINI_1,
    PLATFORM_MINI_1_RIGHT,
    PLATFORM_MINI_2_LEFT,
    PLATFORM_MINI_2,
    PLATFORM_MINI_2_RIGHT,
    PLATFORM_MINI_3_LEFT,
    PLATFORM_MINI_3,
    PLATFORM_MINI_3_RIGHT,

    // MAIN CHARACTER
    MC_1_DOUBLE_JUMP,
    MC_1_FALL,
    MC_1_HIT,
    MC_1_IDLE,
    MC_1_JUMP,
    MC_1_RUN,
    MC_1_WALL_JUMP,

    MC_2_DOUBLE_JUMP,
    MC_2_FALL,
    MC_2_HIT,
    MC_2_IDLE,
    MC_2_JUMP,
    MC_2_RUN,
    MC_2_WALL_JUMP,

    MC_3_DOUBLE_JUMP,
    MC_3_FALL,
    MC_3_HIT,
    MC_3_IDLE,
    MC_3_JUMP,
    MC_3_RUN,
    MC_3_WALL_JUMP,

    MC_APPEARING,
    MC_DESAPPEARING,

    // ENEMY
    ENEMY_TV_FALL,
    ENEMY_TV_HIT,
    ENEMY_TV_IDLE,
    ENEMY_TV_JUMP,
    ENEMY_TV_RUN,

    ENEMY_CACTUS_FALL,
    ENEMY_CACTUS_HIT,
    ENEMY_CACTUS_IDLE,
    ENEMY_CACTUS_JUMP,
    ENEMY_CACTUS_RUN,

    ENEMY_BARREL_CHARGE,
    ENEMY_BARREL_HIT,
    ENEMY_BARREL_IDLE,
    ENEMY_BARREL_STUN,
    ENEMY_BARREL_WALK,

    ENEMY_CANON_ATTACK,
    ENEMY_CANON_HIT,
    ENEMY_CANON_IDLE,
    ENEMY_CANON_WALK,
    ENEMY_CANON_BALL_1,
    ENEMY_CANON_BALL_2,

    ENEMY_FLYER_ATTACK,
    ENEMY_FLYER_FLY,
    ENEMY_FLYER_HIT,
    ENEMY_FLYER_IDLE,

    ENEMY_TOAD_ATTACK,
    ENEMY_TOAD_HIT,
    ENEMY_TOAD_IDLE,
    ENEMY_TOAD_RUN,
    ENEMY_TOAD_RUN_ATTACK,

    // OBJECTS

    CHECKPOINT_EMPTY,
    CHECKPOINT_1_OUT,
    CHECKPOINT_2_OUT,
    CHECKPOINT_1_IDLE,
    CHECKPOINT_2_IDLE,

    CUP_IDLE,
    CUP_TOUCH,

    GEM_1,
    GEM_2,
    GEM_3,
    GEM_4,
    GEM_5,
    GEM_6,

    // TRAP
    SAW,
    SPIKE,
    FRAGILE_PLATFORM,
    ELECTRICITY
};

inline const std::string& assetPath(AssetID id) {

    // FONT 
    static const std::string MAIN_FONT_PATH = "Minecraft.ttf";

    // SOUND
    static const std::string SOUND_UI_PUSHED_PATH = "assets/Sound/UI_pushed.wav";
    static const std::string SOUND_UI_HOVERED_PATH = "assets/Sound/UI_hovered.wav";
    static const std::string SOUND_JUMP_PATH = "assets/Sound/jump.wav";
    static const std::string SOUND_MUSIC_PATH = "assets/Sound/music.wav";

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
    static const std::string BUTTON_GREY_UP_PATH = "assets/5 GUI/Buttons/Button_05.png";
    static const std::string BUTTON_GREY_DOWN_PATH = "assets/5 GUI/Buttons/Button_06.png";
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
    static const std::string GREEN_FRAME_TOP_LEFT_PATH = "assets/5 GUI/Interface/Tile_01.png";
    static const std::string GREEN_FRAME_TOP_PATH = "assets/5 GUI/Interface/Tile_02.png";
    static const std::string GREEN_FRAME_TOP_RIGHT_PATH = "assets/5 GUI/Interface/Tile_03.png";
    static const std::string GREEN_FRAME_LEFT_PATH = "assets/5 GUI/Interface/Tile_14.png";
    static const std::string GREEN_FRAME_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_15.png";
    static const std::string GREEN_FRAME_RIGHT_PATH = "assets/5 GUI/Interface/Tile_16.png";
    static const std::string GREEN_FRAME_BOTTOM_LEFT_PATH = "assets/5 GUI/Interface/Tile_27.png";
    static const std::string GREEN_FRAME_BOTTOM_PATH = "assets/5 GUI/Interface/Tile_28.png";
    static const std::string GREEN_FRAME_BOTTOM_RIGHT_PATH = "assets/5 GUI/Interface/Tile_29.png";
    static const std::string GREEN_BAR_LEFT_PATH = "assets/5 GUI/Interface/Tile_11.png";
    static const std::string GREEN_BAR_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_12.png";
    static const std::string GREEN_BAR_RIGHT_PATH = "assets/5 GUI/Interface/Tile_13.png";

    static const std::string GRAY_FRAME_TOP_LEFT_PATH = "assets/5 GUI/Interface/Tile_06.png";
    static const std::string GRAY_FRAME_TOP_PATH = "assets/5 GUI/Interface/Tile_07.png";
    static const std::string GRAY_FRAME_TOP_RIGHT_PATH = "assets/5 GUI/Interface/Tile_08.png";
    static const std::string GRAY_FRAME_LEFT_PATH = "assets/5 GUI/Interface/Tile_19.png";
    static const std::string GRAY_FRAME_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_20.png";
    static const std::string GRAY_FRAME_RIGHT_PATH = "assets/5 GUI/Interface/Tile_21.png";
    static const std::string GRAY_FRAME_BOTTOM_LEFT_PATH = "assets/5 GUI/Interface/Tile_32.png";
    static const std::string GRAY_FRAME_BOTTOM_PATH = "assets/5 GUI/Interface/Tile_33.png";
    static const std::string GRAY_FRAME_BOTTOM_RIGHT_PATH = "assets/5 GUI/Interface/Tile_34.png";
    static const std::string GRAY_BAR_LEFT_PATH = "assets/5 GUI/Interface/Tile_24.png";
    static const std::string GRAY_BAR_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_25.png";
    static const std::string GRAY_BAR_RIGHT_PATH = "assets/5 GUI/Interface/Tile_26.png";

    static const std::string BRICK_FRAME_TOP_LEFT_PATH = "assets/5 GUI/Interface/Tile_40.png";
    static const std::string BRICK_FRAME_TOP_PATH = "assets/5 GUI/Interface/Tile_41.png";
    static const std::string BRICK_FRAME_TOP_RIGHT_PATH = "assets/5 GUI/Interface/Tile_42.png";
    static const std::string BRICK_FRAME_LEFT_PATH = "assets/5 GUI/Interface/Tile_53.png";
    static const std::string BRICK_FRAME_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_54.png";
    static const std::string BRICK_FRAME_RIGHT_PATH = "assets/5 GUI/Interface/Tile_55.png";
    static const std::string BRICK_FRAME_BOTTOM_LEFT_PATH = "assets/5 GUI/Interface/Tile_66.png";
    static const std::string BRICK_FRAME_BOTTOM_PATH = "assets/5 GUI/Interface/Tile_67.png";
    static const std::string BRICK_FRAME_BOTTOM_RIGHT_PATH = "assets/5 GUI/Interface/Tile_68.png";
    static const std::string BRICK_BAR_LEFT_PATH = "assets/5 GUI/Interface/Tile_37.png";
    static const std::string BRICK_BAR_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_38.png";
    static const std::string BRICK_BAR_RIGHT_PATH = "assets/5 GUI/Interface/Tile_39.png";

    static const std::string WARN_FRAME_TOP_LEFT_PATH = "assets/5 GUI/Interface/Tile_45.png";
    static const std::string WARN_FRAME_TOP_PATH = "assets/5 GUI/Interface/Tile_46.png";
    static const std::string WARN_FRAME_TOP_RIGHT_PATH = "assets/5 GUI/Interface/Tile_47.png";
    static const std::string WARN_FRAME_LEFT_PATH = "assets/5 GUI/Interface/Tile_58.png";
    static const std::string WARN_FRAME_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_59.png";
    static const std::string WARN_FRAME_RIGHT_PATH = "assets/5 GUI/Interface/Tile_60.png";
    static const std::string WARN_FRAME_BOTTOM_LEFT_PATH = "assets/5 GUI/Interface/Tile_71.png";
    static const std::string WARN_FRAME_BOTTOM_PATH = "assets/5 GUI/Interface/Tile_72.png";
    static const std::string WARN_FRAME_BOTTOM_RIGHT_PATH = "assets/5 GUI/Interface/Tile_73.png";
    static const std::string WARN_BAR_LEFT_PATH = "assets/5 GUI/Interface/Tile_50.png";
    static const std::string WARN_BAR_MIDDLE_PATH = "assets/5 GUI/Interface/Tile_51.png";
    static const std::string WARN_BAR_RIGHT_PATH = "assets/5 GUI/Interface/Tile_52.png";

    // PLATFORM TILES
    static const std::string PLATFORM_GRASS_1_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_01.png";
    static const std::string PLATFORM_GRASS_1_TOP_PATH = "assets/2 Locations/Tiles/Tile_02.png";
    static const std::string PLATFORM_GRASS_1_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_03.png";
    static const std::string PLATFORM_GRASS_1_MIDDLE_LEFT_PATH = "assets/2 Locations/Tiles/Tile_15.png";
    static const std::string PLATFORM_GRASS_1_MIDDLE_PATH = "assets/2 Locations/Tiles/Tile_16.png";
    static const std::string PLATFORM_GRASS_1_MIDDLE_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_17.png";
    static const std::string PLATFORM_GRASS_1_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_29.png";
    static const std::string PLATFORM_GRASS_1_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_30.png";
    static const std::string PLATFORM_GRASS_1_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_31.png";
    static const std::string PLATFORM_GRASS_1_INSIDE_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_04.png";
    static const std::string PLATFORM_GRASS_1_INSIDE_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_05.png";
    static const std::string PLATFORM_GRASS_1_INSIDE_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_18.png";
    static const std::string PLATFORM_GRASS_1_INSIDE_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_19.png";

    static const std::string PLATFORM_GRASS_2_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_06.png";
    static const std::string PLATFORM_GRASS_2_TOP_PATH = "assets/2 Locations/Tiles/Tile_07.png";
    static const std::string PLATFORM_GRASS_2_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_08.png";
    static const std::string PLATFORM_GRASS_2_MIDDLE_LEFT_PATH = "assets/2 Locations/Tiles/Tile_20.png";
    static const std::string PLATFORM_GRASS_2_MIDDLE_PATH = "assets/2 Locations/Tiles/Tile_21.png";
    static const std::string PLATFORM_GRASS_2_MIDDLE_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_22.png";
    static const std::string PLATFORM_GRASS_2_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_34.png";
    static const std::string PLATFORM_GRASS_2_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_35.png";
    static const std::string PLATFORM_GRASS_2_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_36.png";
    static const std::string PLATFORM_GRASS_2_INSIDE_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_09.png";
    static const std::string PLATFORM_GRASS_2_INSIDE_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_10.png";
    static const std::string PLATFORM_GRASS_2_INSIDE_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_23.png";
    static const std::string PLATFORM_GRASS_2_INSIDE_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_24.png";

    static const std::string PLATFORM_BLOCK_1_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_43.png";
    static const std::string PLATFORM_BLOCK_1_TOP_PATH = "assets/2 Locations/Tiles/Tile_44.png";
    static const std::string PLATFORM_BLOCK_1_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_45.png";
    static const std::string PLATFORM_BLOCK_1_MIDDLE_LEFT_PATH = "assets/2 Locations/Tiles/Tile_57.png";
    static const std::string PLATFORM_BLOCK_1_MIDDLE_PATH = "assets/2 Locations/Tiles/Tile_58.png";
    static const std::string PLATFORM_BLOCK_1_MIDDLE_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_59.png";
    static const std::string PLATFORM_BLOCK_1_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_71.png";
    static const std::string PLATFORM_BLOCK_1_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_72.png";
    static const std::string PLATFORM_BLOCK_1_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_73.png";
    static const std::string PLATFORM_BLOCK_1_INSIDE_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_46.png";
    static const std::string PLATFORM_BLOCK_1_INSIDE_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_47.png";
    static const std::string PLATFORM_BLOCK_1_INSIDE_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_60.png";
    static const std::string PLATFORM_BLOCK_1_INSIDE_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_61.png";

    static const std::string PLATFORM_BLOCK_2_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_90.png";
    static const std::string PLATFORM_BLOCK_2_TOP_PATH = "assets/2 Locations/Tiles/Tile_91.png";
    static const std::string PLATFORM_BLOCK_2_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_92.png";
    static const std::string PLATFORM_BLOCK_2_MIDDLE_LEFT_PATH = "assets/2 Locations/Tiles/Tile_104.png";
    static const std::string PLATFORM_BLOCK_2_MIDDLE_PATH = "assets/2 Locations/Tiles/Tile_105.png";
    static const std::string PLATFORM_BLOCK_2_MIDDLE_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_106.png";
    static const std::string PLATFORM_BLOCK_2_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_118.png";
    static const std::string PLATFORM_BLOCK_2_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_119.png";
    static const std::string PLATFORM_BLOCK_2_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_120.png";
    static const std::string PLATFORM_BLOCK_2_INSIDE_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_93.png";
    static const std::string PLATFORM_BLOCK_2_INSIDE_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_94.png";
    static const std::string PLATFORM_BLOCK_2_INSIDE_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_107.png";
    static const std::string PLATFORM_BLOCK_2_INSIDE_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_108.png";

    static const std::string PLATFORM_METAL_1_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_48.png";
    static const std::string PLATFORM_METAL_1_TOP_PATH = "assets/2 Locations/Tiles/Tile_49.png";
    static const std::string PLATFORM_METAL_1_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_50.png";
    static const std::string PLATFORM_METAL_1_MIDDLE_LEFT_PATH = "assets/2 Locations/Tiles/Tile_62.png";
    static const std::string PLATFORM_METAL_1_MIDDLE_PATH = "assets/2 Locations/Tiles/Tile_63.png";
    static const std::string PLATFORM_METAL_1_MIDDLE_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_64.png";
    static const std::string PLATFORM_METAL_1_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_76.png";
    static const std::string PLATFORM_METAL_1_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_77.png";
    static const std::string PLATFORM_METAL_1_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_78.png";
    static const std::string PLATFORM_METAL_1_INSIDE_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_51.png";
    static const std::string PLATFORM_METAL_1_INSIDE_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_52.png";
    static const std::string PLATFORM_METAL_1_INSIDE_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_65.png";
    static const std::string PLATFORM_METAL_1_INSIDE_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_66.png";

    static const std::string PLATFORM_METAL_2_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_85.png";
    static const std::string PLATFORM_METAL_2_TOP_PATH = "assets/2 Locations/Tiles/Tile_86.png";
    static const std::string PLATFORM_METAL_2_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_87.png";
    static const std::string PLATFORM_METAL_2_MIDDLE_LEFT_PATH = "assets/2 Locations/Tiles/Tile_99.png";
    static const std::string PLATFORM_METAL_2_MIDDLE_PATH = "assets/2 Locations/Tiles/Tile_100.png";
    static const std::string PLATFORM_METAL_2_MIDDLE_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_101.png";
    static const std::string PLATFORM_METAL_2_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_113.png";
    static const std::string PLATFORM_METAL_2_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_114.png";
    static const std::string PLATFORM_METAL_2_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_115.png";
    static const std::string PLATFORM_METAL_2_INSIDE_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_88.png";
    static const std::string PLATFORM_METAL_2_INSIDE_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_89.png";
    static const std::string PLATFORM_METAL_2_INSIDE_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_102.png";
    static const std::string PLATFORM_METAL_2_INSIDE_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_103.png";

    static const std::string PLATFORM_FULL_GREEN_H_BAR_LEFT_PATH = "assets/2 Locations/Tiles/Tile_53.png";
    static const std::string PLATFORM_FULL_GREEN_H_BAR_PATH = "assets/2 Locations/Tiles/Tile_54.png";
    static const std::string PLATFORM_FULL_GREEN_H_BAR_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_55.png";
    static const std::string PLATFORM_FULL_GREEN_V_BAR_TOP_PATH = "assets/2 Locations/Tiles/Tile_56.png";
    static const std::string PLATFORM_FULL_GREEN_V_BAR_PATH = "assets/2 Locations/Tiles/Tile_70.png";
    static const std::string PLATFORM_FULL_GREEN_V_BAR_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_84.png";
    static const std::string PLATFORM_FULL_GREEN_1_1_PATH = "assets/2 Locations/Tiles/Tile_67.png";
    static const std::string PLATFORM_FULL_GREEN_2_2_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_68.png";
    static const std::string PLATFORM_FULL_GREEN_2_2_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_69.png";
    static const std::string PLATFORM_FULL_GREEN_2_2_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_82.png";
    static const std::string PLATFORM_FULL_GREEN_2_2_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_83.png";

    static const std::string PLATFORM_FULL_METAL_H_BAR_LEFT_PATH = "assets/2 Locations/Tiles/Tile_11.png";
    static const std::string PLATFORM_FULL_METAL_H_BAR_PATH = "assets/2 Locations/Tiles/Tile_12.png";
    static const std::string PLATFORM_FULL_METAL_H_BAR_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_13.png";
    static const std::string PLATFORM_FULL_METAL_V_BAR_TOP_PATH = "assets/2 Locations/Tiles/Tile_14.png";
    static const std::string PLATFORM_FULL_METAL_V_BAR_PATH = "assets/2 Locations/Tiles/Tile_28.png";
    static const std::string PLATFORM_FULL_METAL_V_BAR_BOTTOM_PATH = "assets/2 Locations/Tiles/Tile_42.png";
    static const std::string PLATFORM_FULL_METAL_1_1_PATH = "assets/2 Locations/Tiles/Tile_25.png";
    static const std::string PLATFORM_FULL_METAL_2_2_TOP_LEFT_PATH = "assets/2 Locations/Tiles/Tile_26.png";
    static const std::string PLATFORM_FULL_METAL_2_2_TOP_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_27.png";
    static const std::string PLATFORM_FULL_METAL_2_2_BOTTOM_LEFT_PATH = "assets/2 Locations/Tiles/Tile_40.png";
    static const std::string PLATFORM_FULL_METAL_2_2_BOTTOM_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_41.png";

    static const std::string PLATFORM_MINI_1_LEFT_PATH = "assets/2 Locations/Tiles/Tile_95.png";
    static const std::string PLATFORM_MINI_1_PATH = "assets/2 Locations/Tiles/Tile_96.png";
    static const std::string PLATFORM_MINI_1_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_97.png";
    static const std::string PLATFORM_MINI_2_LEFT_PATH = "assets/2 Locations/Tiles/Tile_109.png";
    static const std::string PLATFORM_MINI_2_PATH = "assets/2 Locations/Tiles/Tile_110.png";
    static const std::string PLATFORM_MINI_2_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_111.png";
    static const std::string PLATFORM_MINI_3_LEFT_PATH = "assets/2 Locations/Tiles/Tile_123.png";
    static const std::string PLATFORM_MINI_3_PATH = "assets/2 Locations/Tiles/Tile_124.png";
    static const std::string PLATFORM_MINI_3_RIGHT_PATH = "assets/2 Locations/Tiles/Tile_125.png";

    // MAIN CHARACTER
    static const std::string MC_1_DOUBLE_JUMP_PATH = "assets/1 Main Characters/1/Double_Jump.png";
    static const std::string MC_1_FALL_PATH = "assets/1 Main Characters/1/Fall.png";
    static const std::string MC_1_HIT_PATH = "assets/1 Main Characters/1/Hit.png";
    static const std::string MC_1_IDLE_PATH = "assets/1 Main Characters/1/Idle.png";
    static const std::string MC_1_JUMP_PATH = "assets/1 Main Characters/1/Jump.png";
    static const std::string MC_1_RUN_PATH = "assets/1 Main Characters/1/Run.png";
    static const std::string MC_1_WALL_JUMP_PATH = "assets/1 Main Characters/1/Wall_Jump.png";

    static const std::string MC_2_DOUBLE_JUMP_PATH = "assets/1 Main Characters/2/Double_Jump.png";
    static const std::string MC_2_FALL_PATH = "assets/1 Main Characters/2/Fall.png";
    static const std::string MC_2_HIT_PATH = "assets/1 Main Characters/2/Hit.png";
    static const std::string MC_2_IDLE_PATH = "assets/1 Main Characters/2/Idle.png";
    static const std::string MC_2_JUMP_PATH = "assets/1 Main Characters/2/Jump.png";
    static const std::string MC_2_RUN_PATH = "assets/1 Main Characters/2/Run.png";
    static const std::string MC_2_WALL_JUMP_PATH = "assets/1 Main Characters/2/Wall_Jump.png";

    static const std::string MC_3_DOUBLE_JUMP_PATH = "assets/1 Main Characters/3/Double_Jump.png";
    static const std::string MC_3_FALL_PATH = "assets/1 Main Characters/3/Fall.png";
    static const std::string MC_3_HIT_PATH = "assets/1 Main Characters/3/Hit.png";
    static const std::string MC_3_IDLE_PATH = "assets/1 Main Characters/3/Idle.png";
    static const std::string MC_3_JUMP_PATH = "assets/1 Main Characters/3/Jump.png";
    static const std::string MC_3_RUN_PATH = "assets/1 Main Characters/3/Run.png";
    static const std::string MC_3_WALL_JUMP_PATH = "assets/1 Main Characters/3/Wall_Jump.png";

    static const std::string MC_APPEARING_PATH = "assets/1 Main Characters/Appearing.png";
    static const std::string MC_DESAPPEARING_PATH = "assets/1 Main Characters/Desappearing.png";

    //ENEMY

    static const std::string ENEMY_TV_FALL_PATH = "assets/4 Enemies/1/Fall.png";
    static const std::string ENEMY_TV_HIT_PATH = "assets/4 Enemies/1/Hit.png";
    static const std::string ENEMY_TV_IDLE_PATH = "assets/4 Enemies/1/Idle.png";
    static const std::string ENEMY_TV_JUMP_PATH = "assets/4 Enemies/1/Jump.png";
    static const std::string ENEMY_TV_RUN_PATH = "assets/4 Enemies/1/Run.png";

    static const std::string ENEMY_CACTUS_FALL_PATH = "assets/4 Enemies/2/Fall.png";
    static const std::string ENEMY_CACTUS_HIT_PATH = "assets/4 Enemies/2/Hit.png";
    static const std::string ENEMY_CACTUS_IDLE_PATH = "assets/4 Enemies/2/Idle.png";
    static const std::string ENEMY_CACTUS_JUMP_PATH = "assets/4 Enemies/2/Jump.png";
    static const std::string ENEMY_CACTUS_RUN_PATH = "assets/4 Enemies/2/Run.png";

    static const std::string ENEMY_BARREL_CHARGE_PATH = "assets/4 Enemies/3/Charge.png";
    static const std::string ENEMY_BARREL_HIT_PATH = "assets/4 Enemies/3/Hit.png";
    static const std::string ENEMY_BARREL_IDLE_PATH = "assets/4 Enemies/3/Idle.png";
    static const std::string ENEMY_BARREL_STUN_PATH = "assets/4 Enemies/3/Stun.png";
    static const std::string ENEMY_BARREL_WALK_PATH = "assets/4 Enemies/3/Walk.png";

    static const std::string ENEMY_CANON_ATTACK_PATH = "assets/4 Enemies/4/Attack.png";
    static const std::string ENEMY_CANON_HIT_PATH = "assets/4 Enemies/4/Hit.png";
    static const std::string ENEMY_CANON_IDLE_PATH = "assets/4 Enemies/4/Idle.png";
    static const std::string ENEMY_CANON_WALK_PATH = "assets/4 Enemies/4/Walk.png";
    static const std::string ENEMY_CANON_BALL_1_PATH = "assets/4 Enemies/4/Cannonball1.png";
    static const std::string ENEMY_CANON_BALL_2_PATH = "assets/4 Enemies/4/Cannonball2.png";

    static const std::string ENEMY_FLYER_ATTACK_PATH = "assets/4 Enemies/5/Attack.png";
    static const std::string ENEMY_FLYER_FLY_PATH = "assets/4 Enemies/5/Fly.png";
    static const std::string ENEMY_FLYER_HIT_PATH = "assets/4 Enemies/5/Hit.png";
    static const std::string ENEMY_FLYER_IDLE_PATH = "assets/4 Enemies/5/Idle.png";

    static const std::string ENEMY_TOAD_ATTACK_PATH = "assets/4 Enemies/6/Attack.png";
    static const std::string ENEMY_TOAD_HIT_PATH = "assets/4 Enemies/6/Hit.png";
    static const std::string ENEMY_TOAD_IDLE_PATH = "assets/4 Enemies/6/Idle.png";
    static const std::string ENEMY_TOAD_RUN_PATH = "assets/4 Enemies/6/Run.png";
    static const std::string ENEMY_TOAD_RUN_ATTACK_PATH = "assets/4 Enemies/6/Run_Attack.png";


    // OBJECTS

    static const std::string CHECKPOINT_EMPTY_PATH = "assets/3 Objects/Checkpoints/Checkpoint_No_Flag.png";
    static const std::string CHECKPOINT_1_OUT_PATH = "assets/3 Objects/Checkpoints/Checkpoint_Flag_Out1.png";
    static const std::string CHECKPOINT_2_OUT_PATH = "assets/3 Objects/Checkpoints/Checkpoint_Flag_Out2.png";
    static const std::string CHECKPOINT_1_IDLE_PATH = "assets/3 Objects/Checkpoints/Checkpoint_Flag_Idle1.png";
    static const std::string CHECKPOINT_2_IDLE_PATH = "assets/3 Objects/Checkpoints/Checkpoint_Flag_Idle2.png";

    static const std::string CUP_IDLE_PATH = "assets/3 Objects/Checkpoints/End_Idle.png";
    static const std::string CUP_TOUCH_PATH = "assets/3 Objects/Checkpoints/End_Pressed.png";

    static const std::string GEM_1_PATH = "assets/3 Objects/Gems/1.png";
    static const std::string GEM_2_PATH = "assets/3 Objects/Gems/2.png";
    static const std::string GEM_3_PATH = "assets/3 Objects/Gems/3.png";
    static const std::string GEM_4_PATH = "assets/3 Objects/Gems/4.png";
    static const std::string GEM_5_PATH = "assets/3 Objects/Gems/5.png";
    static const std::string GEM_6_PATH = "assets/3 Objects/Gems/6.png";

    // TRAP

    static const std::string SAW_PATH = "assets/6 Traps/2.png";
    static const std::string SPIKE_PATH = "assets/6 Traps/4.png";
    static const std::string FRAGILE_PLATFORM_PATH = "assets/6 Traps/5.png";
    static const std::string ELECTRICITY_PATH = "assets/6 Traps/6.png";

    switch (id) {

        // FONT
    case AssetID::MAIN_FONT:   return MAIN_FONT_PATH;

        // SOUND
    case AssetID::SOUND_UI_PUSHED: return SOUND_UI_PUSHED_PATH;
    case AssetID::SOUND_UI_HOVERED: return SOUND_UI_HOVERED_PATH;
    case AssetID::SOUND_JUMP: return SOUND_JUMP_PATH;
    case AssetID::SOUND_MUSIC: return SOUND_MUSIC_PATH;

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
    case AssetID::BUTTON_GREY_UP:   return BUTTON_GREY_UP_PATH;
    case AssetID::BUTTON_GREY_DOWN: return BUTTON_GREY_DOWN_PATH;
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
    case AssetID::GREEN_FRAME_TOP_LEFT:     return GREEN_FRAME_TOP_LEFT_PATH;
    case AssetID::GREEN_FRAME_TOP:          return GREEN_FRAME_TOP_PATH;
    case AssetID::GREEN_FRAME_TOP_RIGHT:    return GREEN_FRAME_TOP_RIGHT_PATH;
    case AssetID::GREEN_FRAME_LEFT:         return GREEN_FRAME_LEFT_PATH;
    case AssetID::GREEN_FRAME_MIDDLE:       return GREEN_FRAME_MIDDLE_PATH;
    case AssetID::GREEN_FRAME_RIGHT:        return GREEN_FRAME_RIGHT_PATH;
    case AssetID::GREEN_FRAME_BOTTOM_LEFT:  return GREEN_FRAME_BOTTOM_LEFT_PATH;
    case AssetID::GREEN_FRAME_BOTTOM:       return GREEN_FRAME_BOTTOM_PATH;
    case AssetID::GREEN_FRAME_BOTTOM_RIGHT: return GREEN_FRAME_BOTTOM_RIGHT_PATH;
    case AssetID::GREEN_BAR_LEFT:           return GREEN_BAR_LEFT_PATH;
    case AssetID::GREEN_BAR_MIDDLE:         return GREEN_BAR_MIDDLE_PATH;
    case AssetID::GREEN_BAR_RIGHT:          return GREEN_BAR_RIGHT_PATH;

    case AssetID::GRAY_FRAME_TOP_LEFT:     return GRAY_FRAME_TOP_LEFT_PATH;
    case AssetID::GRAY_FRAME_TOP:          return GRAY_FRAME_TOP_PATH;
    case AssetID::GRAY_FRAME_TOP_RIGHT:    return GRAY_FRAME_TOP_RIGHT_PATH;
    case AssetID::GRAY_FRAME_LEFT:         return GRAY_FRAME_LEFT_PATH;
    case AssetID::GRAY_FRAME_MIDDLE:       return GRAY_FRAME_MIDDLE_PATH;
    case AssetID::GRAY_FRAME_RIGHT:        return GRAY_FRAME_RIGHT_PATH;
    case AssetID::GRAY_FRAME_BOTTOM_LEFT:  return GRAY_FRAME_BOTTOM_LEFT_PATH;
    case AssetID::GRAY_FRAME_BOTTOM:       return GRAY_FRAME_BOTTOM_PATH;
    case AssetID::GRAY_FRAME_BOTTOM_RIGHT: return GRAY_FRAME_BOTTOM_RIGHT_PATH;
    case AssetID::GRAY_BAR_LEFT:           return GRAY_BAR_LEFT_PATH;
    case AssetID::GRAY_BAR_MIDDLE:         return GRAY_BAR_MIDDLE_PATH;
    case AssetID::GRAY_BAR_RIGHT:          return GRAY_BAR_RIGHT_PATH;

    case AssetID::BRICK_FRAME_TOP_LEFT:     return BRICK_FRAME_TOP_LEFT_PATH;
    case AssetID::BRICK_FRAME_TOP:          return BRICK_FRAME_TOP_PATH;
    case AssetID::BRICK_FRAME_TOP_RIGHT:    return BRICK_FRAME_TOP_RIGHT_PATH;
    case AssetID::BRICK_FRAME_LEFT:         return BRICK_FRAME_LEFT_PATH;
    case AssetID::BRICK_FRAME_MIDDLE:       return BRICK_FRAME_MIDDLE_PATH;
    case AssetID::BRICK_FRAME_RIGHT:        return BRICK_FRAME_RIGHT_PATH;
    case AssetID::BRICK_FRAME_BOTTOM_LEFT:  return BRICK_FRAME_BOTTOM_LEFT_PATH;
    case AssetID::BRICK_FRAME_BOTTOM:       return BRICK_FRAME_BOTTOM_PATH;
    case AssetID::BRICK_FRAME_BOTTOM_RIGHT: return BRICK_FRAME_BOTTOM_RIGHT_PATH;
    case AssetID::BRICK_BAR_LEFT:           return BRICK_BAR_LEFT_PATH;
    case AssetID::BRICK_BAR_MIDDLE:         return BRICK_BAR_MIDDLE_PATH;
    case AssetID::BRICK_BAR_RIGHT:          return BRICK_BAR_RIGHT_PATH;

    case AssetID::WARN_FRAME_TOP_LEFT:     return WARN_FRAME_TOP_LEFT_PATH;
    case AssetID::WARN_FRAME_TOP:          return WARN_FRAME_TOP_PATH;
    case AssetID::WARN_FRAME_TOP_RIGHT:    return WARN_FRAME_TOP_RIGHT_PATH;
    case AssetID::WARN_FRAME_LEFT:         return WARN_FRAME_LEFT_PATH;
    case AssetID::WARN_FRAME_MIDDLE:       return WARN_FRAME_MIDDLE_PATH;
    case AssetID::WARN_FRAME_RIGHT:        return WARN_FRAME_RIGHT_PATH;
    case AssetID::WARN_FRAME_BOTTOM_LEFT:  return WARN_FRAME_BOTTOM_LEFT_PATH;
    case AssetID::WARN_FRAME_BOTTOM:       return WARN_FRAME_BOTTOM_PATH;
    case AssetID::WARN_FRAME_BOTTOM_RIGHT: return WARN_FRAME_BOTTOM_RIGHT_PATH;
    case AssetID::WARN_BAR_LEFT:           return WARN_BAR_LEFT_PATH;
    case AssetID::WARN_BAR_MIDDLE:         return WARN_BAR_MIDDLE_PATH;
    case AssetID::WARN_BAR_RIGHT:          return WARN_BAR_RIGHT_PATH;

        // PLATFORM TILES
    case AssetID::PLATFORM_GRASS_1_TOP_LEFT: return PLATFORM_GRASS_1_TOP_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_1_TOP: return PLATFORM_GRASS_1_TOP_PATH;
    case AssetID::PLATFORM_GRASS_1_TOP_RIGHT: return PLATFORM_GRASS_1_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_1_MIDDLE_LEFT: return PLATFORM_GRASS_1_MIDDLE_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_1_MIDDLE: return PLATFORM_GRASS_1_MIDDLE_PATH;
    case AssetID::PLATFORM_GRASS_1_MIDDLE_RIGHT: return PLATFORM_GRASS_1_MIDDLE_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_1_BOTTOM_LEFT: return PLATFORM_GRASS_1_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_1_BOTTOM: return PLATFORM_GRASS_1_BOTTOM_PATH;
    case AssetID::PLATFORM_GRASS_1_BOTTOM_RIGHT: return PLATFORM_GRASS_1_BOTTOM_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_1_INSIDE_TOP_LEFT: return PLATFORM_GRASS_1_INSIDE_TOP_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_1_INSIDE_TOP_RIGHT: return PLATFORM_GRASS_1_INSIDE_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_1_INSIDE_BOTTOM_LEFT: return PLATFORM_GRASS_1_INSIDE_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_1_INSIDE_BOTTOM_RIGHT: return PLATFORM_GRASS_1_INSIDE_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_GRASS_2_TOP_LEFT: return PLATFORM_GRASS_2_TOP_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_2_TOP: return PLATFORM_GRASS_2_TOP_PATH;
    case AssetID::PLATFORM_GRASS_2_TOP_RIGHT: return PLATFORM_GRASS_2_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_2_MIDDLE_LEFT: return PLATFORM_GRASS_2_MIDDLE_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_2_MIDDLE: return PLATFORM_GRASS_2_MIDDLE_PATH;
    case AssetID::PLATFORM_GRASS_2_MIDDLE_RIGHT: return PLATFORM_GRASS_2_MIDDLE_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_2_BOTTOM_LEFT: return PLATFORM_GRASS_2_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_2_BOTTOM: return PLATFORM_GRASS_2_BOTTOM_PATH;
    case AssetID::PLATFORM_GRASS_2_BOTTOM_RIGHT: return PLATFORM_GRASS_2_BOTTOM_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_2_INSIDE_TOP_LEFT: return PLATFORM_GRASS_2_INSIDE_TOP_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_2_INSIDE_TOP_RIGHT: return PLATFORM_GRASS_2_INSIDE_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_GRASS_2_INSIDE_BOTTOM_LEFT: return PLATFORM_GRASS_2_INSIDE_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_GRASS_2_INSIDE_BOTTOM_RIGHT: return PLATFORM_GRASS_2_INSIDE_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_BLOCK_1_TOP_LEFT: return PLATFORM_BLOCK_1_TOP_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_1_TOP: return PLATFORM_BLOCK_1_TOP_PATH;
    case AssetID::PLATFORM_BLOCK_1_TOP_RIGHT: return PLATFORM_BLOCK_1_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_1_MIDDLE_LEFT: return PLATFORM_BLOCK_1_MIDDLE_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_1_MIDDLE: return PLATFORM_BLOCK_1_MIDDLE_PATH;
    case AssetID::PLATFORM_BLOCK_1_MIDDLE_RIGHT: return PLATFORM_BLOCK_1_MIDDLE_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_1_BOTTOM_LEFT: return PLATFORM_BLOCK_1_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_1_BOTTOM: return PLATFORM_BLOCK_1_BOTTOM_PATH;
    case AssetID::PLATFORM_BLOCK_1_BOTTOM_RIGHT: return PLATFORM_BLOCK_1_BOTTOM_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_1_INSIDE_TOP_LEFT: return PLATFORM_BLOCK_1_INSIDE_TOP_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_1_INSIDE_TOP_RIGHT: return PLATFORM_BLOCK_1_INSIDE_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_1_INSIDE_BOTTOM_LEFT: return PLATFORM_BLOCK_1_INSIDE_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_1_INSIDE_BOTTOM_RIGHT: return PLATFORM_BLOCK_1_INSIDE_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_BLOCK_2_TOP_LEFT: return PLATFORM_BLOCK_2_TOP_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_2_TOP: return PLATFORM_BLOCK_2_TOP_PATH;
    case AssetID::PLATFORM_BLOCK_2_TOP_RIGHT: return PLATFORM_BLOCK_2_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_2_MIDDLE_LEFT: return PLATFORM_BLOCK_2_MIDDLE_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_2_MIDDLE: return PLATFORM_BLOCK_2_MIDDLE_PATH;
    case AssetID::PLATFORM_BLOCK_2_MIDDLE_RIGHT: return PLATFORM_BLOCK_2_MIDDLE_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_2_BOTTOM_LEFT: return PLATFORM_BLOCK_2_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_2_BOTTOM: return PLATFORM_BLOCK_2_BOTTOM_PATH;
    case AssetID::PLATFORM_BLOCK_2_BOTTOM_RIGHT: return PLATFORM_BLOCK_2_BOTTOM_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_2_INSIDE_TOP_LEFT: return PLATFORM_BLOCK_2_INSIDE_TOP_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_2_INSIDE_TOP_RIGHT: return PLATFORM_BLOCK_2_INSIDE_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_BLOCK_2_INSIDE_BOTTOM_LEFT: return PLATFORM_BLOCK_2_INSIDE_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_BLOCK_2_INSIDE_BOTTOM_RIGHT: return PLATFORM_BLOCK_2_INSIDE_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_METAL_1_TOP_LEFT: return PLATFORM_METAL_1_TOP_LEFT_PATH;
    case AssetID::PLATFORM_METAL_1_TOP: return PLATFORM_METAL_1_TOP_PATH;
    case AssetID::PLATFORM_METAL_1_TOP_RIGHT: return PLATFORM_METAL_1_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_1_MIDDLE_LEFT: return PLATFORM_METAL_1_MIDDLE_LEFT_PATH;
    case AssetID::PLATFORM_METAL_1_MIDDLE: return PLATFORM_METAL_1_MIDDLE_PATH;
    case AssetID::PLATFORM_METAL_1_MIDDLE_RIGHT: return PLATFORM_METAL_1_MIDDLE_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_1_BOTTOM_LEFT: return PLATFORM_METAL_1_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_METAL_1_BOTTOM: return PLATFORM_METAL_1_BOTTOM_PATH;
    case AssetID::PLATFORM_METAL_1_BOTTOM_RIGHT: return PLATFORM_METAL_1_BOTTOM_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_1_INSIDE_TOP_LEFT: return PLATFORM_METAL_1_INSIDE_TOP_LEFT_PATH;
    case AssetID::PLATFORM_METAL_1_INSIDE_TOP_RIGHT: return PLATFORM_METAL_1_INSIDE_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_1_INSIDE_BOTTOM_LEFT: return PLATFORM_METAL_1_INSIDE_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_METAL_1_INSIDE_BOTTOM_RIGHT: return PLATFORM_METAL_1_INSIDE_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_METAL_2_TOP_LEFT: return PLATFORM_METAL_2_TOP_LEFT_PATH;
    case AssetID::PLATFORM_METAL_2_TOP: return PLATFORM_METAL_2_TOP_PATH;
    case AssetID::PLATFORM_METAL_2_TOP_RIGHT: return PLATFORM_METAL_2_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_2_MIDDLE_LEFT: return PLATFORM_METAL_2_MIDDLE_LEFT_PATH;
    case AssetID::PLATFORM_METAL_2_MIDDLE: return PLATFORM_METAL_2_MIDDLE_PATH;
    case AssetID::PLATFORM_METAL_2_MIDDLE_RIGHT: return PLATFORM_METAL_2_MIDDLE_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_2_BOTTOM_LEFT: return PLATFORM_METAL_2_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_METAL_2_BOTTOM: return PLATFORM_METAL_2_BOTTOM_PATH;
    case AssetID::PLATFORM_METAL_2_BOTTOM_RIGHT: return PLATFORM_METAL_2_BOTTOM_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_2_INSIDE_TOP_LEFT: return PLATFORM_METAL_2_INSIDE_TOP_LEFT_PATH;
    case AssetID::PLATFORM_METAL_2_INSIDE_TOP_RIGHT: return PLATFORM_METAL_2_INSIDE_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_METAL_2_INSIDE_BOTTOM_LEFT: return PLATFORM_METAL_2_INSIDE_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_METAL_2_INSIDE_BOTTOM_RIGHT: return PLATFORM_METAL_2_INSIDE_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_FULL_GREEN_H_BAR_LEFT: return PLATFORM_FULL_GREEN_H_BAR_LEFT_PATH;
    case AssetID::PLATFORM_FULL_GREEN_H_BAR: return PLATFORM_FULL_GREEN_H_BAR_PATH;
    case AssetID::PLATFORM_FULL_GREEN_H_BAR_RIGHT: return PLATFORM_FULL_GREEN_H_BAR_RIGHT_PATH;
    case AssetID::PLATFORM_FULL_GREEN_V_BAR_TOP: return PLATFORM_FULL_GREEN_V_BAR_TOP_PATH;
    case AssetID::PLATFORM_FULL_GREEN_V_BAR: return PLATFORM_FULL_GREEN_V_BAR_PATH;
    case AssetID::PLATFORM_FULL_GREEN_V_BAR_BOTTOM: return PLATFORM_FULL_GREEN_V_BAR_BOTTOM_PATH;
    case AssetID::PLATFORM_FULL_GREEN_1_1: return PLATFORM_FULL_GREEN_1_1_PATH;
    case AssetID::PLATFORM_FULL_GREEN_2_2_TOP_LEFT: return PLATFORM_FULL_GREEN_2_2_TOP_LEFT_PATH;
    case AssetID::PLATFORM_FULL_GREEN_2_2_TOP_RIGHT: return PLATFORM_FULL_GREEN_2_2_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_FULL_GREEN_2_2_BOTTOM_LEFT: return PLATFORM_FULL_GREEN_2_2_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_FULL_GREEN_2_2_BOTTOM_RIGHT: return PLATFORM_FULL_GREEN_2_2_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_FULL_METAL_H_BAR_LEFT: return PLATFORM_FULL_METAL_H_BAR_LEFT_PATH;
    case AssetID::PLATFORM_FULL_METAL_H_BAR: return PLATFORM_FULL_METAL_H_BAR_PATH;
    case AssetID::PLATFORM_FULL_METAL_H_BAR_RIGHT: return PLATFORM_FULL_METAL_H_BAR_RIGHT_PATH;
    case AssetID::PLATFORM_FULL_METAL_V_BAR_TOP: return PLATFORM_FULL_METAL_V_BAR_TOP_PATH;
    case AssetID::PLATFORM_FULL_METAL_V_BAR: return PLATFORM_FULL_METAL_V_BAR_PATH;
    case AssetID::PLATFORM_FULL_METAL_V_BAR_BOTTOM: return PLATFORM_FULL_METAL_V_BAR_BOTTOM_PATH;
    case AssetID::PLATFORM_FULL_METAL_1_1: return PLATFORM_FULL_METAL_1_1_PATH;
    case AssetID::PLATFORM_FULL_METAL_2_2_TOP_LEFT: return PLATFORM_FULL_METAL_2_2_TOP_LEFT_PATH;
    case AssetID::PLATFORM_FULL_METAL_2_2_TOP_RIGHT: return PLATFORM_FULL_METAL_2_2_TOP_RIGHT_PATH;
    case AssetID::PLATFORM_FULL_METAL_2_2_BOTTOM_LEFT: return PLATFORM_FULL_METAL_2_2_BOTTOM_LEFT_PATH;
    case AssetID::PLATFORM_FULL_METAL_2_2_BOTTOM_RIGHT: return PLATFORM_FULL_METAL_2_2_BOTTOM_RIGHT_PATH;

    case AssetID::PLATFORM_MINI_1_LEFT: return PLATFORM_MINI_1_LEFT_PATH;
    case AssetID::PLATFORM_MINI_1: return PLATFORM_MINI_1_PATH;
    case AssetID::PLATFORM_MINI_1_RIGHT: return PLATFORM_MINI_1_RIGHT_PATH;
    case AssetID::PLATFORM_MINI_2_LEFT: return PLATFORM_MINI_2_LEFT_PATH;
    case AssetID::PLATFORM_MINI_2: return PLATFORM_MINI_2_PATH;
    case AssetID::PLATFORM_MINI_2_RIGHT: return PLATFORM_MINI_2_RIGHT_PATH;
    case AssetID::PLATFORM_MINI_3_LEFT: return PLATFORM_MINI_3_LEFT_PATH;
    case AssetID::PLATFORM_MINI_3: return PLATFORM_MINI_3_PATH;
    case AssetID::PLATFORM_MINI_3_RIGHT: return PLATFORM_MINI_3_RIGHT_PATH;
        // MAIN CHARACTER
    case AssetID::MC_1_DOUBLE_JUMP:          return MC_1_DOUBLE_JUMP_PATH;
    case AssetID::MC_1_FALL:          return MC_1_FALL_PATH;
    case AssetID::MC_1_HIT:          return MC_1_HIT_PATH;
    case AssetID::MC_1_IDLE:          return MC_1_IDLE_PATH;
    case AssetID::MC_1_JUMP:          return MC_1_JUMP_PATH;
    case AssetID::MC_1_RUN:          return MC_1_RUN_PATH;
    case AssetID::MC_1_WALL_JUMP:          return MC_1_WALL_JUMP_PATH;

    case AssetID::MC_2_DOUBLE_JUMP:          return MC_2_DOUBLE_JUMP_PATH;
    case AssetID::MC_2_FALL:          return MC_2_FALL_PATH;
    case AssetID::MC_2_HIT:          return MC_2_HIT_PATH;
    case AssetID::MC_2_IDLE:          return MC_2_IDLE_PATH;
    case AssetID::MC_2_JUMP:          return MC_2_JUMP_PATH;
    case AssetID::MC_2_RUN:          return MC_2_RUN_PATH;
    case AssetID::MC_2_WALL_JUMP:          return MC_2_WALL_JUMP_PATH;

    case AssetID::MC_3_DOUBLE_JUMP:          return MC_3_DOUBLE_JUMP_PATH;
    case AssetID::MC_3_FALL:          return MC_3_FALL_PATH;
    case AssetID::MC_3_HIT:          return MC_3_HIT_PATH;
    case AssetID::MC_3_IDLE:          return MC_3_IDLE_PATH;
    case AssetID::MC_3_JUMP:          return MC_3_JUMP_PATH;
    case AssetID::MC_3_RUN:          return MC_3_RUN_PATH;
    case AssetID::MC_3_WALL_JUMP:          return MC_3_WALL_JUMP_PATH;

    case AssetID::MC_APPEARING:         return MC_APPEARING_PATH;
    case AssetID::MC_DESAPPEARING:         return MC_DESAPPEARING_PATH;

        //ENEMY
    case AssetID::ENEMY_TV_FALL:   return ENEMY_TV_FALL_PATH;
    case AssetID::ENEMY_TV_HIT:    return ENEMY_TV_HIT_PATH;
    case AssetID::ENEMY_TV_IDLE:   return ENEMY_TV_IDLE_PATH;
    case AssetID::ENEMY_TV_JUMP:   return ENEMY_TV_JUMP_PATH;
    case AssetID::ENEMY_TV_RUN:    return ENEMY_TV_RUN_PATH;

    case AssetID::ENEMY_CACTUS_FALL:     return ENEMY_CACTUS_FALL_PATH;
    case AssetID::ENEMY_CACTUS_HIT:      return ENEMY_CACTUS_HIT_PATH;
    case AssetID::ENEMY_CACTUS_IDLE:     return ENEMY_CACTUS_IDLE_PATH;
    case AssetID::ENEMY_CACTUS_JUMP:     return ENEMY_CACTUS_JUMP_PATH;
    case AssetID::ENEMY_CACTUS_RUN:      return ENEMY_CACTUS_RUN_PATH;

    case AssetID::ENEMY_BARREL_CHARGE:   return ENEMY_BARREL_CHARGE_PATH;
    case AssetID::ENEMY_BARREL_HIT:      return ENEMY_BARREL_HIT_PATH;
    case AssetID::ENEMY_BARREL_IDLE:     return ENEMY_BARREL_IDLE_PATH;
    case AssetID::ENEMY_BARREL_STUN:     return ENEMY_BARREL_STUN_PATH;
    case AssetID::ENEMY_BARREL_WALK:     return ENEMY_BARREL_WALK_PATH;

    case AssetID::ENEMY_CANON_ATTACK:    return ENEMY_CANON_ATTACK_PATH;
    case AssetID::ENEMY_CANON_HIT:       return ENEMY_CANON_HIT_PATH;
    case AssetID::ENEMY_CANON_IDLE:      return ENEMY_CANON_IDLE_PATH;
    case AssetID::ENEMY_CANON_WALK:      return ENEMY_CANON_WALK_PATH;
    case AssetID::ENEMY_CANON_BALL_1:    return ENEMY_CANON_BALL_1_PATH;
    case AssetID::ENEMY_CANON_BALL_2:    return ENEMY_CANON_BALL_2_PATH;

    case AssetID::ENEMY_FLYER_ATTACK:    return ENEMY_FLYER_ATTACK_PATH;
    case AssetID::ENEMY_FLYER_FLY:       return ENEMY_FLYER_FLY_PATH;
    case AssetID::ENEMY_FLYER_HIT:       return ENEMY_FLYER_HIT_PATH;
    case AssetID::ENEMY_FLYER_IDLE:      return ENEMY_FLYER_IDLE_PATH;

    case AssetID::ENEMY_TOAD_ATTACK:     return ENEMY_TOAD_ATTACK_PATH;
    case AssetID::ENEMY_TOAD_HIT:        return ENEMY_TOAD_HIT_PATH;
    case AssetID::ENEMY_TOAD_IDLE:       return ENEMY_TOAD_IDLE_PATH;
    case AssetID::ENEMY_TOAD_RUN:        return ENEMY_TOAD_RUN_PATH;
    case AssetID::ENEMY_TOAD_RUN_ATTACK: return ENEMY_TOAD_RUN_ATTACK_PATH;

        // OBJECTS

    case AssetID::CHECKPOINT_EMPTY:   return CHECKPOINT_EMPTY_PATH;
    case AssetID::CHECKPOINT_1_OUT:   return CHECKPOINT_1_OUT_PATH;
    case AssetID::CHECKPOINT_2_OUT:   return CHECKPOINT_2_OUT_PATH;
    case AssetID::CHECKPOINT_1_IDLE:  return CHECKPOINT_1_IDLE_PATH;
    case AssetID::CHECKPOINT_2_IDLE:  return CHECKPOINT_2_IDLE_PATH;

    case AssetID::CUP_IDLE:           return CUP_IDLE_PATH;
    case AssetID::CUP_TOUCH:          return CUP_TOUCH_PATH;

    case AssetID::GEM_1:              return GEM_1_PATH;
    case AssetID::GEM_2:              return GEM_2_PATH;
    case AssetID::GEM_3:              return GEM_3_PATH;
    case AssetID::GEM_4:              return GEM_4_PATH;
    case AssetID::GEM_5:              return GEM_5_PATH;
    case AssetID::GEM_6:              return GEM_6_PATH;

        // TRAP

    case AssetID::SAW:                return SAW_PATH;
    case AssetID::SPIKE:              return SPIKE_PATH;
    case AssetID::FRAGILE_PLATFORM:   return FRAGILE_PLATFORM_PATH;
    case AssetID::ELECTRICITY:        return ELECTRICITY_PATH;

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
