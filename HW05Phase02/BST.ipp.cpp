#include <string>
#include "BST.h"
#include <iostream>

#define NULL 0

template <class Key, class Value>
BSTNode<Key,Value>::BSTNode(){
    k = -1;
    v = "";
    left = NULL;
    right = NULL;
}

template <class Key, class Value>
BSTNode<Key,Value>::BSTNode(Key kk, Value vv){
    k = myK;
    v = myV;
    left = NULL;
    right = NULL;
}




template <class Key, class Value>
BST<Key,Value>::BST(){
    root = NULL;
}



template <class Key, class Value>
BST<Key,Value>::~BST(){
    while (root != NULL) {
        remove(root->k);
    }
    delete root;
    root = NULL;
}
  

/***
 * Return the number of items currently in the Dictionary.
 ***/
template <class Key, class Value>
unsigned long BST<Key,Value>::size(){
    return sizeHelper(root);
}

template <class Key, class Value>
unsigned long BST<Key,Value>::sizeHelper(BSTNode<Key,Value>* r){
    if (r == NULL) return 0;
    return 1 + sizeHelper(r->left) + sizeHelper(r->right);
}



/*** 
 * Add a new entry with key k and value v.
 * If an item with key k already exists, overwrite it.
 ***/
template <class Key, class Value>
void BST<Key,Value>::insert(Key k, Value v){
    root = insertHelper(root, k, v);
}

template <class Key, class Value>
BSTNode<Key,Value>* BST<Key,Value>::insertHelper(BSTNode<Key,Value>* r, Key k, Value v){
    if (r == NULL) {
        r = new BSTNode(k, v);
    } else if (r->k > k) {
        r->left = insertHelper(r->left, k, v);
    } else if (r->k < k) {
        r->right = insertHelper(r->right, k, v);
    } else { 
        // (r->k == k)
        r->v = v;
    }
    return r;
}



/***
 * Remove the entry with key k. 
 * If there is no such item, do nothing.
 ***/
template <class Key, class Value>
void BST<Key,Value>::remove(Key k){
    root = removeHelper(root, k);
}

template <class Key, class Value>
BSTNode<Key,Value>* BST<Key,Value>::removeHelper(BSTNode<Key,Value>* r, Key k){
    if (r == NULL) {
        return r;
    }
    else if (r->k > k) {
        r->left = removeHelper(r->left, k);
    }
    else if (r->k < k) {
        r->right = removeHelper(r->right, k);
    }
    else {// (r->k == k) // Leaf node
        if (r->left == NULL && r->right == NULL) {
            delete r;
            r = NULL;
        }
        else if (r->left == NULL) { 
            BSTNode* n = r->right;
            r->k = r->right->k;
            r->v = r->right->v;
            r->left = r->right->left;
            r->right = r->right->right;
            delete n;
        }
        else { // Two children or left child only
            BSTNode* n = max(r->left);
            r->k = n->k;
            r->v = n->v;
            r->left = removeHelper(r->left, n->k);
        }
    }
    return r;
}




/***
 * Return the value of the entry with key k. 
 * If there is no such item, throw an exception.
 ***/
template <class Key, class Value>
Value BST<Key,Value>::find(Key k){
    BSTNode* n = findHelper(root, k);
    if (n == NULL) {
        cout << "There is no entry with key " << k << "!" << endl;
        throw 10;
    }
    return n->v;
}

template <class Key, class Value>
BSTNode<Key,Value>* BST<Key,Value>::findHelper(BSTNode<Key,Value>* r, Key k){
    if (r == NULL) {
        return NULL;
    }
    else if (r->k > k) {
        return findHelper(r->left, k);
    }
    else if (r->k < k) {
        return findHelper(r->right, k);
    }
    return r;
}



/***
 * Return true if there is an entry with key k in the dictionary. 
 * If not, return false.
 ***/
template <class Key, class Value>
bool BST<Key,Value>::keyExists(Key k){
    if (findHelper(root, k) == NULL) {
        return false;
    }
    return true;
}



