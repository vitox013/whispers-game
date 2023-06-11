#include "..\..\..\include\Manager\EventManager\EventManager.h"

using namespace Whispers::Manager;
using namespace Whispers::Entity::Character;

EventManager *EventManager::pEvent = nullptr;
Whispers::List::ObserverList *EventManager::pObsList = nullptr;

EventManager::EventManager()
    : pGraphic(pGraphic->getGraphicManager()),
      pState(pState->getStateManager())
{
    pObsList = new List::ObserverList();
    if (pObsList == nullptr)
    {
        std::cout << "Erro ao Alocar observer List" << std::endl;
        exit(1);
    }
}

EventManager *EventManager::getEventManager()
{
    if (pEvent == nullptr)
    {
        pEvent = new EventManager();
    }
    return pEvent;
}

EventManager::~EventManager()
{
    if (pObsList)
    {
        delete pObsList;
        pObsList = nullptr;
    }
    if (pEvent)
    {
        delete pEvent;
        pEvent = nullptr;
    }
}

void Whispers::Manager::EventManager::AddObserver(
    Observer::Observer *pObserver)
{
    pObsList->AddObserver(pObserver);
}

void Whispers::Manager::EventManager::RemoveObserver(
    Observer::Observer *pObserver)
{
    pObsList->RemoveObserver(pObserver);
}

void Whispers::Manager::EventManager::RemoveObserver(int pos)
{
    pObsList->RemoveObserver(pos);
}

void EventManager::handleKeyPress()
{
    if (pState->getCurrentState()->getId() == ID::ID::play_midnight ||
        pState->getCurrentState()->getId() == ID::ID::play_graveyard)
    {
        State::StatePlay *pStatePlay =
            dynamic_cast<State::StatePlay *>(pState->getCurrentState());
        Entity::Character::Player *pPlayer = pStatePlay->getPlayer();
        Entity::Character::Player *pPlayer2 = pStatePlay->getPlayer2();
        cout << "Player2 existe: " << pStatePlay->getPlayer2() << endl;
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
        if (pPlayer->getPosition().x > 6400.0f && pState->getCurrentState()->getId() == ID::ID::play_midnight)
        {
            pObsList->NotifyEndLevel();
            pState->popState();
            pState->pushState(ID::ID::play_graveyard);
        }
        // if (Keyboard::isKeyPressed(Keyboard::Escape))
        //{
        // pState->popState();
        //}
        // if (Keyboard::isKeyPressed(Keyboard::R))
        //{
        // pState->pushState(ID::ID::play_midnight);
        //}
        // Segundo Jogador
        if (pPlayer2 != nullptr) {
            cout << "Player 2 movimentado" << endl;
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                pPlayer2->walk(true);
            } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                pPlayer2->walk(false);
            } else {
                pPlayer2->stop();
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                pPlayer2->jump();
            }
            if (Keyboard::isKeyPressed(Keyboard::RShift)) {
                pPlayer2->attack(true);
            }
        }
    }
}

void EventManager::execute()
{
    sf::Event event;
    while (pGraphic->getWindow()->pollEvent(event))
    {
        handleKeyPress();
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
            pObsList->NotifyMouseReleased(event.mouseButton.button);
        }
        else if (event.type == sf::Event::Closed)
        {
            pGraphic->closeWindow();
        }
    }
}