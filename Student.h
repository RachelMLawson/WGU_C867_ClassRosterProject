#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Degree.h"
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysToCompleteCourse;
	DegreeProgram program;

public:
	const static int daysArraySize = 4;

	//Empty constructor
	Student();

	//Full constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram program);

	//Accessors
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysToCompleteCourse();
	DegreeProgram GetDegreeProgram();

	//Mutators
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysToCompleteCourse(int daysToCompleteCourse[]);
	void SetDegreeProgram(DegreeProgram program);
	void print();
	
	~Student();
};
