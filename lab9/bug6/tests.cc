#include "catch.hpp"
#include <sstream>
#include "List.h"
#include "cs102List.h"

using namespace std;

TEST_CASE("Lists start empty", "[testA]") {
  List list;

  CAPTURE(list);
  REQUIRE(list.length() == 0);
}

TEST_CASE("Appending to an empty list creates a list of length 1", "[testB]") {
  List list;

  list.append(10);
  CAPTURE(list, list.length());
  REQUIRE(list.length() == 1);
}

TEST_CASE("Appending any number of times maintains correct length", "[testC]") {
  List list;

  for (size_t i = 0; i < 10; i++) {
    CAPTURE(list, list.length());
    REQUIRE(list.length() == i);
    list.append(i);
  }
}

TEST_CASE("Popping elements maintains correct length", "[testD]") {
  List list;

  for (size_t i = 0; i < 10; i++) {
    REQUIRE(list.length() == i);
    list.append(i);
  }

  for (size_t i = 10; i > 0; i--) {
    CAPTURE(list, list.length());
    REQUIRE(list.length() == i);
    list.pop(0);
  }

  CAPTURE(list, list.length());
  REQUIRE(list.length() == 0);
}

TEST_CASE("Pop removes the last element", "[testE]") {
  List list;

  for (size_t i = 0; i < 10; i++) {
    CAPTURE(list, list.length());
    REQUIRE(list.length() == i);
    list.append(i);
  }

  for (size_t i = 10; i > 0; i--) {
    CAPTURE(list, list.length());
    REQUIRE(list.length() == i);
    list.pop();
  }

  CAPTURE(list, list.length());
  REQUIRE(list.length() == 0);
}

TEST_CASE("Remove removes items from a list", "[testF]") {
  List list;

  for (size_t i = 0; i < 10; i++) {
    CAPTURE(list, list.length());
    REQUIRE(list.length() == i);
    list.append(i + 10);
  }

  for (size_t i = 0; i < 10; i++) {
    CAPTURE(list, list.length());
    REQUIRE(list.length() == 10 - i);
    list.remove(i + 10);
  }
}  

TEST_CASE("Index returns index for each value", "[testG]") {
  List list;

  for (size_t i = 0; i < 10; i++)
    list.append(i + 10);

  for (size_t i = 0; i < 10; i++) {
    CAPTURE(list, list.length());
    REQUIRE(list.index(i + 10) == i);
  }
}

TEST_CASE("Operator [] returns correct value for each index", "[testH]") {
  List list;
  
  for (size_t i = 0; i < 10; i++)
    list.append(i + 10);

  const List clist = list;
  for (int i = 0; i < 10; i++) {
    CAPTURE(clist, clist.length());
    REQUIRE(clist[i] == i + 10);
  }

}

// Need something for the const version. How?

TEST_CASE("A list can be constructed from another list", "[testI]") {
  List listA;

  for (size_t i = 0; i < 10; i++)
    listA.append(i + 10);

  List listB = listA;

  for (int i = 0; i < 10; i++) {
    CAPTURE(listA, listA.length(), listB, listB.length());
    REQUIRE(listA[i] == listB[i]);
  }
}  

TEST_CASE("A list can be assigned to another list", "[testJ]") {
  List listA;
  List listB;

  for (size_t i = 0; i < 10; i++)
    listA.append(i + 10);

  listB = listA;

  for (int i = 0; i < 10; i++) {
    CAPTURE(listA, listA.length(), listB, listB.length());
    REQUIRE(listA[i] == listB[i]);
  }
}  

TEST_CASE("A list can be gracefully destroyed", "[testK]") {
  List* listA = new List();

  for (size_t i = 0; i < 10; i++)
    listA->append(i + 10);

  delete listA;
}  

TEST_CASE("Two lists can be concatinated together", "[testL]") {
  List listA;
  List listB;
  List listC;

  for (size_t i = 0; i < 10; i++)
    listA.append(i + 10);

  for (size_t i = 0; i < 10; i++)
    listB.append(i + 20);

  listC = listA + listB;

  for (int i = 0; i < 10; i++) {
    CAPTURE(listA, listA.length(), listB, listB.length(), listC, listC.length());
    REQUIRE(listC[i] == listA[i]);
    REQUIRE(listC[i + 10] == listB[i]);
  }
}  

TEST_CASE("Output operator and print create correct string representations", "[testM]") {
  List listA;
  cs102::List listB;

  for (size_t i = 0; i < 10; i++) {
    stringstream A;
    stringstream B;
    listA.append(i + 10);
    listB.append(i + 10);

    CAPTURE(i, i + 10, listA, listB);
    REQUIRE(A.str() == B.str());
  }
}

#include <chrono>
TEST_CASE("Indexing should be fast", "[testN]") {
  {

    List* list = new List;
    
    cerr << "Creating a big list" << endl;
    for (size_t i = 0; i < 1000000; i++) {
      list->append(i + 10);
    }  
    cerr << "Done" << endl;
    
    cerr << "Indexing a big list" << endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++) {
      //      cerr << "Attempting to access item " << list->length() << endl;
      (*list)[list->length()];
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    cerr << "Done" << endl;
    cerr << "Destroying a big list..." << endl;
  }

  cerr << "Done" << endl;
  REQUIRE(false);
}
