#include "demonstration.h"
#include "Array.h"
#include "myvector.h"
#include "cycliclist.h"
#include <iostream>

void rundemonstration() {
    std::cout << "Demonstration start\n";

    Array a;
    myvector v;
    cycliclist c;

    a.insert(0, {1,1,1});
    v.insert(0, {2,2,2});
    c.insert(0, {3,3,3});

    std::cout << "Array length: " << a.length() << "\n";
    std::cout << "myvector length: " << v.length() << "\n";
    std::cout << "cycliclist length: " << c.length() << "\n";

    std::cout << "Demonstration end\n";
}