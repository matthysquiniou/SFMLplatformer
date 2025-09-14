#include "PhysicEngine.hpp"
#include "Player.hpp"

void PhysicEngine::updatePlayerPhysic(Player& player, float dt) {
    switch (player.direction)
    {
    case -1:
        if (player.maxRunVelocity > abs(player.velocityX))
        {
            player.velocityX -= player.runAcceleration * dt;
        }
        break;
    case 0:
        player.velocityX -= (player.velocityX * groundFriction * dt);
        if (std::abs(player.velocityX) < 10.f) player.velocityX = 0;
        break;
    case 1:
        if (player.maxRunVelocity > player.velocityX)
        {
            player.velocityX += player.runAcceleration * dt;
        }
        break;
    default:
        break;
    }

    if (!player.isGrounded) {
        if (player.fastFall) {
            player.velocityY += gravity * dt * 2.5f;
        } else {
            player.velocityY += gravity * dt;
        }
    }

    player.getSprite().move({ player.velocityX * dt , player.velocityY * dt });
}
