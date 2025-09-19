#pragma once
#include "Entity.hpp"
#include "PhysicEngine.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>



class Player : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum PlayerAnimation {
		DOUBLE_JUMP = 0,
		FALL = 1,
		HIT = 2,
		IDLE = 3,
		JUMP = 4,
		RUN = 5,
		WALL_JUMP = 6,
		APPEARING = 7,
		DESAPPEARING = 8
	};

public:
	Player(SpriteComposite s, sf::View& view);

    void handleEvents(const sf::Event& e, GameContext& ctx) override;

    void update(float dt, GameContext& ctx) override;

    void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void doCollision();

	void switchAnimation(PlayerAnimation newAnimation);

	void respawn();

	sf::Vector2f respawnPos;

	bool isGrounded = false;

	bool doubleJumpUsed = false;

	bool isOnWall = false;

	bool fastFall = false;

	int direction = 0;

	float velocityX = 0.f;

	float velocityY = 0.f;

	float maxRunVelocity = 400.f;

	float runAcceleration = 500.f;

	bool hasBeenHit = false;

private:
	PlayerAnimation activeAnimation = PlayerAnimation::IDLE;

	PhysicEngine physicEngine;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;

	sf::View& view;
};
