#include<iostream>
#include "PokerGame.h"
using namespace std;

void cheatInput(vector<int>& player) {
	//TO_DO: Ask user input five number and store them to vector of player
	
	for (int i = 0; i < 5; i++) {
		int c;
		cin >> c;
		player.push_back(c);
	}
}

int main() {
	bool Exit = false;

	while (!Exit) {
		PokerGame player1, player2;
		vector<int> cheatCards1, cheatCards2;
		bool usedCards[52] = { false };//0
		int winner;
		char GameType;
		cout << "Enter S to start the game, C to enter cheating mode, Q to Exit the process" << endl;
		cin >> GameType;
		cout << endl;

		switch (GameType) {
		case 's':
		case 'S':
			//Normal mode, generate five cards for each players
			player1.distribute(usedCards);
			player2.distribute(usedCards);

			//Evaluate the type of cards and which is maxNumber in the cards
			player1.evaluate();
			player2.evaluate();

			//Print the cards of each players
			player1.printCards();
			player2.printCards();

			cout << "Player1 Type = " << table[player1.getType()] << endl;
			cout << "Player2 Type = " << table[player2.getType()] << endl;

			//Compare and output winner
			player1.compare(player2.getType(),player2.getMaxNumber());
			break;
		case 'c':
		case 'C':
			//Cheat mode , input the player cards
			cout << "Input player 1's card:";
			cheatInput(cheatCards1);
			cout << "Input player 2's card:";
			cheatInput(cheatCards2);

			player1.set(cheatCards1);
			player2.set(cheatCards2);

			//Evaluate the type of cards and which is maxNumber in the cards
			player1.evaluate();
			player2.evaluate();

			//Print the cards of each players
			player1.printCards();
			player2.printCards();

			cout << "Player1 Type = " << table[player1.getType()] << endl;
			cout << "Player2 Type = " << table[player2.getType()] << endl;

			//Compare and output winner
			player1.compare(player2.getType(),player2.getMaxNumber());
			break;
		case 'q':
		case 'Q':
			Exit = true;
			break;//iwt
		default:
			break;
		}
	}
}