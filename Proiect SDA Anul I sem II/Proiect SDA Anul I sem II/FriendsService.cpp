#include "FriendsService.h"
#include "Friends.h"
#include "Exeption.h"
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


FriendsService::FriendsService()
{

}

FriendsService::FriendsService(FriendsRepoFile& repo, UserService& user_service)
{
	this->repo = repo;
	this->user_service = user_service;
}

FriendsService::~FriendsService()
{
}

void FriendsService::add_friend(int id, int id_user_1, int id_user_2)
{
	try
	{
		if (!this->user_service.find(id_user_1))
			throw("Utilizatorul cu id: " + to_string(id_user_1) + " nu exista.");
		if (!this->user_service.find(id_user_2))
			throw("Utilizatorul cu id: " + to_string(id_user_2) + " nu exista.");
		Friends fr(id, id_user_1, id_user_2);
		this->repo.add_friend(fr);
	}
	catch (Exception(e))
	{
		cout << "Exceptio: " << e.getMessage();
	}
	
}

void FriendsService::del_friend(int id, int id_user_1, int id_user_2)
{
	try
	{
		if (!this->user_service.find(id_user_1))
			throw("Utilizatorul cu id: " + to_string(id_user_1) + " nu exista.");
		if (!this->user_service.find(id_user_2))
			throw("Utilizatorul cu id: " + to_string(id_user_2) + " nu exista.");
		Friends f(id, id_user_1, id_user_2);
		this->repo.delete_friend(f);
	}
	catch (Exception(e))
	{
		cout << "Exceptio: " << e.getMessage();
	}
}

void FriendsService::update_friend(int id, int id_user_1, int id_user_2, int id_new, int id_user1_new, int id_user2_new)
{
	try
	{
		if(!this->user_service.find(id_user_1))
			throw("Utilizatorul cu id: " + to_string(id_user_1) + " nu exista.");
		if (!this->user_service.find(id_user_2))
			throw("Utilizatorul cu id: " + to_string(id_user_2) + " nu exista.");
		if(!this->user_service.find(id_user1_new))
			throw("Utilizatorul cu id: " + to_string(id_user1_new) + " nu exista.");
		if (!this->user_service.find(id_user2_new))
			throw("Utilizatorul cu id: " + to_string(id_user2_new) + " nu exista.");
		Friends f(id, id_user_1, id_user_2), f_new(id_new, id_user1_new, id_user2_new);
		this->repo.update_friend(f, f_new);
	}
	catch (Exception(e))
	{
		cout << "Exceptio: " << e.getMessage();
	}
}

int FriendsService::number_of_friendships()
{
	return this->repo.numar_prietenii();
}

bool FriendsService::find(int id, int id_user_1, int id_user_2)
{
	Friends f1(id, id_user_1, id_user_2);
	return this->repo.find(f1);
}

void FriendsService::friends_of_a_user(int id_user)
{
	try
	{
		if (this->user_service.find(id_user))
			throw(Exception("Utilizatorujl cu id " + to_string(id_user) + " nu exista."));
		vector<int> user_ids;
		auto first = this->repo.get_all().get_first();
		while (first != nullptr)
		{
			int id_user1 = first->info.get_id_user1(), id_user2 = first->info.get_id_user2();
			if (id_user == id_user1 && !vector_check(id_user2, user_ids))
				user_ids.push_back(id_user2);
			else if (id_user == id_user2 && !vector_check(id_user1, user_ids))
				user_ids.push_back(id_user1);
		}
	}
	catch (Exception(e))
	{
		cout << "Exception: " << e.getMessage() << endl;
	}
}

bool FriendsService::vector_check(int n, vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == n)
			return true;
	}
	return false;
}

void FriendsService::nice_friends_display()
{
	auto first = this->repo.get_all().get_first();
	while (first != nullptr)
	{
		User u1(this->user_service.get_user(first->info.get_id_user1())), u2 (this->user_service.get_user(first->info.get_id_user2()));
		cout << u1.get_nume() << " (id: " << u1.get_id() << ") si " << u2.get_nume() << " (id:" << u2.get_id() << ") sunt prieteni" << endl;
		first = first->next;
	}
}
