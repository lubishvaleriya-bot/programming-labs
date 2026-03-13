#include "interactive.h"
#include "myvector.h"
#include <iostream>

void runinteractive() {
    myvector list;
    int cmd;

    while (true) {
        std::cout << "\n1 insert\n2 remove\n3 get\n4 set\n5 length\n0 exit\n";
        std::cin >> cmd;

        if (cmd == 0) break;

        if (cmd == 1) {
            point p; int i;
            std::cin >> i >> p.x >> p.y >> p.z;
            list.insert(i, p);
        }
        else if (cmd == 2) {
            int i; std::cin >> i;
            list.remove(i);
        }
        else if (cmd == 3) {
            int i; std::cin >> i;
            point p = list.get(i);
            std::cout << p.x << " " << p.y << " " << p.z << "\n";
        }
        else if (cmd == 4) {
            point p; int i;
            std::cin >> i >> p.x >> p.y >> p.z;
            list.set(i, p);
        }
        else if (cmd == 5) {
            std::cout << list.length() << "\n";
        }
    }
}