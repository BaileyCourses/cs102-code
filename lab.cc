#include <iostream>

#include "Widget.h"

using namespace std;

void showem(const Widget& widgetA, Widget widgetB) {
  cout << widgetA;
  cout << widgetB;
}

int main() {
  Widget w1;
  Widget w2;
  Widget w3 = w2;

  cout << w1 << endl;
  cout << w2 << endl;
  w1.connect(w2);

  showem(w1, w2);

  w3 = w1;
}
