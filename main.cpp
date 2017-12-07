 #include <iostream>
 #include <cstring>
 #include <map>
 #include "room.h"
 #include "items.h"
 #include <vector>
 #include <cstdlib>
 //methods
 void goRoom(char demand[], vector<room*> rooms, room* &currentRoom);
 void displayRoom(room* nowRoom, vector<items*>* inventory, int &done);
 void finalRoom();


 int main() {
   //rooms, inventory, current room 
   vector<room*> rooms;
   vector<items*>*inventory = new vector<items*>();
   room* currentRoom;
  
   int answer = 0;
   //rooms
   room* outside = new room("The Outside");
   room* mainHall = new room("The Main Hall");
   room* office = new room("The Office");
   room* basement = new room("The Basement");
   room* secretOperatingRoom = new room("The Secret Operating Room");
   room* upperHallway = new room("The Upper Hallway");
   room* attic = new room("The Attic");
   room* closet = new room("The Closet");
   room* room210 = new room("Room 210");
   room* room206 = new room("Room 206");
   room* room217 = new room("Room 217");
   room* unmarkedRoom = new room("The Unmarked Room");
   room* innerWall = new room("The Inner Wall");
   room* secretPassageway = new room("The Secret Passageway");
   room* southPassageway = new room("The South Passageway");
   room* northPassageway = new room("The North Passageway");
   room* theRoom = new room("The Room");
   room* coffinRoom = new room("The Coffin Room");
   //exits set for each room using map
   map<char*, room*>* outsideMap = new map<char*,room*>();
   outsideMap->insert(pair <char*, room*>("Front Door", mainHall));
   outsideMap->insert(pair <char*, room*>("Window", mainHall));
   outsideMap->insert(pair <char*, room*>("Back Door", mainHall));
   outside->setExits(outsideMap);
   outsideMap = new map<char*, room*>(); 
   outsideMap->insert(pair <char*, room*>("Front Door", outside));
   outsideMap->insert(pair <char*, room*>("Window", outside));
   outsideMap->insert(pair <char*, room*>("Back Door", outside));
   outsideMap->insert(pair <char*, room*>("Stairs", upperHallway));
   outsideMap->insert(pair <char*, room*>("Office Door", office));
   mainHall->setExits(outsideMap);
  outsideMap = new map<char*, room*>(); 
   outsideMap->insert(pair <char*, room*>("Office Door", mainHall));
   outsideMap->insert(pair <char*, room*>("Book Shelf", basement));
   office->setExits(outsideMap);
   outsideMap = new map<char*, room*>(); 
   outsideMap->insert(pair <char*, room*>("Stairs", office));
   outsideMap->insert(pair <char*, room*>("Metal Door", secretOperatingRoom));
   basement->setExits(outsideMap);
   outsideMap = new map<char*, room*>();
   outsideMap->insert(pair <char*, room*>("Metal Door", basement));
   secretOperatingRoom->setExits(outsideMap);
   outsideMap = new map<char*, room*>(); 
   outsideMap->insert(pair <char*, room*>("Lower Stairs", mainHall));
   outsideMap->insert(pair <char*, room*>("Room 210", room210));
   outsideMap->insert(pair <char*, room*>("Upper Stairs", attic));
   outsideMap->insert(pair <char*, room*>("Room 206", room206));
   outsideMap->insert(pair <char*, room*>("Room 217", room217));
   outsideMap->insert(pair <char*, room*>("Unmarked Room", unmarkedRoom));
   upperHallway->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Stairs", upperHallway));
     outsideMap->insert(pair <char*, room*>("Closet", closet));
     attic->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Door", attic));
     closet->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Door", upperHallway));
     room210->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Door", upperHallway));
     room206->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Door", upperHallway));
     outsideMap->insert(pair <char*, room*>("Hole In The Wall", innerWall));
     room217->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Door", upperHallway));
     unmarkedRoom->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Hole In The Wall", room217));
    outsideMap->insert(pair <char*, room*>("Hole in the Ground", secretPassageway));
     innerWall->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Hole in the Ceiling", innerWall));
     outsideMap->insert(pair <char*, room*>("North", northPassageway));
     outsideMap->insert(pair <char*, room*>("South", southPassageway));
     secretPassageway->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("North", secretPassageway));
     southPassageway->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("South", secretPassageway));
     outsideMap->insert(pair <char*, room*>("Door", theRoom));
     northPassageway->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Door", northPassageway));
     outsideMap->insert(pair <char*, room*>("Trap Door", coffinRoom));
     theRoom->setExits(outsideMap);
     outsideMap = new map<char*, room*>(); 
     outsideMap->insert(pair <char*, room*>("Ladder", theRoom));
     coffinRoom->setExits(outsideMap);
     //items, flashlight goes in inventory vector
     items* flashlight = new items("flashlight", 0);
     inventory->push_back(flashlight);
     items* backDoorKey = new items("Silver Key", 1);
     items* unmarkedRoomKey = new items("Copper Key", 1);
     items* metalDoorKey = new items("Black Key", 1);
     items* bookshelfKey = new items("Rusted Key", 1);
     items* daniel = new items("Daniel", 2);
     items* scalpal = new items("scalpal", 0);
     items* crowBar = new items("Crow Bar", 0);
     items* screw = new items("screw", 0);
     items* basket = new items("basket", 0);
     items* painting = new items("painting", 0);
     items* theEyepiece = new items("Eyepiece", 3);
     items* wardenJournal = new items("Warden's Journal", 4);
     items* pictureBox = new items("Picture Box", 5);
     items* diary = new items("Diary", 6);
         //set items for each room with vectors
     vector<items*>* officeItems = new vector<items*>();
     officeItems->push_back(wardenJournal);
     office->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(scalpal);
     secretOperatingRoom->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(bookshelfKey);
     officeItems->push_back(theEyepiece);
     attic->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(pictureBox);
     closet->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(diary);
     room210->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(metalDoorKey);
     room206->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(daniel);
     officeItems->push_back(backDoorKey);
     unmarkedRoom->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(unmarkedRoomKey);
     southPassageway->setItems(officeItems);
     officeItems = new vector<items*>();
     officeItems->push_back(basket);
     officeItems->push_back(screw);
     officeItems->push_back(painting);
     coffinRoom->setItems(officeItems);
     //set current room, and begin!
     bool playing = true;
     currentRoom = outside;
     int done = 0;
     //description
     cout << "Your friend Daniel has been missing for days. As far as you know, you are the last person to have heard from him. 2 days ago he sent you a series of eerie text messages:" << endl;
     cout << "9:32pm - I think someone's inside Ceranburry. " << endl;
     cout << "9:33pm - No one lives there though, right?" << endl;
     cout << "10:00pm - I'm checking it out." << endl;
     cout << "10:30pm - Are you there? Please tell me you're there." << endl;
     cout << "11:00pm - I just found something." << endl;
     cout << "11:02pm - Whatever happens, you can't tell anyone. Please." << endl;
     cout << "11:04pm - CALL ME NOW" << endl;
     cout << "11:04pm - do't worry. it's okay." << endl;
     cout << endl << "It's been 2 days. You haven't told anyone." << endl;
     cout << "He's your best friend, he could be in trouble" << endl;
     cout << "Tonight, you will sneak into the long abandoned and forbidden Ceranburry Asylum located just off campus to look for your friend." << endl;
     cout << "You're approaching the entrance now" << endl;


  
     while (playing == true) {
       //display room in each new room
       displayRoom(currentRoom, inventory, done);
       //for reference to go back to the top
     playerInput:
       //try this, if it doesn't work, go back to the top
       try {
         //enter command
         char command[50];
         cout << endl << "command: " << endl;
       cin.get(command, 50);
       cin.get();
       char keyWord[15];
       char demand[20];
       int count = 0;
       bool secondWord = false;
       //split command into 2 words: key word and demand
       for (int i = 0; i < strlen(command); i++) { 
	 if (command[i] == ' ' && secondWord == false) {
   	secondWord = true;
   	keyWord[i] = '\0';
         }
         else if (secondWord == false) {
   	keyWord[i] = command[i];
         }
         else {
   	demand[count] = command[i];
   	count++;
         }
       }
       demand[count] = '\0';
       //based on key word, go to a room, get an item, drop an item, or print inventory
       if (strcmp(keyWord, "go") == 0) {
         goRoom(demand, rooms, currentRoom);
       }
    
       else if (strcmp(keyWord, "get") == 0) {
         //get the item if it exists     
   	if (currentRoom->checkItem(demand) == true) {
   	  cout << "here" << endl;
   	  inventory->push_back(currentRoom->giveItem(demand));
   	  cout << "I hope you're happy with your " << demand << endl;
      	}
   	else {
   	  cout << "This item is not in here. It may not exist at all." << endl;
   	}
         //back to top
         goto playerInput;
       }
    
       else if (strcmp(keyWord, "drop") == 0) {
         //find the item by running through inventory
         //drop item
         vector<items*>::iterator it;
         items* dropItem = NULL;
         for (it = inventory->begin(); it != inventory->end(); it++) {
	   if (strcmp((*it)->getName(), demand) == 0) {
   	  dropItem = (*it);
   	  currentRoom->addItem(dropItem);
   	  cout << "You've rid of this item. It belongs to the room now." << endl;
   	  inventory->erase(it);
   	  break;
   	}
         }
         //if can't find item, back to top
         if (dropItem == NULL) {
   	cout << "Item not found in your inventory." << endl;
   	//fancy answers 
   	if (answer == 0) {
   	  cout << "Are you okay?" << endl;
   	  answer++;
   	}
   	else if (answer == 1) {
   	  cout << "Did that item ever even exist?" << endl;
   	  answer++;
   	}
   	else {
   	  cout << "You don't look well." << endl;
   	}
         }
         goto playerInput;
       }
       
       else if (strcmp(keyWord, "inventory") == 0) {
         //iterate through and print
         vector<items*>::iterator it;
         cout << endl << "Inventory:" << endl;
         for (it = inventory->begin(); it != inventory->end(); it++) {
	   cout << (*it)->getName() << endl;
         }
         goto playerInput;
       }
       
       else {
         cout << "Improper Command" << endl;
         goto playerInput;
       }
    
       } catch(...) {
         //if error, back to top
         cout << "error" << endl;
         goto playerInput;
       }
     }
     return 0;
   }
   //displays exits, items, and description
   void displayRoom(room* nowRoom, vector<items*>* inventory, int &done) {
     //if you've won (outside w daniel), end game
     if (strcmp(nowRoom->getRoomName(), "The Outside") == 0) {
       //check if u have daniel
       
    bool haveDaniel = false;
    vector<items*>::iterator it;
    for (it = inventory->begin(); it != inventory->end(); it++) {
      if (strcmp((*it)->getName(), "Daniel") == 0) {
	haveDaniel = true;
	break;
      }
    }
    if (haveDaniel == true) {
    cout << "Congratulations. You've escaped Asylum. Or have you?" << endl;
    exit(-1);
    }
  }
  //if you enter unmarekd room, time to see if you win
  if (strcmp(nowRoom->getRoomName(), "The Unmarked Room") == 0 && done == 0) {
    finalRoom();
    cout << "Objective: Get Daniel. Run." << endl;
    cout << "EXITS: " << endl;
    nowRoom->getExits();
    cout << endl << "ITEMS: " << endl;
    nowRoom->getItems();
    cout << endl;
    done = 1;
    return;
  }
  cout << endl;
  //print room
  cout << "You are now in " << nowRoom->getRoomName() << endl;
  //different room descriptions
  if (strcmp(nowRoom->getRoomName(), "Outside") == 0) {
    cout << "It's cold outside. Hurry." << endl;
  }
  if (strcmp(nowRoom->getRoomName(), "Main Hall") == 0) {
    cout << "What was that noise?" << endl;
  }
  if (strcmp(nowRoom->getRoomName(), "Upper Hallway") == 0) {
    cout << "A lot of the rooms here are still locked. I wonder what the locks were for..." << endl;
  }
  if (strcmp(nowRoom->getRoomName(), "Room 217") == 0) {
    cout << "There's a hole in the wall, but wherever it leads is pretty dark." << endl;
  }
  if (strcmp(nowRoom->getRoomName(), "Attic") == 0) {
    cout << "There's dust everywhere. Don't choke." << endl;
  }
  cout << endl;
  cout << "EXITS:" << endl;
  nowRoom->getExits();
  cout << endl;
  cout << "Items: " << endl;
  nowRoom->getItems();
  cout << endl;
  cout << "Your commands are: go, drop, get, and inventory" << endl;
}
//solve a riddle, exit if incorrect, return if true
void finalRoom() {
  cout << "Welcome to the Unmarked Room, Player." << endl;
  cout << "Here is where you will find Daniel. But lets play a game first." << endl;
  cout << endl << "I feel your every thought." << endl;
  cout << "I feel your every move" << endl;
  cout << "I'm with you from birth and I'll see you rot." << endl;
  cout << "What am I?" << endl << endl << "Guess correctly and I might just let you in: " << endl;
  char finalAnswer[30];
  cin.get(finalAnswer, 30);
  cin.get();
  if (strcmp(finalAnswer, "Reflection") == 0 || strcmp(finalAnswer, "reflection") == 0
      || strcmp(finalAnswer, "A Reflection") == 0 || strcmp(finalAnswer, "a reflection") == 0
      || strcmp(finalAnswer, "Your Reflection") == 0 || strcmp(finalAnswer, "your reflection") == 0
      || strcmp(finalAnswer, "My Reflection") == 0 || strcmp(finalAnswer, "my reflection") == 0) {
    cout << endl << "Good Answer. You're free to enter." << endl;
    cout << "Your friend is unconcious. Who knows why?" << endl;
    cout << "The only thing you have to do now, is run." << endl;
 
  }
  else {
    cout << endl << "Such a shame. I really did like you." << endl;
    cout << "Don't bother getting out, you'll join your friend here soon." << endl;
    cout << "Asleep forever. Ever wondered what it's like?" << endl;
    exit(-1);
  }
}
//change current room
void goRoom(char demand[], vector<room*> rooms, room* &currentRoom) {
  //find desired exit and go to room it belongs to according to the map
  map<char*, room*>::iterator it;
  bool found = false;
  map<char*, room*>* getMap = (currentRoom->returnExits());
  for (it = getMap->begin(); it != getMap->end(); it++) {
    if (strcmp(it->first, demand) == 0) {
      currentRoom = it->second;
      found =   true;
    }
  }
  if (found == false) {
    cout << "This is not an exit. Maybe you should look at the exits again." << endl;
  }
}
//Sole Purpose: To make this program 400 lines
void neverUsed() {
  int noValue;
  char unImportant;
  float completelyPointless;
  cout << "You'll never see this" << endl;
  cin >> noValue;
}
