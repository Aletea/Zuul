#include <iostream>
#include "room.h"
#include "items.h"
#include <map>
#include <cstring>
#include <vector>

using namespace std;

//variables
room::room (char roomTitle[]) {
  roomName = roomTitle;
  roomItems = NULL;
  exits = NULL;
}

//return room name
char* room::getRoom() {
  return roomName;
}

//assign items to incoming vector
void room::setItems(vector<items*>* newItems) {
  roomItems = newItems;
  
}

//same for exts: assign exits
void room::setExits(map<char*, room*>* newExits) {
  exits = newExits;
  
}

//run through all items and print their names out (if there are any items)
//if no items, print None
void room::getItems() {
  vector<items*>::iterator run;
  if (roomItems != NULL) {
  for (run = roomItems->begin(); run != roomItems->end(); run++) {
    cout << (*run)->getName() << endl;
  }
  }
  else {
    cout << "None" << endl;
  }
}

//find item in room by running through iterator
//return that item
//erase it from this room's items
items* room::giveItem (char item[]) {
  vector<items*>::iterator give;
  for(give = roomItems->begin(); give != roomItems->end(); give++) {
    char* itemName = (*give)->getName();
    if (strcmp(itemName, item) == 0) {
      items* swapitem = *give;
      (*roomItems).erase(give);
      return swapitem;
    }
  }
  return NULL;
}

//print exits same way items are printed
void room::getExits() {
  if (exits != NULL) {
  map<char*, room*>::iterator it;
  for (it = exits->begin(); it != exits->end(); it++) {
    cout << (*it).first << endl;
  }
  }
}

//add item to vector list
void room::addItem(items* newItems) {
  roomItems->push_back(newItems);
}

//return room name (yes, I know this is a copy. My bad)
char* room::getRoomName() {
  return roomName;
}
//return exits vector
map<char*, room*>* room::returnExits() {
  return exits;
}
