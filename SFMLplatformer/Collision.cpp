#include "Collision.hpp"
#include <iostream>

namespace Collision {

    bool shouldCollide(EntityType a, EntityType b) {
        if (a > b) std::swap(a, b);
        if ((a == EntityType::Player && b == EntityType::Platform) ||
            (a == EntityType::Enemy && b == EntityType::Platform) ||
            (a == EntityType::Player && b == EntityType::Enemy)) {
            return true;
        }
        return false;
    }

    bool shouldCollide(BoxType a, BoxType b) {
        if (a > b) std::swap(a, b);
        if ((a == BoxType::Collision && b == BoxType::Collision) ||
            (a == BoxType::Hurt && b == BoxType::Hit) ||
            (a == BoxType::Collision && b == BoxType::CollisionObserver)) {
            return true;
        }
        return false;
    }

    void processAll() {
        auto& managers = BoxManager::allManagers;
        for (size_t i = 0; i < managers.size(); ++i) {
            auto* mgrA = managers[i];

            for (size_t j = i + 1; j < managers.size(); ++j) {
                auto* mgrB = managers[j];

                if (!shouldCollide(mgrA->getType(), mgrB->getType()))
                    continue;

                for (auto& boxA : mgrA->getBoxes()) {

                    if (!boxA.active) continue;

                    for (auto& boxB : mgrB->getBoxes()) {

                        if (!boxB.active) continue;

                        if (!shouldCollide(boxA.type, boxB.type))
                            continue;

                        auto intersection = boxA.rect.findIntersection(boxB.rect);
                        if (intersection.has_value()) {
                            mgrA->getEntity()->onCollision(*mgrB->getEntity(), boxA, boxB, intersection.value());
                            mgrB->getEntity()->onCollision(*mgrA->getEntity(), boxB, boxA, intersection.value());
                        }
                    }
                }
            }
        }

        for (size_t i = 0; i < managers.size(); ++i) {
            auto* mgrA = managers[i];
            mgrA->getEntity()->doCollision();
        }
    }

} 
