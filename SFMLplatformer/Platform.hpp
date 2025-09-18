#pragma once
#include "Entity.hpp"
#include "Assets.hpp"
#include "BoxManager.hpp"
#include <memory>
class Platform : public Entity {

public:
	Platform(SpriteComposite s, sf::FloatRect box, bool hasColision);
	EntityType getType() override;
	void draw(sf::RenderWindow& window, GameContext& ctx) override; // TODO::remove later

private:
	BoxManager boxManager;
};
