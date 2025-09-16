#include <iostream>
#include <cassert>
#include "SafeArray.h"

using namespace std;

SafeArray::SafeArray(size_t capacity, int default_value) {
  _capacity = capacity;
  
  _protectedArray = new int[_capacity];
  for (size_t i = 0; i < _capacity; i++) {
    put(i, default_value);
  }
}

int SafeArray::get(size_t index) const {
  assert(index <= _capacity);
  return _protectedArray[index];
}

void SafeArray::put(size_t index, int value) {
  assert(index <= _capacity);
  _protectedArray[index] = value;
}

void SafeArray::print() const {
  for (size_t i = 0; i < _capacity; i++) {
    cout << get(i) << endl;
  }
}

void SafeArray::input() {
  for (size_t i = 0; i < _capacity; i++) {
    int value;
    cin >> value;
    if (value == 0) 
      break;
    put(i, value);
  }
}

void SafeArray::copy(SafeArray other) {
  _capacity = other._capacity;
  
  _protectedArray = new int[_capacity];
  for (size_t i = 0; i < _capacity; i++) {
    put(i, get(i));
  }
}
