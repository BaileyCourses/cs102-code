#if !defined(ARRAY_H)
#define ARRAY_H

#include <cs102>

class SafeArray : cs102Object {
 public:
  SafeArray(size_t capacity, int default_value);
  int get(size_t index) const;
  void put(size_t index, int value);
  void print() const;
  void input();
  void copy(SafeArray other);
  
 private:
  size_t _capacity;
  int* _protectedArray;
};

#endif
