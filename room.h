#ifndef ROOM_H
#define ROOM_H
#include "items.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class room {
 public:
  //variables and methods
  room(char* roomName);
  char* getRoom();
  char* getRoomName();
  void setItems(vector<items*>* newItems);
  void setExits(map<char*, room*>* newExits);
  void getItems();
  bool checkItem(char item[]);
  items* giveItem(char item[]);
  void getExits();
  map<char*, room*>* returnExits();
  void addItem(items* newItem);

 private:
  char* roomName;
  vector <items*>* roomItems;
  map<char*, room*>* exits;
};
#endif
