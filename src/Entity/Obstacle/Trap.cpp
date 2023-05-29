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
    if (ds.x < 0.0f && ds.y < 0.0f) {
        if (ds.x > ds.y) {
            if (pChar->getId() == ID::ID::player) {
                pChar->setTakeDamage(true);
                const float distanceToMove = 40.0f;
                if (pChar->getPosition().x < position.x) {
                    pChar->setPosition(
                        Vector2f(pChar->getPosition().x - distanceToMove,
                                 pChar->getPosition().y));
                } else {
                    pChar->setPosition(
                        Vector2f(pChar->getPosition().x + distanceToMove,
                                 pChar->getPosition().y));
                }
            }
        } else {
            if (pChar->getId() == ID::ID::player) {
                pChar->setTakeDamage(true);

                if (pChar->getPosition().y < position.y) {
                    const float maxDistanceToMove =
                        10.0f;  // Distância máxima a ser movida
                    const float increment =
                        maxDistanceToMove / 10.0f;  // Incremento de movimento

                    for (int i = 1; i <= 10; i++) {
                        const float distanceToMove2 = increment * i;

                        if (pChar->getPosition().x < position.x) {
                            // Jogador vem do lado esquerdo
                            pChar->setPosition(Vector2f(
                                pChar->getPosition().x - distanceToMove2,
                                pChar->getPosition().y - distanceToMove2));
                        } else {
                            // Jogador vem do lado direito
                            pChar->setPosition(Vector2f(
                                pChar->getPosition().x + distanceToMove2,
                                pChar->getPosition().y - distanceToMove2));
                        }
                    }
                }
            }
        }
    }
}
