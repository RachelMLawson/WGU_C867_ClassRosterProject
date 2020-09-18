#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

const int numStudents = 5;
const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Rachel,Lawson,arremel@gmail.com,30,25,20,30,SOFTWARE" };


class Roster {
public: 
	int lastIndex;
	int capacity; 
	Student** classRosterArray;

	Roster();
	Roster(int capacity);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};