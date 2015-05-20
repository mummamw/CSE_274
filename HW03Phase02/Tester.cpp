/*****
 * Author   : brinkmwj
 * Date     : 2009-07-23
 * Modified : inclezd (2/10/2015)
 * Sources  : All code is original
 * Purpose  : The Tester class is used to test your IntList implementation.
 * Note     : DO NOT CHANGE THIS FILE!!! Also, you might want to look over my approach
 *            to code testing, or even copy and paste from this file, for testing in future
 *            assignments.
 *****/
#include "Tester.h"
#include <CRTDBG.H>

void Tester::doTests(){
	testNodeCtor();
	testListCtor();

	testIsEmptyYes();
	testIsEmptyNo();
	
	testGetSentinel();
	testGetHeadEmpty();
	testGetTailEmpty();
	testGetHeadNormal();
	testGetTailNormal();

	testPushBackEmpty();
	testPushBackOne();
	testPushBackTwo();

	testPopBackEmpty();
	testPopBackOne();
	testPopBackTwo();

	testClearEmpty();
	testClearOne();
	testClearTwo();

	testSplice();
}

void Tester::testNodeCtor(){
	IntListNode testNodeCtor_t;
	_ASSERTE(testNodeCtor_t.data == -1);
	_ASSERTE(testNodeCtor_t.next == &testNodeCtor_t);
	_ASSERTE(testNodeCtor_t.prev == &testNodeCtor_t);
}

void Tester::testListCtor(){
	IntList testListCtor_t;
	_ASSERTE(testListCtor_t.sentinel != NULL);
	_ASSERTE(testListCtor_t.sentinel->data == -1);
	_ASSERTE(testListCtor_t.sentinel->next == testListCtor_t.sentinel);
	_ASSERTE(testListCtor_t.sentinel->prev == testListCtor_t.sentinel);
}

