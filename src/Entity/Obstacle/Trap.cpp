#include "..\..\..\include\Entity\Obstacle\Trap.h"

using namespace Whispers::Entity::Obstacle;

Trap::Trap(Vector2f pos, Vector2f size)
    : Obstacle(pos, size, ID::ID::trap, TRAP_TEXTURE_PATH), damage(1) {}

Trap::~Trap() {}

void Trap::collision(Entity* entity, Vector2f ds) {
    if (entity->getId() == ID::ID::player) {
        collideObstacle(ds, static_cast<Character::Character*>(entity));
    }
}

void Trap::collideObstacle(Vector2f ds, Character::Character* pChar) {
    Character::Player* pPlayer = static_cast<Character::Player*>(pChar);
    if (!pPlayer->getIsInvincible()) {
        if (ds.x < 0.0f && ds.y < 0.0f) {
            pPlayer->setTakeDamage(true);

            const float maxDistanceToMove =
                20.0f;  // Distância máxima a ser movida

            pPlayer->setSpeed(Vector2f(pPlayer->getSpeed().x,
                                       -sqrt(0.6f * GRAVITY * JUMP_SIZE)));

            pPlayer->setInvincible(true);
        }
    }
}
