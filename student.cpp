#pragma once
#include <iostream>
#include<iomanip>
#include <string>
#include "student.h"
using namespace std;

//empty constructor
Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	this->daysInCourse = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = 0;
	degreeProgram = degreeType::SOFTWARE;
}
//full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], degreeType degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse = new int[daysArraySize]; //created dynamically
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}


//setters for Student class
void Student::SetStudentId(string studentId) {
	studentID = studentId;
	return;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}
void Student::SetEmailAddress(string email) {
	emailAddress = email;
	return;
}
void Student::SetAge(int ageYears) {
	age = ageYears;
	return;
}
void Student::SetDaysInCourse(int daysInCourse[]) {
	this->daysInCourse = daysInCourse;
	return;
}
void Student::SetDegreeProgram(degreeType degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;
}
//getters for Student class

string Student::GetStudentId() {
	return studentID;
}
string Student::GetFirstName() {
	return firstName;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetEmailAddress() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
int* Student::GetDaysInCourse() {
	return daysInCourse;
}
degreeType Student::GetDegreeProgram() {
	return degreeProgram;
}
void Student::Print() {
	cout << left << setw(4) << GetStudentId();
	cout << left << "First name: " << setw(10) << GetFirstName();
	cout << left << "Last name: " << setw(10) << GetLastName();
	cout << left << "E-mail: " << setw(25) << GetEmailAddress();
	cout << left << "Age: " << setw(4) << GetAge();
	cout << left << "Number of days in each course: " << setw(4) << daysInCourse[0];
	cout << left << setw(4) << daysInCourse[1];
	cout << left << setw(4) << daysInCourse[2];
	cout << left << "Degree Program: " << setw(10) << degreeTypeStrings[GetDegreeProgram()] << endl;
	return;
}
Student::~Student() { //daysInCourse was made dynamically so we need to use the destructor to get rid of it
	if (daysInCourse != nullptr) {
		delete[] daysInCourse;
		daysInCourse = nullptr;
	}
}
