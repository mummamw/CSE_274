/*****
 * Author   : brinkmwj
 * Date     : 2009-07-23
 * Modified : inclezd (2/10/2015)
 * Sources  : All code is original
 * Purpose  : The IntList class implements a linked list of integers, as described by our textbook.
 *            This file also declares IntListNode, which is a class that represents a single node of
 *            an IntList, and a stand-alone function called splice that will be useful in Phase02.
 * Note     : DO NOT CHANGE THIS FILE!!! All code should be in you IntList.cpp
 *****/

#pragma once
#include "Tester.h"

/*
 * When you have a pointer variable that is not pointing to anything, you should always set it to NULL.
 * Before you use a pointer, you should always assert that it is != NULL. That way you will avoid one of
 * the number one pitfalls of C++: Losing track of which pointers are valid!
 */
#define NULL 0

/*
 * The node class is what actually makes up the list. The IntListNode class works together
 * with the list class: The IntList class function simply manipulates nodes in order to
 * make the necessary modifications to the list.
 */
class IntListNode {
public:
	/*
	 * Initialize data to -1, and also initialize prev and next. See Section 3.1.1 of the textbook if you
	 * don't know what prev and next should be initialized to.
	 */
	IntListNode();

	int data; //IntList is a list of integers, so our data member for IntListNode is an int

	//Every node also needs a pointer to the next item in the list, and a pointer to the previous item
	IntListNode* prev;
	IntListNode* next;
};

/*
 * Splice is definied on page 62 of the textbook. Note that it is not very hard to translate
 * the book's code into C++. You should not, however, call your variables things
 * like "a" and "b" ... that is really confusing, and terrible style!
 *
 * Note that splice is not a member function of IntList, but a separate function. The purpose of splice
 * is to take two lists, and perform surgery on them to move one chunk of list from one list to another.
 * Please see the assertions on page 62 ... you will notice that there are a lot of conditions that must
 * hold in order for splicing to be safe!
 *
 * Comment for Phase02: Splice can be very helpful in implementing the shuffle and cut methods of Deck in Phase02.
 */
void splice(IntListNode* sourceStart, IntListNode* sourceEnd, IntListNode* target);

class IntList {
public:
	/*
	 * Every list class must have a dummy node. This constructor should create
	 * the dummy node using the "new" operator, and set "sentinel" to point to it.
	 */
	IntList();

	/*
	 * The destructor needs to make sure all memory used by the list is deallocated using
	 * the "delete" operator. You may find it easiest to first call clear(), and then
	 * delete the dummy node afterward.
	 */
	~IntList();

	/*
	 * Purpose: Create a new node using new, set its data to be the same value as i, and then
	 *          attach it to the end of the list. You can use splice for this, or you could try to do
	 *          it more simply by directly grafting the new node into the list between sentinel->prev and
	 *          sentinel
	 */
	void push_back(int i);

	/*
	 * Purpose: Delete the last node from the list. This means first performing list surgery to graft
	 *          the node out of the list, and THEN deleting it with the "delete" operator. Again, you
	 *          may choose to use splice, or you can write pop_back from scratch.
	 * Special case: If the only node left in the list is the dummy node, do NOT delete it!
	 */
	void pop_back();

	/*
	 * Purpose: Delete all nodes in the list EXCEPT the dummy node. isEmpty() and pop_back() might be helpful here.
	 */
	void clear();

	/*
	 * Purpose: Return true if (and only if) the dummy node is the only node in the list.
	 */
	bool isEmpty();
	
	/*
	 * Purpose: These three functions allow the user to get handles for nodes in our list.
	 *          getSentinel() should return a pointer to the dummy node. head() should return
	 *          sentinel->next, UNLESS the list is empty ... in that case return NULL.
	 *          tail() should return sentinel->prev, unless the list is empty ... in that case return NULL.
	 */
	IntListNode* head();
	IntListNode* tail();
	IntListNode* getSentinel();

	/*
	 * Purpose: Prints the elements of the list separated by a blank space.
	 *          For instance, if the list contains the numbers 1, 2, and 3 in this order
	 *          then the output should be:
	 *          1 2 3
	 */
	void printList();

private:
	/*
	 * Sentinel always points to the "dummy" item of the list.
	 * The user should never need to change this, so we make it private
	 */
	IntListNode* sentinel;

	friend class Tester;
};
