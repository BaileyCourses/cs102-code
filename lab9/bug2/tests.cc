#include "catch.hpp"
#include <sstream>
#include "List.h"

using namespace std;

TEST_CASE("Lists start empty", "[testA]") {
  List list;

  CAPTURE(list);
  REQUIRE(list.length() == 0);
}

