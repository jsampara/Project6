// list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

// Define the node structure for the linked list
struct LNode {
    string key;       // full name 
    string value;     // phone number
    LNode *next;      // pointer to the next node

    // Constructor for easy initialization
    LNode(const string &k, const string &v) : key(k), value(v), next(nullptr) {}
};

// define the List class
class List {
public:
    List();                        
    ~List();                        
    bool Insert(const string &key, const string &value); // insert a new entry
    bool Search(const string &key, string &value);       // search for an entry
    bool Delete(const string &key);                      // delete an entry
    void Print() const;                                  // print all entries

private:
    LNode *head; // head pointer of the linked list
};

#endif
