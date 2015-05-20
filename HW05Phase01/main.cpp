#include <string>
#include <iostream>
#include "BST.h"

using namespace std;

void myTests() {
	BST myTree;

	// INSERT
	cout << "INSERT" << endl;
	myTree.insert(20,"1");
	myTree.insert(10,"2");
	myTree.insert(30,"3");
	myTree.insert(27,"4");
	myTree.insert(35,"5");
	myTree.insert(21,"6");
	myTree.insert(13,"7");
	myTree.printInOrder();
	cout << endl;

	// PRINT 
	cout << "PRE-ORDER: " << endl;
	myTree.printPreOrder();
	cout << endl;

	cout << "POST-ORDER: " << endl;
	myTree.printPostOrder();
	cout << endl;

	// REMOVE - 4 tests
	cout << "REMOVE" << endl;

	cout << "Remove 13" << endl;
	myTree.remove(13);
	myTree.printInOrder();
	cout << endl;

	cout << "Remove 27" << endl;
	myTree.remove(27);
	myTree.printInOrder();
	cout << endl;

	cout << "Remove 30" << endl;
	myTree.remove(30);
	myTree.printInOrder();
	cout << endl;

	cout << "Remove 30" << endl;
	myTree.remove(30);
	myTree.printInOrder();
	cout << endl;

	// FIND
	cout << "FIND" << endl;
	cout << "Find 10: " << myTree.find(10) << endl;
	cout << "Find 25: " << myTree.find(25) << endl;
	cout << endl;

	// NEXT
	cout << "NEXT" << endl;
	cout << "Next 10: " << myTree.next(10) << endl;
	cout << "Next 20: " << myTree.next(20) << endl;
	cout << "Next 35: " << myTree.next(35) << endl;
	cout << endl;

	// PREV
	cout << "PREV" << endl;
	cout << "Prev 10: " << myTree.prev(10) << endl;
	cout << "Prev 20: " << myTree.prev(20) << endl;
	cout << "Prev 35: " << myTree.prev(35) << endl;
	cout << endl;

	// SIZE
	cout << "SIZE: " << myTree.size() << endl;
}


int main() {
    string exp = "Node not found";

    try{
        myTests();
    }
    catch (string exception) {
        cout << exp << endl;
    }

	return 0;
}