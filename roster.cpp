#pragma once
#include <iostream>
#include "roster.h"
#include <string>
using namespace std;

Roster::Roster() { //default constructor
	this->capacity = 0;
	this->lastStudent = -1; //implying the roster is empty
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) { //full constructor
	this->capacity = capacity;
	this->lastStudent = -1; //empty roster
	this->classRosterArray = new Student * [capacity];
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeType degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		classRosterArray[lastStudent] = new Student(studentID, firstName, lastName, emailAddress,
			age, daysInCourse, degreeProgram);
}

void Roster::parse(string datarow) {
	if (lastStudent < capacity) {
		lastStudent++;

		//Set the student ID
		int rhs = datarow.find(",");
		//classRosterArray[lastStudent]->SetStudentId(studentData[lastStudent].substr(0, rhs));
		string studentID = (datarow.substr(0, rhs));

		//Set first name
		int lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		//classRosterArray[lastStudent]->SetFirstName(studentData[lastStudent].substr(lhs, rhs - lhs));
		string firstName = (datarow.substr(lhs, rhs - lhs));

		//Set last name
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		//classRosterArray[lastStudent]->SetLastName(studentData[lastStudent].substr(lhs, rhs - lhs));
		string lastName = (datarow.substr(lhs, rhs - lhs));

		//Set email address
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		//classRosterArray[lastStudent]->SetEmailAddress(studentData[lastStudent].substr(lhs, rhs - lhs));
		string emailAddress = (datarow.substr(lhs, rhs - lhs));

		//set age
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		//classRosterArray[lastStudent]->SetAge(stoi(studentData[lastStudent].substr(lhs, rhs - lhs)));
		int age = stoi(datarow.substr(lhs, rhs - lhs));

		//set days in course
		int daysInCourse[3];
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		daysInCourse[0] = stoi(datarow.substr(lhs, rhs - lhs));
		int daysInCourse1 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		daysInCourse[1] = stoi(datarow.substr(lhs, rhs - lhs));
		int daysInCourse2 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		daysInCourse[2] = stoi(datarow.substr(lhs, rhs - lhs));
		int daysInCourse3 = stoi(datarow.substr(lhs, rhs - lhs));

		//set degree type
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string degreeP = (datarow.substr(lhs, rhs - lhs));

		degreeType degreeProgram = SOFTWARE;
		if (degreeP == "SOFTWARE") {
			//classRosterArray[lastStudent]->SetDegreeProgram(degreeType::SOFTWARE);
			degreeProgram = SOFTWARE;
		}
		else if (degreeP == "NETWORK") {
			//classRosterArray[lastStudent]->SetDegreeProgram(degreeType::NETWORK);
			degreeProgram = NETWORK;
		}
		else if (degreeP == "SECURITY") {
			//classRosterArray[lastStudent]->SetDegreeProgram(degreeType::SECURITY);
			degreeProgram = SECURITY;
		}

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}
}


void Roster::remove(string studentID)
{
	if (lastStudent < capacity) {
		bool foundID = false;
		for (int i = 0; i <= lastStudent; i++) {
			if (this->classRosterArray[i]->GetStudentId() == studentID) {
				foundID = true;
				delete this->classRosterArray[i]; //removing that Student from Roster
				this->classRosterArray[i] = this->classRosterArray[lastStudent]; //change where it points to
				lastStudent--; //changing the Roster to have one less element
				cout << studentID << " has been removed." << endl;
			}
		}
		if (!foundID) cout << "Student not found." << endl;
	}
}


void Roster::printAll() {
	cout << "All students in roster: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->Print(); 
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->Student::GetStudentId() == studentID) {//Student is found
			int* day = classRosterArray[i]->GetDaysInCourse();
			cout << classRosterArray[i]->GetFirstName() << "'s average amount of days in each course: " << (day[0] + day[1] + day[2]) / 3 << endl;
		}
	}
	

}

void Roster::printInvalidEmails() {
	cout << "Invalid e-mail addresses: " << endl;
	for (int i = 0; i < numStudents; i++) {
		string email = classRosterArray[i]->GetEmailAddress();
		if (email.find('@') == string::npos) {
			cout << email << ". -> Invalid, missing @ symbol" << endl;
		}
		else if (email.find(' ') != string::npos) {
			cout << email << ". -> Invalid, contains a space" << endl;
		}
		else if (email.find('.') == string::npos) {
			cout << email << ". -> Invalid, missing . symbol" << endl;
		}
	}
}

void Roster::printByDegreeProgram(degreeType degreeProgram) {
	
	cout << "Students who chose " << degreeTypeStrings[degreeProgram] << " for their major: " << endl;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}

	}
}


	Roster::~Roster() { //destructor gets rid of the student objects created dynamically
	for (int i = 0; i < numStudents; i++) {
		delete this->classRosterArray[i];
	}
	delete this;

}
