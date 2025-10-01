#include "Player.hpp"
#include "SoundManager.hpp"

Player::Player(SpriteComposite s, sf::View& view) : Entity(std::move(s)), boxManager(EntityType::Player, this), view(view) {
	respawnPos = sprite.getPosition();
	boxManager.addBox({ {5.f,2.f} ,{24.f,28.f}}, BoxType::Collision);
	boxManager.addBox({ {5.f,2.f} ,{24.f,20.f} }, BoxType::Hit);
	boxManager.addBox({ {5.f,22.f} ,{24.f,8.f} }, BoxType::Hurt);
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
					SoundManager::play(SoundManager::SoundName::JUMP);
				} else {
					velocityY = -450.f;
					SoundManager::play(SoundManager::SoundName::JUMP);
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
				SoundManager::play(SoundManager::SoundName::JUMP);
			}
			break;
		case sf::Keyboard::Key::Right:
			sprite.flipX = false;
			direction = 1;
			SoundManager::play(SoundManager::SoundName::STEP);
			break;
		case sf::Keyboard::Key::Left:
			sprite.flipX = true;
			direction = -1;
			SoundManager::play(SoundManager::SoundName::STEP);
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
				SoundManager::stop(SoundManager::SoundName::STEP);
			}
			break;
		case sf::Keyboard::Key::Left:
			if (direction == -1)
			{
				direction = 0;
				SoundManager::stop(SoundManager::SoundName::STEP);
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

	if (hasBeenHit)
	{
		sprite.update(dt);
		if (!sprite.isAnimationGoing() && activeAnimation == PlayerAnimation::HIT)
		{
			switchAnimation(PlayerAnimation::DESAPPEARING);
			SoundManager::play(SoundManager::SoundName::PLAYER_DEATH);
		}
		if (!sprite.isAnimationGoing() && activeAnimation == PlayerAnimation::DESAPPEARING)
		{
			respawn();
		}
		return;
	}

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

	for (auto& pc : pendingCollisions) {
		if (pc.intersection.size.x < NOISE && pc.intersection.size.y < NOISE) continue;

		EntityType otherType = pc.other->getType();
		BoxType myBoxType = pc.myBox.type;

		//platform
		
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
		} else if ( myBoxType == BoxType::Hit && otherType == EntityType::Enemy) {
			switchAnimation(PlayerAnimation::HIT);
			boxManager.disableBoxType(BoxType::Hit);
			boxManager.disableBoxType(BoxType::Hurt);
			hasBeenHit = true;
		} else if ( myBoxType == BoxType::Collision && otherType == EntityType::Checkpoint) {
			sf::Vector2f checkpointPos = pc.other->getSprite().getPosition();
			if (respawnPos.y < checkpointPos.y) respawnPos = checkpointPos;
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

	pendingCollisions.clear();
}

void Player::respawn() {
	sprite.setPosition(respawnPos);
	hasBeenHit = false;
	velocityX = 0.f;
	velocityY = 0.f;
	boxManager.activateBoxType(BoxType::Hit);
	boxManager.activateBoxType(BoxType::Hurt);
	switchAnimation(PlayerAnimation::APPEARING);
	SoundManager::play(SoundManager::SoundName::RESPAWN);
}


void Player::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}

void Player::switchAnimation(PlayerAnimation newAnimation) {
	if (newAnimation == activeAnimation ||
		(activeAnimation == PlayerAnimation::HIT && sprite.isAnimationGoing()) ||
		(activeAnimation == PlayerAnimation::APPEARING && sprite.isAnimationGoing()) ||
		(activeAnimation == PlayerAnimation::DESAPPEARING && sprite.isAnimationGoing()) ) return;
	sprite.resetAnimation(activeAnimation);
	sprite.setVisible(activeAnimation, false);
	sprite.setVisible(newAnimation, true);
	sprite.update(0.f);
	if (newAnimation == PlayerAnimation::HIT ||
		newAnimation == PlayerAnimation::DOUBLE_JUMP || 
		newAnimation == PlayerAnimation::DESAPPEARING ||
		newAnimation == PlayerAnimation::APPEARING)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}