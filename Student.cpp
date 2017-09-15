/*******
* Student.cpp file
*/

#include "stdafx.h"
#include "Student.h"
#include<iostream>
#include<string>

using namespace std;

Student::Student()
{
}
Student::Student(string name, int age, long id)
{
	this->name = name;
	this->age = age;
	this->studentId = id;
}
void Student::printInfo()
{
	
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Student ID: " << this->studentId<< endl;
	cout << "-------------------------------------" << endl;
	cout << " "<<endl;
}
Student::~Student(){}
void Graduate::printInfo() 
{
	cout << "Graduate Student " << endl;
	cout << "Advisor Name: " << this->AdvisorName << endl;
	cout << "Thesis Title: " << this->thesisTitle << endl;
	Student::printInfo();
}
Graduate::~Graduate(){}
void Undergraduate::printInfo()
{
	cout << "Undergraduate Student " << endl;
	cout << "Graduation year: " << this->year << endl;
	cout << "Courses completed: " << this->CourseCompleted << endl;
	Student::printInfo();
}
Undergraduate::~Undergraduate(){}