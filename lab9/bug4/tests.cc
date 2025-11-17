#include "catch.hpp"
#include <sstream>
#include "List.h"

using namespace std;

TEST_CASE("Appending any number of times maintains correct length", "[testC]") {
  List listA;
  List listB;
  
  for (size_t i = 0; i < 10; i++) {
    CAPTURE(listA, listA.length());
    REQUIRE(listA.length() == i);
    listA.append(i);
  }
  listB.append(10);
  listA = listA;

  CAPTURE(listA, listB);
  REQUIRE(listA.length() == listB.length());
}

