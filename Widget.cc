#include "Widget.h"

using namespace std;

int Widget::_widgetCount = 0;

Widget::Widget() {
  _serial = _widgetCount++;
  _peer = nullptr;
}

/*
Widget::Widget(const Widget& other) {
}
*/

/*
Widget& Widget::operator = (const Widget& other) {
}
*/

/*
Widget::~Widget() {
}
*/

void Widget::copy(const Widget& other) {
}

void Widget::destroy() {
}

void Widget::connect(Widget& other) {
  _peer = &other;
}

void Widget::print(ostream& stream) const {
  stream << "I'm widget #" << _serial;

  if (_peer != nullptr) {
    stream << " (connected to #" << _peer->_serial << ")";
  }
  stream << endl;
}

ostream& operator << (ostream& stream, const Widget& widget) {
  widget.print(stream);
  return stream;
}

