#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

// Stack class to implement a LIFO (last-in first-out) structure

  class Stack {
  public:

    // The type of element stored in the Stack

    typedef size_t Item;

    // The type of Node used to link Stack elements together. This is a utility
    // class so everything is public (except copy and assignment operators

    class Node {
    public:

      // The constructor.
      // PRE:  None
      // POST: A node is propoerly constructed with next pointer initialized
      Node(const Item& value, Node* next = NULL);
      Item _value;
      Node* _next;
    private:
      Node(const Node& node);
      Node& operator = (const Node& node);
    };

    // The constructor.
    // PRE:  None
    // POST: A stack is properly constructed.
    Stack();

    // The copy constructor
    // PRE:  None
    // POST: A stack is properly constructed with copies of elements from other
    Stack(const Stack& other);

    // The destructor.
    // PRE:  None
    // POST: All memory associated with the stack is returned to the heap
    ~Stack();

    // The assignment operator
    // PRE:  None
    // POST: All memory associated with the old stack contents is returned
    //       to the heap. The other stack's contents is copied to this
    //       stack
    Stack& operator = (const Stack& other);
  
    // push - a value is pushed onto the top of the stack
    // PRE:  None
    // POST: A call to top() will return this element
    void push(const Item& item);

    // pop - the top value is popped off the stack and discarded
    // PRE:  the stack is not empty
    // POST: the top element of the stack has been removed
    void pop();

    // top - get top element of stack
    // PRE:  the stack is not empty
    // POST: the top element of the stack is returned
    Item top() const;

    // empty - determines if the stack contains no elements
    // PRE:  None
    // POST: true is returned if the stack has no elments, false otherwise.
    bool empty() const;

    // display - a string representation of the stack is sent to the stream
    // PRE:  None
    // POST: a string representing the stack is sent to the stream. 
    //       Empty stacks display as:
    //       <empty stack>
    //       None empty stacks display as:
    //       10 <------Top
    //       5
    //       3
    //       <bottom>

    void print(std::ostream& stream) const;

  private:
    void copy(const Stack& other);
    void destroy();
    Node* _top;
  };

  // output operator - a string representation of the stack is sent to the
  //                   stream
  // PRE:  None
  // POST: a string representing the stack is sent to the stream. 
  std::ostream& operator << (std::ostream& stream, const Stack& stack);

#include "Stack.cc"

#endif
