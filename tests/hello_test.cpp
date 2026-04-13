#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"
#include "../src/TodoList.hpp"
#include "catch2/internal/catch_list.hpp"

TEST_CASE("it returns Hello World") {
    REQUIRE( hello() == "Hello World!" );
}


TEST_CASE( "add" ) {
    TodoList list;
    REQUIRE( list.incomplete() == "Incomplete: \n" );
    list.add("a");
    REQUIRE( list.incomplete() == "Incomplete: a\n" );
}
TEST_CASE( "complete" ) {
    TodoList list;
    REQUIRE( list.complete() == "Complete: \n" );
    list.complete("a");
    REQUIRE( list.complete() == "Complete: \n" );
    list.add("a");
    list.complete("a");
    REQUIRE( list.incomplete() == "Incomplete: \n" );
    REQUIRE( list.complete() == "Complete: a\n" );
}
TEST_CASE( "clear" ) {
    TodoList list;
    list.add("a");
    list.add("1");
    list.complete("1");
    REQUIRE( list.all() == "All: \n  Incomplete: a\n  Complete: 1\n" );
    list.clear();
    REQUIRE( list.all() == "All: \n  Incomplete: \n  Complete: \n" );
    list.clear();
    REQUIRE( list.all() == "All: \n  Incomplete: \n  Complete: \n" );
}


TEST_CASE(" \"and\" and \",\" " ) {
    TodoList list;
    list.add("a");
    REQUIRE( list.incomplete() == "Incomplete: a\n" );
    list.add("b");
    REQUIRE( list.incomplete() == "Incomplete: a and b\n" );
    list.add("c");
    REQUIRE( list.incomplete() == "Incomplete: a, b, and c\n" );
    list.add("1");
    list.complete("1");
    REQUIRE( list.complete() == "Complete: 1\n" );
    list.add("2");
    list.complete("2");
    REQUIRE( list.complete() == "Complete: 1 and 2\n" );
    list.add("3");
    list.complete("3");
    REQUIRE( list.complete() == "Complete: 1, 2, and 3\n" );
    REQUIRE( list.all() == "All: \n  Incomplete: a, b, and c\n  Complete: 1, 2, and 3\n" );
}

TEST_CASE( "blank input" ) {
    TodoList list;
    list.add("");
    list.add("");
    REQUIRE( list.incomplete() == "Incomplete: \n" );
}
TEST_CASE( "duplicates" ) {
    TodoList list;
    list.add("a");
    REQUIRE( list.incomplete() == "Incomplete: a\n" );
    list.add("a");
    REQUIRE( list.incomplete() == "Incomplete: a\n" );

    list.complete("a");
    list.add("a");
    REQUIRE( list.all() == "All: \n  Incomplete: a\n  Complete: a\n" );
    list.complete("a");
    REQUIRE( list.complete() == "Complete: a and a\n" );
}