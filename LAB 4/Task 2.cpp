#include<iostream>
using namespace std;

class car{
private:
    string brand;
    string model;
    float rentalprice;
    bool available;

public:
    car(){
        brand="unknown";
        model="generic";
        rentalprice=0.0;
        available=true;
    }

    car(string b, string m, float rp, bool ava) {
        brand = b;
        model = m;
        rentalprice = rp;
        available = ava;
    }

    void updatedcar(string b, string m, float rp, bool ava){
        brand = b;
        model = m;
        rentalprice = rp;
        available = ava;
    }

    void display(){
        cout << "model is " << model << endl;
        cout << "brand is " << brand << endl;
        cout << "rental price is " << rentalprice << endl;
        cout << "is available " << (available ? "Yes" : "No") << endl;
    }

    bool checkavailablity(){
        return available;
    }

    void rentalreq(){
        if (checkavailablity()){
            cout << "Car is available" << endl;
            available = false;
        }
        else{
            cout << "Car is already rented" << endl;
        }
    }

    void returncar(){
        available = true;
        cout << "Car has been returned" << endl;
    }

    void applyDiscount(int days){
        if (days > 10) {
            rentalprice *= 0.90;
            cout << "A 10% discount has been applied." << endl;
        } else if (days > 5) {
            rentalprice *= 0.95;
            cout << "A 5% discount has been applied." << endl;
        } else {
            cout << "No discount available." << endl;
        }
    }
};

int main(){
    car car1, car2("BMW", "M5", 30000, true);
    car1.display();
    car2.display();
    car2.rentalreq();
    car2.display();
    car2.rentalreq();
    car2.returncar();
    car2.display();
    car2.applyDiscount(7);
    car2.display();
    return 0;
}
