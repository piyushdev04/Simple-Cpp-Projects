#include<bits/stdc++.h>
using namespace std;

struct Movie {
    string name;
    int availableSeats;
    float price;
};

Movie movies[] = {
    {"Avatar", 50, 10.0},
    {"Titanic", 30, 8.5},
    {"Inception", 40, 9.0}
};

void displayMovies() {
    cout << "Available Movies:\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << movies[i].name << " - Seats: " << movies[i].availableSeats << " - Price: $" << movies[i].price << endl;
    }
}

void bookTicket() {
    int choice, tickets;
    displayMovies();
    cout << "Select movie (1-3): ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice!\n";
        return;
    }

    cout << "Enter number of tickets: ";
    cin >> tickets;

    if (tickets > movies[choice - 1].availableSeats) {
        cout << "Not enough seats available!\n";
        return;
    }

    float totalCost = tickets * movies[choice - 1].price;
    movies[choice - 1].availableSeats -= tickets;

    ofstream file("bookings.txt", ios::app);
    file << "Movie: " << movies[choice - 1].name << ", Tickets: " << tickets << ", Total Cost: $" << totalCost << endl;
    file.close();

    cout << "Booking successful! Total cost: $" << totalCost << endl;
}

void viewBookings() {
    ifstream file("bookings.txt");
    string line;

    cout << "Booking History:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Display Movies\n2. Book Ticket\n3. View Bookings\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayMovies(); break;
            case 2: bookTicket(); break;
            case 3: viewBookings(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}