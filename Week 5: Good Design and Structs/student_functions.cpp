#include "student_functions.h"
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

double compute_student_total_score(const student & s, const grading_schema & g)
{   
    try
    {
        double sum_of_components = g.final_weight + g.hw_weight + g.midterm_weight;
        if ((sum_of_components < 0.99) || (sum_of_components > 1.01))
            throw exception();
    }
    catch(const exception& e)
    {
        cerr << e.what() << ": invalid grading schema" << '\n';
        return -1;
    }
    
    double final_total_score{0.0};
    double sum{0.0}, hw_average{0.0};

    if (s.hw_grades.size() == 0) {
        double sum_of_weights = g.final_weight + g.midterm_weight;
        hw_average += (g.final_weight / sum_of_weights) * s.final;
        hw_average += (g.midterm_weight / sum_of_weights) * s.midterm;
    } else {
        for (auto h_score : s.hw_grades) {
            sum += h_score;
        }
        hw_average = sum / s.hw_grades.size();
    }

    final_total_score = (hw_average * g.hw_weight) + (s.midterm * g.midterm_weight) + (s.final * g.final_weight);
    return final_total_score;
}

grading_schema get_grading_schema() 
{
    double midterm_weight, final_weight, hw_weight;
    grading_schema g;
    cout << "Enter weight of midterm grade: ";
    cin >> midterm_weight;
    
    cout << "Enter weight of final grade: ";
    cin >> final_weight;

    cout << "Enter weight of homework average: ";
    cin >> hw_weight;

    try
    {
        double sum_of_components = final_weight + hw_weight + midterm_weight;
        if ((sum_of_components < 0.99) || (sum_of_components > 1.01))
            throw exception();
    }
    catch(const exception& e)
    {
        cerr << e.what() << ": invalid grading schema, set to default weights" << '\n';
        return g;
    }

    g.midterm_weight = midterm_weight;
    g.final_weight = final_weight;
    g.hw_weight = hw_weight;

    return g;
}

student get_student_struct_data() 
{
    student s;
    cout << "Enter the student's id: ";
    cin >> s.id;

    cout << "Enter the student's name: ";
    cin >> s.name;
    
    cout << "Enter the student's midterm: ";
    cin >> s.midterm;

    cout << "Enter the student's final: ";
    cin >> s.final;

    cout << "Enter a homework score (-1 to exit): ";
    int score; 
    while(cin >> score && score != -1) {
        cout << "Enter a homework score (-1 to exit): ";
        s.hw_grades.push_back(score);
    }
    
    return s;    
}

void output_student_struct_data(const student & s)
{
    cout << "Student id: " << s.id << endl
         << "Student name: " << s.name << endl
         << "Student homework grades: ";
    for (auto h_score : s.hw_grades) 
        cout << h_score << " ";
    cout << endl
         << "Student midterm exam grade: " << s.midterm << endl
         << "Student final exam grade: " << s.final << endl;
}