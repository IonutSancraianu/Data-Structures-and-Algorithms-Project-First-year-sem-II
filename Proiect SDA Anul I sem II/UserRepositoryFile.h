#pragma once

#include "Multimap.h"
#include "User.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class UserRepoFile
{
private:
	Multimap<int, User> users;
	string filename;
public:
	UserRepoFile();
	UserRepoFile(string filename);
	~UserRepoFile();
	int get_number_of_users();
	void save_to_file();
	void load_from_file();
	void add_user(User& u);
	void del_user(int id);
	bool is_empy();
	void update_user(User& u);
	void display_all_users();
	bool find(int id);
	User get_user(int key);
	Multimap<int, User> get_all();
};