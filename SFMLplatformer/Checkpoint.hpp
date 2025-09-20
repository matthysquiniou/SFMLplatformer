#pragma once
#include "Entity.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class Checkpoint : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum CheckpointAnimation {
		EMPTY = 0,
		OUT = 1,
		IDLE = 2
	};

public:
	Checkpoint(SpriteComposite s);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void doCollision();

	void switchAnimation(CheckpointAnimation newAnimation);

	bool activated = false;

private:
	CheckpointAnimation activeAnimation = CheckpointAnimation::EMPTY;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
