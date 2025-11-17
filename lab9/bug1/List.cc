#include <cassert>
#include "List.h"

using namespace std;

typedef List::Node Node;
typedef List::Item Item;

const Node* atIndex(const Node* node, size_t index);
Node* atIndex(Node* node, size_t index);

List::Node::Node(const Item& value, Node* previous, Node* next) {
  _value = value;
  _previous = previous;
  _next = next;
}

List::List() {
  _head = nullptr;
  _tail = nullptr;
  _currentIndex = nullptr;
  _length = 0;
}

void List::copy(const List& other) {
  for (size_t i = 0; i < other.length(); i++) {
    const Node* p = atIndex(other._head, i);
    append(p->_value);
  }
}

List::List(const List& other) {
  _tail = _head = nullptr;
  _length = 0;
  copy(other);
}

void List::destroy() {
  while(length() > 0)
    pop();
}

List::~List() {
  destroy();
}

List& List::operator = (const List& other) {
  if (_head != other._head) {
    destroy();
    copy(other);
  }

  return *this;
}

size_t List::length() const {
  return _length;
}

void List::append(const Item& value) {
  if (!_head) {
    _head = _tail = new Node(value);
  }
  else {
    _tail->_next = new Node(value, _tail);
    _tail = _tail->_next;
  }
}

void List::pop() {
  pop(length() - 1);
}

void List::pop(size_t index) {
  assert(index < length());

  Node* garbage = atIndex(_head, index);

  if (garbage == _head)
    _head = garbage->_next;
  else
    garbage->_previous->_next = garbage->_next;

  if (garbage == _tail)
    _tail = garbage->_previous;
  else
    garbage->_next->_previous = garbage->_previous;

  garbage->_next = garbage->_previous = nullptr;
  delete garbage;
  _length--;
}

const Node* atIndex(const Node* node, size_t index) {
  const Node* p = node;

  for (size_t i = 0; i < index ; i++)
    p = p->_next;

  return p;
}

Node* atIndex(Node* node, size_t index) {
  Node* p = node;

  for (size_t i = 0; i < index ; i++)
    p = p->_next;

  return p;
}

size_t List::indexOf(const Item& item) const {
  Node* p = _head;

  for (size_t i = 0; i < length(); i++, p = p->_next)
    if (p->_value == item)
      return i;

  assert(!in(item));
  return 0;
}

size_t List::index(const Item& item) const {
  return indexOf(item);
}

void List::remove(const Item& item) {
  size_t index = indexOf(item);

  pop(index);
}

Item List::operator [] (size_t idx) const {
  return atIndex(_head, idx)->_value;
}

Item& List::operator [] (size_t idx) {
  return atIndex(_head, idx)->_value;
}

List List::operator + (const List& other) const {
  List result = *this;

  for (size_t i = 0; i < other.length(); i++) {
    Node* p = atIndex(other._head, i);

    result.append(p->_value);
  }
  return result;
}

bool List::in(const Item& item) const {
  Node* p = _head;

  for (size_t i = 0; i < length(); i++, p = p->_next)
    if (p->_value == item)
      return true;

  return false;
}

void List::print(std::ostream& stream) const {
  Node* p = _head;

  stream << "[";

  if (p) {
    stream << p->_value;
    p = p->_next;
  }

  for (; p; p = p->_next) {
    stream << ", ";
    stream << p->_value;
  }

  stream << "]";
}

ostream& operator << (ostream& stream, const List& list) {
  list.print(stream);
  return stream;
}
