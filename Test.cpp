#include "catch.hpp"
#include "AList.h"
#include "DLList.h"
#include "Stack.h"
#include "Origin.h"

using namespace std;

TEST_CASE("DList class", "[DList]") {
    SECTION("Testing insertAtEnd function") {
        DLList<int> x;
        int y = 1;
        int z = 2;

        x.insertAtEnd(y);

        REQUIRE(x.getSize() == 1);

        x.insertAtEnd(z);

        //REQUIRE(x.isElement(2) == true);
        //REQUIRE(x.getHead() == 1);
        REQUIRE(x.getSize() == 2);

        x.insertAtEnd(z);
        REQUIRE(x.getSize() == 3);
        x.insertAtEnd(z);
        REQUIRE(x.getSize() == 4);
        x.insertAtEnd(z);
        REQUIRE(x.getSize() == 5);

    }

    SECTION("Testing insertAtFront function") {
        DLList<int> x;
        int y = 1;
        int z = 2;

        x.insertAtFront(y);
        REQUIRE(x.getSize() == 1);
        x.insertAtFront(z);

        //REQUIRE(x.getTail() == 1);
        //REQUIRE(x.getHead() == 2);
        REQUIRE(x.getSize() == 2);
        x.insertAtFront(y);
        REQUIRE(x.getSize() == 3);
        x.insertAtFront(y);
        REQUIRE(x.getSize() == 4);
        x.insertAtFront(y);
        REQUIRE(x.getSize() == 5);
    }

    SECTION("Testing isElement function") {
        DLList<int> x;
        int y = 1;
        int z = 2;
        int a = 4;
        int b = 5;
        int c = 3;

        x.insertAtFront(y);
        //puts y in the linked list

        REQUIRE(x.isElement(y) == true);
        REQUIRE(x.isElement(z) == false);
        REQUIRE(x.isElement(a) == false);
        REQUIRE(x.isElement(b) == false);
        REQUIRE(x.isElement(c) == false);
    }
}

TEST_CASE("MyStack class", "[MyStack]") {
    SECTION ("Testing push, peek, isEmpty and pop function") {
        Stack<int> x;
        int y = 1;
        int z = 2;
        int a = 3;
        int b = 4;
        int c = 5;

        //REQUIRE(x.peek() == "empty");

        x.push(y);
        REQUIRE(x.peek() == 1);
        x.push(z);
        //fills the stack with two elements

        REQUIRE(x.peek() == 2);
        x.push(a);
        REQUIRE(x.peek() == 3);
        x.pop();
        //REQUIRE(x.peek() == 2);
        x.pop();
        //REQUIRE(x.peek() == 1);
        REQUIRE(x.isEmpty() == false);
        x.pop();
        REQUIRE(x.isEmpty() == true);
    }

    SECTION("Testing doesContain function") {
        Stack<int> x;
        int y = 1;

        x.push(y);

        REQUIRE(x.doesContain(y) == true);
        REQUIRE(x.doesContain(3) == false);
    }
}
