#pragma once
#include "point.h"

class cycliclist {
private:
    struct Node {
        point data;
        Node* next;
    };

    Node* head;
    int size;

public:
    cycliclist();  // Конструктор
    ~cycliclist(); // Деструктор для очищення пам'яті
    void insert(int k, point value);
    void remove(int k);
    point get(int k);
    void set(int k, point value);
    int length();
};