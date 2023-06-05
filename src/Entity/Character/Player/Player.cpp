#include "..\..\..\..\include\Entity\Character\Player\Player.h"
#include "..\..\..\..\include\Observer\PlayerObserver.h"


using namespace Whispers::Entity::Character;

Player::Player(const Vector2f pos, const Vector2f size)
    : Character(pos, size, PLAYER_SPEED, PLAYER_LIFE, PLAYER_DAMAGE,
                ID::ID::player),
      onFloor(false),
      pPlayerObs(new Observer::PlayerObserver(this)) 
{
    if (pPlayerObs == nullptr)
    {
        std::cout << "Nao foi possivel criar PlayerObserver" << std::endl;
    }
    
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
    animation.addAnimation("assets/character/player/death.png", "death", 6,
                           0.2f, Vector2f(6, 6));
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
void Player::collision(Entity* other, Vector2f ds) {
    Character* character = dynamic_cast<Character*>(other);
    if (character->getId() == ID::ID::skeleton) {
        if (!takeDamage) {
            // Player is not currently taking damage and either the player or
            // the skeleton is in the air
            takeDamage = true;
            cout << "Player: " << life << endl;
            life -= character->getDamage();
            if (life <= 0) {
                life = 0;
                isAlive = false;
            }
        }
    }
}

void Player::updateAnimation() {
    if (isAlive) {
        if (!onFloor && speed.y > 0.0f) {
            animation.update(faceLeft, "fall");
            if (isAttacking) animation.update(faceLeft, "attack");
        } else if (!onFloor) {
            animation.update(faceLeft, "jump");
        }
        if (isAttacking) {
            animation.update(faceLeft, "attack");
            if (!isAttackingAnimationActive) {
                attackStartTime = std::chrono::steady_clock::now();
                isAttackingAnimationActive = true;
            } else {
                auto elapsedTime =
                    std::chrono::steady_clock::now() - attackStartTime;
                if (elapsedTime >= attackDuration) {
                    isAttacking = false;
                    isAttackingAnimationActive = false;
                }
            }
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
    } else {
        animation.update(faceLeft, "death");
    }
}

void Player::attack(const bool isAttacking) { this->isAttacking = isAttacking; }
void Whispers::Entity::Character::Player::ChangeObserverStatus()
{
    pPlayerObs->changeActiveState();
}