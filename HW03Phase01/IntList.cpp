//Michael Mumma

#include "IntList.h"
#include <iostream>
using namespace std;

IntListNode::IntListNode(){
		next = this;
		prev = this;
		data = -1;
}

void splice(IntListNode* sourceStart, IntListNode* sourceEnd, IntListNode* target){
	sourceStart->prev->next = sourceEnd->next;
	sourceEnd->next->prev = sourceStart->prev;

	sourceEnd->next = target->next;
	sourceStart->prev = target;

	target->next = sourceStart;
	sourceEnd->next->prev = sourceEnd;
}

IntList::IntList(){
	sentinel = new IntListNode;
}

IntList::~IntList(){
	clear();
	delete sentinel;
}

void IntList::push_back(int i){
	IntListNode *u = new IntListNode;    //creates node
	u->data = i;

	u->prev = sentinel->prev;            //sets node to back
	u->next = sentinel;

	u->next->prev = u;                  //points old nodes to reconize new node
	u->prev->next = u;
}

void IntList::pop_back(){
	IntListNode *u;
	u = tail();
	if (isEmpty()) return;
	u->prev->next = u->next;
	u->next->prev = u->prev;
}

void IntList::clear(){
	while(!isEmpty()){ pop_back();}
}

bool IntList::isEmpty(){
	if (sentinel->next == sentinel) return true;
	return false;                
}


//
IntListNode* IntList::head() {  
	if (isEmpty()) return NULL;
	return sentinel->next;            
}
IntListNode* IntList::tail() {
	if (isEmpty()) return NULL;
	return sentinel->prev; 
}
IntListNode* IntList::getSentinel() { 
	return sentinel; 
}

void IntList::printList(){
	IntListNode* u = new IntListNode;  
	u->next = sentinel->next;          
	
	while (u != sentinel) {
		cout << u->data << " ";
	}

	delete u;                         
}
