#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "course.h"

class LectureCourse : public Course {
public:
    LectureCourse(string code, int cr);
    void calculateGrade() override;
    void displayInfo() override;
};

#endif
