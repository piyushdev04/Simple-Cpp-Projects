#include<bits/stdc++.h>
using namespace std;

struct Car {
    string brand;
    string model;
    int pricePerDay;
    bool isRented;
};

vector<Car> cars;

void saveCars() {
    ofstream file("cars.txt");
    for (const auto& car : cars) {
        file << car.brand << " " << car.model << " " << car.pricePerDay << " " << car.isRented << endl;
    }
    file.close();
}

void loadCars() {
    ifstream file("cars.txt");
    Car car;
    while (file >> car.brand >> car.model >> car.pricePerDay >> car.isRented) {
        cars.push_back(car);
    }
    file.close();
}

void addCar() {
    Car car;
    cout << "Enter car brand: "; cin >> car.brand;
    cout << "Enter car model: "; cin >> car.model;
    cout << "Enter price per day: "; cin >> car.pricePerDay;
    car.isRented = false;
    cars.push_back(car);
    saveCars();
    cout << "Cars added successfully!\n";
}

void viewCars() {
    cout << "\nAvailable Cars:\n";
    for (const auto& car : cars) {
        if (!car.isRented) {
            cout << "Brand: " << car.brand << ", Model: " << car.model << ", Price per day: " << car.pricePerDay << endl;
        }
    }
}

void rentCar() {
    string model;
    cout << "Enter car model to rent: "; cin >> model;
    for (auto& car : cars) {
        if (car.model == model && !car.isRented) {
            car.isRented = true;
            saveCars();
            cout << "Car rented successfully!\n";
            return;
        }
    }
    cout << "Car not available!\n";
}

void returnCar() {
    string model;
    cout << "Enter car model to return: "; cin >> model;
    for (auto& car : cars) {
        if (car.model == model && car.isRented) {
            car.isRented = false;
            saveCars();
            cout << "Car returned successfully!\n";
            return;
        }
    }
    cout << "Car not found or not rented!\n";
}

int main() {
    loadCars();
    int choice;
    do {
        cout << "\nCar Rental System\n";
        cout << "1. Add Car\n2. View Cars\n3. Rent Car\n4. Return Car\n5. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: addCar(); break;
            case 2: viewCars(); break;
            case 3: rentCar(); break;
            case 4: returnCar(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}