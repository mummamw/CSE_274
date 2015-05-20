/* Michael Mumma 
*  CSE 274 HW05Phase01 
*  Binary Search Tree
*  4/18/2015
*/  

#include "BST.h"

#include <iostream>
#include <string>

using namespace std;

BSTNode::BSTNode(){
    left = NULL;
    right = NULL;
    k = -1;
    v = "";
}
BSTNode::BSTNode(int myK, string myV){
    left = NULL;
    right = NULL;
    k = myK;
    v = myV;
}

//BinarySearchTree section

BST::BST(){
    root = NULL;
}

BST::~BST(){
    if (root == NULL){               //Checks if the tree has nothing
        delete root;
        root = NULL;
        return;                      
    }
    while (root != NULL){
        remove(root->k); 
    }
    return;
}


/***
* Return the number of items currently in the BST.
//Needs - Something to search the tree
***/
unsigned long BST::size(){
    unsigned long b = sizeHelper(root); // Doesn't have to be two lines?
	return b;
}


/***
* Add a new entry with key k and value v.
* If an item with key k already exists, overwrite it.
***/
void BST::insert(int k, string v){
    //if (root = NULL) {
        //cout << "creating root node" << endl;
        //BSTNode* n = new BSTNode();
        //n->k = k;
        //n->v = v;
        //root = n;
    //}
    //else {
        root = insertHelper(root, k, v);
    //}
}


/***
* Remove the entry with key k.
* If there is no such item, do nothing.
***/
void BST::remove(int k){
    removeHelper(root, k);
}


/***
* Return the value of the entry with key k.
* If there is no such item, throw an exception.
***/
string BST::find(int k){
   BSTNode* r = findHelper(root, k);
   return r->v;
/*    BSTNode* w = root;
    while (w != NULL){
        if (w->k > k) w = w->right;
        if (w->k < k) w = w->left;
        return w->v;
    }
    /////////////////////////NEEDS WORK//////////////////////////////////////
    return "This is my suedo Error code";      
    //findHelper(root, k);
    //if (intExists(k)){  }
    //else{ Throws exception }
    //try {
        //code that throws excpetion
        //findHelper(root, k)
    //} catch (string exception) {
        //Print the error message
    //}
*/	
}


/***
* Return true if there is an entry with key k in the BST.
* If not, return false.
***/

bool BST::intExists(int k){
    BSTNode* w = root;
    if (w == NULL) return false;         //Kills if tree is empty.
    while (w != NULL) {                  //Moves until it is empty
        if (k > root->k) w = w->right;   
        if (k < root->k) w = w->left;
        if (k == w->k) return true;
    }
	return false;                       //w got to Null 
}


/*
bool BST::intExists(int k){
    Maybe dont use a pointer?
    if (w == NULL) return false;         
    while (w != NULL) {                  
        if (k > root->k) w = w->right;
        if (k < root->k) w = w->left;
        if (k == w->k) return true;
    }
    return false;                        
}
*/

/***
* If any of the entries in the BST has a key greater than k,
* return the smallest such key.
* If not, return k.
***/
int BST::next(int k){ //Needs find with int k
    BSTNode* w = nextHelper(root, k);
    return w->k;
    
    /*    BSTNode* w = max(root);
    w->k = k;
	return NULL;
*/
}


/***
* If any of the entries in the BST has a key smaller than k,
* return the greatest such key.
* If not, return k.
***/
int BST::prev(int k){ 
    BSTNode* w = prevHelper(root, k);
    return w->k;

}


/***
* The following additional functions print the tree using
* pre-order, in-order, and post-order traversals, respectively.
* Print each entry r using the statement:
*   cout << "(" << r->k << "," << r->v << ") ";
***/
void BST::printPreOrder(){
    //Left to Right
    BSTNode* w = min(root);
    printPreOrderHelper(w);
}
void BST::printInOrder(){
    printInOrderHelper(root);
}
void BST::printPostOrder(){
    printPostOrderHelper(root);
}


/***
* These are the recursive versions of each of your public member functions.
* You should return the address of the new root node,
* whether or not the root node changes.
***/
unsigned long BST::sizeHelper(BSTNode* r){ 
    if (root == NULL) return 0;
    else {
        int count = 1; 
        count += sizeHelper(r->left);
        count += sizeHelper(r->right);
        return count;
    }
}
 	
