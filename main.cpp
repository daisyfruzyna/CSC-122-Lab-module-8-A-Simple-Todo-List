#include <iostream>

#include "src/hello.hpp"
#include "src/TodoList.hpp"

int main() {
  TodoList list;

  list.add("");
  list.add("Buy milk");
  list.add("Buy eggs");
  list.add("Prepare a lesson for CSC 122");
  list.add("Sow beet seeds");

  list.complete("Buy eggs");

   // Pretty prints a list of each of the four tasks above
   list.all();

  // Pretty prints the task "Buy eggs"
  list.complete();

  // Pretty prints the tasks "Buy milk",
  // "Prepare a lesson for CSC 122", and "Sow beet seeds"
  list.incomplete();

  // Clears the to-do list
  list.clear();
  // Pretty prints a message saying that the list is empty
  list.all();
}
