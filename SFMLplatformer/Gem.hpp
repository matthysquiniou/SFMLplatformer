#pragma once
#include "Entity.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class Gem : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

public:
	Gem(SpriteComposite s);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void doCollision();

	bool hasBeenTouch = false;

private:
	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
