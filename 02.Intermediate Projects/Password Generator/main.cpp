#include<bits/stdc++.h>
using namespace std;

string generatePassword(int length) {
    string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    string password = "";

    srand(time(0));

    for (int i = 0; i < length; i++) {
        password += characters[rand() % characters.size()];
    }

    return password;
}

int main() {
    int length;
    cout << "Enter password length: ";
    cin >> length;

    cout << "Generated Password: " << generatePassword(length) << endl;

    return 0;
}