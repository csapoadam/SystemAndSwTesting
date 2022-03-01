#include <iostream>
#include "IntVector.h"

IntVector::IntVector(const IntVector& other) :
    currentNumElements(other.currentNumElements),
    currentSizeInMemory(other.currentSizeInMemory)
{
    //std::cout << "  -> copy CSTR called" << std::endl;
    firstElement = new int[currentSizeInMemory];
    for (int inx = 0; inx < currentNumElements; inx++) {
        *(firstElement + inx) = *(other.firstElement + inx);
    }
}

IntVector& IntVector::operator=(const IntVector& other) {
    //std::cout << "  -> copy ASSGN called" << std::endl;
    if (this == &other) { return *this; }
    // eloszor felszabaditjuk a beltartalmat - visszaadjuk a rendszernek
    // a memoriat
    delete firstElement;

    // ezt kovetoen lemasoljuk other-t
    currentNumElements = other.currentNumElements;
    currentSizeInMemory = other.currentSizeInMemory;
    firstElement = new int[currentSizeInMemory];
    for (int inx = 0; inx < currentNumElements; inx++) {
        *(firstElement + inx) = *(other.firstElement + inx);
    }
    return *this;
}

IntVector::IntVector(IntVector&& other) noexcept {
    //std::cout << "  -> move CSTR called" << std::endl;
    currentNumElements = other.currentNumElements;
    currentSizeInMemory = other.currentSizeInMemory;
    firstElement = other.firstElement;
    other.firstElement = nullptr; // ez fontos!!
}

IntVector& IntVector::operator=(IntVector&& other) noexcept {
    //std::cout << "  -> move ASSGN called" << std::endl;
    if (this == &other) { return *this; }
    delete[] firstElement;

    currentNumElements = other.currentNumElements;
    currentSizeInMemory = other.currentSizeInMemory;
    firstElement = other.firstElement;
    other.firstElement = nullptr; // ez fontos!!

    return *this;
}

IntVector& IntVector::addElement(int elem) {
    if (currentNumElements == currentSizeInMemory) {
        // uj mem.teruletet is le kell foglalnunk...
        //std::cout << "  -> adding " << currentNumElements + 1 << "-th ";
        //std::cout << "element... allocating new memory" << std::endl;
        int* newAddress = new int[currentSizeInMemory + 10];
        for (int inx = 0; inx < currentNumElements; inx++) {
            *(newAddress + inx) = *(firstElement + inx);
        }
        delete[] firstElement;
        firstElement = newAddress;
        currentSizeInMemory += 10;
    }
    *(firstElement + currentNumElements) = elem;
    currentNumElements++;
    return *this;
}

void IntVector::print() {
    if (currentNumElements > 0) {
        std::cout << *firstElement;
        for (int inx = 1; inx < currentNumElements; inx++) {
            std::cout << ", " << *(firstElement + inx);
        }
        std::cout << std::endl;
    }
}
