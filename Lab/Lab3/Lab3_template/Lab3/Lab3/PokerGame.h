#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

enum cardType
{
	HighCard,
	OnePair,
	TwoPairs,
	ThreeOfKind,
	Straight,
	Flush,
	FullHouse,
	FourOfKind,
	StraightFlush
};

static string table[] = {
	"HighCard",
	"OnePair",
	"TwoPairs",
	"ThreeOfKind",
	"Straight",
	"Flush",
	"FullHouse",
	"FourOfKind",
	"StraightFlush"
};

class PokerGame 
{
private:
	vector<int> playerCards;
	cardType type;
	int maxNumber; 
	//maxNumber stores the maximum number of the type.
	//It's easy to compare which number is large when both of card types are the same. 
public:
	PokerGame();
	void distribute(bool usedCards[52]);
	void set(vector<int> cards);
	void printCards();
	void sortCards();
	void evaluate();
	int getType();
	int getMaxNumber();
	void compare(int type_, int maxNumber_);

	bool isStraight();
	bool isFlush();
	bool isFourOfKind();
	bool isFullHouse();
	bool isThreeOfKind();
	bool isTwoPairs();
	bool isOnePair();
};