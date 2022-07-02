#include "Message.h"

#include <string>
#include <iostream>

using namespace std;

Message::Message()
{
	this->id = 0;
	this->id_sender = 0;
	this->id_receiver = 0;
	this->content = "";
}

Message::Message(int id, int id_sender, int id_receiver, string content)
{
	this->id = id;
	this->id_sender = id_sender;
	this->id_receiver = id_receiver;
	this->content = content;
}

Message::Message(Message& m)
{
	this->id = m.id;
	this->id_sender = m.id_sender;
	this->id_receiver = m.id_receiver;
	this->content = m.content;
}

bool Message::operator==(const Message& m)
{
	return this->id == m.id && (this->id==m.id && this->id_sender==m.id_sender && this->id_receiver==m.id_receiver && this->content==m.content);
}

Message& Message::operator=(const Message& m)
{
	this->id = m.id;
	this->id_sender = m.id_sender;
	this->id_receiver = m.id_receiver;
	this->content = m.content;
	return *this;
}

Message::~Message()
{

}

int Message::get_id()
{
	return this->id;
}

int Message::get_id_sender()
{
	return this->id_sender;
}

int Message::get_id_receiver()
{
	return this->id_receiver;
}

string Message::get_content()
{
	return this->content;
}

ostream& operator<<(ostream& out, const Message& m)
{
	cout << m.content << endl;
	cout << "        Id expeditor: " << m.id_sender << "  Id destinatar: " << m.id_receiver << endl;;
	return out;
}
