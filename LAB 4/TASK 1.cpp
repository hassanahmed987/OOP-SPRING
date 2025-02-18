#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    float rentalPrice;
    bool available;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        available = true;
    }

    void updateCar(string b, string m, float rp, bool ava) {
        brand = b;
        model = m;
        rentalPrice = rp;
        available = ava;
    }

    void display() {
        cout << "Model: " << model << endl;
        cout << "Brand: " << brand << endl;
        cout << "Rental Price: $" << rentalPrice << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }

    bool checkAvailability() {
        return available;
    }

    void rentCar() {
        if (checkAvailability()) {
            cout << "Car is available and has been rented." << endl;
            available = false;
        } else {
            cout << "Car is already rented." << endl;
        }
    }

    void returnCar() {
        available = true;
        cout << "Car has been returned." << endl;
    }
};

int main() {
    Car car1, car2;
    car1.display();
    
    car2.updateCar("BMW", "M5", 30000, true);
    car2.display();
    
    car2.rentCar();
    car2.display();
    
    car2.rentCar(); // Trying to rent again when already rented
    
    car2.returnCar();
    car2.display();

    return 0;
}


    return 0;
}
