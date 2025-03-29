#include<bits/stdc++.h>
using namespace std;

struct Contact {
    string name;
    string phone;
};

void addContact() {
    Contact c;
    ofstream file("Contacts.txt", ios::app);
    cout << "Enter name: ";
    cin >> c.name;
    cout << "Enter phone: ";
    cin >> c.phone;
    file << c.name << " " << c.phone << endl;
    file.close();
    cout << "Contact added successfully!\n";
}

void displayContacts() {
    Contact c;
    ifstream file("Contacts.txt");
    cout << "Contacts List:\n";
    while (file >> c.name >> c.phone) {
        cout << "Name: " << c.name << ", Phone: " << c.phone << endl;
    }
    file.close();
}

void searchContact(string name) {
    Contact c;
    ifstream file("Contacts.txt");
    bool found = false;
    while (file >> c.name >> c.phone) {
        if (c.name == name) {
            cout << "Contact Found: " << c.name << " - " << c.phone << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Contact not found!\n";
    file.close();
}

int main() {
    int choice;
    string name;

    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3:
                cout << "Enter name to search: ";
                cin >> name;
                searchContact(name);
                break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}