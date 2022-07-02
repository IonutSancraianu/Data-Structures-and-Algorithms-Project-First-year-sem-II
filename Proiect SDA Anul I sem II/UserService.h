#pragma once


#include "UserRepositoryFile.h"
#include "User.h"

#include <iostream>
#include <string>

using namespace std;

class UserService
{
private:
	UserRepoFile repo;
public:
	UserService();
	UserService(UserRepoFile& repo);
	~UserService();
	void add_user(int id, string nume, string mail);
	void stergere(int id);
	void update(int id, string nume, string mail);
	bool find(int id);
	int number_of_users();
	User get_user(int key);
	Multimap<int, User> get_all();
	void display_all_users();
}; 