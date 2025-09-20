#include "EnemyCanonBall.hpp"

EnemyCanonBall::EnemyCanonBall(SpriteComposite s, int direction) : Entity(std::move(s)), boxManager(EntityType::Enemy, this), direction(direction) {
	boxManager.addBox({ {0.f,0.f} ,{10.f,10.f} }, BoxType::Collision);
	boxManager.addBox({ {0.f,0.f} ,{10.f,10.f} }, BoxType::Hurt);
}

void EnemyCanonBall::update(float dt, GameContext& ctx) {

	firstSpriteTime += dt;

	if (firstSpriteTime > 0.5f)
	{
		sprite.setVisible(0, false);
		sprite.setVisible(0, true);
	}

	sprite.move({ velocityX * dt * direction,0.f });

	boxManager.updateBoxesPosition(sprite.getPosition());

	sprite.update(dt);
}

void EnemyCanonBall::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType EnemyCanonBall::getType() {
	return EntityType::Enemy;
}

void EnemyCanonBall::doCollision() {
	if (pendingCollisions.empty()) return;
	const float NOISE = 0.5f;
	const float EPS = 0.001f;

	float maxLeft = 0.f; bool hasLeft = false; Box leftBox;
	float maxRight = 0.f; bool hasRight = false; Box rightBox;

	for (auto& pc : pendingCollisions) {

		if (pc.intersection.size.x < NOISE && pc.intersection.size.y < NOISE) continue;

		EntityType otherType = pc.other->getType();
		BoxType myBoxType = pc.myBox.type;

		// platform collision
		if (otherType == EntityType::Platform && myBoxType == BoxType::Collision) {

			const auto& inter = pc.intersection;

			if (inter.size.x < inter.size.y) {
				if (pc.myBox.rect.position.x < pc.otherBox.rect.position.x) {
					if (inter.size.x > maxRight) {
						maxRight = inter.size.x;
						rightBox = pc.otherBox;
						hasRight = true;
					}
				}
				else {
					if (inter.size.x > maxLeft) {
						maxLeft = inter.size.x;
						leftBox = pc.otherBox;
						hasLeft = true;
					}
				}
			}
		}
		else if (myBoxType == BoxType::Hurt && otherType == EntityType::Player) {
			deleteIt = true;
		}
	}

	if (hasRight) {
		deleteIt = true;
	}
	if (hasLeft) {
		deleteIt = true;
	}

	pendingCollisions.clear();
}

void EnemyCanonBall::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}