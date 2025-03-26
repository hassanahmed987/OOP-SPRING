#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;
public:
    Person(string n, int a, string contact, string addr)
        : name(n), age(a), contactNumber(contact), address(addr) {}
    
     void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber;
        cout << "\nAddress: " << address;
        cout << endl;
    }
    
    void updateInfo(string newContact, string newAddress) {
        contactNumber = newContact;
        address = newAddress;
    }
};

class Patient : public Person {
    int patientID;
    string medicalHistory;
    string doctorAssigned;
public:
    Patient(string n, int a, string contact, int id, string history, string doctor, string addr)
        : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    
    void displayInfo() {
        Person::displayInfo();
        cout << "\nPatient ID: " << patientID << "\nMedical History: " << medicalHistory 
             << "\nDoctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    float consultationFee;
    string patientsList;
public:
    Doctor(string n, int a, string contact, string spec, float fee, string patients, string addr)
        : Person(n, a, contact, addr), specialization(spec), consultationFee(fee), patientsList(patients) {}
    
    void displayInfo()  {
        Person::displayInfo();
        cout << "\nSpecialization: " << specialization << "\nConsultation Fee: " << consultationFee
             << "\nPatients List: " << patientsList << endl;
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string contact, string ward, string shift, string addr)
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}
    
    void displayInfo()  {
        Person::displayInfo();
        cout << "\nAssigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    float salary;
public:
    Administrator(string n, int a, string contact, string dept, float sal, string addr)
        : Person(n, a, contact, addr), department(dept), salary(sal) {}
    
    void updateInfo(string newContact, string newAddress, float newSalary) {
        Person::updateInfo(newContact, newAddress);
        salary = newSalary;
    }
    
    void displayInfo()  {
        Person::displayInfo();
        cout << "\nDepartment: " << department << "\nSalary: " << salary << endl;
    }
};

int main() {
    Patient p1("Aamir Khan", 40, "0300-1234567", 101, "Hypertension", "Dr. Ahmed", "House #12, Gulberg, Lahore");
    Doctor d1("Dr. Ahmed", 50, "0321-9876543", "Cardiology", 3000.0, "Aamir Khan, Salman Ali", "Clinic #5, Johar Town, Lahore");
    Nurse n1("Saira Bibi", 35, "0345-5551234", "ICU", "Night Shift", "Flat #21, Saddar, Karachi");
    Administrator a1("Rizwan Sheikh", 45, "0333-9998887", "HR", 75000.0, "Office #8, Blue Area, Islamabad");
    
    p1.displayInfo();
    cout << "\n";
    d1.displayInfo();
    cout << "\n";
    n1.displayInfo();
    cout << "\n";
    a1.displayInfo();
    
    return 0;
}

