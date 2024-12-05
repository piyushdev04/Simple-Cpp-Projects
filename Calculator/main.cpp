#include<bits/stdc++.h>
using namespace std;

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2, result;
    int choice;

    do {
        // Display menu
        cout << "\n--- Calculator ---\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiply (*)\n";
        cout << "4. Divide (/)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 2:
                result = subtract(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 3:
                result = multiply(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed. \n";
                }
                break;
            case 5:
                cout << "Exiting the Calculator. Goodbye! \n";
                break; // Add break to avoid fall-through to default
            default:
                cout << "Invalid choice. Please try again. \n";
        }
    } while (choice != 5); // Exit when the user selects "Exit"
    return 0;
}

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    return a / b;
}