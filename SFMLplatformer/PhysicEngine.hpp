#pragma once
class Player;
class EnemyCactus;
class EnemyTv;
class EnemyBarrel;
class EnemyFlyer;

class PhysicEngine {
public:
	void updatePlayerPhysic(Player& player, float dt);
	void updateEnemyCactusPhysic(EnemyCactus& cactus, float dt);
	void updateEnemyTvPhysic(EnemyTv& tv, float dt);
	void updateEnemyBarrelPhysic(EnemyBarrel& barrel, float dt);
	void updateEnemyFlyerPhysic(EnemyFlyer& flyer, float dt);

private:
	float gravity = 700.f;
	float groundFriction = 4.f;
};