#include "Player.hpp"

void Player::handleEvents(const sf::Event& e, GameContext& ctx) {
	if (e.is<sf::Event::KeyPressed>())
	{
		auto key = e.getIf<sf::Event::KeyPressed>();
		switch (key->code)
		{
		case sf::Keyboard::Key::Up:
			if (activeAnimation != PlayerAnimation::JUMP && (isGrounded || isOnWall ))
			{
				isGrounded = false;
				isOnWall = false;
				velocityY = -250.f;
				switchAnimation(PlayerAnimation::JUMP);
				break;
			}

			if (!isGrounded && !doubleJumpUsed)
			{
				doubleJumpUsed = true;
				velocityY = -250.f;
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

	if (velocityY > 0 && ((activeAnimation != PlayerAnimation::WALL_JUMP && activeAnimation != PlayerAnimation::DOUBLE_JUMP) || (activeAnimation == PlayerAnimation::DOUBLE_JUMP && !sprite.isAnimationGoing())))
	{
		switchAnimation(PlayerAnimation::FALL);
	}

	if (velocityY < 0 && ((activeAnimation != PlayerAnimation::WALL_JUMP && activeAnimation != PlayerAnimation::DOUBLE_JUMP) || (activeAnimation == PlayerAnimation::DOUBLE_JUMP && !sprite.isAnimationGoing())))
	{
		switchAnimation(PlayerAnimation::JUMP);
	}

	if (velocityX == 0 && velocityY == 0)
	{
		switchAnimation(PlayerAnimation::IDLE);
	}

	if (isOnWall)
	{
		switchAnimation(PlayerAnimation::WALL_JUMP);
	}

	if (isGrounded && (direction != 0))
	{
		switchAnimation(PlayerAnimation::RUN);
	}

    sprite.update(dt);
}

void Player::draw(sf::RenderWindow& window, GameContext& ctx) {
    window.draw(sprite);
}

void Player::switchAnimation(PlayerAnimation newAnimation) {
	if (newAnimation == activeAnimation || (activeAnimation == PlayerAnimation::HIT && sprite.isAnimationGoing())) return;
	sprite.setVisible(activeAnimation, false);
	sprite.setVisible(newAnimation, true);
	sprite.resetAnimation(newAnimation);
	if (newAnimation == PlayerAnimation::HIT || newAnimation == PlayerAnimation::DOUBLE_JUMP)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}