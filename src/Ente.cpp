#pragma once
#include "..\include\Ente.h"

using namespace Whispers;

Ente::Ente(const ID::ID id) : id(id), pGraphic(pGraphic->getGraphicManager()) {}

Ente::~Ente() {}

const ID::ID Ente::getId() const { return id; }
