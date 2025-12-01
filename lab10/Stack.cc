#include <cassert>

using namespace std;

typedef Stack::Node Node;

// The constructor.
// PRE:  None
// POST: A node is propoerly constructed with next pointer initialized
Node::Node(const Item& value, Node* next) : _value(value), _next(next) {
}

// The constructor.
// PRE:  None
// POST: A stack is properly constructed.
Stack::Stack() {
  _top = NULL;
}

// The copy constructor
// PRE:  None
// POST: A stack is properly constructed with copies of elements from other
Stack::Stack(const Stack& other) {
  copy(other);
}

// The destructor.
// PRE:  None
// POST: All memory associated with the stack is returned to the heap
Stack::~Stack() {
  //    destroy();
}

// The assignment operator
// PRE:  None
// POST: All memory associated with the old stack contents is returned
//       to the heap. The other stack's contents is copied to this
//       stack
Stack& Stack::operator = (const Stack& other) {
  if (this->_top != other._top) {
    destroy();
    copy(other);
  }
  return *this;
}
  
// push - a value is pushed onto the top of the stack
// PRE:  None
// POST: A call to top() will return this element
void Stack::push(const Item& item) {
  _top = new Node(item, _top);
}

// pop - the top value is popped off the stack and discarded
// PRE:  the stack is not empty
// POST: the top element of the stack has been removed
void Stack::pop() {
  assert(!empty());
  Node* garbage = _top;
  _top = _top->_next;
  delete garbage;
}

// top - get top element of stack
// PRE:  the stack is not empty
// POST: the top element of the stack is returned
Stack::Item Stack::top() const {
  assert(!empty());
  return _top->_value;
}

// empty - determines if the stack contains no elements
// PRE:  None
// POST: true is returned if the stack has no elments, false otherwise.
bool Stack::empty() const {
  return _top == NULL;
}

// print - a string representation of the stack is sent to the stream
// PRE:  None
// POST: a string representing the stack is sent to the stream. 
//       Empty stacks display as:
//       <empty stack>
//       None empty stacks display as:
//       10 <------Top
//       5
//       3
//       <bottom>
void Stack::print(std::ostream& stream) const {
  if (empty()) {
    stream << "<empty stack>" << endl;
    return;
  }

  stream << _top->_value << " <------Top" << endl;
  for(Node* p = _top->_next; p != NULL; p = p->_next) {
    stream << p->_value << endl;
  }
  stream << "<bottom>" << endl;
}

void Stack::copy(const Stack& other) {
  _top = nullptr;
  Node* prev = nullptr;
  for (Node* p = other._top; p; p = p->_next) {
    Node* node = new Node(p->_value);
    if (prev)
      node->_next = prev;
    else
      _top = node;
    prev = node;
  } 
}

void Stack::destroy() {
  while (!empty())
    pop();
}

// output operator - a string representation of the stack is sent to the
//                   stream
// PRE:  None
// POST: a string representing the stack is sent to the stream. 
ostream& operator << (ostream& stream, const Stack& stack) {
  stack.print(stream);
  return stream;
}
