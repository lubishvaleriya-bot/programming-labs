#pragma once
#include <vector>
#include "point.h"

class myvector {
private:
    std::vector<point> data;

public:
    myvector();
    void insert(int k, point value);
    void remove(int k);
    point get(int k);
    void set(int k, point value);
    int length();
};

   