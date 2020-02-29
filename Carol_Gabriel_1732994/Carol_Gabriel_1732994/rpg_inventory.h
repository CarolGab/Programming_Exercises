#pragma once
#include <iostream>
#include <string>
#include <iomanip> //for setw
#include <cstdlib> //for exit(0)

using namespace std;

//structure prototype
struct Item {
	int iD;
	string name;
	string power;
	int price;
};

//global variables
const int MAXNUM = 100; //constant variable
Item items[MAXNUM] = { NULL };
Item backpack[MAXNUM] = { NULL };
int playerPoints;
int numItems;


//functions prototype
void inventoryMenu();
int selectOption(int);
void adminMenu();
void setPlayerPoints();
void displayOneItem(int);
void addNewItems(int);
void displayItemsList(int);
Item searchItemID(int, int);
void playerMenu();
void sortByPrice();
void displayShop();
void displayBackpack();
