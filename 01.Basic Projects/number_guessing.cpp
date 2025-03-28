#include<bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess;

    cout << "Guess the number (1 - 100): ";
    do {
        cin >> guess;
        if (guess > secret)
            cout << "Too high! Try again: ";
        else if (guess < secret)
            cout << "Too low! Try again: ";
        else
            cout << "Congratulation! You guessed it!";
    } while (guess != secret);

    return 0;
}