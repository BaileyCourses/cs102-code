#if !defined(WIDGET_H)
#define WIDGET_H

#include <iostream>

class Widget {
 public:

  // The constructor.
  // PRE:  None
  // POST: A widget is properly constructed
  Widget();

  // The copy constructor
  // PRE:  None
  // POST: A Widget is properly constructed using another widget
//  Widget(const Widget& other);

  // The assignment operator
  // PRE:  None
  // POST: The current widget is destroyed. A copy of the other widget it made
//  Widget& operator = (const Widget& other);

  // The destructor
  // PRE:  None
  // POST: All memory associated with the widget is returned to the system
//  ~Widget();

  // Connect
  // PRE:  None
  // POST: The current Widget is connected to the other widget
  void connect(Widget& other);

  // Print
  // PRE:  None
  // POST: A string representation of the Widget is sent to the stream
  void print(std::ostream& stream) const;
 private:
  void copy(const Widget& other);
  void destroy();
  static int _widgetCount;
  int _serial;
  Widget* _peer;
};

std::ostream& operator << (std::ostream& stream, const Widget& widget);

#endif
