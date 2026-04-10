//
// Created by daisy on 4/6/2026.
//

#include "TodoList.hpp"

#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;


TodoList::TodoList() = default;

void TodoList::add(const string& item) {
  if (item.empty()) {
    cout << "invalid - Empty input" << endl;
    return;
  }
  if (any_of(incompleteList.begin(), incompleteList.end(), [item](const string& s) { return item == s; })) {
    cout << "invalid - no duplicate todos" << endl;
    return;
  }
  incompleteList.push_back(item);
}

void TodoList::complete(const string& item) {
  for (auto it = incompleteList.begin(); it != incompleteList.end(); ++it) {
    if (*it == item) {
      incompleteList.erase(it);
      completeList.push_back(item);
      return;
    }
  }
  cout << "Sorry looks like that isn't in the incomplete list" << endl;
}

string TodoList::complete() {
  string ret = "Complete: ";
  // cout << "Complete: ";
  for (auto it = completeList.begin(); it != completeList.end(); ++it) {
    if (it != completeList.begin() && completeList.size() > 2 && (it ) != completeList.end()) {
      ret += ", ";
    }
    if (it-1 == completeList.begin() && it + 1  == completeList.end()) {
      ret += " and ";
    } else if (it != completeList.begin() && it + 1  == completeList.end()) {
      ret += "and ";
    }

    ret += *it;
  }
  ret += "\n";
  cout << ret;
  return ret;
}

string TodoList::incomplete() {
  string ret = "Incomplete: ";
  // cout << "Incomplete: ";
  for (auto it = incompleteList.begin(); it != incompleteList.end(); ++it) {
    if (it != incompleteList.begin() && incompleteList.size() >2 && (it) != incompleteList.end()) {
      ret += ", ";
      // cout << ", ";
    }
    if (it-1 == incompleteList.begin() && it + 1  == incompleteList.end()) {
      ret += " and ";
    } else if (it != incompleteList.begin() && it + 1  == incompleteList.end()) {
      ret += "and ";
    }
    ret += *it;
  }
  ret += "\n";
  cout << ret;
  return ret;
}

string TodoList::all() {
  cout << "All:" << endl;
  cout << "  ";
  string ret = "All: \n  ";
  ret += incomplete();
  cout << "  ";
  ret += "  " + complete();
  return ret;
}

void TodoList::clear() {
  for (auto it = incompleteList.end(); it != incompleteList.begin(); --it) {
    incompleteList.pop_back();
  }
  for (auto it = completeList.end(); it != completeList.begin(); --it) {
    completeList.pop_back();
  }
}