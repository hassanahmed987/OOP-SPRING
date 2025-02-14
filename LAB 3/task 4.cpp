#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

public:
    Car(string carBrand, string carModel, double capacity) {
        brand = carBrand;
        model = carModel;
        fuelCapacity = capacity;
        currentFuelLevel = capacity;
    }

    void drive(double distance) {
        double fuelNeeded = distance * 0.05;
        if (fuelNeeded > currentFuelLevel) {
            cout << "Error: Not enough fuel to drive " << distance << " kilometers." << endl;
        } else {
            currentFuelLevel -= fuelNeeded;
            cout << "Drove " << distance << " km. Fuel consumed: " << fuelNeeded << " liters." << endl;
            displayFuelLevel();
        }
    }

    void refuel(double liters) {
        if ((currentFuelLevel + liters) > fuelCapacity) {
            currentFuelLevel = fuelCapacity;
            cout << "Tank full. Refueled to " << fuelCapacity << " liters." << endl;
        } else {
            currentFuelLevel += liters;
            cout << "Refueled " << liters << " liters. Current fuel: " << currentFuelLevel << " liters." << endl;
        }
        displayFuelLevel();
    }

    void displayFuelLevel() const {
        cout << "Current fuel level: " << currentFuelLevel << " liters." << endl;
        if (currentFuelLevel <= (fuelCapacity * 0.15)) {
            cout << "Warning: Fuel is low. Please refuel soon!" << endl;
        }
    }
};

int main() {
    Car myCar("Honda", "Civic", 45.0);

    myCar.drive(150);
    myCar.refuel(20);
    myCar.drive(200);
    myCar.refuel(30);

    return 0;
}
