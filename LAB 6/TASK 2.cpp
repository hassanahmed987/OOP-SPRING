#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    string brand;
    int speed;

    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }

    void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
public:
    int seats;

    Car(string b, int s, int se) : Vehicle(b, s) {
        seats = se;
    }

    void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h, Seats: " << seats << endl;
    }
};

// Derived class: ElectricCar (inherits from Car)
class ElectricCar : public Car {
public:
    int batteryLife;

    ElectricCar(string b, int s, int se, int bl) : Car(b, s, se) {
        batteryLife = bl;
    }

    void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h, Seats: " << seats 
             << ", Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    ElectricCar Car("Tesla Model H", 202, 5, 16);
    Car.displayDetails();

    return 0;
}
