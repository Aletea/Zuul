#include <iostream>
#include "items.h"
#include <cstring>

using namespace std;
//initialize
items::items (char itemTitle[], int description) {
  itemName = new char[20];
  strcpy(itemName, itemTitle);
  descriptionMethod = description;
}
//get name
char* items::getName() {
  return itemName;
}
//haven't worked with this yet: ignore
int items::getDescription() {
  return descriptionMethod;
}
