#include "..\..\..\..\include\Entity\Character\Player\Player.h"

using namespace Whispers::Entity::Character;

Player::Player(const Vector2f pos, const Vector2f size)
    : Character(pos, size, PLAYER_SPEED, ID::ID::player), onFloor(false) {
    init();
}

Player::~Player() {}

void Player::Player::init() {
    animation.addAnimation("assets/character/player/idle.png", "idle", 8, 0.15f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/walk.png", "walk", 8, 0.1f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/jump.png", "jump", 2, 0.15f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/fall.png", "fall", 2, 0.15f,
                           Vector2f(6, 6));
    animation.addAnimation("assets/character/player/attack.png", "attack", 4,
                           0.1f, Vector2f(6, 6));
    animation.addAnimation("assets/character/player/hurt.png", "hurt", 4, 0.2f,
                           Vector2f(6, 6));
    shape.setOrigin(Vector2f(size.x / 2.5f, size.y / 2.5f));
}

void Player::update() {
    updatePosition();
    updateAnimation();
    pGraphic->updateCamera(position);
}

void Player::jump() {
    if (onFloor && !takeDamage) {
        speed.y = -sqrt(2.0f * GRAVITY * JUMP_SIZE);
        onFloor = false;
    }
}

void Player::canJump() { onFloor = true; }
void Player::collision(Entity* other, Vector2f ds) {}

void Player::updateAnimation() {
    if (!onFloor && speed.y > 0.0f) {
        animation.update(faceLeft, "fall");
    } else if (!onFloor) {
        animation.update(faceLeft, "jump");
    } else if (isAttacking) {
        animation.update(faceLeft, "attack");
    } else if (canWalk && !takeDamage) {
        animation.update(faceLeft, "walk");
    } else if (!takeDamage) {
        animation.update(faceLeft, "idle");
    }
    if (takeDamage) {
        animation.update(faceLeft, "hurt");
        canWalk = false;

        if (!isDamageAnimationActive) {
            damageStartTime =
                std::chrono::steady_clock::now();  // Inicia o temporizador
                                                   // quando a animação de dano
                                                   // começa
            isDamageAnimationActive = true;
        } else {
            auto elapsedTime =
                std::chrono::steady_clock::now() -
                damageStartTime;  // Calcula o tempo decorrido desde o início da
                                  // animação de dano

            if (elapsedTime >= damageDuration) {
                takeDamage = false;  // Restaura a capacidade de andar após a
                                     // conclusão da animação de dano
                isDamageAnimationActive = false;
            }
        }
    }
}