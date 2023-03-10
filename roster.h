#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

const int numStudents = 5;

const string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Aubrey,Quintana,ahbree@gmail.com,29,65,36,10,SOFTWARE"
};

class Roster {
public:
	Roster(); //default constructor
	Roster(int capacity); //full constructor
	int lastStudent;
	int capacity;
	Student* *classRosterArray;
	void parse(string datarow);
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeType degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(degreeType degreeProgram);
	~Roster(); //deconstructor

};

