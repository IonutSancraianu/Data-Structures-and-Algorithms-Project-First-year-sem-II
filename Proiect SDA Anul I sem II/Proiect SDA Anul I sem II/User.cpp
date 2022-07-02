#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

User::User()
{
	this->id = 0;
	this->mail = "";
	this->nume = "";
}

User::User(int id, string nume, string mail)
{
	this->id = id;
	this->mail = mail;
	this->nume = nume;
}

User::User(const User& user)
{
	this->id = user.id;
	this->nume = user.nume;
	this->mail = user.mail;
}

User::~User()
{
}

int User::get_id()
{
	return this->id;
}

string User::get_nume()
{
	return this->nume;
}

string User::get_mail()
{
	return this->mail;
}

bool User::operator==(const User& u)
{
	return this->id == u.id && this->nume == u.nume && this->mail == u.mail;
}

string User::to_string_delimiter(char sep)
{
	return to_string(this->id) + sep + this->nume + sep + this->nume;
}

ostream& operator<<(ostream& out, const User& user)
{
	out << "Utilizator Id: " << user.id << " Nume: " << user.nume << " Mail: " << user.mail << endl;
	return out;
}
