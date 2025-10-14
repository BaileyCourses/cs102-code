#include <cassert>
#include "List.h"

using namespace std;

List::Node::Node(const Item& value, Node* prev, Node* next) {
  _value = value;
  _prev = prev;
  _next = next;
}

List::List() {
  _head = nullptr;
  _tail = nullptr;
  _current = nullptr;
  _length = 0;
}

