// list.cpp
#include "list.h"

List::List() {
    head = nullptr;
}

List::~List() {
    while (head != nullptr) {
        LNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// insert a (key, value) pair in sorted order into the linked list
bool List::Insert(const string &key, const string &value) {
    LNode *newNode = new LNode(key, value);

    // check if list is empty or if the new node goes at the head
    if (!head || head->key > key) {
        newNode->next = head;
        head = newNode;
        return true;
    }

    // Insert in sorted order
    LNode *curr = head;
    while (curr->next && curr->next->key < key) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

// Search for an entry by key
bool List::Search(const string &key, string &value) {
    LNode *curr = head;
    while (curr) {
        if (curr->key == key) {
            value = curr->value;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Delete an entry by key
bool List::Delete(const string &key) {
    LNode *curr = head;
    LNode *prev = nullptr;

    // Search for the node to delete
    while (curr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    // If key not found, return false
    if (!curr) return false;

    // Node to delete is found
    if (!prev) {
        head = curr->next; // Update head if deleting the first node
    } else {
        prev->next = curr->next; // Bypass the node to delete
    }

    delete curr;
    return true;
}

void List::Print() const {
    LNode *curr = head;
    while (curr) {
        cout << curr->key << ": " << curr->value << endl;
        curr = curr->next;
    }
}
