/**********************************************
* Oscar Lugo
* 9/22/17
* CS 311
* Lab 3
*********************/

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<class T>
class Queue
{
public:
	Queue();
	void Push(const T&);
	T Pop();
	void ReadAnItem();
	
	friend ostream &operator<<(ostream &output, const Queue<T> &D) 
	{
		output << D.PrintQ();
		return output;
	}
	
	void PrintQ();
	~Queue();

protected:
	vector<T> theQ;
};

template<class T>
Queue<T>::Queue()
{

}

template<class T>
void Queue<T>::Push(const T& item)
{
	this->theQ.push_back(item);
}
template<class T>
T Queue<T>::Pop()
{
	T element = theQ.front();
	theQ.erase( theQ.begin() );
	return element;
}
template<class T>
void Queue<T>::ReadAnItem()
{
	T item;
	cout << "Enter the data please : " << endl;
	cin >> item;
	Push(item);
}
template<class T>
void Queue<T>::PrintQ()
{
	cout << "The content of the array is as follows : " << endl;
	for (int i = 0; i < theQ.size(); i++)
	{
		cout << theQ[i] << endl;
	}
}
template<class T>
Queue<T>::~Queue()
{
}


class Student
{
public:
	Student();
	Student(long i, int y, string sn) { stId = i; year = y; email = "Unknown"; schoolName = sn; }
	~Student();
	
	friend ostream &operator<<(ostream &output, const Student &D) {
		output << "Student ID: " << D.stId << " School Name: " << D.schoolName << " Year: " << D.year << " Email: " << D.email << endl;;
		return output;
	}
	
	friend istream &operator>>(istream  &input, Student &D) {
		input >> D.stId >> D.schoolName >> D.year >> D.email;
		return input;
	}
	
protected:
	long stId;
	int	year;
	string	email;
	string	schoolName;
};

class Employee
{
public:
	Employee();
	Employee(long i, string n) { empName = n, empId = i; email = "Unknow"; }
	friend ostream &operator<<(ostream &output, const Employee &D) 
	{
		output <<"Employee ID: " << D.empId << " Employee Name: " << D.empName << " Email: " << D.email << endl;;
		return output;
	}

	friend istream &operator>>(istream  &input, Employee &D) 
	{
		input >> D.empId >> D.empName >> D.email;
		return input;
	}

	~Employee();

protected:
	long empId;
	string empName;
	string email;
};

int main()
{	
	Queue<Student> stu;
	Queue<Employee> emp;	
	Queue<int> numbers;
	
	Student Joe(1234,11,"Lincoln HIgh School");
	Student Sam(5678, 9, "Lincoln HIgh School");
	Student Leah(6569, 12, "Lincoln HIgh School");

	Employee Oscar(4343,"Oscar Lugo");
	Employee Liz(7575,"Liz Jones");
	Employee Chris(7653,"Chris Mixon");

	stu.Push(Joe);
	stu.Push(Sam);
	stu.Push(Leah);
	stu.Pop();

	emp.Push(Oscar);
	emp.Push(Liz);
	emp.Push(Chris);
	emp.Pop();
	
	numbers.Push(1);
	numbers.Push(2);
	numbers.Push(3);
	numbers.Pop();
	
	stu.ReadAnItem();
	cout << "--------------------------------" << endl;
	cout << "Students " << endl;
	stu.PrintQ();
	emp.ReadAnItem();
	cout << "--------------------------------" << endl;
	cout << "Employees " << endl;
	emp.PrintQ();
	numbers.ReadAnItem();
	cout << "--------------------------------" << endl;
	cout << "Numbers " << endl;
	numbers.PrintQ();
	cout << endl;

    return 0;
}