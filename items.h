#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>

using namespace std;

class items {
 public:
  items(char* itemName, int descriptionMethod);
  char* getName();
  int getDescription();
 private:
  char* itemName;
  int descriptionMethod;
 
};
#endif
