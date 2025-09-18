#include "Player.hpp"

Player::Player(SpriteComposite s, sf::View& view) : Entity(std::move(s)), boxManager(EntityType::Player, this), view(view) {
	boxManager.addBox({ {5.f,2.f} ,{24.f,28.f}}, BoxType::Collision);
	boxManager.addBox({ {5.f,2.f} ,{24.f,18.f} }, BoxType::Hit);
	boxManager.addBox({ {5.f,20.f} ,{24.f,10.f} }, BoxType::Hurt);
}

void Player::handleEvents(const sf::Event& e, GameContext& ctx) {
	if (e.is<sf::Event::KeyPressed>())
	{
		auto key = e.getIf<sf::Event::KeyPressed>();
		switch (key->code)
		{
		case sf::Keyboard::Key::Up:
			if (activeAnimation != PlayerAnimation::JUMP && (isGrounded || isOnWall ))
			{
				if (isOnWall && !isGrounded) {
					velocityY = -350.f;
					velocityX = -300.f;
					if (sprite.flipX) velocityX *= -1.f;
				} else {
					velocityY = -450.f;
				}
				switchAnimation(PlayerAnimation::JUMP);
				isGrounded = false;
				isOnWall = false;
				break;
			}

			if (!isGrounded && !isOnWall && !doubleJumpUsed)
			{
				doubleJumpUsed = true;
				velocityY = -450.f;
				switchAnimation(PlayerAnimation::DOUBLE_JUMP);
			}
			break;
		case sf::Keyboard::Key::Right:
			sprite.flipX = false;
			direction = 1;
			break;
		case sf::Keyboard::Key::Left:
			sprite.flipX = true;
			direction = -1;
			break;
		case sf::Keyboard::Key::Down:
			fastFall = true;
			break;
		default:
			break;
		}
	}

	if (e.is<sf::Event::KeyReleased>())
	{
		auto key = e.getIf<sf::Event::KeyReleased>();
		switch (key->code) {
		case sf::Keyboard::Key::Right:
			if (direction == 1)
			{
				direction = 0;
			}
			break;
		case sf::Keyboard::Key::Left:
			if (direction == -1)
			{
				direction = 0;
			}
			break;
		case sf::Keyboard::Key::Down:
			fastFall = false;
			break;
		default:
			break;
		}
	}
}

void Player::update(float dt, GameContext& ctx) {
	physicEngine.updatePlayerPhysic(*this, dt);

	if (velocityY > 0 && ((activeAnimation != PlayerAnimation::WALL_JUMP && activeAnimation != PlayerAnimation::DOUBLE_JUMP) || (activeAnimation == PlayerAnimation::DOUBLE_JUMP && !sprite.isAnimationGoing()) || (activeAnimation == PlayerAnimation::WALL_JUMP && !isOnWall)))
	{
		switchAnimation(PlayerAnimation::FALL);
	}

	if (velocityY < 0 && ((activeAnimation != PlayerAnimation::WALL_JUMP && activeAnimation != PlayerAnimation::DOUBLE_JUMP) || (activeAnimation == PlayerAnimation::DOUBLE_JUMP && !sprite.isAnimationGoing()) || (activeAnimation == PlayerAnimation::WALL_JUMP && !isOnWall)))
	{
		switchAnimation(PlayerAnimation::JUMP);
	}

	if (velocityX == 0 && velocityY == 0)
	{
		switchAnimation(PlayerAnimation::IDLE);
	}

	if (isOnWall && !isGrounded)
	{
		switchAnimation(PlayerAnimation::WALL_JUMP);
	}

	if (isGrounded && (direction != 0))
	{
		switchAnimation(PlayerAnimation::RUN);
	}

    sprite.update(dt);

	boxManager.updateBoxesPosition(sprite.getPosition());
	view.setCenter(sprite.getPosition());

	isGrounded = false;
	isOnWall = false;
}

void Player::draw(sf::RenderWindow& window, GameContext& ctx) {
    window.draw(sprite);
	boxManager.draw(window);
}

EntityType Player::getType() {
	return EntityType::Player;
}

void Player::doCollision() {
	if (pendingCollisions.empty()) return;

	const float NOISE = 0.5f; 
	const float EPS = 0.001f; 

	float maxFloor = 0.f; bool hasFloor = false; Box floorBox;
	float maxCeil = 0.f; bool hasCeil = false; Box ceilBox;
	float maxLeft = 0.f; bool hasLeft = false; Box leftBox;
	float maxRight = 0.f; bool hasRight = false; Box rightBox;

	std::vector<PendingCollision> otherCollisions;

	for (auto& pc : pendingCollisions) {
		if (pc.intersection.size.x < NOISE && pc.intersection.size.y < NOISE) continue;

		EntityType otherType = pc.other->getType();
		
		if (otherType == EntityType::Platform) { 
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
		else {
			otherCollisions.push_back(pc);
		}
	}

	sf::Vector2f totalMove{ 0.f, 0.f };

	if (hasFloor) {
		totalMove.y -= (maxFloor - EPS); 
		velocityY = 0.f;
		isGrounded = true;
		doubleJumpUsed = false;
	}

	if (hasCeil) {
		totalMove.y += (maxCeil - EPS); 
		velocityY = 0.f;
	}

	if (hasRight) {
		totalMove.x -= (maxRight - EPS);
		velocityX = 0.f;
		isOnWall = true;
	}
	if (hasLeft) {
		totalMove.x += (maxLeft - EPS); 
		velocityX = 0.f;
		isOnWall = true;
	}

	if (totalMove.x != 0.f || totalMove.y != 0.f) {
		sprite.move(totalMove);
	}

	for (auto& pc : otherCollisions) {
		// TODO::otherCollisions
	}

	pendingCollisions.clear();
}


void Player::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}

void Player::switchAnimation(PlayerAnimation newAnimation) {
	if (newAnimation == activeAnimation || (activeAnimation == PlayerAnimation::HIT && sprite.isAnimationGoing())) return;
	sprite.resetAnimation(activeAnimation);
	sprite.setVisible(activeAnimation, false);
	sprite.setVisible(newAnimation, true);
	if (newAnimation == PlayerAnimation::HIT || newAnimation == PlayerAnimation::DOUBLE_JUMP)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}