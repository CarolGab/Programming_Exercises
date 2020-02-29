#include<iostream>


using namespace std;



void main() {
	char answer;
	do {
		const char PLAYER1 = 'X', PLAYER2 = 'O';
		char position[9]{ '1','2','3','4','5','6','7','8','9' };
		char input;
		bool players = true;
		bool win1 = false, win2 = false;
		for (int i = 0; i < 9; i++) {

			cout << "\t\tTic Tac Toe" << endl << endl;
			cout << "\tPlayer 1 <X> \tPlayer 2 <O>" << endl;
			cout << "\t     |     |     " << endl;
			cout << "\t  " << position[0] << "  |  " << position[1] << "  |  " << position[2] << "  " << endl;
			cout << "\t_____|_____|_____" << endl;
			cout << "\t     |     |     " << endl;
			cout << "\t  " << position[3] << "  |  " << position[4] << "  |  " << position[5] << "  " << endl;
			cout << "\t_____|_____|_____" << endl;
			cout << "\t     |     |     " << endl;
			cout << "\t  " << position[6] << "  |  " << position[7] << "  |  " << position[8] << "  " << endl;
			cout << "\t     |     |     " << endl;

			if (position[0] == PLAYER1&&position[4] == PLAYER1&&position[8] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[0] == PLAYER1&&position[3] == PLAYER1&&position[6] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[0] == PLAYER1&&position[1] == PLAYER1&&position[2] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[1] == PLAYER1&&position[4] == PLAYER1&&position[7] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[2] == PLAYER1&&position[5] == PLAYER1&&position[8] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[2] == PLAYER1&&position[4] == PLAYER1&&position[6] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[3] == PLAYER1&&position[4] == PLAYER1&&position[5] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[6] == PLAYER1&&position[7] == PLAYER1&&position[8] == PLAYER1) {
				system("cls");
				win1 = true;
				break;
			}
			if (position[0] == PLAYER2&&position[4] == PLAYER2&&position[8] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (position[0] == PLAYER2&&position[3] == PLAYER2&&position[6] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (position[0] == PLAYER2&&position[1] == PLAYER2&&position[2] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (position[1] == PLAYER2&&position[4] == PLAYER2&&position[7] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (position[2] == PLAYER2&&position[5] == PLAYER2&&position[8] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (position[2] == PLAYER2&&position[4] == PLAYER2&&position[6] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (position[3] == PLAYER2&&position[4] == PLAYER2&&position[5] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (position[6] == PLAYER2&&position[7] == PLAYER2&&position[8] == PLAYER2) {
				system("cls");
				win2 = true;
				break;
			}
			if (players == true) {
				cout << "Player 1: ";
				cin >> input;

				if (input == '1'&&position[0] == '1') {
					position[0] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '2'&&position[1] == '2') {
					position[1] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '3'&&position[2] == '3') {
					position[2] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '4'&&position[3] == '4') {
					position[3] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '5'&&position[4] == '5') {
					position[4] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '6'&&position[5] == '6') {
					position[5] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '7'&&position[6] == '7') {
					position[6] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '8'&&position[7] == '8') {
					position[7] = PLAYER1;
					players = false;
					system("cls");
				}
				else if (input == '9'&&position[8] == '9') {
					position[8] = PLAYER1;
					players = false;
					system("cls");
				}
				system("cls");
			}
			else {
				cout << "Player 2: ";
				cin >> input;
				if (input == '1'&&position[0] == '1') {
					position[0] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '2'&&position[1] == '2') {
					position[1] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '3'&&position[2] == '3') {
					position[2] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '4'&&position[3] == '4') {
					position[3] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '5'&&position[4] == '5') {
					position[4] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '6'&&position[5] == '6') {
					position[5] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '7'&&position[6] == '7') {
					position[6] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '8'&&position[7] == '8') {
					position[7] = PLAYER2;
					players = true;
					system("cls");
				}
				else if (input == '9'&&position[8] == '9') {
					position[8] = PLAYER2;
					players = true;
					system("cls");
				}
				system("cls");
			}
		}
		cout << "\t\tTic Tac Toe" << endl << endl;
		cout << "\tPlayer 1 <X> \tPlayer 2 <O>" << endl;
		cout << "\t     |     |     " << endl;
		cout << "\t  " << position[0] << "  |  " << position[1] << "  |  " << position[2] << "  " << endl;
		cout << "\t_____|_____|_____" << endl;
		cout << "\t     |     |     " << endl;
		cout << "\t  " << position[3] << "  |  " << position[4] << "  |  " << position[5] << "  " << endl;
		cout << "\t_____|_____|_____" << endl;
		cout << "\t     |     |     " << endl;
		cout << "\t  " << position[6] << "  |  " << position[7] << "  |  " << position[8] << "  " << endl;
		cout << "\t     |     |     " << endl;
		if (win1 == true) {
			cout << "Player 1 wins.";
		}
		else if (win2 == true)
		{
			cout << "Player 2 wins.";
		}
		else if (win1 == false && win2 == false) {
			cout << "It's a draw.";
		}
		cout << endl << "Do you want to play again(y/n)?";
		cin >> answer;
		players = true;
		system("cls");
	}while (answer == 'y' || answer == 'Y');
	system("pause");
}