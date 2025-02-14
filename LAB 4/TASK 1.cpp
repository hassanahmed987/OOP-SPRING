#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    float rentalprice;
    int available;  

public:
    Car() {
        brand = "unknown";
        model = "generic";
        rentalprice = 0.0;
        available = 1;
    }

    Car(string b, string m, float RP, int av) {
        brand = b;
        model = m;
        rentalprice = RP;
        available = av;
    }

    void rentalreq(int request) {
        if (request == available) {
            cout << "Car is rented!" << endl;
            available = 0; 
        } else {
            cout << "Car not available!" << endl;
        }
    }
    void displayCarDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price: " << rentalprice << endl;
        cout << "Available: " << available << endl;
    }
};
int main() {
    Car c("BMW", "M5", 2000, 1);
    c.displayCarDetails();
    c.rentalreq(1); 
    c.rentalreq(1);  

    return 0;
}
