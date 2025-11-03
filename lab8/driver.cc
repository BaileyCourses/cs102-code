#include <iostream>
#include "List.h"

using namespace std;

int main() {
  List l;

  l.insert(1);
  l.insert(2);
  l.append(3);
  cout << l << endl;
}
