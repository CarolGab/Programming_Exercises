#pragma once
#include "rpg_inventory.h"

/*
Brief: To display the inventory menu
params: ---
return: ---
*/
void inventoryMenu() {
	bool mainMenu = true;
	string username, password;
	int option = 0;
	do {
		system("cls");
		cout << endl;
		cout << setw(22) << "INVENTORY MENU" << endl;
		cout << setw(22) << "--------------" << endl << endl;
		cout << "1) Admin" << endl;
		cout << "2) Player" << endl;
		cout << "3) Exit" << endl << endl;
		//use the select option function
		option = selectOption(option);
		switch (option) {
		case 1: system("cls");
			cout << "Username: ";
			cin >> username;
			cout << endl << "Password: ";
			cin >> password;
			//checks if username and password for admin are right
			if (username == "admin"&&password == "admin") {
				//stops the loop of the main menu by turning bool variable into false
				mainMenu = false;
				//use the function adminMenu to display the menu of the admin
				adminMenu();
			}
			else {
				//if wrong password or username, the user is brought back to main menu
				cout << endl << "Error: You have entered the wrong username or password." << endl << endl;
				system("pause");
			}
			break;
		case 2:
			playerMenu();
			break;
		case 3: //if player chooses to exit
			exit(0); //found this command online, needs to include #cstdlib. alternatively could've changed mainMenu into false. (wanted to try something new)
			break;
		default: break;
		}
	} while (mainMenu == true); //loop back to main menu as long as it is not turned false
}

/*
Brief: To select an option
params: int  x (for option)
return: int option chosen
*/
int selectOption(int x) {
	cout << endl << "Select an option: ";
	cin >> x;
	cout << endl;
	return x;
}

/*
Brief: To display admin menu
params: ---
return: ---
*/
void adminMenu() {
	int num = 0;
	int idNum;
	bool returnToMenu = false;
	int option = 0;
	do {
		system("cls");
		cout << setw(24) << "ADMIN MENU" << endl;
		cout << setw(24) << "----------" << endl << endl;
		cout << "1- Set Player Points" << endl;
		cout << "2- Add new items" << endl;
		cout << "3- Display list of items" << endl;
		cout << "4- Search for an item" << endl;
		cout << "5- Back to the main menu" << endl;
		//use the select option function
		option = selectOption(option);
		switch (option) {
		case 1:
			//use function to set the player points
			setPlayerPoints();
			break;
		case 2:
			cout << "How many items do you want to add? ";
			cin >> num;
			//start counting from which item slot in array will start to add new items
			for (int i = 0; i < MAXNUM; i++) {
				if (items[i].iD != NULL) {
					num++;
				}
			}
			//set global variable to the number of total items that are in items array
			numItems = num;
			//use function to add new items, using num which counted where in array to start adding items
			addNewItems(num);
			break;
		case 3:
			//use function to display items, using the global variable that keeps track of total items in array
			displayItemsList(numItems);
			break;
		case 4:
			cout << endl << "Enter an ID to search for a game: ";
			cin >> idNum;
			//use function to search using id inputed by user and using global variable numItems to look into items that exist in array
			searchItemID(numItems, idNum);
			break;
		case 5:
			//turns bool variable into true to stop loop
			returnToMenu = true;
			//use function inventoryMenu to return to menu
			inventoryMenu();
			break;
		default: break;
		}
	} while (returnToMenu == false);

}

/*
Brief: To set the Player Points for global variable playerPoints
params: ---
return: ---
*/
void setPlayerPoints() {
	system("cls");
	cout << "Enter the amount of Player Points: ";
	cin >> playerPoints;
}

/*
Brief: To display one item
params: int  x (for number of items[x])
return: ---
*/
void displayOneItem(int x) {
	cout << items[x].iD << setw(24) << items[x].name << setw(24) << items[x].power << setw(12) << items[x].price << " Pts" << endl << endl;
}

