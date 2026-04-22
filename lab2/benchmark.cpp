#include "benchmark.h"
#include "Array.h"
#include "myvector.h"
#include "cycliclist.h"
#include <iostream>
#include <chrono>

using namespace std;

void runbenchmark() {
    cout << "Benchmark mode\n";
    const int N = 10000;

    Array a;
    myvector v;
    cycliclist c;

    auto test = [&](auto& list, const std::string& name) {
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < N; i++)
            list.insert(i, {1, 2, 3});

        auto end = std::chrono::high_resolution_clock::now();

        std::cout << name << ": "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    };

    // Array не може вмістити 10000 елементів (його розмір 100). 
    // Тому він швидко видасть помилку заповнення, але програма не впаде.
    test(a, "Array"); 
    test(v, "myvector");
    test(c, "cycliclist");
}