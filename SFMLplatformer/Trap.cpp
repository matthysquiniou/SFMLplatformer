#include "Trap.hpp"
#include "SoundManager.hpp"

Trap::Trap(SpriteComposite s, TrapType trapType, float animationDelay) : Entity(std::move(s)), boxManager(EntityType::Enemy, this), trapType(trapType), animationDelay(animationDelay) {

	switch (trapType)
	{
	case Trap::SAW:
		boxManager.addBox({ {8.f,8.f} ,{32.f,32.f} }, BoxType::Hurt, 4);
		boxManager.addBox({ {8.f,8.f} ,{32.f,32.f} }, BoxType::Hurt, 5);
		boxManager.addBox({ {8.f,8.f} ,{32.f,32.f} }, BoxType::Hurt, 6);
		break;
	case Trap::SPIKE:
		if (sprite.flipY)
		{
			boxManager.addBox({ {16.f,0.f} ,{16.f,8.f} }, BoxType::Hurt, 2);
			boxManager.addBox({ {16.f,0.f} ,{16.f,12.f} }, BoxType::Hurt, 3);
			boxManager.addBox({ {16.f,0.f} ,{16.f,12.f} }, BoxType::Hurt, 4);
			boxManager.addBox({ {16.f,0.f} ,{16.f,12.f} }, BoxType::Hurt, 5);
			boxManager.addBox({ {16.f,0.f} ,{16.f,8.f} }, BoxType::Hurt, 6);
		} else {
			boxManager.addBox({ {16.f,40.f} ,{16.f,8.f} }, BoxType::Hurt, 2);
			boxManager.addBox({ {16.f,36.f} ,{16.f,12.f} }, BoxType::Hurt, 3);
			boxManager.addBox({ {16.f,36.f} ,{16.f,12.f} }, BoxType::Hurt, 4);
			boxManager.addBox({ {16.f,36.f} ,{16.f,12.f} }, BoxType::Hurt, 5);
			boxManager.addBox({ {16.f,40.f} ,{16.f,8.f} }, BoxType::Hurt, 6);
		}

		break;
	case Trap::ELECTRICITY:
		if (sprite.flipY)
		{
			boxManager.addBox({ {15.f,6.f} ,{18.f,24.f} }, BoxType::Hurt, 3);
			boxManager.addBox({ {7.f,6.f} ,{28.f,36.f} }, BoxType::Hurt, 4);
			boxManager.addBox({ {7.f,6.f} ,{28.f,36.f} }, BoxType::Hurt, 5);
			boxManager.addBox({ {5.f,6.f} ,{32.f,42.f} }, BoxType::Hurt, 6);
			boxManager.addBox({ {5.f,6.f} ,{32.f,42.f} }, BoxType::Hurt, 7);
		} else {
			boxManager.addBox({ {15.f,18.f} ,{18.f,24.f} }, BoxType::Hurt, 3);
			boxManager.addBox({ {7.f,6.f} ,{28.f,36.f} }, BoxType::Hurt, 4);
			boxManager.addBox({ {7.f,6.f} ,{28.f,36.f} }, BoxType::Hurt, 5);
			boxManager.addBox({ {5.f,0.f} ,{32.f,42.f} }, BoxType::Hurt, 6);
			boxManager.addBox({ {5.f,0.f} ,{32.f,42.f} }, BoxType::Hurt, 7);
		}

		break;
	default:
		break;
	}

	boxManager.disableBoxType(BoxType::Hurt);

	boxManager.updateBoxesPosition(sprite.getPosition());
}

void Trap::update(float dt, GameContext& ctx) {
	if (!isIdling)
	{
		animationTime += dt;
		updateHurtBox();
		sprite.update(dt);
	}
	else {
		idleTime += dt;
		if (idleTime > 3.f)
		{
			isIdling = false;
			sprite.setAnimationActive(0, true);
		}
	}

}

void Trap::draw(sf::RenderWindow& window, GameContext& ctx) {
	window.draw(sprite);
	boxManager.draw(window);
}

EntityType Trap::getType() {
	return EntityType::Enemy;
}

void Trap::updateHurtBox() {
	if (animationTime > animationDelay)
	{
		if (hurtBoxActive == 7) {
			bool deactivate = boxManager.disableBoxObserver(hurtBoxActive);
			hurtBoxActive = 1;
			bool activate = boxManager.activateBoxObserver(hurtBoxActive);
			sprite.setAnimationActive(0, false);
			sprite.resetAnimation(0);
			idleTime = 0.f;
			isIdling = true;
			animationTime = 0.f;
			updateSound(activate, deactivate);
		} else {
			bool deactivate = boxManager.disableBoxObserver(hurtBoxActive);
			hurtBoxActive++;
			bool activate = boxManager.activateBoxObserver(hurtBoxActive);
			animationTime -= animationDelay;
			updateSound(activate, deactivate);
		}
	}
}

void Trap::updateSound(bool activate, bool deactivate) {
	switch (trapType)
	{
	case Trap::SAW:
		if (activate) SoundManager::play(SoundManager::SoundName::SAW,true);
		if (deactivate) SoundManager::stop(SoundManager::SoundName::SAW);
		break;
	case Trap::SPIKE:
		if (activate) SoundManager::play(SoundManager::SoundName::SPIKE, true);
		if (deactivate) SoundManager::play(SoundManager::SoundName::SPIKE);
		break;
	case Trap::ELECTRICITY:
		if (activate) SoundManager::play(SoundManager::SoundName::ELECTRICITY, true);
		if (deactivate) SoundManager::stop(SoundManager::SoundName::ELECTRICITY);
		break;
	default:
		break;
	}
}