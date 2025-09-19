#pragma once
#include "Entity.hpp"
#include "PhysicEngine.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class EnemyTv : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum EnemyTvAnimation {
		FALL = 0,
		HIT = 1,
		IDLE = 2,
		JUMP = 3,
		RUN = 4
	};

	enum ObserverID {
		DIRECTION_1 = 0,
		DIRECTION_2 = 1
	};

public:
	EnemyTv(SpriteComposite s);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void switchAnimation(EnemyTvAnimation newAnimation);

	void doCollision();

	bool isGrounded = false;

	int direction = -1;

	float directionChangedTime = 0.5f;

	float jumpTime = 0.f;

	float velocityX = 0.f;

	float velocityY = 0.f;

	float maxRunVelocity = 200.f;

	float runAcceleration = 300.f;

	bool hasBeenHit = false;

private:
	EnemyTvAnimation activeAnimation = EnemyTvAnimation::IDLE;

	PhysicEngine physicEngine;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
