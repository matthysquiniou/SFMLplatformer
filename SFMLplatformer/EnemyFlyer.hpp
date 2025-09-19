#pragma once
#include "Entity.hpp"
#include "PhysicEngine.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class EnemyFlyer : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum EnemyFlyerAnimation {
		ATTACK = 0,
		FLY = 1,
		HIT = 2,
		IDLE = 3
	};

	enum ObserverID {
		DIRECTION_1 = 0,
		DIRECTION_2 = 1,
		PLAYER = 2
	};

public:
	EnemyFlyer(SpriteComposite s);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void switchAnimation(EnemyFlyerAnimation newAnimation);

	void doCollision();

	int direction = -1;

	float directionChangedTime = 0.5f;

	float velocityY = 0.f;

	float velocityX = 0.f;

	float baseY;

	bool isGoingUp = false;

	float goingUpSpeed = 75.f;

	float maxFlyVelocity = 250.f;

	float flyAcceleration = 300.f;

	bool isAttacking = false;

	bool hasBeenHit = false;

private:
	EnemyFlyerAnimation activeAnimation = EnemyFlyerAnimation::IDLE;

	PhysicEngine physicEngine;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
