#include "catch.hpp"
#include "List.h"

using namespace std;

TEST_CASE("Lists start empty", "[testA]") {
  List list;

  REQUIRE(list.length() != 0);
}
