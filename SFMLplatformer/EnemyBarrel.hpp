#pragma once
#include "Entity.hpp"
#include "PhysicEngine.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class EnemyBarrel : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum EnemyBarrelAnimation {
		CHARGE = 0,
		HIT = 1,
		IDLE = 2,
		STUN = 3,
		WALK = 4
	};

	enum ObserverID {
		DIRECTION_1 = 0,
		DIRECTION_2 = 1,
		PLAYER_1 = 2,
		PLAYER_2 = 3
	};

public:
	EnemyBarrel(SpriteComposite s);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void switchAnimation(EnemyBarrelAnimation newAnimation);

	void switchPlayerObserver();

	void doCollision();

	void activateStun();

	bool isGrounded = false;

	bool isRunning = false;

	bool isStuned = false;

	int direction = -1;

	float directionChangedTime = 0.5f;

	float stunTime = 0.f;

	float velocityX = 0.f;

	float velocityY = 0.f;

	float maxWalkVelocity = 200.f;

	float walkAcceleration = 300.f;

	float maxRunVelocity = 800.f;

	float runAcceleration = 1000.f;

	bool hasBeenHit = false;

	ObserverID activePlayerObserver = ObserverID::PLAYER_1;

private:
	EnemyBarrelAnimation activeAnimation = EnemyBarrelAnimation::IDLE;

	PhysicEngine physicEngine;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
