#include<bits/stdc++.h>
using namespace std;

int main() {
    int birthYear, currentYear;
    cout << "Enter your birth year: ";
    cin >> birthYear;

    cout << "Enter the current year: ";
    cin >> currentYear;

    if (currentYear >= birthYear)
        cout << "Your age is: " << currentYear - birthYear;
    else
        cout << "Invalid input! Birth year cannot be greater than the current year.";

    return 0;
}