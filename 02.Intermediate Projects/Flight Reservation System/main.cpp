#include<bits/stdc++.h>
using namespace std;

struct Flight {
    int flightNumber;
    string destination;
    int availablesSeats;
};

struct Booking {
    string passengerName;
    int flightNumber;
};

vector<Flight> flights = {
    {101, "New York", 10},
    {102, "Los Angeles", 8},
    {103, "Chicago", 12},
    {104, "San Francisco", 5}
};

vector<Booking> bookings;

void displayFlights() {
    cout << "\nAvailable Flights:\n";
    cout << "Flight No\tDestination\tAvailable Seats\n";
    for (const auto &flight : flights) {
        cout << flight.flightNumber << "\t\t" << flight.destination << "\t\t" << flight.availablesSeats << endl;
    }
}

void bookTicket() {
    string name;
    int flightNum;

    cout << "\nEnter your name: ";
    cin >> name;
    cout << "Enter flight number: ";
    cin >> flightNum;

    for (auto &flight : flights) {
        if (flight.flightNumber == flightNum && flight.availablesSeats > 0) {
            flight.availablesSeats--;
            bookings.push_back({name, flightNum});

            ofstream file("bookings.txt", ios::app);
            file << name << " " << flightNum << endl;
            file.close();

            cout << "Ticket booked successfully for " << name << " on Flight " << flightNum << "!\n";
            return;
        }
    }
    cout << "Flight not found or no available seats.\n";
}

void cancelTicket() {
    string name;
    int flightNum;

    cout << "\nEnter your name: ";
    cin >> name;
    cout << "Enter flight number to cancel: ";
    cin >> flightNum;

    for (auto it = bookings.begin(); it != bookings.end(); it++) {
        if (it->passengerName == name && it->flightNumber == flightNum) {
            bookings.erase(it);

            for(auto &flight : flights) {
                if (flight.flightNumber == flightNum) {
                    flight.availablesSeats++;
                    break;
                }
            }

            ofstream file("bookings.txt");
            for (const auto &booking : bookings) {
                file << booking.passengerName << " " << booking.flightNumber << endl;
            }
            file.close();

            cout << "Ticket canceled successfully!\n";
            return;
        }
    }
    cout << "Booking not found.\n";
}

void loadBookings() {
    ifstream file("bookings.txt");
    string name;
    int flightNum;

    while (file >> name >> flightNum) {
        bookings.push_back({name, flightNum});
    }
    file.close();
}

int main() {
    loadBookings();

    int choice;
    do {
        cout << "\nFlight Reservation System";
        cout << "\n1. View Flights";
        cout << "\n2. Book a Ticket";
        cout << "\n3. Cancel a Ticket";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayFlights(); break;
            case 2: bookTicket(); break;
            case 3: cancelTicket(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);

    return 0;
}