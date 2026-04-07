//
// Created by daisy on 4/6/2026.
//
#include <string>
#include <vector>

#ifndef A_SIMPLE_TODO_LIST_TODOLIST_HPP
#define A_SIMPLE_TODO_LIST_TODOLIST_HPP

using namespace std;

class TodoList {
  vector<string> incompleteList;
  vector<string> completeList;

  public:
  TodoList();
  void add(const string& item);
  void complete(const string& item);
  void all();
  void complete();
  void incomplete();
  void clear();

};


#endif //A_SIMPLE_TODO_LIST_TODOLIST_HPP