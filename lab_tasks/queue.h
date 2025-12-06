#ifndef QUEUE_H
#define QUEUE_H

#include <cstdint>
#include <stdexcept>
#include "stack.h"

template <typename T>
class Queue {
private:
    Stack<T> stackIn;
    Stack<T> stackOut;

public:
    explicit Queue(std::int64_t maxSize = 1000);

    void enqueue(const T& x);
    T dequeue();
    bool isEmpty() const;
    std::int64_t size() const;
};

#include "queue.cc"

#endif