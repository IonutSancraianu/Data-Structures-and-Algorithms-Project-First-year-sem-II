#include "FriendsRepositoryFile.h"

#include <iostream>
#include <fstream>
#include <string>
#include "Exeption.h"

using namespace std;

FriendsRepoFile::FriendsRepoFile()
{
}

FriendsRepoFile::FriendsRepoFile(const string& filename)
{
	this->filename = filename;
	this->load_from_file();
}

FriendsRepoFile::~FriendsRepoFile()
{
}

void FriendsRepoFile::save_to_file()
{
	ofstream f(this->filename);
	auto aux = this->friends.get_first();
	while (aux != nullptr)
	{
		Friends fr(aux->info);
		f << fr.get_id() << " " << fr.get_id_user1() << " " << fr.get_id_user2();
		if (aux->next != nullptr)
			f << endl;
		aux = aux->next;
	}
	f.close();
}

void FriendsRepoFile::load_from_file()
{
	ifstream f(this->filename);
	bool is_empty = f.peek() == EOF;
	while (!f.eof() && !is_empty)
	{
		int id, id_user1, id_user2;
		f >> id >> id_user1 >> id_user2;
		Friends fr(id, id_user1, id_user2);
		this->friends.add(fr);
	}

	f.close();
}

bool FriendsRepoFile::find(Friends& fr)
{
	return this->friends.find(fr);
}

void FriendsRepoFile::add_friend(Friends& fr)
{
	try
	{
		if (!this->find(fr))
		{
			this->friends.add(fr);
			this->save_to_file();
		}
		else
			throw(Exception("Prietenia pe care doriti sa o adaugati exista deja."));
	}
	catch (Exception(e))
	{
		cout << "Exeption: " << e.getMessage() << endl;
	}
}

void FriendsRepoFile::delete_friend(Friends& fr)
{
	try
	{
		if (this->find(fr))
		{
			this->friends.remove(fr);
			this->save_to_file();
		}
		else
			throw(Exception("Prietenia pe care doriti sa o stergeti nu exista deja."));
	}
	catch (Exception(e))
	{
		cout << "Exeption: " << e.getMessage() << endl;
	}
}

void FriendsRepoFile::update_friend(Friends& fr, Friends& fr_nou)
{

	try
	{
		if (this->find(fr))
		{
			if (!this->find(fr_nou))
			{
				this->friends.update(fr, fr_nou);
				this->save_to_file();
			}
			else
				throw(Exception("Prietenia noua este deja existenta."));
		}
		else
			throw(Exception("Prietenia pe care doriti sa o actualizati exista deja."));
	}
	catch (Exception(e))
	{
		cout << "Exeption: " << e.getMessage() << endl;
	}
}

int FriendsRepoFile::numar_prietenii()
{
	return this->friends.get_size();
}

void FriendsRepoFile::display_all_friendships()
{
	auto first = this->friends.get_first();
	while (first != nullptr)
	{
		cout << first->info;
		first = first->next;
	}
}

Multime<Friends> FriendsRepoFile::get_all()
{
	return this->friends;
}

