/*************************************************************
* Oscar Lugo
* CS311 - Data Structures
* Lab2 - Virtual Function
* 9/17/17
*/

#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include<typeinfo>

using namespace std;

void printingDifferentObjects(vector <Student*> s);

int main()
{
	//Create vector of Student references
	vector <Student*> stu;
	//Create list of combination of students 
	Graduate grad = Graduate("Mr Jones","USB Connections","Joe Mixon", 23, 1234);
	Undergraduate underG = Undergraduate(2019,60,"Oscar Lugo", 25, 5678);
	Graduate grad2 = Graduate("Mr Jones","ARM Architecture","Phillip Rivers",32,7565);
	Undergraduate underG2 = Undergraduate(2020,30,"Jane Doe", 19,6342);
	Graduate grad3 = Graduate("Mr Jackson","CPU Designs","Melvin Gordon",24,62413);
	Undergraduate underG3 = Undergraduate(2018,80,"Bruce Wayne", 27,6558);
	
	//add list to vector
	stu.push_back(&grad);
	stu.push_back(&underG2);
	stu.push_back(&grad3);
	stu.push_back(&grad2);
	stu.push_back(&underG);
	stu.push_back(&underG3);

	printingDifferentObjects(stu);

    return 0;
}

void printingDifferentObjects(vector <Student*> s)
{
	Student *stdptr;

	for (int i = 0; i < s.size(); i++)
	{
		stdptr = s[i];
		stdptr->printInfo(); //using Dynamic binding to call proper function
	}
	
}