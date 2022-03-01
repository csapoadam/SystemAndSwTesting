#pragma once

class IntVector {
    int currentNumElements; // hany elemet adott hozza a user
    int currentSizeInMemory; // mekkora mem.terulet van lefoglalva
    int* firstElement;
public:
    IntVector() : currentNumElements(0), currentSizeInMemory(10) {
        firstElement = new int[currentSizeInMemory];
    }
    virtual ~IntVector() {
        delete[] firstElement;
    }
    IntVector(const IntVector& other);
    IntVector& operator=(const IntVector& other);

    // move constructor and assignment:
    IntVector(IntVector&& other) noexcept;
    IntVector& operator=(IntVector&& other) noexcept;

    int getSize() const { return currentNumElements; }

    int operator[](int inx) const { return *(firstElement + inx); }

    IntVector& addElement(int elem);
    virtual void print();
};
