#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student_functions.h"


TEST_CASE("Testing compute_class_score")
{
    grading_schema g = {0.30, 0.30, 0.4};

    student s;
    s.final = 100;
    s.midterm = 100;
    s.hw_grades.push_back(100);
    s.hw_grades.push_back(100);
    
    double class_score = compute_student_total_score(s, g);
    CHECK(class_score >= 99.9);
    CHECK(class_score <= 100.1);

    cout << "s2-------------------------" << endl;
    student s2 = get_student_struct_data();
    output_student_struct_data(s2);

    cout << "s3-------------------------" << endl;
    student s3 = {3, "student 3", {0, 0, 0}, 100, 100};
    output_student_struct_data(s3);
    double score = compute_student_total_score(s3, g);
    cout << "student 3 score: " << score << endl;

    cout << "s4-------------------------" << endl;
    grading_schema g4 = get_grading_schema();
    student s4 = {4, "student 4", {100, 100, 100}, 0, 0};
    score = compute_student_total_score(s4, g4);
    cout << "score using grading schema g4: " << score << endl;
    score = compute_student_total_score(s4, g);
    cout << "score using og grading schema: " << score << endl;
}