void Tester::testIsEmptyYes(){
	IntList* testIsEmptyYes_t = new IntList();
	_ASSERTE(testIsEmptyYes_t->isEmpty() == 1);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testIsEmptyNo(){
	IntList* testIsEmptyNo_t = new IntList();
	IntListNode* newNode = new IntListNode();
	newNode->data = 5;
	newNode->prev = testIsEmptyNo_t->sentinel;
	newNode->next = testIsEmptyNo_t->sentinel;
	testIsEmptyNo_t->sentinel->next = newNode;
	testIsEmptyNo_t->sentinel->prev = newNode;
	//At this point I have a list of length 1 that I have built by hand.
	_ASSERTE(testIsEmptyNo_t->isEmpty() == 0);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testGetSentinel(){
	IntList* testGetSentinel_t = new IntList();
	_ASSERTE(testGetSentinel_t->getSentinel() == testGetSentinel_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testGetHeadEmpty(){
	IntList* testGetHeadEmpty_t = new IntList();
	_ASSERTE(testGetHeadEmpty_t->head() == 0);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testGetTailEmpty(){
	IntList* testGetTailEmpty_t = new IntList();
	_ASSERTE(testGetTailEmpty_t->tail() == 0);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testGetHeadNormal(){
	IntList* testGetHeadNormal_t = new IntList();
	IntListNode* newNode1 = new IntListNode();
	IntListNode* newNode2 = new IntListNode();
	newNode1->data = 1;
	newNode2->data = 2;

	newNode1->prev = testGetHeadNormal_t->sentinel;
	newNode1->next = newNode2;

	newNode2->prev = newNode1;
	newNode2->next = testGetHeadNormal_t->sentinel;

	testGetHeadNormal_t->sentinel->next = newNode1;
	testGetHeadNormal_t->sentinel->prev = newNode2;
	//At this point I have a list of length 2 that I have built by hand.
	_ASSERTE(testGetHeadNormal_t->head() == newNode1);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testGetTailNormal(){
	IntList* testGetTailNormal_t = new IntList();
	IntListNode* newNode1 = new IntListNode();
	IntListNode* newNode2 = new IntListNode();
	newNode1->data = 1;
	newNode2->data = 2;

	newNode1->prev = testGetTailNormal_t->sentinel;
	newNode1->next = newNode2;

	newNode2->prev = newNode1;
	newNode2->next = testGetTailNormal_t->sentinel;

	testGetTailNormal_t->sentinel->next = newNode1;
	testGetTailNormal_t->sentinel->prev = newNode2;
	//At this point I have a list of length 2 that I have built by hand.
	_ASSERTE(testGetTailNormal_t->tail() == newNode2);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testPushBackEmpty(){
	IntList* testPushBackEmpty_t = new IntList();
	testPushBackEmpty_t->push_back(15);
	
	_ASSERTE(testPushBackEmpty_t->sentinel->next->data == 15);
	_ASSERTE(testPushBackEmpty_t->sentinel->data == -1);

	_ASSERTE(testPushBackEmpty_t->sentinel->next->next == testPushBackEmpty_t->sentinel);
	_ASSERTE(testPushBackEmpty_t->sentinel->prev->prev == testPushBackEmpty_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testPushBackOne(){
	IntList* testPushBackOne_t = new IntList();
	IntListNode* newNode = new IntListNode();
	newNode->data = 5;
	newNode->prev = testPushBackOne_t->sentinel;
	newNode->next = testPushBackOne_t->sentinel;
	testPushBackOne_t->sentinel->next = newNode;
	testPushBackOne_t->sentinel->prev = newNode;

	testPushBackOne_t->push_back(15);

	_ASSERTE(testPushBackOne_t->sentinel->next->next->data == 15);
	_ASSERTE(testPushBackOne_t->sentinel->next->data == 5);
	_ASSERTE(testPushBackOne_t->sentinel->prev->data == 15);
	_ASSERTE(testPushBackOne_t->sentinel->data == -1);

	_ASSERTE(testPushBackOne_t->sentinel->next == newNode);
	_ASSERTE(testPushBackOne_t->sentinel->prev->prev == newNode);
	_ASSERTE(testPushBackOne_t->sentinel->next->next->next == testPushBackOne_t->sentinel);
	_ASSERTE(testPushBackOne_t->sentinel->prev->prev->prev == testPushBackOne_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testPushBackTwo(){
	IntList* testPushBackTwo_t = new IntList();
	IntListNode* newNode1 = new IntListNode();
	IntListNode* newNode2 = new IntListNode();
	newNode1->data = 1;
	newNode2->data = 2;

	newNode1->prev = testPushBackTwo_t->sentinel;
	newNode1->next = newNode2;

	newNode2->prev = newNode1;
	newNode2->next = testPushBackTwo_t->sentinel;

	testPushBackTwo_t->sentinel->next = newNode1;
	testPushBackTwo_t->sentinel->prev = newNode2;

	testPushBackTwo_t->push_back(15);

	_ASSERTE(testPushBackTwo_t->sentinel->next->next->next->data == 15);
	_ASSERTE(testPushBackTwo_t->sentinel->next->data == 1);
	_ASSERTE(testPushBackTwo_t->sentinel->data == -1);
	_ASSERTE(testPushBackTwo_t->sentinel->next->next->data == 2);
	_ASSERTE(testPushBackTwo_t->sentinel->prev->data == 15);
	_ASSERTE(testPushBackTwo_t->sentinel->prev->prev->data == 2);
	_ASSERTE(testPushBackTwo_t->sentinel->prev->prev->prev->data == 1);

	_ASSERTE(testPushBackTwo_t->sentinel->next == newNode1);
	_ASSERTE(testPushBackTwo_t->sentinel->next->next == newNode2);
	_ASSERTE(testPushBackTwo_t->sentinel->prev->prev == newNode2);
	_ASSERTE(testPushBackTwo_t->sentinel->prev->prev->prev == newNode1);
	_ASSERTE(testPushBackTwo_t->sentinel->next->next->next->next == testPushBackTwo_t->sentinel);
	_ASSERTE(testPushBackTwo_t->sentinel->prev->prev->prev->prev == testPushBackTwo_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testPopBackEmpty(){
	IntList* testPopBackEmpty_t = new IntList();
	testPopBackEmpty_t->pop_back();
	_ASSERTE(testPopBackEmpty_t->sentinel->next == testPopBackEmpty_t->sentinel);
	_ASSERTE(testPopBackEmpty_t->sentinel->prev == testPopBackEmpty_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testPopBackOne(){
	IntList* testPopBackOne_t = new IntList();
	IntListNode* newNode = new IntListNode();
	newNode->data = 5;
	newNode->prev = testPopBackOne_t->sentinel;
	newNode->next = testPopBackOne_t->sentinel;
	testPopBackOne_t->sentinel->next = newNode;
	testPopBackOne_t->sentinel->prev = newNode;

	testPopBackOne_t->pop_back();

	_ASSERTE(testPopBackOne_t->sentinel->next == testPopBackOne_t->sentinel);
	_ASSERTE(testPopBackOne_t->sentinel->prev == testPopBackOne_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testPopBackTwo(){
	IntList* testPopBackTwo_t = new IntList();
	IntListNode* newNode1 = new IntListNode();
	IntListNode* newNode2 = new IntListNode();
	newNode1->data = 1;
	newNode2->data = 2;

	newNode1->prev = testPopBackTwo_t->sentinel;
	newNode1->next = newNode2;

	newNode2->prev = newNode1;
	newNode2->next = testPopBackTwo_t->sentinel;

	testPopBackTwo_t->sentinel->next = newNode1;
	testPopBackTwo_t->sentinel->prev = newNode2;

	testPopBackTwo_t->pop_back();

	_ASSERTE(testPopBackTwo_t->sentinel->next->data == 1);
	_ASSERTE(testPopBackTwo_t->sentinel->prev->data == 1);
	_ASSERTE(testPopBackTwo_t->sentinel->prev->prev->data == -1);

	_ASSERTE(testPopBackTwo_t->sentinel->next == newNode1);
	_ASSERTE(testPopBackTwo_t->sentinel->prev == newNode1);
	_ASSERTE(testPopBackTwo_t->sentinel->prev->prev == testPopBackTwo_t->sentinel);
	_ASSERTE(testPopBackTwo_t->sentinel->next->next == testPopBackTwo_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testClearEmpty(){
	IntList* testClearEmpty_t = new IntList();
	testClearEmpty_t->clear();
	_ASSERTE(testClearEmpty_t->sentinel->next == testClearEmpty_t->sentinel);
	_ASSERTE(testClearEmpty_t->sentinel->prev == testClearEmpty_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testClearOne(){
	IntList* testClearOne_t = new IntList();
	IntListNode* newNode = new IntListNode();
	newNode->data = 5;
	newNode->prev = testClearOne_t->sentinel;
	newNode->next = testClearOne_t->sentinel;
	testClearOne_t->sentinel->next = newNode;
	testClearOne_t->sentinel->prev = newNode;

	testClearOne_t->clear();

	_ASSERTE(testClearOne_t->sentinel->next == testClearOne_t->sentinel);
	_ASSERTE(testClearOne_t->sentinel->prev == testClearOne_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testClearTwo(){
	IntList* testClearTwo_t = new IntList();
	IntListNode* newNode1 = new IntListNode();
	IntListNode* newNode2 = new IntListNode();
	newNode1->data = 1;
	newNode2->data = 2;

	newNode1->prev = testClearTwo_t->sentinel;
	newNode1->next = newNode2;

	newNode2->prev = newNode1;
	newNode2->next = testClearTwo_t->sentinel;

	testClearTwo_t->sentinel->next = newNode1;
	testClearTwo_t->sentinel->prev = newNode2;

	testClearTwo_t->clear();

	_ASSERTE(testClearTwo_t->sentinel->next == testClearTwo_t->sentinel);
	_ASSERTE(testClearTwo_t->sentinel->prev == testClearTwo_t->sentinel);
	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}

void Tester::testSplice(){
	IntList* testSplice1 = new IntList();
	IntListNode* newNode1 = new IntListNode();
	IntListNode* newNode2 = new IntListNode();
	IntListNode* newNode3 = new IntListNode();
	newNode1->data = 1;
	newNode2->data = 2;
	newNode3->data = 3;

	newNode1->prev = testSplice1->sentinel;
	newNode1->next = newNode2;

	newNode2->prev = newNode1;
	newNode2->next = newNode3;

	newNode3->prev = newNode2;
	newNode3->next = testSplice1->sentinel;

	testSplice1->sentinel->prev = newNode3;
	testSplice1->sentinel->next = newNode1;

	IntList* testSplice2 = new IntList();
	IntListNode* newNode4 = new IntListNode();
	newNode4->data = 4;

	newNode4->prev = testSplice2->sentinel;
	newNode4->next = testSplice2->sentinel;

	testSplice2->sentinel->prev = newNode4;
	testSplice2->sentinel->next = newNode4;

	// call splice
	splice(newNode1, newNode2, testSplice2->sentinel);

	_ASSERTE(testSplice1->sentinel->next->data == 3);
	_ASSERTE(testSplice1->sentinel->next->next->data == -1);
	_ASSERTE(testSplice1->sentinel->prev->data == 3);
	_ASSERTE(testSplice1->sentinel->prev->prev->data == -1);

	_ASSERTE(testSplice2->sentinel->next->data == 1);
	_ASSERTE(testSplice2->sentinel->next->next->data == 2);
	_ASSERTE(testSplice2->sentinel->next->next->next->data == 4);
	_ASSERTE(testSplice2->sentinel->next->next->next->next->data == -1);
	_ASSERTE(testSplice2->sentinel->prev->data == 4);
	_ASSERTE(testSplice2->sentinel->prev->prev->data == 2);
	_ASSERTE(testSplice2->sentinel->prev->prev->prev->data == 1);
	_ASSERTE(testSplice2->sentinel->prev->prev->prev->prev->data == -1);

	_ASSERTE(testSplice1->sentinel->next == newNode3);
	_ASSERTE(testSplice1->sentinel->next->next == testSplice1->sentinel);
	_ASSERTE(testSplice1->sentinel->prev == newNode3);
	_ASSERTE(testSplice1->sentinel->prev->prev == testSplice1->sentinel);

	_ASSERTE(testSplice2->sentinel->next == newNode1);
	_ASSERTE(testSplice2->sentinel->next->next == newNode2);
	_ASSERTE(testSplice2->sentinel->next->next->next == newNode4);
	_ASSERTE(testSplice2->sentinel->next->next->next->next == testSplice2->sentinel);
	_ASSERTE(testSplice2->sentinel->prev == newNode4);
	_ASSERTE(testSplice2->sentinel->prev->prev == newNode2);
	_ASSERTE(testSplice2->sentinel->prev->prev->prev == newNode1);
	_ASSERTE(testSplice2->sentinel->prev->prev->prev->prev == testSplice2->sentinel);

	//Note: I am INTENTIONALLY leaking memory here, because I do not want
	// the destructor to get called.
}
