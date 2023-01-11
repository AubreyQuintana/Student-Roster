#pragma once
#include<iostream>
#include "degree.h"
#include<string>
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysInCourse; //Number of days to complete each course
	degreeType degreeProgram; //enumerator degree type

public:
	const static int daysArraySize = 3;
	Student(); //empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse[], degreeType degreeProgram); //full constructor

	//setters for each instance field
	void SetStudentId(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string email);
	void SetAge(int ageYears);
	void SetDaysInCourse(int daysInCourse[]);
	void SetDegreeProgram(degreeType degreeProgram);

	//getters for each instance field
	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysInCourse();
	degreeType GetDegreeProgram();
	void Print();

	//the destructor
	~Student();

};

