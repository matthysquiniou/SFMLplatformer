#include "FragilePlatform.hpp"
#include "SoundManager.hpp"

FragilePlatform::FragilePlatform(SpriteComposite s) : Entity(std::move(s)), boxManager(EntityType::Platform, this) {
	boxManager.addBox({ {8.f,20.f} ,{32.f,8.f} }, BoxType::Collision);
	boxManager.updateBoxesPosition(sprite.getPosition());
}

void FragilePlatform::update(float dt, GameContext& ctx) {
	if (hasBeenTouch)
	{
		sprite.update(dt);

		if (!sprite.isAnimationGoing())
		{
			sprite.setVisible(0, false);
			boxManager.disableBoxType(BoxType::Collision);
			respawnTime += dt;
		}

		if (respawnTime > 15.f)
		{
			respawnTime = 0.f;
			hasBeenTouch = false;
			boxManager.activateBoxType(BoxType::Collision);
			sprite.setVisible(0, true);
			sprite.resetAnimation(0);
			sprite.update(0.f);
			sprite.setAnimationActive(0,false);
		}
	}
}

void FragilePlatform::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType FragilePlatform::getType() {
	return EntityType::Platform;
}

void FragilePlatform::doCollision() {
	if (pendingCollisions.empty()) return;
	const float NOISE = 0.5f;
	const float EPS = 0.001f;


	for (auto& pc : pendingCollisions) {

		if (pc.intersection.size.x < NOISE && pc.intersection.size.y < NOISE) continue;

		EntityType otherType = pc.other->getType();

		if (otherType == EntityType::Player && !hasBeenTouch) {
			SoundManager::play(SoundManager::SoundName::BREAK);
			hasBeenTouch = true;
			sprite.setAnimationActive(0, true);
			sprite.stopAnimationAfterLoop(0);
		}
	}

	pendingCollisions.clear();
}

void FragilePlatform::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}