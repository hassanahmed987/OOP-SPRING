#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : public Person {
public:
    string subject;

    Teacher(string n, int a, string sub) : Person(n, a) {
        subject = sub;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

class Researcher : public Person {
public:
    string researchArea;

    Researcher(string n, int a, string area) : Person(n, a) {
        researchArea = area;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
public:
    int publications;

    Professor(string n, int a, string sub, string area, int pubs)
        : Teacher(n, a, sub), Researcher(n, a, area) {
        publications = pubs;
    }

    void displayDetails() {
        cout << "Name: " << Teacher::name << ", Age: " << Teacher::age
             << ", Subject: " << subject << ", Research Area: " << researchArea
             << ", Publications: " << publications << endl;
    }
};

int main() {
    Professor prof("Dr. qureshi", 45, "Mathematics", "Artificial Intelligence", 30);
    prof.displayDetails();

    return 0;
}
