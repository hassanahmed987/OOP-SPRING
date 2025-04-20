#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"

int main() {
    LectureCourse lec("CS101", 3);
    LabCourse lab("CS102L", 1);

    Course*c1=&lec;
    Course*c2=&lab;
    c1->displayInfo();
    c1->calculateGrade();
    c2->displayInfo();
    c2->calculateGrade();
	}
