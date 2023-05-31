#include "..\..\..\include\Manager\EventManager\EventManager.h"

using namespace Whispers::Manager;
using namespace Whispers::Entity::Character;

EventManager* EventManager::pEvent = nullptr;

EventManager::EventManager()
    : pGraphic(pGraphic->getGraphicManager()),
      pState(pState->getStateManager()) {}

EventManager* EventManager::getEventManager() {
    if (pEvent == nullptr) {
        pEvent = new EventManager();
    }
    return pEvent;
}

EventManager::~EventManager() {
    if (pEvent) {
        delete pEvent;
        pEvent = nullptr;
    }
}

void EventManager::handleKeyPress() {
    if (pState->getCurrentState()->getId() == ID::ID::play_midnight) {
        State::StatePlay* pStatePlay =
            dynamic_cast<State::StatePlay*>(pState->getCurrentState());
        Entity::Character::Player* pPlayer = pStatePlay->getPlayer();
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
        if (Keyboard::isKeyPressed(Keyboard::LShift)) {
            pPlayer->attack(true);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            pState->popState();
        }
        if (Keyboard::isKeyPressed(Keyboard::R)) {
            pState->pushState(ID::ID::play_midnight);
        }
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