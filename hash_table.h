#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "list.h"
#include <vector>

class HashTable {
public:
    HashTable(int size);                         
    ~HashTable();                                
    void Insert(const string &key, const string &value); // Insert a key-value pair
    bool Search(const string &key, string &value);       // Search for a key
    bool Delete(const string &key);                      // Delete a key-value pair
    void Print() const;                                  

private:
    vector<List> table; // Vector of linked lists
    int tableSize;      // Number of buckets in the hash table
    int HashFunction(const string &key) const;  // Hash function
};

#endif