/*
Brief: To add new items
params: int x (for max number of id of last item to add)
return: ---
*/
void addNewItems(int x) {
	bool goodID = true;
	//loops until the admin writes a valid id
	do {
		for (int i = 0; i < x; i++) {
			system("cls");
			//check for an empty slot in items array to add a new item
			if (items[i].iD == NULL) {
				cout << endl << "ID: ";
				cin >> items[i].iD;
				//check if valid size of iD
				if (items[i].iD >= 10000 && items[i].iD <= 99999) {
					for (int j = 0; j < x; j++) {
						if (j == i) {
							j++;
						}
						//checks if two items have the same id
						if (items[j].iD == items[i].iD) {
							cout << "Error: There is already an item with this ID." << endl;
							system("pause");
							system("cls");
							//reset the item id to NULL, to erase the bad id if the id already exists
							items[i].iD = NULL;
							//change bool variable to false to restart the do while loop and breaks out of the immediate loop
							goodID = false;
							break;
						}
						//if all conditions check out, goodID either remains true or is turned back to true
						goodID = true;
					}
					//if the id is not valid, break out of the immediate loop to ask for a new id
					if (goodID == false) {
						break;
					}
					//if it's a good id, the admin can proceed to add the other parameters
					cout << endl << "Name: ";
					cin.ignore();
					getline(cin, items[i].name);
					cout << endl << "Power: ";
					getline(cin, items[i].power);
					cout << endl << "Price: ";
					cin >> items[i].price;
					goodID = true;
				}
				//if it is not a valid id, the id is set back to NULL and the loop restarts
				else {
					cout << "Error: Please enter a valid ID." << endl;
					system("pause");
					items[i].iD = NULL;
					i--;
					goodID = false;
					system("cls");
				}
			}
		}
	} while (goodID == false);
}

/*
Brief: To display the items list for admin
params: int x (for the max number of set items)
return: ---
*/
void displayItemsList(int x) {
	system("cls");
	cout << setw(40) << "LIST OF ITEMS" << endl;
	cout << setw(40) << "-------------" << endl;
	cout << "ID" << setw(26) << "NAME" << setw(26) << "POWER" << setw(14) << "PRICE" << endl << endl;
	for (int i = 0; i < x; i++) {
		//use the displayOneItem function in a loop
		displayOneItem(i);
	}
	system("pause");
}

/*
Brief: To search and item using ID
params: int x, y (x being the number of items that are defined, y being the ID entered by user)
return: Item that matches the ID
*/
Item searchItemID(int x, int y) {
	system("cls");
	cout << setw(40) << "SEARCH" << endl;
	cout << setw(40) << "------" << endl << endl;
	for (int i = 0; i < x; i++) {
		if (items[i].iD == y) {
			//use the displayOneItem function in a loop
			displayOneItem(i);
			system("pause");
			return items[i];
		}
	}
}

/*
Brief: To display the player menu
params: ---
return: ---
*/
void playerMenu() {
	system("cls");
	bool backToMenu = false;
	int option = 0;
	//shows player menu again as long as the player does not choose to go back to main menu
	do {
		cout << setw(24) << "PLAYER MENU" << "\t\t\t\t\tPlayer Points: " << playerPoints << endl;
		cout << setw(24) << "-----------" << endl << endl;
		cout << "1- Buy new Items" << endl;
		cout << "2- Display Backpack" << endl;
		cout << "3- Back to Main Menu" << endl;
		//use the select option function
		option = selectOption(option);
		switch (option) {
		case 1:
			displayShop();
			break;
		case 2:
			displayBackpack();
			break;
		case 3:
			backToMenu = true;
			inventoryMenu();
			break;
		}
	} while (backToMenu == false);
}

/*
Brief: To sort the items in array using pointers from least expensive to most expensive
params: ---
return: ---
*/
void sortByPrice() {
	Item *ptrPrice, temp;
	for (int i = 0; i < numItems; i++) {
		for (int j = 0; j < numItems - 1; j++) {
			if (items[j].price > items[j + 1].price) {
				ptrPrice = &items[j];
				temp = items[j];
				*ptrPrice = items[j + 1];
				ptrPrice = &items[j + 1];
				*ptrPrice = temp;
			}
		}
	}
}

