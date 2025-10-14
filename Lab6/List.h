#if !defined(LIST_H)
#define LIST_H
#include <iostream>

class List {
 public:
  typedef int Item;
  class Node {
  public:
    Node(const Item& value, Node* prev = nullptr, Node* next = nullptr);
    Item _value;
    Node* _next;
    Node* _prev;
  private:
    Node(const Node& node);
    Node& operator = (const Node& node);
  };
  List();

 private:  
  Node* _head;
  Node* _tail;
  Node* _current;
  size_t _length;
};

#endif
