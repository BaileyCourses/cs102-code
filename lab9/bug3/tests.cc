#include "catch.hpp"
#include <sstream>
#include "List.h"

using namespace std;

TEST_CASE("Appending any number of times maintains correct length", "[testC]") {
  List list;

  for (size_t i = 0; i < 10; i++) {
    CAPTURE(list, list.length());
    REQUIRE(list.length() == i);
    list.append(i);
  }
  list.pop();
  REQUIRE(list.index(8) == 8);
}

