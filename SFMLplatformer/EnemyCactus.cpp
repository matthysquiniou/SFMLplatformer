#include "EnemyCactus.hpp"
#include "SoundManager.hpp"
#include <iostream>

EnemyCactus::EnemyCactus(SpriteComposite s) : Entity(std::move(s)), boxManager(EntityType::Enemy, this) {
	boxManager.addBox({ {12.f,20.f} ,{24.f,24.f} }, BoxType::Collision);
	boxManager.addBox({ {12.f,20.f} ,{24.f,8.f} }, BoxType::Hit);
	boxManager.addBox({ {12.f,28.f} ,{24.f,20.f} }, BoxType::Hurt);
	boxManager.addBox({ {-4.f,48.f} ,{16.f,192.f} }, BoxType::CollisionObserver, ObserverID::DIRECTION_1);
	boxManager.addBox({ {36.f,48.f} ,{16.f,192.f} }, BoxType::CollisionObserver, ObserverID::DIRECTION_2);
}

void EnemyCactus::handleEvents(const sf::Event& e, GameContext& ctx) {
	if (e.is<sf::Event::KeyPressed>())
	{
		auto key = e.getIf<sf::Event::KeyPressed>();
		switch (key->code)
		{
		case sf::Keyboard::Key::Up:
			if (!playerJumped && isGrounded)
			{
				jumpTime = 0.f;
				playerJumped = true;
			}
			break;
		}
	}
}

void EnemyCactus::update(float dt, GameContext& ctx) {

	if (hasBeenHit)
	{
		sprite.update(dt);
		if (!sprite.isAnimationGoing())
		{
			deleteIt = true;
			ctx.score += 50;
		}
		return;
	}

	if (jumpTime > 1.f && playerJumped)
	{
		playerJumped = false;
		velocityY = -500.f;
		SoundManager::play(SoundManager::SoundName::JUMP);
	}

	physicEngine.updateEnemyCactusPhysic(*this, dt);

	if (velocityY > 0)
	{
		switchAnimation(EnemyCactusAnimation::FALL);
	}

	if (velocityY < 0)
	{
		switchAnimation(EnemyCactusAnimation::JUMP);
	}

	if (isGrounded && (direction != 0))
	{
		switchAnimation(EnemyCactusAnimation::RUN);
	}

	boxManager.updateBoxesPosition(sprite.getPosition());

	isGrounded = false;

	directionChangedTime += dt;

	jumpTime += dt;

	sprite.update(dt);
}

void EnemyCactus::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType EnemyCactus::getType() {
	return EntityType::Enemy;
}

void EnemyCactus::doCollision() {
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
		// being hit
		else if (myBoxType == BoxType::Hit && otherType == EntityType::Player) {
			switchAnimation(EnemyCactusAnimation::HIT);
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
		isGrounded = true;
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

	if ((!direction1Flag || !direction2Flag) && directionChangedTime > 0.1f)
	{
		direction *= -1;
		velocityX = 0;
		directionChangedTime = 0.f;
		sprite.flipX = !sprite.flipX;
	}

	pendingCollisions.clear();
}

void EnemyCactus::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}

void EnemyCactus::switchAnimation(EnemyCactusAnimation newAnimation) {
	if (newAnimation == activeAnimation || (activeAnimation == EnemyCactusAnimation::HIT && sprite.isAnimationGoing())) return;
	sprite.resetAnimation(activeAnimation);
	sprite.setVisible(activeAnimation, false);
	sprite.setVisible(newAnimation, true);
	sprite.update(0.f);
	if (newAnimation == EnemyCactusAnimation::HIT)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}