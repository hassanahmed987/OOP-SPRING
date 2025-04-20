#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int cr)
    : Course(code, cr) {}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << " | Credits: " << credits << endl;
}

void LectureCourse::calculateGrade() {
    cout << "Final Grade of Lecture: 90" << endl;
}
