#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
    cout << "Application: Visual Studio" << endl;
    cout << "Scripting & Programming Applications" << endl;
    cout << "Language used: C++" << endl;
    cout << "My student ID: 001044242" << endl;
    cout << "My name: Aubrey Quintana" << endl;
    cout << endl;

    Roster* classRoster = new Roster(numStudents);

    for (int i = 0; i < numStudents; i++) {
        classRoster->parse(studentData[i]);
    }
    cout << endl;

    classRoster->printAll();
    cout << endl;

    classRoster->printInvalidEmails();
    cout << endl;

    for (int i = 0; i < numStudents; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentId());
    }
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing StudentID 'A3' from Roster: " << endl;
    classRoster->remove("A3");
    cout << endl;
    
    cout << "Updated Roster with student removed: " << endl;
    classRoster->printAll();
    cout << endl;

    cout << "Removing Student ID 'A3' from Roster: " << endl;
    classRoster->remove("A3");
    //Should produce an error message of Student not found.

   

    //Roster::~Roster();



    
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
