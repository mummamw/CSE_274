//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman

template <class Key, class Value>
class Dictionary {
 public:
  /***
   * Return the number of items currently in the Dictionary.
   ***/
  virtual unsigned long size() = 0;

  /*** 
   * Add a new entry with key k and value v.
   * If an item with key k already exists, overwrite it.
   ***/
  virtual void insert(Key k, Value v) = 0;

  /***
   * Remove the entry with key k. 
   * If there is no such item, do nothing.
   ***/
  virtual void remove(Key k) = 0;

  /***
   * Return the value of the entry with key k. 
   * If there is no such item, throw an exception.
   ***/
  virtual Value find(Key k) = 0;

  /***
   * Return true if there is an entry with key k in the dictionary. 
   * If not, return false.
   ***/
  virtual bool keyExists(Key k) = 0;

  /***
   * If there is a key in the set that is > k, return the first such key. 
   * If not, return k.
   ***/
  virtual Key next(Key k) = 0;

  /***
   * If there is a key in the set that is < k, return the first such key. 
   * If not, return k.
   ***/
  virtual Key prev(Key k) = 0;
};
