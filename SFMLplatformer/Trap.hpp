#pragma once
#include "Entity.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class Trap : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

public:

	enum TrapType
	{
		SAW = 0,
		SPIKE = 1,
		ELECTRICITY = 2
	};

	Trap(SpriteComposite s, TrapType trapType, float animationDelay);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void updateHurtBox();

	TrapType trapType;

	float animationDelay;

	float animationTime = 0.f;

	float idleTime = 2.f;

	bool isIdling = false;

	int hurtBoxActive = 1;

private:
	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
