#include "Trends.h"

class MyTrends : public Trends {
	
public:
	//constructors 
	MyTrends();

	virtual ~MyTrends();

	//Hashing for more points 
	int hash(string word, int n);

	/*
	* If the string "s" has not been added to the data structure yet, add it, and set its count to "amount"
	* If the string "s" already has an entry in your data structure, just increase the count by "amount"
	*
	* Usually, "amount" will be equal to 1. See Controller.cpp for an example of how increaseCount is used.
	*/
	virtual void increaseCount(string s, int amount);

	/*
	* Return the count for the given string.
	*/
	virtual int getCount(string s);

	/*
	* Return the nth most popular item, based on its count (0 = most popular, 1 = 2nd most popular).
	* If there is a tie, return the string that comes first according to the the < operator for strings
	* (that is, comes first alphabetically).
	*/
	virtual string getNthPopular(int n);

	/*
	* Return the total number of UNIQUE strings in the list. This will NOT be equal to the number of
	* times increaseCount has been called, because sometimes you will add the same string to the
	* data structure more than once. This function is useful when looping through the results
	* using getNthPopular. If you do getNthPopular(numEntries()-1), it should get the least popular item.
	*/
	virtual int numEntries();

private: 
	pair<string, int> *hashTable;
	int CurSize;
	int sizeTable;
	int numOfEntries;
};
