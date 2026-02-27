#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>

struct Message {
    std::string text;
    std::time_t timestamp;
};

class CyclicLog {
    std::vector<Message> buffer;
    size_t capacity;
    size_t start = 0;  // індекс найстарішого
    size_t count = 0; //реальних записів

public:
    CyclicLog(size_t N) : buffer(N), capacity(N) {}

    void add(const std::string& text) {
        size_t index = (start + count) % capacity;

        if (count == capacity) {  // журнал повний
            index = start;  // перезапис найстарішого
            start = (start + 1) % capacity;
        } else {
            count++;
        }

        buffer[index] = { text, std::time(nullptr) };
    }

    std::vector<Message> getLast(size_t K) const {
        if (K > count) K = count;

        std::vector<Message> result;
        for (size_t i = count - K; i < count; i++) {
            size_t index = (start + i) % capacity;
            result.push_back(buffer[index]);
        }
        return result;
    }
};