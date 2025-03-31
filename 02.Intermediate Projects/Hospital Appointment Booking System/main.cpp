#include<bits/stdc++.h>
using namespace std;

struct Appointment {
    string patientName;
    string doctorName;
    string specialization;
    string time;
};

vector<Appointment> appointments;

void saveAppointments() {
    ofstream file("appointments.txt");
    for (const auto& appt : appointments) {
        file << appt.patientName << " " << appt.doctorName << " "
            << appt.specialization << " " << appt.time << endl;
    }
    file.close();
}

void loadAppointments() {
    ifstream file("appointments.txt");
    Appointment appt;
    while (file >> appt.patientName >> appt.doctorName >> appt.specialization >> appt.time) {
        appointments.push_back(appt);
    }
    file.close();
}

void bookAppointment() {
    Appointment appt;
    cout << "Enter patient name: "; cin >> appt.patientName;
    cout << "Enter doctor name: "; cin >> appt.doctorName;
    cout << "Enter specialization: "; cin >> appt.specialization;
    cout << "Enter appointment time (e.g., 10:00AM): "; cin >> appt.time;
    appointments.push_back(appt);
    saveAppointments();
    cout << "Appointment booked successfully!\n";
}

void viewAppointments() {
    if (appointments.empty()) {
        cout << "No appointments available.\n";
        return;
    }
    cout << "\nAppointments:\n";
    for (const auto& appt : appointments) {
        cout << "Patient: " << appt.patientName << ", Doctor: " << appt.doctorName
            << " (" << appt.specialization << "), Time: " << appt.time << endl;
    }
}

void cancelAppointment() {
    string name;
    cout << "Enter patient name to cancel appointment: "; cin >> name;
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->patientName == name) {
            appointments.erase(it);
            saveAppointments();
            cout << "Appointment canceled successfully!\n";
            return;
        }
    }
    cout << "Appointment not found!\n";
}

int main() {
    loadAppointments();
    int choice;
    do {
        cout << "\nHospital Appointment System\n";
        cout << "1. Book Appointment\n2. View Appointments\n3. Cancel Appointment\n4. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: bookAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: cancelAppointment(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    }while (choice != 4);
    return 0;
}