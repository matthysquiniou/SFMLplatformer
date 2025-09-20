#pragma once
#include "Entity.hpp"
#include "BoxManager.hpp"
#include <functional>
#include <cmath>

class EnemyCanonBall : public Entity {

	struct PendingCollision {
		Entity* other;
		Box myBox;
		Box otherBox;
		sf::FloatRect intersection;
	};

public:
	EnemyCanonBall(SpriteComposite s, int direction);

	void update(float dt, GameContext& ctx) override;

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	EntityType getType() override;

	void onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) override;

	void doCollision();

	int direction;

	float velocityX = 600.f;

	float firstSpriteTime = 0.f;
private:
	BoxManager boxManager;

	std::vector<PendingCollision> pendingCollisions;
};
