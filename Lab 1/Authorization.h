/**********************************
* Authorization.h
*/

#include<iostream>
#include<string>

using namespace std;

class node;
typedef node* nodePtr;

class node
{
public:
	int stId;
	string userid;
	string password;
	nodePtr next;
	node();
	node(int id, string user, string pass);
};

class Authorization
{
private:
	nodePtr top;
public:
	Authorization();
	bool AddMember(int studentId, string user, string  pass);
	bool RemoveMember(int studentId);
	bool SearchId(int StudentId);
	bool ChangePassword(int userId, string newPass);
	bool PrintAll();
	bool PrintRecord(int StudentId);;
	bool ProcessTransaction();
	bool SaveConfiguration();
	bool LoadConfiguration();
	~Authorization();
};
