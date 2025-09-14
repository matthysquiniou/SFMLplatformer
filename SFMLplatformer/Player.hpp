#pragma once
#include "Entity.hpp"
#include "Assets.hpp"
#include "PhysicEngine.hpp"
#include <functional>
#include <cmath>

enum PlayerAnimation {
	DOUBLE_JUMP = 0,
	FALL = 1,
	HIT = 2,
	IDLE = 3,
	JUMP = 4,
	RUN = 5,
	WALL_JUMP = 6
};

class Player : public Entity {

public:
    Player(SpriteComposite s) : Entity(std::move(s)) {}

    void handleEvents(const sf::Event& e, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

	void switchAnimation(PlayerAnimation newAnimation);

	bool isGrounded = true;

	bool doubleJumpUsed = false;

	bool isOnWall = false;

	bool fastFall = false;

	int direction = 0;

	float velocityX = 0.f;

	float velocityY = 0.f;

	float maxRunVelocity = 400.f;

	float runAcceleration = 500.f;

private:
	PlayerAnimation activeAnimation = PlayerAnimation::IDLE;

	PhysicEngine physicEngine;
};
