/*****
 * Author   : brinkmwj
 * Date     : 2009-07-23
 * Sources  : All code is original
 * Purpose  : The Tester class is used to test your IntList implementation.
 * Note     : DO NOT CHANGE THIS FILE!!!
 *****/
#pragma once
#include "IntList.h"

class Tester{
public:
	void doTests();

public:
	void testNodeCtor();
	void testListCtor();
	/* Note that it is QUITE difficult to test the destructor directly in this way (using unit tests).
	 * For this reason, most professional software developers use Valgrind, or similar tools, to test
	 * their code for memory leaks. Another good practice is to keep the destructor VERY simple, having it
	 * call helper functions to actually do the deleting ... this is a little easier to test, because then
	 * you can test your helper functions without destroying the class instance itself. */
	void testIsEmptyYes();
	void testIsEmptyNo();

	void testGetSentinel();
	void testGetHeadEmpty();
	void testGetTailEmpty();
	void testGetHeadNormal();
	void testGetTailNormal();

	void testPushBackEmpty();
	void testPushBackOne();
	void testPushBackTwo();

	void testPopBackEmpty();
	void testPopBackOne();
	void testPopBackTwo();

	void testClearEmpty();
	void testClearOne();
	void testClearTwo();

	void testSplice();
};