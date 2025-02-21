#include<iostream>
using namespace std;

class car{
private:
    string brand;
    string model;
    float rentalprice;
    bool available;
    float totalRevenue;
    int carID;

public:
    car() : carID(0) {
        brand="unknown";
        model="generic";
        rentalprice=0.0;
        available=true;
        totalRevenue = 0.0;
    }

    car(int id, string b, string m, float rp, bool ava) : carID(id), brand(b), model(m), rentalprice(rp), available(ava), totalRevenue(0.0) {}

    car(const car &c) : carID(c.carID), brand(c.brand), model(c.model), rentalprice(c.rentalprice), available(c.available), totalRevenue(c.totalRevenue) {
        cout << "Copy constructor called" << endl;
    }

    ~car() {
        cout << "Car object for " << brand << " " << model << " (ID: " << carID << ") is being deleted" << endl;
    }

    void updatedcar(string b, string m, float rp, bool ava){
        brand = b;
        model = m;
        rentalprice = rp;
        available = ava;
    }

    void display(){
        cout << "Car ID: " << carID << endl;
        cout << "Model: " << model << endl;
        cout << "Brand: " << brand << endl;
        cout << "Rental Price: " << rentalprice << endl;
        cout << "Availability: " << (available ? "Yes" : "No") << endl;
        cout << "Total Revenue: " << totalRevenue << endl;
    }

    bool checkavailablity(){
        return available;
    }

    void rentalreq(int days){
        if (checkavailablity()){
            cout << "Car (ID: " << carID << ") is available and rented for " << days << " days." << endl;
            available = false;
            float discount = 1.0;
            if (days > 10) discount = 0.90;
            else if (days > 5) discount = 0.95;
            
            float cost = rentalprice * days * discount;
            this->totalRevenue += cost;
            cout << "Total cost after discount: " << cost << endl;
        }
        else{
            cout << "Car (ID: " << carID << ") is already rented" << endl;
        }
    }

    void returncar(){
        available = true;
        cout << "Car (ID: " << carID << ") has been returned" << endl;
    }
};

int main(){
    car car1(101, "Toyota", "Corolla", 15000, true);
    car car2(102, "BMW", "M5", 30000, true);
    car1.display();
    car2.display();
    
    car car3 = car2; 
    car3.display();
    
    car2.updatedcar("Audi", "A6", 28000, true);
    cout << "After modifying car2 details:" << endl;
    car2.display();
    car3.display(); 
    
    car2.rentalreq(7);
    car2.display();
    
    car2.rentalreq(3);
    
    car2.returncar();
    car2.display();
    
    return 0;
}
