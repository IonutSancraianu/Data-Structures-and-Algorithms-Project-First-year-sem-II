#pragma once
#include "Multime.h"
#include <string>

using namespace std;

class Message
{
private:
	int id, id_sender, id_receiver;
	string content;
public:
	Message();
	Message(int id, int id_sender, int id_receiver, string content);
	Message(Message& m);
	friend ostream& operator<<(ostream& out, const Message& user);
	bool operator==(const Message&);
	Message& operator=(const Message&);
	~Message();
	int get_id();
	int get_id_sender();
	int get_id_receiver();
	string get_content();

};


