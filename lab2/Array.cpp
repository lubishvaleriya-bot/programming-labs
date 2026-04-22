#include <iostream>
#include "Array.h"

using namespace std;

Array::Array() {
    size = 0;
}

void Array::insert(int k, point value) {
    if (size >= A || k < 0 || k > size) {
        cout << "Помилка: індекс виходить за межі або масив заповнений.\n";
        return;
    }
    for (int i = size; i > k; --i) {
        data[i] = data[i - 1];
    }
    data[k] = value;
    ++size;
}

void Array::remove(int k) {
    if (k < 0 || k >= size) {
        cout << "Помилка: індекс виходить за межі.\n";
        return;
    }
    for (int i = k; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

point Array::get(int k) {
    if (k < 0 || k >= size) {
        cout << "Помилка: індекс виходить за межі.\n";
        return {0, 0, 0};
    }
    return data[k];
}

void Array::set(int k, point value) {
    if (k < 0 || k >= size) {
        cout << "Помилка: індекс виходить за межі.\n";
        return;
    }
    data[k] = value;
}

int Array::length() {
    return size;
}