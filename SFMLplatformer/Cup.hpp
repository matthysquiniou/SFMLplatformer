#pragma once
#include "Entity.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class Cup : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

	enum CupAnimation {
		IDLE = 0,
		TOUCH = 1
	};

public:
	Cup(SpriteComposite s);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void doCollision();

	void switchAnimation(CupAnimation newAnimation);

	bool hasBeenTouch = false;

private:
	CupAnimation activeAnimation = CupAnimation::IDLE;

	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
