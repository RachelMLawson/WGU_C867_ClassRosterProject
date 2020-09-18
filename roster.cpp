#include <string>
#include <iostream>
#include <iomanip>
#include "Roster.h"
using namespace std;		

Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	lastIndex++;
	int daysToCompleteCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* addedStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourse, degreeProgram);
	classRosterArray[lastIndex] = addedStudent;
}

void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (!found) {
		cout << "Student with this ID not found\n";
	}
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++)
		(this->classRosterArray)[i]->print();
}


void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			int* day = classRosterArray[i]->GetDaysToCompleteCourse();
			cout << "Average days to complete course for student " << studentID << " is " << (day[0] + day[1] + day[2]) / 3 << endl;
		}
	}
	if (!found) {
		cout << "Student not found\n";
	}
}

void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= lastIndex; i++) {
		if ((this->classRosterArray[i]->GetEmailAddress().find('@') == string::npos) ||
			(this->classRosterArray[i]->GetEmailAddress().find('.') == string::npos) ||
			(this->classRosterArray[i]->GetEmailAddress().find(' ') != string::npos)) {
			any = true;
			cout << "Student ID " << classRosterArray[i]->GetStudentID() << ": ";
			cout << this->classRosterArray[i]->GetEmailAddress() << endl;
		}	
	}
	if (any == false) {
		cout << "None" << endl;
	}
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Printing students in the " << degreeProgramStrings[degreeProgram] << " program... \n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

	Roster::~Roster() {
		for (int i = 0; i < numStudents; i++) {
			delete this->classRosterArray[i];
		}
		delete this;
	}

