#if !defined(QUEUE_H)
#define QUEUE_H

#include <string>

class Queue {
 public:
  typedef std::string item_t;
  Queue();
  void enqueue(const item_t value);
  void dequeue();
  item_t front() const;
  bool empty() const;
  size_t size() const;
  void print(std::ostream& stream) const;
 private:
  size_t _front;
  size_t _back;
  size_t _size;
  size_t _capacity;
  item_t* _values;
};

#endif
