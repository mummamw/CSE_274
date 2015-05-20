#include "IntList.h"
#include <iostream>

using namespace std;

IntListNode::IntListNode(){
	data = -1;
	next = this;
	prev = this;
}

IntList::IntList(){
	//Remember to use node to start
	IntListNode* dummyNode = new IntListNode();  
	sentinel = dummyNode;
}

IntList::~IntList(){
	clear();
	delete sentinel;
}

void IntList::pop_back(){ //slower way maybe but seems to help
	if (sentinel->prev != sentinel){
		IntListNode* lastNode = sentinel->prev;
		IntListNode* newLast = sentinel->prev->prev;
		sentinel->prev = newLast;
		newLast->next = sentinel;
		delete lastNode;
	}
}

bool IntList::isEmpty(){
	if (sentinel->next==sentinel) { return true; }
	return false;
}

void IntList::clear(){
	while (!isEmpty()){
		pop_back();
	}
}

void IntList::push_back(int c){
	IntListNode* n = new IntListNode();
	n->data = c;
	splice(n, n, sentinel->prev);		//using new splice function
}

//changing after realizing function was running 100 times then failing
void splice(IntListNode* sourceStart, IntListNode* sourceEnd, IntListNode* target){
	IntListNode* tempStart;
	IntListNode* tempEnd;
	IntListNode* tempTarget;

	tempStart = sourceStart->prev;
	tempEnd = sourceEnd->next;

	tempStart->next = tempEnd;
	tempEnd->prev = tempStart;

	tempTarget = target->next;
	sourceEnd->next = tempTarget;
	sourceStart->prev = target;

	target->next = sourceStart;
	tempTarget->prev = sourceEnd;

	/*
	IntListNode* oldTargetNext = target->next;
	IntListNode* sourceStartPrev = sourceStart->prev;
	IntListNode* sourceEndNext = sourceEnd->next;

	//Splice into target
	sourceEnd->next = target->next;
	sourceStart->prev = target;
	target->next = sourceStart;
	oldTargetNext->prev = sourceEnd;

	//Splice out of old list
	sourceStartPrev->next = sourceEndNext;
	sourceEndNext->prev = sourceStartPrev;
	*/
}

IntListNode* IntList::head(){
	if (isEmpty()){
		return 0;
	}
	else{
		return sentinel->next;
	}
}

IntListNode* IntList::tail(){
	if (isEmpty()){
		return 0;
	}
	else{
		return sentinel->prev;
	}
}

IntListNode* IntList::getSentinel(){
	return sentinel;
}

void IntList::printList() {
	IntListNode* cur = sentinel->next;
	while (cur != sentinel) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}
