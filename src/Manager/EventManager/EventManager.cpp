#include "..\..\..\include\Manager\EventManager\EventManager.h"

using namespace Whispers::Manager;

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

void EventManager::handleKeyPress(Keyboard::Key key) {
    if (key == Keyboard::A) {
        pPlayer->walk(true);
    }
    if (key == Keyboard::D) {
        pPlayer->walk(false);
    }
    if (key == Keyboard::W) {
        pPlayer->jump();
    }
    if (key == Keyboard::Escape) {
        pGraphic->clearWindow();
    }
}

void EventManager::handleKeyRelease(Keyboard::Key key) {
    if (key == Keyboard::A || key == Keyboard::D) {
        pPlayer->stop();
    }
}

void EventManager::execute() {
    Event event;
    while (pGraphic->getWindow()->pollEvent(event)) {
        if (event.type == Event::KeyPressed) {
            handleKeyPress(event.key.code);
        }
        if (event.type == Event::KeyReleased) {
            handleKeyRelease(event.key.code);
        }
        if (event.type == Event::Closed) {
            pGraphic->closeWindow();
        }
    }
}