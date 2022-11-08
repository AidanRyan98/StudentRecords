#include <iostream>
#include "functions.h"
#include <vector>

using namespace std;

int main() {
    string school_name;
    int num_students;
    string student_first_name;
    string student_last_name;
    int student_classes;

    //Create School Object
    cout << "Enter name of school: ";
    cin >> school_name;
    cout << "How many students are in this school: ";
    cin >> num_students;

    School SchoolObject = School(school_name, num_students);

    //Print Welcome Message
    cout << "Welcome to " << SchoolObject.school_name << "!" << endl;

    //Create array of students
    Student StudentArray[SchoolObject.num_students];

    //Complete students details
    for (int i = 0; i < SchoolObject.num_students; i++) {
        cout << "~~~Student " << i + 1 << "~~~" << endl;
        cout << "First Name: ";
        cin >> student_first_name;
        cout << "Last Name: ";
        cin >> student_last_name;
        cout << "Classes: ";
        cin >> student_classes;

        Student new_student(student_first_name, student_last_name, student_classes);
        StudentArray[i] = new_student;
    }

    //Complete students subject choice
    for (int j = 0; j < SchoolObject.num_students; j++) {
        StudentArray[j].SubjectChoice(SchoolObject);
    }

    //Calculate Student Grades
    for (int k = 0; k < SchoolObject.num_students; k++) {
        StudentArray[k].StudentGrade();
    }
}