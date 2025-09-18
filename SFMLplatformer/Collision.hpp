#pragma once
#include "BoxManager.hpp"

namespace Collision {

    bool shouldCollide(EntityType a, EntityType b);
    bool shouldCollide(BoxType a, BoxType b);

    void processAll();

}