//(1) Checks empty (2) Looks left until its bigger (3) Once it is adds r
//to the right side. 
BSTNode* BST::insertHelper(BSTNode* r, int k, string v){   
    if (r == NULL){
        r = new BSTNode(k, v); 
        //cout << " add root node " << k << endl;
        return r;
    } else if (r->k > k) {
        r->left = insertHelper(r->left, k, v); 
        return r;
    } else{
        r->right = insertHelper(r->right, k, v);
        return r;
    }
    return r;
    
}
	
BSTNode* BST::removeHelper(BSTNode* r, int k){
    if (r == NULL){ 
        return r; 
    }   else if (r->k > k) {
        r->left = removeHelper(r->left, k);
        return r;
    }   else if (r->k < k){
        r->right = removeHelper(r->right, k);
        return r;
    }   else if (r->k == k){ 
            if (r->left == NULL || r->right == NULL) {     
                delete r;
                r = NULL;
                return r;
            }
            //(2) Right child only
            else if (r->right != NULL && r->left == NULL) {
                r->k = r->right->k;
                r->v = r->right->v;
                r->right = r->right->right;
                r->right = r->right->left;
                delete r->right;
                return r;
            }
            //(3) Two Children
            else if (r->right != NULL || r->left != NULL) {
                BSTNode* w = max(r);
                r->k = w->k;
                r->v = w->v;
                r->right = w->right;
                r->right = w->left;
                //recursively delete rightmost element in left sub tree
                remove(w->k);
            }
    }
    return r; 
}
	
BSTNode* BST::findHelper(BSTNode* r, int k){ 
    if (r == NULL || r->k == k){ return r; }
    else if (r->k > k) {
        r->left = findHelper(r->left, k);
        return r;
    }
    else if (r->k < k){
        r->right = findHelper(r->right, k);
        return r;
    }
    return r;
}
	
BSTNode* BST::nextHelper(BSTNode* r, int k){ 
    //Trying to find if there is a spot with a greater value
    //cases (1) It is max - No more work (2) root = Null
    //      (3) It has a right child - Then go to min of that

    if (r == NULL || r->k == k) return r;  //(1)(2)
    else if (r->right != NULL) {
        return min(r->right);
    }
    return r; 
}
	
BSTNode* BST::prevHelper(BSTNode* r, int k){ 
    if (r == NULL || r->k == k) return r;  //(1)(2)
    else if (r->right != NULL) {
        return max(r->right);
    }
    return r;
}
	
void BST::printPreOrderHelper(BSTNode* r){
    if (r != NULL){
        cout << r->k << " ";
        printPreOrderHelper(r->left);
        printPreOrderHelper(r->right);
    }
}
	
void BST::printInOrderHelper(BSTNode* r){
    if (r != NULL){
        if (r->left != NULL)
        printInOrderHelper(r->left);
        cout << r->k << " ";
        if (r->right != NULL)
        printInOrderHelper(r->right);
    }
}
	
void BST::printPostOrderHelper(BSTNode* r){
    printInOrderHelper(r->left);
    printInOrderHelper(r->right);
    cout << r->k << " ";
}


/***
* The following two are just some helper functions.
***/

/***
* Find the item in the sub-tree rooted at r which has the smallest kry.
***/
BSTNode* BST::min(BSTNode* r){      
    BSTNode* w = root;              
    while (w->left != NULL){ w = w->left;}
	return w;
}

/***
* Find the item in the sub-tree rooted at r which has the largest key.
***/
BSTNode* BST::max(BSTNode* r){
   // BSTNode* w = root;              
    //while (r->right != NULL){ 
      //  r = r->right;01
    //}
    //return r;
    /*
    if (r->right == NULL) return r;
    else { return max(r); }
    return r;
    
   // while (r->right != NULL){
    //    r = r -> right;
   // }
   // return r;
    if (r->right == NULL) return r;
    while (r->right != NULL){
        r = r->right;
    }
    return r;
   
  
    BSTNode* w = r;

    if (w->right == NULL) return w;
        while (w->left != NULL) {
            w = w->left;
        }
        return(w);
     */
    return r->right;
}
