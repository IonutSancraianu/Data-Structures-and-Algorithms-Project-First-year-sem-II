#pragma once

#include "Multime.h"
#include "Message.h"
#include <string>
#include <iostream>

using namespace std;

class RepoMessageFile
{
private:
	Multime<Message> messages;
	string filename;
public:
	RepoMessageFile();
	RepoMessageFile(const string&);
	~RepoMessageFile();
	void save_to_file();
	void load_from_file();
	bool find(Message& m);
	void add_message(Message& m);
	void del_message(Message& m);
	void update_message(Message& m, Message& m_new);
	void display_all_messages();
	Multime<Message> get_first();
	int number_messages();
};
