#include "Platform.hpp"

Platform::Platform(SpriteComposite s, sf::FloatRect box, bool hasColision) : Entity(std::move(s)), boxManager(EntityType::Platform, this)  {
	if (hasColision)
	{
		boxManager.addBox(box, BoxType::Collision);
		boxManager.updateBoxesPosition(s.getPosition());
	}
}

EntityType Platform::getType() {
	return EntityType::Platform;
}

void Platform::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
}