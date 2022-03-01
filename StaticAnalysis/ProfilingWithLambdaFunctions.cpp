// ProfilingWithLambdaFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <chrono>
#include <vector>
#include <array>
#include <string>
#include <utility>

#include "IntVector.h"
#include "IntVectorUtils.h"


class ProfilerClass {
    int numTimesToRun;
public:
    explicit ProfilerClass(int nttr) : numTimesToRun{ nttr } {}

    template <typename Function>
    void profile(Function f, const std::string& name) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numTimesToRun; i++) {
            f();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Stats for " << name << ": ";
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << std::endl;
    }
};

void helper() {
    IntVector vec;
    vec.addElement(5).addElement(6).addElement(7);
    vec.addElement(8).addElement(9).addElement(10);
    vec.addElement(11).addElement(12).addElement(13);
    vec.addElement(14).addElement(15).addElement(16);

    IntVector vec2;
    vec2.addElement(99).addElement(100);

    ProfilerClass profiler{ 100000 };
    profiler.profile([&vec, &vec2]() { swapIntVecsWithCopy(vec, vec2); }, "swapWithCopy");
    profiler.profile([&vec, &vec2]() { swapIntVecsWithMove(vec, vec2); }, "swapWithMove");
}


int main() {
    helper();
    _CrtDumpMemoryLeaks();
}



