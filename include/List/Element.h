#pragma once
#include "./stdafx.h"
namespace Whispers::List {
template <class TE>
class Element {
   private:
    Element<TE>* pNext;
    TE* pElement;

   public:
    Element();
    ~Element();
    void setNext(Element<TE>* next);
    void setElement(TE* element);
    Element<TE>* getNext() const;
    TE* getElement() const;
};

template <class TE>
Element<TE>::Element() : pNext(nullptr), pElement(nullptr) {}

template <class TE>
Element<TE>::~Element() {}

template <class TE>
void Element<TE>::setNext(Element<TE>* next) {
    this->pNext = next;
}

template <class TE>
void Element<TE>::setElement(TE* element) {
    this->pElement = element;
}

template <class TE>
Element<TE>* Element<TE>::getNext() const {
    return pNext;
}

template <class TE>
TE* Element<TE>::getElement() const {
    return pElement;
}
}  // namespace Whispers::List
