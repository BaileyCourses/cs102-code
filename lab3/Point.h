#if !defined(POINT_H)
#define POINT_H

#include <cs102>

class Point : cs102Object {
 public:
  Point(int x, int y);
 private:
  int _x;
  int _y;
};

#endif
