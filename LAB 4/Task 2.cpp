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
        if (request == available&& daysrent>5) {
            cout << "Car is rented!" << endl;
            rentalprice=rentalprice -0.05 * rentalprice;
            cout << "you have got a 5 percent discount";
            cout << "your rental is" << rentalprice
            available = 0; 
        } 
		else if(request == available && daysrent >10){
			rentalprice=rentalprice-0.10*rentalprice;
			cout<<"car rented with a 10 percent discount"
		}
		else {
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
