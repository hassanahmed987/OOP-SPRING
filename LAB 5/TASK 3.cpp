#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    string designation;

    Employee(string name, string designation) : name(name), designation(designation) {}
};

class Project {
public:
    string title;
    string deadline;
    Employee* employees[10]; 
    int employeeCount;

    Project(string title, string deadline) : title(title), deadline(deadline), employeeCount(0) {}

    void addEmployee(Employee* employee) {
        if (employeeCount < 10) {
            employees[employeeCount++] = employee;
        } else {
            cout << "Cannot add more employees to project: " << title << endl;
        }
    }

    void displayProjectDetails() {
        cout << "Project: " << title << endl;
		cout<< "Deadline: " << deadline << endl;
        cout << "Assigned Employees:" << endl;
        for (int i = 0; i < employeeCount; i++) {
            cout << " - " << employees[i]->name << " (" << employees[i]->designation << ")" << endl;
        }
        cout << endl;
    }
};

int main() {
    Employee emp1("hassan", "Software Engineer");
    Employee emp2("faaiz", "Project Manager");
    Employee emp3("baqar", "Designer");

    Project proj1("AI Development", "2025-06-30");
    Project proj2("Web App", "2025-05-15");

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);
    proj2.addEmployee(&emp1);
    proj2.addEmployee(&emp3);

    proj1.displayProjectDetails();
    proj2.displayProjectDetails();

    return 0;
}
