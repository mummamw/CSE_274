//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Modified by Daniela Inclezan

#include "Dictionary.h"
#include <iostream>

using namespace std;

template <class Key, class Value>
class BSTNode {
public:
  BSTNode();
  BSTNode(Key k, Value v);

  Key k;
  Value v;
  BSTNode* left;
  BSTNode* right;
};

template <class Key, class Value>
class BST : public Dictionary<Key,Value> {
public:
  BST();
  ~BST();

  /***
   * Return the number of items currently in the Dictionary.
   ***/
  virtual unsigned long size();

  /*** 
   * Add a new entry with key k and value v.
   * If an item with key k already exists, overwrite it.
   ***/
  virtual void insert(Key k, Value v);

  /***
   * Remove the entry with key k. 
   * If there is no such item, do nothing.
   ***/
  virtual void remove(Key k);

  /***
   * Return the value of the entry with key k. 
   * If there is no such item, throw an exception.
   ***/
  virtual Value find(Key k);

  /***
   * Return true if there is an entry with key k in the dictionary. 
   * If not, return false.
   ***/
  virtual bool keyExists(Key k);

  /***
   * If there is a key in the set that is > k, return the first such key. 
   * If not, return k.
   ***/
  virtual Key next(Key k);

  /***
   * If there is a key in the set that is < k, return the first such key. 
   * If not, return k.
   ***/
  virtual Key prev(Key k);


  /***
   * The following additional functions print the tree using
   * pre-order, in-order, and post-order traversals, respectively.
   * Print each entry r using the statement:
   *   cout << "(" << r->k << "," << r->v << ") ";
   ***/
  virtual void printPreOrder();
  virtual void printInOrder();
  virtual void printPostOrder();


private:
  BSTNode<Key,Value>* root;

  /*** 
   * These are the recursive versions of each of your public member functions. 
   * You should return the address of the new root node, 
   * whether or not the root node changes.
   ***/
  virtual unsigned long sizeHelper(BSTNode<Key,Value>* r);
  virtual BSTNode<Key,Value>* insertHelper(BSTNode<Key,Value>* r, Key k, Value v);
  virtual BSTNode<Key,Value>* removeHelper(BSTNode<Key,Value>* r, Key k);
  virtual BSTNode<Key,Value>* findHelper(BSTNode<Key,Value>* r, Key k);
  virtual BSTNode<Key,Value>* nextHelper(BSTNode<Key,Value>* r, Key k);
  virtual BSTNode<Key,Value>* prevHelper(BSTNode<Key,Value>* r, Key k);
  virtual void printPreOrderHelper(BSTNode<Key,Value>* r);
  virtual void printInOrderHelper(BSTNode<Key,Value>* r);
  virtual void printPostOrderHelper(BSTNode<Key,Value>* r);


  /***
   * The following two are just some helper functions.
   ***/

  /***
   * Find the item in the sub-tree rooted at r which has the smallest key.
   ***/
  virtual BSTNode<Key,Value>* min(BSTNode<Key,Value>* r);

  /*** 
   * Find the item in the sub-tree rooted at r which has the largest key.
   ***/
  virtual BSTNode<Key,Value>* max(BSTNode<Key,Value>* r);
};


#include "BST.ipp"

