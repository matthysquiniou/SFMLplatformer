#include "Checkpoint.hpp"
#include "SoundManager.hpp"

Checkpoint::Checkpoint(SpriteComposite s) : Entity(std::move(s)), boxManager(EntityType::Checkpoint, this) {
	boxManager.addBox({ {18.f,0.f} ,{12.f,48.f} }, BoxType::Collision);
	boxManager.updateBoxesPosition(sprite.getPosition());
}

void Checkpoint::update(float dt, GameContext& ctx) {
	if (activeAnimation == CheckpointAnimation::OUT && !sprite.isAnimationGoing())
	{
		switchAnimation(CheckpointAnimation::IDLE);
	}
	if (!scoreGiven && activated)
	{
		ctx.score += 50;
		scoreGiven = true;
		SoundManager::play(SoundManager::SoundName::CHECKPOINT_TAKE);
	}
	sprite.update(dt);
}

void Checkpoint::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType Checkpoint::getType() {
	return EntityType::Checkpoint;
}

void Checkpoint::doCollision() {
	if (pendingCollisions.empty()) return;
	const float NOISE = 0.5f;
	const float EPS = 0.001f;


	for (auto& pc : pendingCollisions) {

		if (pc.intersection.size.x < NOISE && pc.intersection.size.y < NOISE) continue;

		EntityType otherType = pc.other->getType();

		if (otherType == EntityType::Player && !activated) {
			activated = true;
			switchAnimation(CheckpointAnimation::OUT);
		}
	}

	pendingCollisions.clear();
}

void Checkpoint::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}

void Checkpoint::switchAnimation(CheckpointAnimation newAnimation) {
	if (newAnimation == activeAnimation || (activeAnimation == CheckpointAnimation::OUT && sprite.isAnimationGoing())) return;
	sprite.resetAnimation(activeAnimation);
	sprite.setVisible(activeAnimation, false);
	sprite.setVisible(newAnimation, true);
	sprite.update(0.f);
	if (newAnimation == CheckpointAnimation::OUT)
	{
		sprite.stopAnimationAfterLoop(newAnimation);
	}
	activeAnimation = newAnimation;
}