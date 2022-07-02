#include "MessageRepoFile.h"
#include "Exeption.h"
#include <fstream>
#include <iostream>
using namespace std;

RepoMessageFile::RepoMessageFile()
{
}

RepoMessageFile::RepoMessageFile(const string& filename)
{
	this->filename = filename;
	this->load_from_file();
}

RepoMessageFile::~RepoMessageFile()
{
}

void RepoMessageFile::save_to_file()
{
	ofstream f(this->filename);
	auto aux = this->messages.get_first();
	while (aux != nullptr)
	{
		Message m(aux->info);
		f << m.get_id() << " " << m.get_id_sender() << " " << m.get_id_receiver() << " " << m.get_content();
		if (aux->next != nullptr)
			f << endl;
		aux = aux->next;
	}
	f.close();
}

void RepoMessageFile::load_from_file()
{

	ifstream f(this->filename);
	bool is_empty = f.peek() == EOF;
	while (!f.eof() && !is_empty)
	{
		int id, id_sender, id_receiver;
		string content;
		f >> id >> id_sender >> id_receiver >> content;
		Message m(id, id_sender, id_receiver, content);
		this->messages.add(m);
	}

	f.close();
}

bool RepoMessageFile::find(Message& m)
{
	return this->messages.find(m);
}

void RepoMessageFile::add_message(Message& m)
{
	try
	{
		if (!this->find(m))
		{
			this->messages.add(m);
			this->save_to_file();
		}
		else throw(Exception("Mesajul pe care vreti sa il adaugati are acelasi id ca un mesaj precedent. Schimbati id-ul mesajului."));
	}
	catch (Exception(e))
	{
		cout << "Exception: " << e.getMessage();
	}
}

void RepoMessageFile::del_message(Message& m)
{
	try
	{
		if (this->find(m))
		{
			this->messages.remove(m);
			this->save_to_file();
		}
		else throw(Exception("Mesajul pe care vreti sa il stergeti nu exista."));
	}
	catch (Exception(e))
	{
		cout << "Exception: " << e.getMessage();
	}
}

void RepoMessageFile::update_message(Message& m, Message& m_new)
{
	try
	{
		if (!this->find(m))
		{
			this->messages.update(m, m_new);
			this->save_to_file();
		}
		else throw(Exception("Mesajul pe care vreti sa il modificati nu exista."));
	}
	catch (Exception(e))
	{
		cout << "Exception: " << e.getMessage();
	}
}

void RepoMessageFile::display_all_messages()
{
	auto first = this->messages.get_first();
	while (first != nullptr)
	{
		cout << first->info;
		first = first->next;
	}
}

Multime<Message> RepoMessageFile::get_first()
{
	return this->messages;
}

int RepoMessageFile::number_messages()
{
	return this->messages.get_size();
}
