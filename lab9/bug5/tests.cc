#include "catch.hpp"
#include <sstream>
#include "List.h"

using namespace std;

TEST_CASE("Appending to an empty list creates a list of length 1", "[testB]") {
  List list;

  list.append(10);
  CAPTURE(list, list.length());
  REQUIRE(list.length() == 1);
}
