#pragma once
#include "Entity.hpp"
#include "PhysicEngine.hpp"
#include "BoxManager.hpp"
#include "EntityManager.hpp"
#include <functional>
#include <cmath>

class EnemyCanon : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum EnemyCanonAnimation {
		ATTACK = 0,
		HIT = 1,
		IDLE = 2,
		WALK = 3
	};

	enum ObserverID {
		DIRECTION_1 = 0,
		DIRECTION_2 = 1,
		PLAYER_1 = 2,
		PLAYER_2 = 3
	};

public:
	EnemyCanon(SpriteComposite s, EntityManager& entityManager);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void switchAnimation(EnemyCanonAnimation newAnimation);

	void switchPlayerObserver();

	void doCollision();

	void shot();

	bool isGrounded = false;

	bool isIdling = false;

	float idlingTime = 0.f;

	int direction = -1;

	float directionChangedTime = 0.5f;

	float velocityX = 0.f;

	float velocityY = 0.f;

	float maxWalkVelocity = 200.f;

	float walkAcceleration = 300.f;

	bool hasBeenHit = false;

	ObserverID activePlayerObserver = ObserverID::PLAYER_1;

private:
	EntityManager& entityManager;

	EnemyCanonAnimation activeAnimation = EnemyCanonAnimation::IDLE;

	PhysicEngine physicEngine;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
