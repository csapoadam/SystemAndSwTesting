#pragma once

class IntVector {
    size_t currentNumElements; // hany elemet adott hozza a user
    size_t currentSizeInMemory; // mekkora mem.terulet van lefoglalva
    size_t* firstElement;
public:
    IntVector() : currentNumElements(0), currentSizeInMemory(10) {
        firstElement = new size_t[currentSizeInMemory];
    }
    virtual ~IntVector() {
        delete[] firstElement;
    }
    IntVector(const IntVector& other);
    IntVector& operator=(const IntVector& other);

    // move constructor and assignment:
    IntVector(IntVector&& other) noexcept;
    IntVector& operator=(IntVector&& other) noexcept;

    size_t getSize() const { return currentNumElements; }

    size_t operator[](size_t inx) const { return *(firstElement + inx); }

    IntVector& addElement(size_t elem);
    virtual void print();
};
