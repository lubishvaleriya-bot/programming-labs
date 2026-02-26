#pragma once
#include "point.h"

class Array {
private:
    static const int A = 100;
    point data[A];
    int size;

public:
    Array(); 
    void insert(int k, point value);
    void remove(int k);
    point get(int k);
    void set(int k, point value);
    int length();
};