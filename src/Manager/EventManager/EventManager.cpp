#include "..\..\..\include\Manager\EventManager\EventManager.h"

using namespace Whispers::Manager;
using namespace Whispers::Entity::Character;

EventManager* EventManager::pEvent = nullptr;

EventManager::EventManager() : pGraphic(pGraphic->getGraphicManager()) {}

EventManager* EventManager::getEventManager() {
    if (pEvent == nullptr) {
        pEvent = new EventManager();
    }
    return pEvent;
}

void EventManager::setPlayer(Entity::Character::Player* pPlayer) {
    this->pPlayer = pPlayer;
}

EventManager::~EventManager() {
    if (pEvent) {
        delete pEvent;
        pEvent = nullptr;
    }
}

Player* EventManager::getPlayer() { return pPlayer; }

void EventManager::handleKeyPress() {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        pPlayer->walk(true);
    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
        pPlayer->walk(false);
    } else {
        pPlayer->stop();
    }
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        pPlayer->jump();
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        pGraphic->closeWindow();
    }
}

void EventManager::execute() {
    Event event;
    while (pGraphic->getWindow()->pollEvent(event)) {
        handleKeyPress();

        if (event.type == Event::Closed) {
            pGraphic->closeWindow();
        }
    }
}