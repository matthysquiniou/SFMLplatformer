#include "EnemyFlyer.hpp"
#include <iostream>

EnemyFlyer::EnemyFlyer(SpriteComposite s) : Entity(std::move(s)), boxManager(EntityType::Enemy, this) {
	boxManager.addBox({ {12.f,0.f} ,{24.f,24.f} }, BoxType::Collision);
	boxManager.addBox({ {12.f,0.f} ,{24.f,8.f} }, BoxType::Hit);
	boxManager.addBox({ {12.f,8.f} ,{24.f,20.f} }, BoxType::Hurt);
	boxManager.addBox({ {-4.f,28.f} ,{16.f,200.f} }, BoxType::CollisionObserver, ObserverID::DIRECTION_1);
	boxManager.addBox({ {36.f,28.f} ,{16.f,200.f} }, BoxType::CollisionObserver, ObserverID::DIRECTION_2);
	boxManager.addBox({ {12.f,28.f} ,{24.f,200.f} }, BoxType::CollisionObserver, ObserverID::PLAYER);
	baseY = sprite.getPosition().y;
}

void EnemyFlyer::update(float dt, GameContext& ctx) {

	if (hasBeenHit)
	{
		sprite.update(dt);
		if (!sprite.isAnimationGoing())
		{
			deleteIt = true;
		}
		return;
	}

	physicEngine.updateEnemyFlyerPhysic(*this, dt);

	if ((direction != 0) && !isAttacking)
	{
		switchAnimation(EnemyFlyerAnimation::FLY);
	}

	boxManager.updateBoxesPosition(sprite.getPosition());

	directionChangedTime += dt;

	sprite.update(dt);
}

void EnemyFlyer::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType EnemyFlyer::getType() {
	return EntityType::Enemy;
}

void EnemyFlyer::doCollision() {
	if (pendingCollisions.empty()) return;
	const float NOISE = 0.5f;
	const float EPS = 0.001f;

	float maxFloor = 0.f; bool hasFloor = false; Box floorBox;
	float maxCeil = 0.f; bool hasCeil = false; Box ceilBox;
	float maxLeft = 0.f; bool hasLeft = false; Box leftBox;
	float maxRight = 0.f; bool hasRight = false; Box rightBox;

	bool direction1Flag = false;
	bool direction2Flag = false;

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
			else {
				if (pc.myBox.rect.position.y < pc.otherBox.rect.position.y) {
					if (inter.size.y > maxFloor) {
						maxFloor = inter.size.y;
						floorBox = pc.otherBox;
						hasFloor = true;
					}
				}
				else {
					if (inter.size.y > maxCeil) {
						maxCeil = inter.size.y;
						ceilBox = pc.otherBox;
						hasCeil = true;
					}
				}
			}
		}
		// direction change
		else if (myBoxType == BoxType::CollisionObserver && otherType == EntityType::Platform) {
			if (pc.myBox.observerID == ObserverID::DIRECTION_1) direction1Flag = true;
			if (pc.myBox.observerID == ObserverID::DIRECTION_2) direction2Flag = true;
		}
		else if (myBoxType == BoxType::CollisionObserver && otherType == EntityType::Player && !isAttacking && !isGoingUp) {
			if (pc.myBox.observerID == ObserverID::PLAYER) {
				isAttacking = true;
				velocityY = 650.f;
				velocityX = 0.f;
				switchAnimation(EnemyFlyerAnimation::ATTACK);
			}
		}
		// being hit
		else if (myBoxType == BoxType::Hit && otherType == EntityType::Player) {
			switchAnimation(EnemyFlyerAnimation::HIT);
			hasBeenHit = true;
			boxManager.disableBoxType(BoxType::Hit);
			boxManager.disableBoxType(BoxType::Hurt);
			boxManager.disableBoxType(BoxType::CollisionObserver);
		}
	}

	sf::Vector2f totalMove{ 0.f, 0.f };

	if (hasFloor) {
		totalMove.y -= (maxFloor - EPS);
		velocityY = 0.f;
		isAttacking = false;
		isGoingUp = true;
	}

	if (hasCeil) {
		totalMove.y += (maxCeil - EPS);
		velocityY = 0.f;
	}

	if (hasRight) {
		totalMove.x -= (maxRight - EPS);
		velocityX = 0.f;
		direction *= -1;
		sprite.flipX = !sprite.flipX;
	}
	if (hasLeft) {
		totalMove.x += (maxLeft - EPS);
		velocityX = 0.f;
		direction *= -1;
		sprite.flipX = !sprite.flipX;
	}

	if (totalMove.x != 0.f || totalMove.y != 0.f) {
		sprite.move(totalMove);
	}

	if ((!direction1Flag || !direction2Flag) && directionChangedTime > 0.5f)
	{
		if (!direction1Flag) sprite.move({ 2.f,0.f });
		if (!direction2Flag) sprite.move({ -2.f,0.f });
		direction *= -1;
		sprite.flipX = !sprite.flipX;
		velocityX = 0;
		directionChangedTime = 0.f;
	}

	pendingCollisions.clear();
}

void EnemyFlyer::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}

void EnemyFlyer::switchAnimation(EnemyFlyerAnimation newAnimation) {
	if (newAnimation == activeAnimation || (activeAnimation == EnemyFlyerAnimation::HIT && sprite.isAnimationGoing())) return;
	sprite.resetAnimation(activeAnimation);
	sprite.setVisible(activeAnimation, false);
	sprite.setVisible(newAnimation, true);
	sprite.update(0.f);
	if (newAnimation == EnemyFlyerAnimation::HIT)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}