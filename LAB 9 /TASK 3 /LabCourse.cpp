#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string code, int cr)
    : Course(code, cr) {}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << " | Credits: " << credits << endl;
}

void LabCourse::calculateGrade() {
    cout << "Final Grade of Lab:80 " << endl;
}
