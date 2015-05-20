/*Michael Mumma
*Easter Sunday 
*/
#include "MyTrends.h"
#include <string>



MyTrends::MyTrends(){
	int size = 3407;
	hashTable = new pair<string, int>[size];
	sizeTable = size;
	for (int i = 0; i < sizeTable; i++){			//Moving through making everything 0
		hashTable[i].second = 0;                    //0 for emtpy
	}
	numOfEntries = 0;                               //This part is actually simple just add and subtract
}

MyTrends::~MyTrends(){
	delete[] hashTable;
}

int hasher(string word, int n){ //terrible name 

	int len = word.length();
	int value = 0;           //Being returned
	for (int i = 0; i < len; i++){
		value = (256 * value + (int)word[i] % n);
	}
	                                              //Function uses the 256 charters as the a part
	return value;
}

/* member variables and methods declared here */

/*
* If the string "s" has not been added to the data structure yet, add it, and set its count to "amount"
* If the string "s" already has an entry in your data structure, just increase the count by "amount"
*
* Usually, "amount" will be equal to 1. See Controller.cpp for an example of how increaseCount is used.
*/
void MyTrends::increaseCount(string s, int amount){
	int hash = hasher(s , amount);
	if (hashTable[hash].second == 0 || hashTable[hash].second == -1){  //Checks for empty and previosly deleted
		hashTable[hash].first = s;
		hashTable[hash].second = amount;
		numOfEntries += 1;
	}
	else if (s.compare(hashTable[hash].first) == 0) {
		hashTable[hash].second += amount;
	}
}

/*
* Return the count for the given string.
*/
int MyTrends::getCount(string s){
	int count = 0;
	int hash = hasher(s, sizeTable);
	return hashTable[hash].second; //does not take into account for moved values/keys?
}

/*
* Return the nth most popular item, based on its count (0 = most popular, 1 = 2nd most popular).
* If there is a tie, return the string that comes first according to the the < operator for strings
* (that is, comes first alphabetically).
*/
string MyTrends::getNthPopular(int n){
	int rando = rand() % sizeTable;
	return hashTable[rando].first; //just to work for now.
}

/*
* Return the total number of UNIQUE strings in the list. This will NOT be equal to the number of
* times increaseCount has been called, because sometimes you will add the same string to the
* data structure more than once. This function is useful when looping through the results
* using getNthPopular. If you do getNthPopular(numEntries()-1), it should get the least popular item.
*/
int MyTrends::numEntries(){
	return numOfEntries;
}


