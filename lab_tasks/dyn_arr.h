#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <stdexcept>
#include <cstdint>
// size_t == unsigned long long

class DynamicArray {
private:
  float* data;
  std::int64_t size = -1; // actual (last occupied)
  std::int64_t capacity; // max


public:
  DynamicArray(); // default ctor
  DynamicArray(std::int64_t capacity); // parametrized ctor
  DynamicArray(DynamicArray& other);
  ~DynamicArray(); // destructor

  void push_back(float x);
  float add(std::int64_t idx1, std::int64_t idx2);
  float max();
  float min();
  void clear(); // deallocate the data
  void reinitialize(); // restore to default
  void printData();

  float operator[](std::int64_t idx) const;
  float operator()();

  bool isEmpty() const{
    return size == -1;
  }

  std::int64_t getSize() const{
    return size + 1;
  }

  void pop_back(){
    if (isEmpty()){
      throw std::out_of_range("pop_back DynamicArray");
    }
    --size;
  }


  void push_front(float val);
  float front();
  float back();
  void insert(std::int64_t idx, float val);
  void delete_idx(std::int64_t idx);
  void erase_after(std::int64_t idx);
  void increase_capacity(std::int64_t newCapacity);
  void decrease_capacity(std::int64_t newCapacity);
};

#endif // DYN_ARR_H
