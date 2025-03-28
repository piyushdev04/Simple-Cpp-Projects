#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int vowels = 0, consonants = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    for (char ch : str) {
        ch = tolower(ch);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Vowels: " << vowels << "\nConsonants: " << consonants;
    return 0;
}