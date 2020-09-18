#include <iostream>
#include <string>
#include "Roster.h"
#include "Student.h"
using namespace std;

int main() {
	
	cout << "Scripting and Programming - Applications - C867\tC++\t001040234\tRachel Lawson" << endl;

	Roster classRoster(5);

	cout << "Parsing data and adding students... ";

	for (int i = 0; i < numStudents; i++) {
		int dayArray[3];
		DegreeProgram program = SECURITY;
		//set the ID
		int rhs = studentData[i].find(",");
		string studentID = studentData[i].substr(0, rhs);

		//set the first name
		int lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string firstName = studentData[i].substr(lhs, rhs - lhs);

		//set last name
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = studentData[i].substr(lhs, rhs - lhs);

		//set email address
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string emailAddress = studentData[i].substr(lhs, rhs - lhs);

		//set age
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs));

		//set each # of days
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		dayArray[0] = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		dayArray[1] = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		dayArray[2] = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].length() - 1; //trying to make rhs equal the last character
		string degreeString = studentData[i].substr(lhs, rhs);
		if (degreeString == "SECURITY") {
			program = DegreeProgram::SECURITY;
		}
		if (degreeString == "NETWORK") {
			program = DegreeProgram::NETWORK;
		}
		if (degreeString == "SOFTWARE") {
			program = DegreeProgram::SOFTWARE;
		}
		classRoster.add(studentID, firstName, lastName, emailAddress, age, dayArray[0], dayArray[1], dayArray[2], program);
	}

	cout << "Done\n";

	cout << "Printing all students...\n";
	classRoster.printAll();

	cout << "Printing invalid emails...\n";
	classRoster.printInvalidEmails();

	cout << "Printing average days for each student...\n";
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}

	classRoster.PrintByDegreeProgram(SOFTWARE);

	cout << "Removing A3\n";
	classRoster.remove("A3");

	cout << "Printing all students...\n";
	classRoster.printAll();

	cout << "Removing A3\n";
	classRoster.remove("A3");
	
	system("pause");
	return 0;

}