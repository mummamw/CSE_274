//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Modified by Daniela Inclezan on 04/06/2015

#include <iostream>
#include <string>

using namespace std;

class BSTNode {
public:
  BSTNode();
  BSTNode(int myK, string myV);

  int k;
  string v;
  BSTNode* left;
  BSTNode* right;
};

class BST {
public:
  BST();
  ~BST();

  /***
   * Return the number of items currently in the BST.
   ***/
  unsigned long size();

  /*** 
   * Add a new entry with key k and value v.
   * If an item with key k already exists, overwrite it.
   ***/
  void insert(int k, string v);

  /***
   * Remove the entry with key k. 
   * If there is no such item, do nothing.
   ***/
  void remove(int k);

  /***
   * Return the value of the entry with key k. 
   * If there is no such item, throw an exception.
   ***/
  string find(int k);

  /***
   * Return true if there is an entry with key k in the BST. 
   * If not, return false.
   ***/
  bool intExists(int k);

  /***
   * If any of the entries in the BST has a key greater than k, 
   * return the smallest such key.
   * If not, return k.
   ***/
  int next(int k);

  /***
   * If any of the entries in the BST has a key smaller than k, 
   * return the greatest such key.
   * If not, return k.
   ***/
  int prev(int k);


  /***
   * The following additional functions print the tree using
   * pre-order, in-order, and post-order traversals, respectively.
   * Print each entry r using the statement:
   *   cout << "(" << r->k << "," << r->v << ") ";
   ***/
  void printPreOrder();
  void printInOrder();
  void printPostOrder();


private:
  BSTNode* root;

  /*** 
   * These are the recursive versions of each of your public member functions. 
   * You should return the address of the new root node, 
   * whether or not the root node changes.
   ***/
  unsigned long sizeHelper(BSTNode* r);
  BSTNode* insertHelper(BSTNode* r, int k, string v);
  BSTNode* removeHelper(BSTNode* r, int k);
  BSTNode* findHelper(BSTNode* r, int k);
  BSTNode* nextHelper(BSTNode* r, int k);
  BSTNode* prevHelper(BSTNode* r, int k);
  void printPreOrderHelper(BSTNode* r);
  void printInOrderHelper(BSTNode* r);
  void printPostOrderHelper(BSTNode* r);


  /***
   * The following two are just some helper functions.
   ***/

  /***
   * Find the item in the sub-tree rooted at r which has the smallest kry.
   ***/
  BSTNode* min(BSTNode* r);

  /*** 
   * Find the item in the sub-tree rooted at r which has the largest key.
   ***/
  BSTNode* max(BSTNode* r);
};


