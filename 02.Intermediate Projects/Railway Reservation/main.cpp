#include<bits/stdc++.h>
using namespace std;

struct Ticket {
    string pnr;
    string passengerName;
    string trainName;
    string time;
};

vector<Ticket> tickets;

void saveTickets() {
    ofstream file("tickets.txt");
    for (const auto& ticket : tickets) {
        file << ticket.pnr << " " << ticket.passengerName << " "
             << ticket.trainName << " " << ticket.time << endl;
    }
    file.close();
}

void loadTickets() {
    ifstream file("tickets.txt");
    Ticket ticket;
    while (file >> ticket.pnr >> ticket.passengerName >> ticket.trainName >> ticket.time) {
        tickets.push_back(ticket);
    }
    file.close();
}

void bookTicket() {
    Ticket ticket;
    cout << "Enter PNR number: "; cin >> ticket.pnr;
    cout << "Enter passenger name: "; cin >> ticket.passengerName;
    cout << "Enter train name: "; cin >> ticket.trainName;
    cout << "Enter departure time: "; cin >> ticket.time;
    tickets.push_back(ticket);
    saveTickets();
    cout << "Ticket booked successfully!\n";
}

void viewTickets() {
    if (tickets.empty()) {
        cout << "No tickets available.\n";
        return;
    }
    cout << "\nBooked Tickets:\n";
    for (const auto& ticket : tickets) {
        cout << "PNR: " << ticket.pnr << ", Passenger: " << ticket.passengerName
             << ", Train: " << ticket.trainName << ", Time: " << ticket.time << endl;
    }
}

void cancelTicket() {
    string pnr;
    cout << "Enter PNR number to cancel ticket: "; cin >> pnr;
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->pnr == pnr) {
            tickets.erase(it);
            saveTickets();
            cout << "Ticket canceled successfully!\n";
            return;
        }
    }
    cout << "Ticket not found!\n";
}

int main() {
    loadTickets();
    int choice;
    do {
        cout << "\nRailway Reservation System\n";
        cout << "1. Book Ticket\n2. View Tickets\n3. Cancel Ticket\n4. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: bookTicket(); break;
            case 2: viewTickets(); break;
            case 3: cancelTicket(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}