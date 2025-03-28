#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> tasks;
    int choice;
    string task;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore newline character

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                tasks.push_back(task);
                break;
            case 2:
                cout << "\nYour To-Do List:\n";
                for (size_t i = 0; i < tasks.size(); i++)
                    cout << i + 1 << ". " << tasks[i] << endl;
                break;
            case 3:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!";
        }
    }while (choice != 3);

    return 0;
}