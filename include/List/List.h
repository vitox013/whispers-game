#pragma once

#include ".\Element.h"

namespace Whispers::List {
template <class TL>
class List {
   private:
    Element<TL>* pFirst;
    Element<TL>* pLast;
    int size;

   public:
    List();
    ~List();
    void addElement(TL* element);
    void removeElement(TL* element);
    void removeElement(int pos);
    const int getSize() const;
    void clearList();
    TL* operator[](int pos);
};

template <class TL>
List<TL>::List() : size(0), pFirst(nullptr), pLast(nullptr) {}

template <class TL>
List<TL>::~List() {
    clearList();
}

template <class TL>
void List<TL>::addElement(TL* element) {
    if (element == nullptr) {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    Element<TL>* newElement = new Element<TL>();
    if (newElement == nullptr) {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    newElement->setElement(element);
    if (pFirst == nullptr) {
        pFirst = newElement;
        pLast = newElement;
    } else {
        pLast->setNext(newElement);
        pLast = newElement;
    }
    size++;
}

template <class TL>
void List<TL>::removeElement(TL* element) {
    if (element == nullptr) {
        std::cout << "Error, element is NULL" << std::endl;
        exit(1);
    }
    Element<TL>* pAux = pFirst;
    while (pAux != nullptr) {
        if (pAux->getElement() == element) {
            delete (pAux);
        }
        pAux = pAux->getNext();
    }
    pAux = nullptr;
}

// talvez não funcione
template <class TL>
void List<TL>::removeElement(int pos) {
    return removeElement(operator[](pos));
}

template <class TL>
const int List<TL>::getSize() const {
    return (int)size;
}

template <class TL>
void List<TL>::clearList() {
    if (pFirst) {
        Element<TL>* pAux = pFirst;
        Element<TL>* pAux2 = nullptr;

        while (pAux != nullptr) {
            pAux2 = pAux->getNext();
            delete (pAux->getElement());
            pAux = pAux2;
        }
        pAux = nullptr;
        pAux2 = nullptr;
    }
}

template <class TL>
TL* List<TL>::operator[](int pos) {
    if (pos >= size || pos < 0) {
        std::cout << "Invalid index " << pos << std::endl;
    }
    Element<TL>* pAux = pFirst;

    for (int i = 0; i < pos; i++) {
        pAux = pAux->getNext();
    }

    return pAux->getElement();
}
}  // namespace Whispers::List