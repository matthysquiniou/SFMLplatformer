#include "EnemyCactus.hpp"

EnemyCactus::EnemyCactus(SpriteComposite s) : Entity(std::move(s)), boxManager(EntityType::Enemy, this) {
	boxManager.addBox({ {0.f,0.f} ,{48.f,48.f} }, BoxType::Collision);
	boxManager.addBox({ {0.f,0.f} ,{48.f,24.f} }, BoxType::Hit);
	boxManager.addBox({ {0.f,24.f} ,{48.f,24.f} }, BoxType::Hurt);
}

void EnemyCactus::handleEvents(const sf::Event& e, GameContext& ctx) {
	if (e.is<sf::Event::KeyPressed>())
	{
		auto key = e.getIf<sf::Event::KeyPressed>();

	}

	if (e.is<sf::Event::KeyReleased>())
	{
		auto key = e.getIf<sf::Event::KeyReleased>();

	}
}

void EnemyCactus::update(float dt, GameContext& ctx) {
	//physicEngine.updatePlayerPhysic(*this, dt);

	if (velocityY > 0)
	{
		switchAnimation(EnemyCactusAnimation::FALL);
	}

	if (velocityY < 0)
	{
		switchAnimation(EnemyCactusAnimation::JUMP);
	}

	if (velocityX == 0 && velocityY == 0)
	{
		switchAnimation(EnemyCactusAnimation::IDLE);
	}

	if (isGrounded && (direction != 0))
	{
		switchAnimation(EnemyCactusAnimation::RUN);
	}

	sprite.update(dt);

	boxManager.updateBoxesPosition(sprite.getPosition());

	isGrounded = false;
}

void EnemyCactus::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType EnemyCactus::getType() {
	return EntityType::Enemy;
}

void EnemyCactus::doCollision() {
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
	if (newAnimation == EnemyCactusAnimation::HIT)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}