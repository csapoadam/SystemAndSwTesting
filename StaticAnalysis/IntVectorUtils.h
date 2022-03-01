#pragma once

void swapIntVecsWithCopy(IntVector& a, IntVector& b) {
    IntVector temp{ b };
    b = a;
    a = temp;
}

void swapIntVecsWithMove(IntVector& a, IntVector& b) {
    IntVector temp{ std::move(b) };
    b = std::move(a);
    a = std::move(temp);
}