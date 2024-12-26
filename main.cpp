#include "hash_table.h"
#include <fstream>
#include <iostream>

using namespace std;

// Function to display the menu
void DisplayMenu() {
    cout << "\nPhone Book Menu:" << endl;
    cout << "1. Load phone book from file" << endl;
    cout << "2. Insert new entry" << endl;
    cout << "3. Search for a phone number" << endl;
    cout << "4. Delete an entry" << endl;
    cout << "5. Print the hash table" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

// function to load phone book data from a file
void LoadFromFile(HashTable &phoneBook) {
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream file(fileName);

    string lName, fName, pNumber;
    while (file >> lName >> fName >> pNumber) {
        string fullName = lName + " " + fName; // combine last and first name as the key
        phoneBook.Insert(fullName, pNumber);
    }

    file.close();
    cout << "Phone book loaded successfully from " << fileName << endl;
}

// function to handle user insertion
void InsertEntry(HashTable &phoneBook) {
    string fName, lName, pNumber;

    cout << "Enter the last name: ";
    cin >> lName;
    cout << "Enter the first name: ";
    cin >> fName;
    cout << "Enter the phone number: ";
    cin >> pNumber;

    string fullName = lName + " " + fName;
    phoneBook.Insert(fullName, pNumber);

}

// function to handle searching
void SearchEntry(HashTable &phoneBook) {
    string firstName, lastName;
    cout << "Enter the last name: ";
    cin >> lastName;
    cout << "Enter the first name: ";
    cin >> firstName;

    string fullName = lastName + " " + firstName;
    string phoneNumber;
    if (phoneBook.Search(fullName, phoneNumber)) {
        cout << "Found: " << fullName << " -> " << phoneNumber << endl;
    } else {
        cout << fullName << " not found in the phone book." << endl;
    }
}

// Function to handle deletion
void DeleteEntry(HashTable &phoneBook) {
    string firstName, lastName;
    cout << "Enter the last name: ";
    cin >> lastName;
    cout << "Enter the first name: ";
    cin >> firstName;

    string fullName = lastName + " " + firstName;
    if (phoneBook.Delete(fullName)) {
        cout << "Entry deleted successfully: " << fullName << endl;
    } else {
        cout << fullName << " not found in the phone book." << endl;
    }
}

// Main function
int main() {
    HashTable phoneBook(10); // Create a hash table with 10 buckets
    int choice = 0;

    // Display the menu and process user input
    while (choice != 6) {
        DisplayMenu();
        cin >> choice;

        if (choice == 1) {
            LoadFromFile(phoneBook);
        } else if (choice == 2) {
            InsertEntry(phoneBook);
        } else if (choice == 3) {
            SearchEntry(phoneBook);
        } else if (choice == 4) {
            DeleteEntry(phoneBook);
        } else if (choice == 5) {
            phoneBook.Print();
        } else if (choice == 6) {
            cout << "Exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
