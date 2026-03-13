#include <iostream>
#include "interactive.h"
#include "demonstration.h"
#include "benchmark.h"

int main() {
    int mode;

    while (true) {
        std::cout << "\n1 Interactive\n2 Demo\n3 Benchmark\n0 Exit\n";
        std::cin >> mode;

        if (mode == 1) runinteractive();
        else if (mode == 2) rundemonstration();
        else if (mode == 3) runbenchmark();
        else if (mode == 0) break;
    }

    return 0;
}