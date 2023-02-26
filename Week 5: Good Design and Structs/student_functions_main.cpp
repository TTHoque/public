#include "student_functions.h"
#include <iostream>
using namespace std;

int main()
{
    student s;
    s = get_student_struct_data();

    double total_class_score{0.0}, sum{0.0};
    double hw_average{0.0};

   for (auto h_score : s.hw_grades) {
        cout << h_score << " ";
        sum += h_score;
    }
    cout << endl;

    output_student_struct_data(s);

    hw_average = sum / s.hw_grades.size();
    cout << "Average homework score: " << hw_average << endl;

    double final_total_score{0.0};
    
    grading_schema g = {0.30, 0.30, 0.40};
    final_total_score = compute_student_total_score(s, g);
    
    cout << "Final total class score: " << final_total_score << endl;
    return 0;
}