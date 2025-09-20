#include "Gem.hpp"

Gem::Gem(SpriteComposite s) : Entity(std::move(s)), boxManager(EntityType::Object, this) {
	boxManager.addBox({ {0.f,0.f} ,{16.f,16.f} }, BoxType::Collision);
	boxManager.updateBoxesPosition(sprite.getPosition());
}

void Gem::update(float dt, GameContext& ctx) {
	sprite.update(dt);
	if (hasBeenTouch)
	{
		ctx.score += 10;
		deleteIt = true;
	}
}

void Gem::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType Gem::getType() {
	return EntityType::Object;
}

void Gem::doCollision() {
	if (pendingCollisions.empty()) return;
	const float NOISE = 0.5f;
	const float EPS = 0.001f;


	for (auto& pc : pendingCollisions) {

		if (pc.intersection.size.x < NOISE && pc.intersection.size.y < NOISE) continue;

		EntityType otherType = pc.other->getType();

		if (otherType == EntityType::Player) {
			hasBeenTouch = true;
			sprite.setVisible(0, false);
			boxManager.disableBoxType(BoxType::Collision);
		}
	}

	pendingCollisions.clear();
}

void Gem::onCollision(Entity& other, const Box& myBox, const Box& otherBox, sf::FloatRect intersection) {
	pendingCollisions.push_back({ &other, myBox, otherBox, intersection });
}