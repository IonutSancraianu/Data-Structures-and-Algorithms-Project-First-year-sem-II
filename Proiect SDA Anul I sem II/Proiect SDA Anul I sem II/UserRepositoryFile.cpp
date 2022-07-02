#include "UserRepositoryFile.h"
#include "Multimap.h"
#include "Exeption.h"
#include "User.h"
#include <fstream>

UserRepoFile::UserRepoFile()
{
}

UserRepoFile::UserRepoFile(string filename)
{
	this->filename = filename;
	this->load_from_file();
}

int UserRepoFile::get_number_of_users()
{
	return this->users.get_size();
}

void UserRepoFile::save_to_file()
{
	ofstream f(this->filename);
	auto aux = this->users.get_first();
	while (aux != nullptr)
	{
		User u(aux->value->info);
		f << u.get_id() << " " << u.get_nume() << " " << u.get_mail();
		if (aux->next != nullptr)
			f << endl;
		aux = aux->next;
	}
	f.close();
}

void UserRepoFile::load_from_file()
{
	ifstream f(this->filename);
	bool is_empty = f.peek() == EOF;
	while (!f.eof() && !is_empty)
	{
		string nume,mail;
		int id;
		f >> id >> nume >> mail;
		User u(id, nume, mail);
		add_user(u);
	}
	/*if (!is_empty)
	{
		auto aux = this->users.get_first();
		while (aux->next != nullptr)
			aux = aux->next;
		this->users.remove(aux->key);
	}*/
	

	f.close();
}


void UserRepoFile::add_user(User& u)
{
	try
	{
		if (!this->find(u.get_id()))
		{
			this->users.put(u.get_id(), u);
			this->save_to_file();
		}
		else
			throw(Exception("Utilizatorul pe care doriti sa il adaugati exista deja"));
	}
	catch (Exception(e))
	{
		cout << "Exception: " << e.getMessage() << endl;
	}
}

void UserRepoFile::del_user(int id)
{
	try
	{
		if (this->find(id))
		{
			this->users.remove(id);
			this->save_to_file();
		}
		else
			throw (Exception("Utilizatorul pe care doriti sa il stergeti nu exista."));
	}
	catch (Exception(e))
	{
		cout << "Exception: " << e.getMessage() << endl;
	}
	
}

bool UserRepoFile::is_empy()
{
	ifstream f(this->filename);
	bool is_empty = f.peek() == EOF;
	f.close();
	return is_empty;
}

void UserRepoFile::update_user(User& u)
{
	try
	{
	if (this->find(u.get_id()))
		{
			this->users.put(u.get_id(), u);
			this->save_to_file();
		}
	else
		throw(Exception("Utilizatorul pe care doriti sa il actualizati nu exista."));
	}
	catch (Exception(e))
	{
		cout << "Eception: " << e.getMessage() << endl;
	}
}

void UserRepoFile::display_all_users()
{
	auto aux = this->users.get_first();
	while(aux != nullptr)
	{
		cout << aux->value->info;
		aux = aux->next;
	}
}

bool UserRepoFile::find(int id)
{
	return this->users.find(id);
}

User UserRepoFile::get_user(int key)
{
	auto aux = this->users.get_first();
	while (aux != nullptr)
	{
		if (aux->key == key)
			return aux->value->info;
		aux = aux->next;
	}
}

Multimap<int, User> UserRepoFile::get_all()
{
	return this->users;
}


UserRepoFile::~UserRepoFile()
{
}
