#include "..\..\include\List\EntityList.h"
using namespace Whispers;

List::EntityList::EntityList() : objEntityList() {}

List::EntityList::~EntityList() {}

void List::EntityList::addEntity(Entity::Entity* entity) {
    objEntityList.addElement(entity);
}

void List::EntityList::removeEntity(Entity::Entity* entity) {
    objEntityList.removeElement(entity);
}

void List::EntityList::removeEntity(int index) {
    objEntityList.removeElement(index);
}

const int List::EntityList::getSize() const { return objEntityList.getSize(); }

Entity::Entity* List::EntityList::operator[](int index) {
    return objEntityList.operator[](index);
}

void List::EntityList::clearList() { objEntityList.clearList(); }

void List::EntityList::execute() {
    int size = objEntityList.getSize();
    Entity::Entity* pAux = nullptr;
    for (int i = 0; i < size; i++) {
        pAux = objEntityList.operator[](i);
        pAux->update();
    }
}