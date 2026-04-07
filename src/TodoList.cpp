//
// Created by daisy on 4/6/2026.
//

#include "TodoList.hpp"

#include <iostream>
#include <ostream>
using namespace std;


TodoList::TodoList() = default;

void TodoList::add(const string& item) {
  if (item.empty()) return;
  incompleteList.push_back(item);
}

void TodoList::complete(const string& item) {
  for (auto it = incompleteList.begin(); it != incompleteList.end(); ++it) {
    if (*it == item) {
      incompleteList.erase(it);
      completeList.push_back(item);
    }
  }
}

void TodoList::complete() {
  cout << "Complete: ";
  for (auto it = completeList.begin(); it != completeList.end(); ++it) {
    if (it != completeList.begin()) {
      cout << ", ";
    }
    if (it + 1  == completeList.end() && it != completeList.begin()) {
      cout << "and ";
    }
    cout << *it;

  }
  cout << endl;
}

void TodoList::incomplete() {
  cout << "Incomplete: ";
  for (auto it = incompleteList.begin(); it != incompleteList.end(); ++it) {
    if (it != incompleteList.begin()) {
      cout << ", ";
    }
    if (it + 1  == incompleteList.end()) {
      cout << "and ";
    }
    cout << *it;
  }
  cout << endl;
}

void TodoList::all() {
  cout << "All: " << endl;
  cout << " ";
  incomplete();
  cout << " ";
  complete();
}

void TodoList::clear() {
  for (auto it = incompleteList.end(); it != incompleteList.begin(); --it) {
    incompleteList.pop_back();
  }
  for (auto it = completeList.end(); it != completeList.begin(); --it) {
    completeList.pop_back();
  }
}