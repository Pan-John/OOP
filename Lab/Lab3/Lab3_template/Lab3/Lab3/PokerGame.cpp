#include "PokerGame.h"

PokerGame::PokerGame() {
	//TO_DO: initial constructor

}

void PokerGame::distribute(bool usedCards[52]) {//rand()%52-->0~51
	//TO_DO: Random generate five cards to player
	//Hint: Use usedCards to record which card have been distributed
	for (int i = 0; i < 5; i++) {
		while (true) {
			int randNum = rand() % 52;
			if (!usedCards[randNum]) {
				playerCards.push_back(randNum + 1);
				usedCards[randNum] = true;
				break;
			}
		}
	}

}

void PokerGame::set(vector<int> cards) {
	//TO_DO: Set the cards to player
	playerCards = cards;
}

void PokerGame::printCards() {
	/////////sortCards();
	cout << "Player cards:" << endl;
	//suitC = 0, suitD = 0, suitH = 0, suitS = 0;
	for (int i = 0; i < 5; i++) {
		//TO_DO: Print the player's cards.
		// For example: "C1" "S2" "H3" ...
		if (0 <= playerCards[i] && playerCards[i] <= 12)
			cout << "C" << playerCards[i] + 1 <<" ";
		else if (13 <= playerCards[i] && playerCards[i] <= 25)
			cout << "D" << playerCards[i]%13 + 1 << " ";
		else if (26 <= playerCards[i] && playerCards[i] <= 38)
			cout << "H" << playerCards[i]%13 + 1 << " ";
		else //39<=playerCards[i] && playerCards[i]<=51
			cout << "S" << playerCards[i]%13 + 1 << " ";		
	}
	cout << endl;
}

void PokerGame::sortCards() {
	//TO_DO: Sort the cards accroding to thier number
	//i also sort the cards according to their suits
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (playerCards[i] > playerCards[j]) {
				int tmp = playerCards[i];
				playerCards[i] = playerCards[j];
				playerCards[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) { 
			if (playerCards[i]%13+1 > playerCards[j]%13+1) {
				int tmp = playerCards[i];
				playerCards[i] = playerCards[j];
				playerCards[j] = tmp;
			}
		}
	}

}

void PokerGame::evaluate() {
	sortCards();
	if (this->isStraight() && this->isFlush()) {
		type = StraightFlush;
	}
	else if (this->isFourOfKind()) {
		type = FourOfKind;
	}
	else if (this->isFullHouse()) {
		type = FullHouse;
	}
	else if (this->isFlush()) {
		type = Flush;
	}
	else if (this->isStraight()) {
		type = Straight;
	}
	else if (this->isThreeOfKind()) {
		type = ThreeOfKind;
	}
	else if (this->isTwoPairs()) {
		type = TwoPairs;
	}
	else if (this->isOnePair()) {
		type = OnePair;
	}
	else {
		type = HighCard;
		//TO_DO: Set the maxNumber
		maxNumber = playerCards[4];
		
	}
}

int PokerGame::getType() {
	return type;
}

int PokerGame::getMaxNumber() {
	return maxNumber;
}

void PokerGame::compare(int type_, int maxNumber_) {
	//TO_DO: Compare the type and output who is winner
	//Compare the type of card first. If types are the same, compare which is max the number of card.
	//If the max number is the same, compare the suit of card.
	if (type > type_)
		cout << "Player1 win\n";
	else if (type < type_)
		cout << "Player2 win\n";
	else if (maxNumber % 13 > maxNumber_ % 13)
		cout << "Player1 win\n";
	else if (maxNumber % 13 < maxNumber_ % 13)
		cout << "Player2 win\n";
	else if (maxNumber > maxNumber_)
		cout << "Player1 win\n";
	else if (maxNumber < maxNumber_)
		cout << "Player2 win\n";

}

bool PokerGame::isStraight() {
	//TO_DO: Check whether the hand of cards is Straight or not and set the maxNumber
	for (int i = 0; i < 4; i++) {//just check 4 times!
		if (playerCards[i + 1] % 13 != playerCards[i] % 13 + 1)
			return false;
	}
	maxNumber = playerCards[4];
	return true;
}

bool PokerGame::isFlush() {//same suit*5
	//TO_DO: Check whether the hand of cards is Flush or not and set the maxNumber
	int suitC = 0, suitD = 0, suitH = 0, suitS = 0;
	for (int i = 0; i < 5; i++) {
		if (0 <= playerCards[i] && playerCards[i] <= 12)
			suitC++;
		else if (13 <= playerCards[i] && playerCards[i] <= 25)
			suitD++;
		else if (26 <= playerCards[i] && playerCards[i] <= 38)
			suitH++;
		else//39<=playerCards[i] && playerCards[i]<=51
			suitS++;
	}
	if (suitC == 5 or suitD == 5 or suitH == 5 or suitS == 5) {
		maxNumber = playerCards[4];
		return true;
	}
	return false;
}

bool PokerGame::isFourOfKind() {
	//TO_DO: Check whether the hand of cards is FourOfaKind or not and set the maxNumber
	for (int i = 0; i < 2; i++) {
		if (playerCards[i] % 13 == playerCards[i + 1] % 13 and playerCards[i + 1] % 13 == playerCards[i + 2] % 13 and playerCards[i + 2] % 13 == playerCards[i + 3] % 13) {
			maxNumber = playerCards[i+3];
			return true;
		}
	}
	return false;
}

bool PokerGame::isFullHouse() {
	//TO_DO: Check whether the hand of cards is FullHouse or not and set the maxNumber
	if (playerCards[0] % 13 == playerCards[1] % 13 && playerCards[0] % 13 == playerCards[2] % 13 && playerCards[3] % 13 == playerCards[4] % 13) {
		maxNumber = playerCards[2];		
		return true;
	}
	if (playerCards[2] % 13 == playerCards[3] % 13 && playerCards[2] % 13 == playerCards[4] % 13 && playerCards[0] % 13 == playerCards[1] % 13) {
		maxNumber = playerCards[4];
		return true;
	}
	return false;
}

bool PokerGame::isThreeOfKind() {
	//TO_DO: Check whether the hand of cards is ThreeOfaKind or not and set the maxNumber
	for (int i = 0; i < 3; i++) {
		if (playerCards[i] % 13 == playerCards[i + 1] % 13 && playerCards[i] % 13 == playerCards[i + 2] % 13) {
			maxNumber = playerCards[i+2];
			return true;
		}

	}
	return false;
}

bool PokerGame::isTwoPairs() {
	//TO_DO: Check whether the hand of cards is TwoPairs or not and set the maxNumber
	for (int i = 0; i < 4; i++) {
		if (playerCards[i] % 13  == playerCards[i + 1] % 13 ) {
			for (int j = i + 2; j < 4; j++) {
				if (playerCards[j] % 13 == playerCards[j + 1] % 13 && playerCards[i] % 13 != playerCards[j] % 13) {//the second condition isn't necessary
					maxNumber = playerCards[j+1];
					return true;
				}

			}
			return false;//needs another false
		}
	}
	return false;
}

bool PokerGame::isOnePair() {
	//TO_DO: Check whether the hand of cards is OnePair or not and set the maxNumber
	for (int i = 0; i < 4; i++) {
		if (playerCards[i] % 13 == playerCards[i + 1] % 13) {
			maxNumber = playerCards[i+1];
			return true;
		}
	}
	return false;
}