#ifndef __STUDENT_FUNCTIONS_H
#define __STUDENT_FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

typedef struct student{
    int id;
    string name; 
    vector<int> hw_grades;
    int midterm = 0;
    int final = 0;
} student;

typedef struct grading_schema{
    double midterm_weight = 0.3;
    double final_weight = 0.3;
    double hw_weight = 0.4;
} grading_schema;

student get_student_struct_data();
grading_schema get_grading_schema();
void output_student_struct_data(const student & s);
double compute_student_total_score(const student & s, const grading_schema & g);

#endif