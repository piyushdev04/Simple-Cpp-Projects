#include<bits/stdc++.h>
using namespace std;

int main() {
    int votes[3] = {0, 0, 0};
    int choice, totalVotes = 0;

    cout << "Voting System\n";
    cout << "1. Candidate A\n2. Candidate B\n3. Candidate C\n4. Exit\n";

    while(true) {
        cout << "Vote for a candidate (1-3) or press 4 to stop: ";
        cin >> choice;

        if (choice == 4) break;
        else if (choice >= 1 && choice <= 3) {
            votes[choice - 1]++;
            totalVotes++;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "\nVoting Results:\n";
    cout << "Candidate A: " << votes[0] << " votes\n";
    cout << "Candidate B: " << votes[1] << " votes\n";
    cout << "Candidate C: " << votes[2] << " votes\n";
    cout << "Total Votes: " << totalVotes << endl;

    return 0;
}