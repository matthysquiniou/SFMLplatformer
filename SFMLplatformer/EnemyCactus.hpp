#pragma once
#include "Entity.hpp"
#include "PhysicEngine.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class EnemyCactus : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum EnemyCactusAnimation {
		FALL = 0,
		HIT = 1,
		IDLE = 2,
		JUMP = 3,
		RUN = 4
	};

public:
	EnemyCactus(SpriteComposite s);

	void handleEvents(const sf::Event& e, GameContext& ctx) override;

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void switchAnimation(EnemyCactusAnimation newAnimation);
	
	void doCollision();

	bool isGrounded = false;

	int direction = 0;

	float velocityX = 0.f;

	float velocityY = 0.f;

private:
	EnemyCactusAnimation activeAnimation = EnemyCactusAnimation::IDLE;

	PhysicEngine physicEngine;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
