#pragma once

#include <iostream>
#include <string>

using namespace std;

class User
{
private:
	int id;
	string nume;
	string mail;
public:
	User();
	User(int id, string nume, string mall);
	User(const User& user);
	~User();
	int get_id();
	string get_nume();
	string get_mail();
	friend ostream& operator<<(ostream& out, const User& user);
	bool operator==(const User&);
	string to_string_delimiter(char sep);
};
