#include "Cup.hpp"
#include "NextLevelState.hpp"
#include "SoundManager.hpp"

Cup::Cup(SpriteComposite s) : Entity(std::move(s)), boxManager(EntityType::Object, this) {
	boxManager.addBox({ {8.f,16.f} ,{48.f,48.f} }, BoxType::Collision);
	boxManager.updateBoxesPosition(sprite.getPosition());
}

void Cup::update(float dt, GameContext& ctx) {
	sprite.update(dt);
	if (hasBeenTouch)
	{
		ctx.currentState = GameState::NEXT_LEVEL;
		ctx.nextLevelState->loadNextLevel(ctx);
	}

	if (!scoreGiven && hasBeenTouch)
	{
		ctx.score += 500;
		SoundManager::play(SoundManager::SoundName::LEVEL_COMPLETE);
		scoreGiven = true;
	}
}

void Cup::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
}

EntityType Cup::getType() {
	return EntityType::Object;
}

void Cup::doCollision() {
	if (pendingCollisions.empty()) return;
	const float NOISE = 0.5f;
	const float EPS = 0.001f;


	for (auto& pc : pendingCollisions) {

		if (pc.intersection.size.x < NOISE && pc.intersection.size.y < NOISE) continue;

		EntityType otherType = pc.other->getType();

		if (otherType == EntityType::Player && !hasBeenTouch) {
			hasBeenTouch = true;
			switchAnimation(CupAnimation::TOUCH);
		}
	}

	pendingCollisions.clear();
}

void Cup::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}

void Cup::switchAnimation(CupAnimation newAnimation) {
	if (newAnimation == activeAnimation) return;
	sprite.resetAnimation(activeAnimation);
	sprite.setVisible(activeAnimation, false);
	sprite.setVisible(newAnimation, true);
	sprite.update(0.f);
	if (newAnimation == CupAnimation::TOUCH)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}