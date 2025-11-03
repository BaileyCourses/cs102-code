#if !defined(LIST_H)
#define LIST_H
#include <iostream>

class List {
 public:
  typedef int Item;
  class Node {
  public:
    Node(const Item& value, Node* previous = nullptr, Node* next = nullptr);
    Item _value;
    Node* _previous;
    Node* _next;
  private:
    Node(const Node& node);
    Node& operator = (const Node& node);
  };

  // Constructor - A list is properly constructed
  //              
  // PRE:  None
  // POST: The list is constructed and all instance variables are initialized
  List();

  // Copy constructor - initializes this list by copying the other list
  //              
  // PRE:  None
  // POST: This list and other contain the same values and have the same length
  List(const List& other);

  // Destructor - cleans up a list upon deletion
  //              
  // PRE:  None
  // POST: The list and all associate memory is returned to the heap
  ~List();

  // Assignment - copies the other list over this list destroying the old
  //              contents of the current list
  // PRE:  None
  // POST: Both lists contain the same values and have the same length
  List& operator = (const List& other);

  // length - returns the number of elements in the list
  // PRE:  None
  // POST: The length of the list is returned
  size_t length() const;

  // append - add an item to the end of the list
  // PRE:  None
  // POST: An item is successfully added to the end of the list
  void append(const Item& value);

  // pop - removes the last item in the list
  // PRE:  length() > 0
  // POST: The item is removed from the end of the list and the length is
  //       reduced by 1.
  void pop();

  // pop - removes the item at the given position in in the list. The first
  //       position in the list is 0.
  // PRE:  length() > 0
  // POST: The item is removed from position index. An item at position
  //       index + 1 now has position index. The length is reduced by 1.
  //       reduced by 1.
  void pop(size_t index);

  // index - Return a zero-based index of the first occurrence of item in
  //         the list.
  // PRE:  The item is in the list
  // POST: The index of the item is returned
  size_t index(const Item& item) const;

  // remove - Remove the first item from the list whose value is equal to item
  // PRE:  The item is in the list
  // POST: The the is removed from the list
  void remove(const Item& item);

  // operator [] - Return the item at position idx
  // PRE:  idx < length()
  // POST: The item at position idx is returned
  Item operator [] (size_t idx) const;

  // operator [] - Return the item at position idx
  // PRE:  idx < length()
  // POST: A reference to the item at position idx is returned
  Item& operator [] (size_t idx);

  List operator + (const List& other) const;

  // print - a string representation of the list is inserted into the stream
  // PRE:  None
  // POST: the stream contains a string representation of the list
  void print(std::ostream& stream) const;

 private:  
  void copy(const List& other);
  void destroy();
  bool in(const Item& item) const;
  size_t indexOf(const Item& item) const;
  Node* getIndex(size_t idx);

  Node* _head;
  Node* _tail;
  Node* _lastIndexedNode;
  size_t _lastIndexUsed;
  size_t _length;
};

std::ostream& operator << (std::ostream& stream, const List& list);
#endif
