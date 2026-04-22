#include "cycliclist.h"
#include <iostream>

using namespace std;

cycliclist::cycliclist() {
    head = nullptr;
    size = 0;
}

// Деструктор, щоб не було витоку пам'яті
cycliclist::~cycliclist() {
    if (size == 0) return;
    Node* cur = head;
    for (int i = 0; i < size; i++) {
        Node* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
}

int cycliclist::length() {
    return size;
}

void cycliclist::insert(int k, point value) {
    if (k < 0 || k > size) {
        cout << "Error: wrong index\n";
        return;
    }

    Node* newNode = new Node{value, nullptr};

    if (size == 0) {
        newNode->next = newNode;
        head = newNode;
    }
    else if (k == 0) {
        Node* last = head;
        for (int i = 0; i < size - 1; i++)
            last = last->next;

        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
    else {
        Node* prev = head;
        for (int i = 0; i < k - 1; i++)
            prev = prev->next;

        newNode->next = prev->next;
        prev->next = newNode;
    }
    size++;
}

void cycliclist::remove(int k) {
    if (size == 0 || k < 0 || k >= size) {
        cout << "Error: wrong index\n";
        return;
    }

    Node* toDelete;

    if (size == 1) {
        delete head;
        head = nullptr;
    }
    else if (k == 0) {
        Node* last = head;
        for (int i = 0; i < size - 1; i++)
            last = last->next;

        toDelete = head;
        head = head->next;
        last->next = head;
        delete toDelete;
    }
    else {
        Node* prev = head;
        for (int i = 0; i < k - 1; i++)
            prev = prev->next;

        toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
    }
    size--;
}

point cycliclist::get(int k) {
    if (k < 0 || k >= size) {
        cout << "Error: wrong index\n";
        return {0, 0, 0};
    }
    Node* cur = head;
    for (int i = 0; i < k; i++)
        cur = cur->next;

    return cur->data;
}

void cycliclist::set(int k, point value) {
    if (k < 0 || k >= size) {
        cout << "Error: wrong index\n";
        return;
    }
    Node* cur = head;
    for (int i = 0; i < k; i++)
        cur = cur->next;

    cur->data = value;
}