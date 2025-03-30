#include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
    char grade;
};

vector<Student> students;

void loadStudents() {
    ifstream file("students.txt");
    Student s;
    while (file >> s.name >> s.age >> s.marks >> s.grade) {
        students.push_back(s);
    }
    file.close();
}

void saveStudents() {
    ofstream file("students.txt");
    for (Student s : students) {
        file << s.name << " " << s.age << " " << s.marks << " " << s.grade << endl;
    }
    file.close();
}

void addStudent() {
    Student s;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Marks: ";
    cin >> s.marks;
    cout << "Enter Grade: ";
    cin >> s.grade;

    students.push_back(s);
    saveStudents();
    cout << "Student added successfully!\n";
}

void displayStudents() {
    for (Student s : students) {
        cout << "Name: " << s.name << ", Age: " << s.age << ", Marks: " << s.marks << ", Grade: " << s.grade << endl;
    }
}

void searchStudent() {
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    for (Student s : students) {
        if (s.name == name) {
            cout << "Found: Name: " << s.name << ", Age: " << s.age << ", Marks: " << s.marks << ", Grade: " << s.grade << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            saveStudents();
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student for found.\n";
}

int main() {
    loadStudents();
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display All\n3. Search Student\n4. Delete Student\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "invalid choice!\n";
        }
    } while (choice != 5);
    
    return 0;
}