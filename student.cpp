#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

//Empty constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToCompleteCourse = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; i++) {
		this->daysToCompleteCourse[i] = 0;
	}
	this->program = SECURITY;
}

//Full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram program) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToCompleteCourse = new int[daysArraySize];
	for (int i = 0; i < 3; i++) {
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
	this->program = program;
}

//Accessors
string Student::GetStudentID() {
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
int* Student::GetDaysToCompleteCourse() {
	return daysToCompleteCourse;
}
DegreeProgram Student::GetDegreeProgram() {
	return program;
}

//Mutators
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::SetAge(int age) {
	this->age = age;
}
void Student::SetDaysToCompleteCourse(int daysToCompleteCourse[]) {
	for (int i = 0; i < 3; i++) {
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram program) {
	this->program = program;
}

//Print student data
void Student::print() {
	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Email Address: " << emailAddress << "\t";
	cout << "Age: " << age << "\t";
	cout << "daysInCourse: " << daysToCompleteCourse[0] << " " << daysToCompleteCourse[1] << " " << daysToCompleteCourse[2] << "\t";
	cout << "Degree Program: " << degreeProgramStrings[GetDegreeProgram()] << endl;
}

Student::~Student() {
	if (daysToCompleteCourse != nullptr) {
		delete[] daysToCompleteCourse;
		daysToCompleteCourse = nullptr;
	}
}