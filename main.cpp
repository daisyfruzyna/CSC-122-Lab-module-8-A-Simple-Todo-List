#include <iostream>

#include "src/hello.hpp"
#include "src/TodoList.hpp"
void test();

int main() {
  TodoList list;
  string inputStr;
  const string errorMessage = "That is not a valid entry";
  do {
    int inputInt = -1;
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1 - Add an item to your todo list" << endl;
    cout << "2 - Move an item to your complete list" << endl;
    cout << "3 - Display your incomplete" << endl;
    cout << "4 - Display your complete" << endl;
    cout << "5 - Display all" << endl;
    cout << "6 - Clear your lists" << endl;
    cout << "7 - Test" << endl;
    cout << "8 - Exit the program" << endl;
    getline(cin, inputStr);

    //check input
    if (inputStr.empty()) {
      cout << errorMessage << endl;
      continue;
    }
    if (!isdigit(inputStr[0])) {
      cout << "selection must be a number" << endl;
      continue;
    }
    if (inputStr.length() > 1) {
      cout << "selection to large" << endl;
      continue;
    }

    inputInt = stoi(inputStr);
    if (inputInt == 8) {break;}
    switch (inputInt) {
      case 1:
        cout << "What would you like to add to your todo list?" << endl;
        getline(cin, inputStr);
        list.add(inputStr);
        break;
      case 2:
        cout << "What would you like to move to your complete list?" << endl;
        getline(cin, inputStr);
        list.complete(inputStr);
        break;
      case 3:
        list.incomplete();
        break;
      case 4:
        list.complete();
        break;
      case 5:
        list.all();
        break;
      case 6:
        list.clear();
        break;
      case 7:
        test();
        break;
      default:
        cout << "selection must be between 1-7" << endl;
        break;
    }




  } while (true);

}


//function so it can be separate from the code
void test() {
  TodoList list;
  list.add("");
  list.add("Buy milk");
  list.add("Buy chalk");
  list.add("Buy eggs");
  list.add("Prepare a lesson for CSC 122");
  list.add("Sow beet seeds");

  list.complete("Buy eggs");

  // Pretty prints a list of each of the four tasks above
  list.all();

  list.complete("Buy chalk");
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