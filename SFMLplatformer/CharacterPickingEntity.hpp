#pragma once
#include "Entity.hpp"

class CharacterPickingEntity : public Entity {
public:
	CharacterPickingEntity(SpriteComposite s, int character) : Entity(std::move(s)), character(character) {}

	void draw(sf::RenderWindow& window, GameContext& ctx) override;

	int character;
};
