#include "..\..\..\include\Manager\EventManager\EventManager.h"

using namespace Whispers::Manager;
using namespace Whispers::Entity::Character;

EventManager *EventManager::pEvent = nullptr;

EventManager::EventManager()
    : pGraphic(pGraphic->getGraphicManager()),
      pState(pState->getStateManager()) {
    pObsList = new List::ObserverList();
    if (pObsList == nullptr) {
        std::cout << "Erro ao Alocar observer List" << std::endl;
        exit(1);
    }
}

EventManager *EventManager::getEventManager() {
    if (pEvent == nullptr) {
        pEvent = new EventManager();
    }
    return pEvent;
}

EventManager::~EventManager() {
    if (pObsList) {
        delete pObsList;
        pObsList = nullptr;
    }
    if (pEvent) {
        delete pEvent;
        pEvent = nullptr;
    }
}

void Whispers::Manager::EventManager::AddObserver(
    Observer::Observer *pObserver) {
    pObsList->AddObserver(pObserver);
}

void Whispers::Manager::EventManager::RemoveObserver(
    Observer::Observer *pObserver) {
    pObsList->RemoveObserver(pObserver);
}

void Whispers::Manager::EventManager::RemoveObserver(int pos) {
    pObsList->RemoveObserver(pos);
}

void EventManager::handleKeyPress() {
    if (pState->getCurrentState()->getId() == ID::ID::play_midnight) {
        State::StatePlay *pStatePlay =
            dynamic_cast<State::StatePlay *>(pState->getCurrentState());
<<<<<<< HEAD
        //Entity::Character::Player *pPlayer = pStatePlay->getPlayer();
        
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
=======
        Entity::Character::Player *pPlayer = pStatePlay->getPlayer();
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
>>>>>>> 0e72f7135033eb6f676f3d04e387dd76ad10e15e
            pState->popState();
        }
        if (Keyboard::isKeyPressed(Keyboard::R)) {
            pState->pushState(ID::ID::play_midnight);
        }
    }
}

void EventManager::execute() {
    sf::Event event;
<<<<<<< HEAD
    while (pGraphic->getWindow()->pollEvent(event))
    {
        //handleKeyPress();
        if (event.type == sf::Event::KeyPressed)
        {
            pObsList->NotifyKeyPressed(event.key.code);
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            pObsList->NotifyKeyReleased(event.key.code);
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
=======
    while (pGraphic->getWindow()->pollEvent(event)) {
        handleKeyPress();
        // if (event.type == sf::Event::KeyPressed) {
        //     pObsList->NotifyKeyPressed(event.key.code);
        // } else if (event.type == sf::Event::KeyReleased) {
        //     // pObsList->NotifyKeyReleased(event.key.code);
        // } else
        if (event.type == sf::Event::MouseButtonReleased) {
>>>>>>> 0e72f7135033eb6f676f3d04e387dd76ad10e15e
            pObsList->NotifyMouseReleased(event.mouseButton.button);
        } else if (event.type == sf::Event::Closed) {
            pGraphic->closeWindow();
        }
    }
}