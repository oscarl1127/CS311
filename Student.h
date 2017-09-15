/*******
* Student.h file
*/

#include<string>
#include<iostream>

using namespace std;

class Student
{
public:
	Student();
	Student(string name, int age, long id);
	virtual void printInfo() = 0; // pure virtual
	~Student();

protected:
	string name;
	int age;
	int studentId;
};
//inherit from Student class
class Graduate : public Student
{
public:
	Graduate() : Student() {}; // inherits constructor from base class
	Graduate(string AdvisorName, string title, string name, int age, long id) : Student(name, age, id) 
	{
		this->AdvisorName = AdvisorName;
		this->thesisTitle = title;
	};
	virtual void printInfo();
	~Graduate();

private:
	string AdvisorName;
	string thesisTitle;
};
class Undergraduate : public Student
{
public:
	Undergraduate() : Student() {}; //inherits constructor from base class
	Undergraduate(int year, int NoCourses, string name, int age, long id) : Student(name, age, id) 
	{
		this->year = year;
		this->CourseCompleted = NoCourses;
	};
	virtual void printInfo();
	~Undergraduate();
private:
	int year;
	int CourseCompleted;

};
