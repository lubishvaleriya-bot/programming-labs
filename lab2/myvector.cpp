#include "myvector.h"

myvector::myvector() {
    data.clear();
}

void myvector::insert(int k, point value) {
    data.insert(data.begin() + k, value);
}

void myvector::remove(int k) {
    data.erase(data.begin() + k);
}

point myvector::get(int k) {
    return data[k];
}

void myvector::set(int k, point value) {
    data[k] = value;
}

int myvector::length() {
    return data.size();
}