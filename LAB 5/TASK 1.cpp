
#include <iostream>
#include <string>
using namespace std;

class Apartment {
private:
    int id;
    string address;
    string* owner;  

public:
    
    Apartment(int aptID, string addr, string own) {
        id = aptID;
        address = addr;
        owner = new string(own);  
    }

    Apartment(const Apartment& apa) {
        id = apa.id;
        address = apa.address;
        owner = apa.owner;  
        cout << "Apartment " << id << " copied"<<endl;
    }

    void displayDetails()  {
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << *owner << endl;
    }

    ~Apartment() {}
};

int main() {
    Apartment apt1(1023, "b-194 gulshan", "shazahd");
    apt1.displayDetails();

    Apartment apt2 = apt1;  
    apt2.displayDetails();
    return 0;
}

