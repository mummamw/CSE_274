/*****
 * Author   : brinkmwj
 * Date     : 2009-07-23
 * Modified : inclezd (2/17/2015)
 * Sources  : All code is original
 * Purpose  : The Deck class is used to represent a deck of cards that can be shuffled and cut.
 * Note     : DO NOT CHANGE THIS FILE!!! All implementations of these functions should be in Deck.cpp
 *****/
#include "IntList.h"

class Deck {
public:
	// A Deck is just a list of the numbers from 0 to 51. (So there are 52 cards)
	// 0-12 correspond to the ace-king of hearts,
	// 13-25 are the ace-king of diamonds,
	// 26-38 are the ace-king of clubs,
	// 39-51 are the ace-king of spades
	//
	// After the constructor is called, deckList should contain the list {0, 1, 2, 3, ... , 51}
	Deck();

	/*
	 * First, cut the deck in half into two decks, A and B
	 * Note: After cut, A should be the TOP HALF of the original deckList, and B should be the BOTTOM HALF
	 * Next, merge A and B back into a single deck. Take turns taking cards from the BOTTOM of A, 
	 * then from the BOTTOM of B.
	 *
	 * At each step, take either 0, 1, or 2 cards from the bottom of the deck you are working with, and put
	 * them on the bottom of deckList (the splice function may be useful here). This mimics the way a shuffle 
	 * actually works: Cards from the bottom of the two piles get dealt with first.
	 */
	void shuffle();

	// This function returns the head of deckList
	IntListNode* getListHead();
	
private:
	/*
	 * This function should take the contents of the deckList and split it into two lists for
	 * shuffling. The first 26 items in deckList should end up in A, the other 26 items should end
	 * up in B. The splice function may be useful here.
	 */
	void cut(IntList* A, IntList* B);

	IntList deckList;
};