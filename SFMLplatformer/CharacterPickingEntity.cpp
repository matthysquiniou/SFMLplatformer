#include "CharacterPickingEntity.hpp"

void CharacterPickingEntity::draw(sf::RenderWindow& window, GameContext& ctx) {
	if (character == ctx.character)
	{
		window.draw(sprite);
	}
}