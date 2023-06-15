#include "../../../../include/Entity/Character/Enemy/Ghost.h"

using namespace Whispers::Entity::Character::Enemy;

Ghost::Ghost(const sf::Vector2f pos, Player *player)
    : Enemy(pos, sf::Vector2f(GHOST_SIZE_X, GHOST_SIZE_Y), GHOST_LIFE, false,
            GHOST_DAMAGE, player, ID::ID::ghost),
      invisible(false) {
    init();
}

Ghost::~Ghost() {}

void Ghost::init() {
    animation.addAnimation("assets/character/enemy/ghost/idle.png", "idle", 1,
                           0.3f, sf::Vector2f(2.0, 2.0));
    animation.addAnimation("assets/character/enemy/ghost/walk.png", "walk", 4,
                           0.2f, sf::Vector2f(2.0, 2.0));
    shape.setOrigin(sf::Vector2f(size.x / 2.5f, size.y / 3.0f));
}

void Ghost::moveEnemy() {
    Vector2f playerPos = player->getPosition();
    Vector2f enemyPos = getPosition();
    sf::Color color = shape.getFillColor();

    if (fabs(playerPos.x - enemyPos.x) <= 1280.0f &&
        fabs(playerPos.y - enemyPos.y) <= 720.0f) {
        if ((playerPos.x - enemyPos.x < 10.0f) &&
            (playerPos.x - enemyPos.x > -10.0f)) {
            stop();
        } else if (playerPos.x - enemyPos.x > 0.0f) {
            if (!player->getFaceLeft()) {
                color.a = 20;
                walk(false);
            } else {
                color.a = 255;
                stop();
            }

        } else {
            if (player->getFaceLeft()) {
                color.a = 20;
                walk(true);
            } else {
                color.a = 255;
                stop();
            }
        }
    } else {
        stop();
        color.a = 255;
    }
    shape.setFillColor(color);
}

bool Ghost::getInvisible() const { return invisible; }

void Ghost::collision(Entity *other, Vector2f ds) {
    if (other->getId() == ID::ID::player || other->getId() == ID::ID::player2) {
        if (player->getIsInvincible() == false &&
            player->getIsAttacking() == false) {
            Player *player = static_cast<Player *>(other);
            Vector2f playerSpeed = player->getSpeed();
            playerSpeed.y = -sqrt(1.2f * GRAVITY * JUMP_SIZE);
            player->setSpeed(playerSpeed);
            player->setTakeDamage(true);
            if (invisible) {
                player->setLife(player->getLife() - (damage + 2));
            } else {
                player->setLife(player->getLife() - damage);
            }
            player->setInvincible(true);
        }
    }
}

void Ghost::updateAnimation() {
    if (canWalk) {
        animation.update(faceLeft, "walk");
    } else {
        animation.update(faceLeft, "idle");
    }
    if (takeDamage) {
        canWalk = false;
        if (!isDamageAnimationActive) {
            damageStartTime =
                std::chrono::steady_clock::now();  // Inicia o temporizador
                                                   // quando a animação de
                                                   // dano começa
            isDamageAnimationActive = true;
        } else {
            auto elapsedTime =
                std::chrono::steady_clock::now() -
                damageStartTime;  // Calcula o tempo decorrido desde o
                                  // início da animação de dano

            if (elapsedTime >= damageDuration) {
                takeDamage = false;  // Restaura a capacidade de andar após
                                     // a conclusão da animação de dano
                isDamageAnimationActive = false;
            }
        }
    }
    auto elapsedTime =
        std::chrono::steady_clock::now() - invincibilityStartTime;
    if (elapsedTime >= invincibilityDuration) {
        // Set invincibility to false
        isInvincible = false;
    }
}