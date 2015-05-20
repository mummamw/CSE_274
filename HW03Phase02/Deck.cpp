#include "Deck.h"
#include <stdlib.h>
#include <time.h>


	// A Deck is just a list of the numbers from 0 to 51. (So there are 52 cards)
	// 0-12 correspond to the ace-king of hearts,
	// 13-25 are the ace-king of diamonds,
	// 26-38 are the ace-king of clubs,
	// 39-51 are the ace-king of spades
	// After the constructor is called, deckList should contain the list {0, 1, 2, 3, ... , 51}
	Deck::Deck(){
		IntList* myList = new IntList();
		for (int i = 0; i <= 51; i++) {
			myList->push_back(i);
		}
		deckList = *myList;
	}

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
	void Deck::shuffle(){
		IntList* deckA = new IntList();
		IntList* deckB = new IntList();
		
		cut(deckA,deckB);

		bool takeA = true;             //Used to switch decks on shuffes. 
		int index = 0;      //had this named as "i" //Not actually main problem Chi^2              
		int cardsA = 26;
		int cardsB = 26;

		while (index < 52) {
			//Deck A grabs
			if (takeA == true && deckA->isEmpty()!=true){
				int cardsToMove = rand()%3;
				if (cardsA-cardsToMove<0){ cardsToMove-=1; }
				if (cardsToMove != 0) {
					IntListNode* endTakeA = deckA->tail();
					IntListNode* startTakeA = endTakeA;
					for (int i = 0; i<cardsToMove - 1; i++){
						startTakeA = startTakeA->prev;
					}
					splice(startTakeA, endTakeA, deckList.getSentinel()->prev);
					index += cardsToMove;
					cardsA -= cardsToMove;
			    }
			}
			else if(takeA == false && deckB->isEmpty() != true) {
				int cardsToMove = rand() % 3;
				if (cardsB - cardsToMove<0){ cardsToMove -= 1;}
				if (cardsToMove != 0){
					IntListNode* endTakeB = deckB->tail();
					IntListNode* startTakeB = endTakeB;
					for (int i = 0; i < cardsToMove - 1; i++){
						startTakeB = startTakeB->prev;
					}
					splice(startTakeB, endTakeB, deckList.getSentinel()->prev);
					index += cardsToMove;
					cardsB -= cardsToMove;
				}
			}
			takeA = !takeA; //Switches bool to move from top to bottom.
		}
		delete deckA;
		delete deckB;
	}

	// This function returns the head of deckList
	IntListNode* Deck::getListHead(){
		return deckList.head();
	}

	/*
	* This function should take the contents of the deckList and split it into two lists for
	* shuffling. The first 26 items in deckList should end up in A, the other 26 items should end
	* up in B. The splice function may be useful here.
	*/
	void Deck::cut(IntList* A, IntList* B){
		IntListNode* aDeck = deckList.getSentinel()->next;
		IntListNode* lastTop = aDeck;
		for (int i = 0; i < 25; i++) {
			lastTop = lastTop->next;
			int number = lastTop->data;
		}

		IntListNode* bDeck = lastTop->next;
		IntListNode* lastBot = deckList.tail();

		splice(aDeck, lastTop, A->getSentinel());
		splice(bDeck, lastBot, B->getSentinel());

	}

