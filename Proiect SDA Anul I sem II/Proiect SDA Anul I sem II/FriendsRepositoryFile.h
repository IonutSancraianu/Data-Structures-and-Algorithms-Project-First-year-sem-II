#pragma once

#include "Multime.h"
#include "Friends.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FriendsRepoFile
{
private:
	Multime<Friends> friends;
	string filename;
public:
	FriendsRepoFile();
	FriendsRepoFile(const string&);
	~FriendsRepoFile();
	void save_to_file();
	void load_from_file();
	bool find(Friends& fr);
	void add_friend(Friends& fr);
	void delete_friend(Friends& fr);
	void update_friend(Friends& fr, Friends& fr_nou);
	int numar_prietenii();
	void display_all_friendships();
	Multime<Friends> get_all();
};
