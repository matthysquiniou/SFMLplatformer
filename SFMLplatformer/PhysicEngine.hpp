#pragma once
class Player;

class PhysicEngine {
public:
	void updatePlayerPhysic(Player& player, float dt);

private:
	float gravity = 300.f;
	float groundFriction = 4.f;
};