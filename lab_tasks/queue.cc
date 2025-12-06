template <typename T>
Queue<T>::Queue(std::int64_t maxSize)
    : stackIn(maxSize), stackOut(maxSize) {}

template <typename T>
void Queue<T>::enqueue(const T& x) {
    stackIn.push(x);
}

template <typename T>
T Queue<T>::dequeue() {
    if (stackOut.isEmpty()) {
        while (!stackIn.isEmpty()) {
            stackOut.push(stackIn.pop());
        }
    }
    if (stackOut.isEmpty()) {
        throw std::out_of_range("queue is empty");
    }
    return stackOut.pop();
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return stackIn.isEmpty() && stackOut.isEmpty();
}

template <typename T>
std::int64_t Queue<T>::size() const {
    return stackIn.size() + stackOut.size();
}