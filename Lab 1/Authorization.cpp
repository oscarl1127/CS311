/************************
* Authorization.cpp
*/

#include "stdafx.h"
#include "Authorization.h"
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

node::node()
{
	stId = 0;
	userid = "";
	password = "";
	node *top = NULL;
}
node::node(int stId, string user, string pass) {
	this->stId = stId;
	this->userid = user;
	this->password = pass;
	node *top = next;
}

	Authorization::Authorization() 
	{
		top = NULL;  //added 9/15
	
	}

	bool Authorization::AddMember(int studentId, string user, string  pass) {
		nodePtr curr = top;
		nodePtr prev = NULL;
		nodePtr newNode = new node(studentId,user, pass);
		bool found = false;

		//make sure doesn't exist
		if (SearchId(studentId)) {
			cout << "member cannot be added twice" << endl;
			return false;
		}
		//look for correct spot
		while (curr != NULL && !found)
		{
			if (studentId > curr->stId) {
				prev = curr;
				curr = curr->next;
			}
			else
			{
				found = true;
			}
		}
		//insert
		newNode->next = curr;
		if (prev == NULL) {
			top = newNode;
		}
		else {
			prev->next = newNode;
		}
		return true;
	}
	bool Authorization::RemoveMember(int studentId) {
		nodePtr P;
		nodePtr curr = new node();
		nodePtr temp = new node();
		P = top;
		//if key not found
		if (!SearchId(studentId))
		{
			cout << "student ID " << studentId <<" doesn't exist , while trying to remove " << endl;
			return false;
		}
		if (P->stId == studentId)
		{
			temp = P;
			P = P->next;
			top = P;   //added 9/15
		}
		else
		{
			curr = P;
			while (curr->next->stId != studentId)
			{
				curr = curr->next;
			}
			temp = curr->next;
			curr->next = curr->next->next;
		}
		delete temp;
		return true;
	}
	bool Authorization::SearchId(int StudentId) 
	{
		nodePtr P = top ;

		while (P != NULL)
		{
			if (P->stId == StudentId) {
				return true;
			}
			else
			{
				P = P->next;
			}
		}	
		//student id not found anywhere
		return false;
	}
	bool Authorization::ChangePassword(int userId, string newPass) {
		nodePtr P = top ;
		//search for user id
		while (P != NULL) {

			if (P->stId == userId) {
				//set password to new password 
				P->password = newPass;
				return true;
			}
			P = P->next;
		}
		return false;
	}
	bool Authorization::PrintAll() {
		nodePtr P = top;
		
		while (P != NULL) {
			cout << P->stId << "\t" << P->userid << "\t" << P->password << endl;
			P = P->next;
		}
		return true;
	}
	bool Authorization::PrintRecord(int StudentId) {
		nodePtr P = top;
		bool found = false;

		while ((P != NULL) && (!found)) 
		{
			if (P->stId == StudentId) {
				cout << "Record requested: " << P->stId << "\t" << P->userid << "\t" << P->password << endl;
				found = true;
				return true;
			}
			else
			{
				P = P->next;
			}
		}
			cout << "Student ID " << StudentId << " requested not found" << endl;
			return false;
	}
	bool Authorization::ProcessTransaction() {
		string line;
		string fileName;
		
		cout << "Enter Transaction file name" << endl;
		cin >> fileName;

		ifstream inFile(fileName);

		while (!inFile.eof())
		{
			int counter = 0; // reset counter
			string arr[4];
			int strToInt = 0;

			getline(inFile, line);

			for (int i = 0; i < line.length(); i++)
			{
				arr[counter] += line[i];

				if (line[i] == '\t')
				{
					counter++;
				}
			}
			//remove tab from strings
			for (int i = 0; i < 4; i++)
			{
				arr[i].erase(std::remove(arr[i].begin(), arr[i].end(), '\t'), arr[i].end());
			}

			if (arr[0] == "Insert") {
				//cout << "you found Insert" << endl;
				strToInt = stoi(arr[1]);
				AddMember(strToInt,arr[2],arr[3]);
				
			}
			else if (arr[0] == "Print") {
				//cout << "you found Print" << endl;
				PrintAll();
			}
			else if (arr[0] == "Delete") {
				//cout << "you found Delete" << endl;
				strToInt = stoi(arr[1]);
				RemoveMember(strToInt);
			}
			else if (arr[0] == "PrintRecord") {
				//cout << "you found PrintRecord" << endl;
				strToInt = stoi(arr[1]);
				PrintRecord(strToInt);
			}
			else if (arr[0] == "Find") {
				//cout << "you found Find" << endl;
				strToInt = stoi(arr[1]);
				if (SearchId(strToInt)) {
					PrintRecord(strToInt);
				}
				else
				{
					cout << "Student ID " << strToInt <<" requested not found" << endl;
				}
			}
			else if (arr[0] == "ChangePassword") {
				//cout << "you found ChangePassword" << endl;
				strToInt = stoi(arr[1]);
				ChangePassword(strToInt,arr[2]);
			}
			else {
				//cout << "no command given" << endl;
			}
		}

		inFile.close();
		return true;
	}
	bool Authorization::SaveConfiguration() {
		ofstream outFile;
		nodePtr P = top;

		outFile.open("C:\\Dropbox\\config.txt");

		while (P != NULL)
		{
			outFile << P->stId << "\t"
				<< P->userid << "\t"
				<< P->password << endl;

			P = P->next;
		}

		outFile.close();

		cout << "Saved to C:\\Dropbox\\config.txt" << endl;
		return true;
	}
	bool Authorization::LoadConfiguration() {
		ifstream inFile;
		inFile.open("C:\\Dropbox\\config.txt");
		int id;
		string user;
		string pass;

		while (inFile >> id >> user >> pass) {
			bool k;
			k = AddMember(id, user, pass);
		}
		inFile.close();

		return true;
	}
	Authorization::~Authorization() {

	}