#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <cstdint>
#include "dyn_arr.h" 

template <typename T>
class Stack {
private:
    DynamicArray data;
    std::int64_t maxSize;

public:
    explicit Stack(std::int64_t maxSize);

    void push(const T& x);
    T top() const;
    T pop();
    bool isEmpty() const;
    std::int64_t size() const;
};

#include "stack.cc"

#endif