/*
Brief: To display the shop for the player
params: ---
return: ---
*/
void displayShop() {
	int purchaseID, option = 0;
	//sort the array of items from cheapest to most expensive
	sortByPrice();
	//bool so that it keeps repeating if the player enters invalid options
	bool itemPurchase = false;
	do {
		bool duplicate = false, valid = false;
		system("cls");
		cout << setw(40) << "SHOP" << "\t\t\t\t\tPlayer Points: " << playerPoints << endl;
		cout << setw(40) << "----" << endl;
		cout << "ID" << setw(26) << "NAME" << setw(26) << "POWER" << setw(14) << "PRICE" << endl << endl;
		//display the items in shop
		for (int i = 0; i < numItems; i++) {
			//use the displayOneItem function in a loop
			displayOneItem(i);
		}
		//give an option to go back to main menu, in case player does not want to purchse, or can't purchase
		cout << endl << "1. Purchase";
		cout << endl << "2. Back to Menu" << endl;
		//use the select option function
		option = selectOption(option);
		switch (option) {
		case 1:
			cout << endl << "Input the item ID of the item you wish to purchase: ";
			cin >> purchaseID;
			cout << endl;
			//loop for finding id that matches id inputed by player begins
			for (int i = 0; i < MAXNUM; i++) {
				//if the player purchased it, it breaks out of loop
				if (itemPurchase == true) {
					break;
				}
				//if the id is found, the condition starts
				if (purchaseID == items[i].iD) {
					valid = true;
					//condition to see if player has enough player points to buy selected item
					if (playerPoints > items[i].price) {
						//if the player has enough points, the condition starts to see if the player already has the item in his backpack
						for (int j = 0; j < MAXNUM; j++) {
							//if the player has it in his backpack
							if (purchaseID == backpack[j].iD) {
								cout << "You already have this item. Please select another item." << endl;
								//turn bool variable into true for duplicate
								duplicate = true;
								system("pause");
								//break out of loop because of duplicate
								break;
							}
						}
						//break out of the other loop also because of duplicate
						if (duplicate == true) {
							break;
						}
						//if everything checks out, the loop starts checking for an empty spot in player's backpack to add the item purchased
						for (int k = 0; k < MAXNUM; k++) {
							if (backpack[k].iD == NULL) {
								backpack[k] = items[i];
								//turn bool variable true to confirm purchase
								itemPurchase = true;
								//change global variable playerPoints by the price of the item purchased
								playerPoints = playerPoints - items[i].price;
								break;
							}
						}
					}
					else {
						//if player does not have enough points, the loop breaks and he is brought back to the shop menu for a new selection
						cout << "You do not have enough Player Points to purchase this item." << endl;
						system("pause");
						break;
					}
				}
			}
			//if the id entered by user is not valid, he is brought back for a new selection
			if (valid == false) {
				cout << endl << "Please enter a valid ID." << endl;
				system("pause");
			}
			break;
		case 2: //if the player chooses to get out of the shop menu, he is brought back to the player menu
			playerMenu();
		}
	} while (itemPurchase == false);
	cout << endl << "Item Purchased!" << endl;
	system("pause");
	system("cls");
}

/*
Brief: To display what the player has purchased in his backpack
params: ---
return: ---
*/
void displayBackpack() {
	system("cls");
	cout << setw(24) << "BACKPACK" << "\t\t\t\t\tPlayer Points: " << playerPoints << endl;
	cout << setw(24) << "--------" << endl << endl;
	cout << endl << endl;
	cout << "ID" << setw(26) << "NAME" << setw(26) << "POWER" << setw(14) << "PRICE" << endl << endl;
	for (int i = 0; i < MAXNUM; i++) {
		if (backpack[i].iD != NULL) {
			cout << backpack[i].iD << setw(24) << backpack[i].name << setw(24) << backpack[i].power << setw(12) << backpack[i].price << " Pts" << endl << endl;
		}
	}
	system("pause");
	system("cls");
}
