#pragma once
#include <iostream>

using namespace std;

//School Class
class School {
public:
    string school_name;
    int num_students;
    string subjects[5] = { "English", "Irish", "Maths", "Science", "History" };

    //Default Constructor
    School() {
        school_name = "School";
        num_students = 0;
    }

    //Constructor
    School(string a, int b) {
        school_name = a;
        num_students = b;
    }
};

//Student Class
class Student {
public:
    string first_name;
    string last_name;
    int num_classes;
    string* subject_choice;
    string* subject_grade;
    int grade_in_percentage;
    double gpa;

    //Default constructor
    Student() {
        first_name = "John";
        last_name = "Doe";
        num_classes = 0;
        subject_choice = new string[num_classes];
        subject_grade = new string[num_classes];
    }

    //Constructor
    Student(string a, string b, int c) {
        first_name = a;
        last_name = b;
        num_classes = c;
        subject_choice = new string[num_classes];
        subject_grade = new string[num_classes];
    }

    void SubjectChoice(School SchoolObject) {
        //Decide what subjects the student studies
        int i = 0;
        int subject_counter = 0;
        char response;

        while (i < num_classes) {
            //Ask the user if the student studies each subject
            cout << "Does " << first_name << " " << last_name << " study " << SchoolObject.subjects[subject_counter] << "? Y/N: " << endl;
            cin >> response;

            //convert response to uppercase
            response = toupper(response);

            //if the student does that subject, add it to their array
            if (response == 'Y') {
                subject_choice[i] = SchoolObject.subjects[subject_counter];
                i++;
            }

            subject_counter++;

            //reset counter
            if (subject_counter >= 5) {
                subject_counter = 0;
            }
        } // End while loop
    } // End function SubjectChoice

    //Student grades
    void StudentGrade() {
        string grade = "F+";
        double grade_total = 0.0;

        //message to user about grading system
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "The grade range for this school is A+, A, A-, B+, B, B-, C+, C, C-, D+, D, D-, F" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "For Student: " << first_name << " " << last_name << endl;

        //itterate through each of the students subjects and assign a grade to them
        for (int i = 0; i < num_classes; i++) {
            cout << "Enter Grade for " << subject_choice[i] << ": " << endl;
            cin >> grade;

            //convert grade to percentge
            if (grade == "A+" || grade == "a+") {
                grade_total += 4.3;
            }
            else if (grade == "A" || grade == "a") {
                grade_total += 4;
            }
            else if (grade == "A-" || grade == "a-") {
                grade_total += 3.7;
            }
            else if (grade == "B+" || grade == "b+") {
                grade_total += 3.3;
            }
            else if (grade == "B" || grade == "b") {
                grade_total += 3;
            }
            else if (grade == "B-" || grade == "b-") {
                grade_total += 2.7;
            }
            else if (grade == "C+" || grade == "c+") {
                grade_total += 2.3;
            }
            else if (grade == "C" || grade == "c") {
                grade_total += 2;
            }
            else if (grade == "C-" || grade == "c-") {
                grade_total += 1.7;
            }
            else if (grade == "D+" || grade == "d+") {
                grade_total += 1.3;
            }
            else if (grade == "D" || grade == "d") {
                grade_total += 1;
            }
            else if (grade == "D-" || grade == "d-") {
                grade_total += 0.7;
            }
            else {
                grade_total += 0;
            }
        } // End for loop

        //calculate GPA based on grade_total
        gpa = grade_total / num_classes;

        cout << "Student " << first_name << " " << last_name << " has a GPA of " << gpa << endl;
    } // End function StudentGrade
};