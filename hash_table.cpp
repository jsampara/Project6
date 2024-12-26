#include "hash_table.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int size) 
{
    tableSize = size;

    table = vector<List>(size);
}

HashTable::~HashTable() {}

int HashTable::HashFunction(const string &key) const 
{
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % tableSize; // 31 is a commonly used multiplier
    }
    return hash;
}

void HashTable::Insert(const string &key, const string &value) 
{
    int index = HashFunction(key);
    table[index].Insert(key, value);
}

bool HashTable::Search(const string &key, string &value) 
{
    int index = HashFunction(key);
    return table[index].Search(key, value);
}

// Delete a key-value pair from the hash table
bool HashTable::Delete(const string &key) 
{
    int index = HashFunction(key);
    return table[index].Delete(key);
}

// Print all entries in the hash table
void HashTable::Print() const 
{
    for (int i = 0; i < tableSize; ++i) 
    {
        cout << "Bucket " << i << ":" << endl;
        table[i].Print();
    }
}
