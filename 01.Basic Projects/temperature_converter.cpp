#include<bits/stdc++.h>
using namespace std;

int main() {
    int choice;
    double temp, converted;

    cout << "Temperature Converter\n";
    cout << "1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Celsius to Kelvin\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    cout << "Enter temperature: ";
    cin >> temp;

    switch (choice) {
        case 1: converted = (temp * 9/5) + 32; cout << "Result: " << converted << " F"; break;
        case 2: converted = (temp - 32) * 5/9; cout << "Result: " << converted << " C"; break;
        case 3: converted = temp + 273.15; cout << "Result: " << converted << " K"; break;
        default: cout << "Invalid choice!";
    }
    return 0;
}