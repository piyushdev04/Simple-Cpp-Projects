#include<bits/stdc++.h>
using namespace std;

int main() {
    double principal, rate, time, SI;

    cout << "Enter Principal amout: ";
    cin >> principal;
    cout << "Enter Rate of Interest (%): ";
    cin >> rate;
    cout << "Enter Time (years): ";
    cin >> time;

    SI = (principal * rate * time) / 100;
    cout << "Simple Interest: " << SI;

    return 0;
}