/***
 * If there is a key in the set that is > k, return the first such key. 
 * If not, return k.
 ***/
template <class Key, class Value>
Key BST<Key,Value>::next(Key k){
    BSTNode* n = nextHelper(root, k);
    if (n == NULL) {
        return k;
    }
    return n->k;
}

template <class Key, class Value>
BSTNode<Key,Value>* BST<Key,Value>::nextHelper(BSTNode<Key,Value>* r, Key k){
    if (r == NULL) {
        return NULL;
    }

    if (k < r->k) {
        if ((r->left != NULL) && (k >= max(r->left)->k)) {
            return r;
        }
        else {
            return nextHelper(r->left, k);
        }
    }
    else if (k == r->k) {
        if (r->right == NULL) {
            return NULL;
        }
        else {
            return min(r->right);
        }
    }
    else {// k > r->k
        return nextHelper(r->right, k);
    }
}



/***
 * If there is a key in the set that is < k, return the first such key. 
 * If not, return k.
 ***/
template <class Key, class Value>
Key BST<Key,Value>::prev(Key k){
    BSTNode* n = prevHelper(root, k);
    if (n == NULL) {
        return k;
    }
    return n->k;
}

template <class Key, class Value>
BSTNode<Key,Value>* BST<Key,Value>::prevHelper(BSTNode<Key,Value>* r, Key k){
    if (r == NULL) {
        return NULL;
    }

    if (k > r->k) {
        if ((r->right != NULL) && (k <= min(r->right)->k)) {
            return r;
        }
        else {
            return prevHelper(r->right, k);
        }
    }
    else if (k == r->k) {
        if (r->left == NULL) {
            return NULL;
        }
        else {
            return max(r->left);
        }
    }
    else { 
        return prevHelper(r->left, k);
    }
}




/***
 * The following additional functions print the tree using
 * pre-order, in-order, and post-order traversals, respectively.
 * Print each entry r using the statement:
 *   cout << "(" << r->k << "," << r->v << ") ";
 ***/

template <class Key, class Value>
void BST<Key,Value>::printPreOrder() {
    printPreOrderHelper(root);
}

template <class Key, class Value>
void BST<Key,Value>::printInOrder() {
    printInOrderHelper(root);
}

template <class Key, class Value>
void BST<Key,Value>::printPostOrder(){
    printPostOrderHelper(root);
}

template <class Key, class Value>
void BST<Key,Value>::printPreOrderHelper(BSTNode<Key,Value>* r) {
    if (r != NULL) {
        cout << "(" << r->k << ", " << r->v << ") ";
        printPreOrderHelper(r->left);
        printPreOrderHelper(r->right);
    }
}

template <class Key, class Value>
void BST<Key,Value>::printInOrderHelper(BSTNode<Key,Value>* r) {
    if (r != NULL) {
        printInOrderHelper(r->left);
        cout << "(" << r->k << ", " << r->v << ") ";
        printInOrderHelper(r->right);
    }
}

template <class Key, class Value>
void BST<Key,Value>::printPostOrderHelper(BSTNode<Key,Value>* r) {
    if (r != NULL) {
        printPostOrderHelper(r->left);
        printPostOrderHelper(r->right);
        cout << "(" << r->k << ", " << r->v << ") ";
    }
}




/***
 * Find the item in the sub-tree rooted at r which has the smallest key.
 ***/
template <class Key, class Value>
BSTNode<Key,Value>* BST<Key,Value>::min(BSTNode<Key,Value>* r){
    if (r == NULL) {
        return NULL;
    }
    else if (r->left == NULL) {
        return r;
    }
    return min(r->left);
}


/*** 
 * Find the item in the sub-tree rooted at r which has the largest key.
 ***/
template <class Key, class Value>
BSTNode<Key,Value>* BST<Key,Value>::max(BSTNode<Key,Value>* r){
    if (r == NULL) {
        return NULL;
    }
    else if (r->right == NULL) {
        return r;
    }
    return max(r->right);
}




