#include<bits/stdc++.h>
using namespace std;

int main() {
    string str, reversedStr;
    cout << "Enter a string: ";
    cin >> str;

    reversedStr = string(str.rbegin(), str.rend());

    if (str == reversedStr)
        cout << str << " is a palindrome.";
    else
        cout << str << " is not a palindrome.";

    return 0;
}