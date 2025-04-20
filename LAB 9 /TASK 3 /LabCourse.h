#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "course.h"

class LabCourse : public Course {

public:
    LabCourse(string code, int cr);
    void calculateGrade() override;
    void displayInfo() override;
};

#endif
