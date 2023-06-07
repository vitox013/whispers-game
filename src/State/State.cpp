#include "..\..\include\State\State.h"

using namespace Whispers::State;

State::State(const ID::ID id) : Ente(id), remove(false) {}

State::~State() {}

void State::draw()
{
    // Desenhar o background
    // Desenhar o mapa
    // Desenhar os inimigos
    // Desenhar o player
    // Desenhar os tiros
    // Desenhar os itens
    // Desenhar o HUD
    // Desenhar o menu
    // Desenhar o cursor
    // Desenhar o fade
    // Desenhar o texto

    // Desenhar
}
void Whispers::State::State::SetRemove(const bool remove)
{
    this->remove = remove;
}

const bool Whispers::State::State::getRemove() const
{
    return remove;
}
