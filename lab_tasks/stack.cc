template <typename T>
Stack<T>::Stack(std::int64_t maxSize)
    : data(), maxSize(maxSize) {}

template <typename T>
void Stack<T>::push(const T& x) {
    if (data.getSize() >= maxSize) {
        throw std::overflow_error("stack overflow");
    }
    data.push_back(static_cast<float>(x));
}

template <typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("stack is empty");
    }
    std::int64_t lastIndex = data.getSize() - 1;
    return static_cast<T>(data[lastIndex]);
}

template <typename T>
T Stack<T>::pop() {
    T value = top();
    data.pop_back();
    return value;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return data.isEmpty();
}

template <typename T>
std::int64_t Stack<T>::size() const {
    return data.getSize();
}