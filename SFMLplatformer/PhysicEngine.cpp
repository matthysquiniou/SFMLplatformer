#include "PhysicEngine.hpp"
#include "Player.hpp"
#include "EnemyCactus.hpp"
#include "EnemyTv.hpp"
#include "EnemyBarrel.hpp"
#include "EnemyFlyer.hpp"
#include "EnemyCanon.hpp"

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


void PhysicEngine::updateEnemyCactusPhysic(EnemyCactus& cactus, float dt) {
    switch (cactus.direction)
    {
    case -1:
        if (cactus.maxRunVelocity > abs(cactus.velocityX))
        {
            cactus.velocityX -= cactus.runAcceleration * dt;
        }
        break;
    case 1:
        if (cactus.maxRunVelocity > cactus.velocityX)
        {
            cactus.velocityX += cactus.runAcceleration * dt;
        }
        break;
    default:
        break;
    }

    if (!cactus.isGrounded) {
        cactus.velocityY += gravity * dt;
    }

    cactus.getSprite().move({ cactus.velocityX * dt , cactus.velocityY * dt });
}

void PhysicEngine::updateEnemyTvPhysic(EnemyTv& tv, float dt) {
    switch (tv.direction)
    {
    case -1:
        if (tv.maxRunVelocity > abs(tv.velocityX))
        {
            tv.velocityX -= tv.runAcceleration * dt;
        }
        break;
    case 1:
        if (tv.maxRunVelocity > tv.velocityX)
        {
            tv.velocityX += tv.runAcceleration * dt;
        }
        break;
    default:
        break;
    }

    if (!tv.isGrounded) {
        tv.velocityY += gravity * dt;
    }

    tv.getSprite().move({ tv.velocityX * dt , tv.velocityY * dt });
}

void PhysicEngine::updateEnemyBarrelPhysic(EnemyBarrel& barrel, float dt) {
    if (barrel.isStuned) return;

    switch (barrel.direction)
    {
    case -1:
        if (barrel.isRunning)
        {
            if (barrel.maxRunVelocity > abs(barrel.velocityX))
            {
                barrel.velocityX -= barrel.runAcceleration * dt;
            }
        } else {
            if (barrel.maxWalkVelocity > abs(barrel.velocityX))
            {
                barrel.velocityX -= barrel.walkAcceleration * dt;
            }
        }

        break;
    case 1:
        if (barrel.isRunning)
        {
            if (barrel.maxRunVelocity > barrel.velocityX)
            {
                barrel.velocityX += barrel.runAcceleration * dt;
            }
        } else {
            if (barrel.maxWalkVelocity > barrel.velocityX)
            {
                barrel.velocityX += barrel.walkAcceleration * dt;
            }
        }

        break;
    default:
        break;
    }

    if (!barrel.isGrounded) {
        barrel.velocityY += gravity * dt;
    }

    barrel.getSprite().move({ barrel.velocityX * dt , barrel.velocityY * dt });
}

void PhysicEngine::updateEnemyFlyerPhysic(EnemyFlyer& flyer, float dt) {

    switch (flyer.direction)
    {
    case -1:
        if (flyer.isAttacking || flyer.isGoingUp) break;
        if (flyer.maxFlyVelocity > abs(flyer.velocityX))
        {
            flyer.velocityX -= flyer.flyAcceleration * dt;
        }
        
        break;
    case 1:
        if (flyer.isAttacking || flyer.isGoingUp) break;
        if (flyer.maxFlyVelocity > flyer.velocityX)
        {
            flyer.velocityX += flyer.flyAcceleration * dt;
        }

        break;
    default:
        break;
    }

    if (flyer.isGoingUp)
    {
        flyer.velocityY = -flyer.goingUpSpeed;
    }else if (!flyer.isAttacking) {
        flyer.velocityY = 0.f;
    }

    if (flyer.isGoingUp && flyer.getSprite().getPosition().y < flyer.baseY)
    {
        flyer.isGoingUp = false;
    }

    flyer.getSprite().move({ flyer.velocityX * dt , flyer.velocityY * dt });
}

void PhysicEngine::updateEnemyCanonPhysic(EnemyCanon& canon, float dt) {
    if (canon.isIdling) return;

    switch (canon.direction)
    {
    case -1:
        if (canon.maxWalkVelocity > abs(canon.velocityX))
        {
            canon.velocityX -= canon.walkAcceleration * dt;
        }

        break;
    case 1:
        if (canon.maxWalkVelocity > canon.velocityX)
        {
            canon.velocityX += canon.walkAcceleration * dt;
        }

        break;
    default:
        break;
    }

    if (!canon.isGrounded) {
        canon.velocityY += gravity * dt;
    }

    canon.getSprite().move({ canon.velocityX * dt , canon.velocityY * dt });
}