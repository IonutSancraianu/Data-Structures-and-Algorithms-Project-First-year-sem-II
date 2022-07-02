#include "UserService.h"

#include <iostream>



UserService::UserService()
{
}

UserService::UserService(UserRepoFile& repo)
{
	this->repo = repo;
}


UserService::~UserService()
{

}

void UserService::add_user(int id, string nume, string mail)
{
	User u(id, nume, mail);
	this->repo.add_user(u);
}

void UserService::stergere(int id)
{
	//try
	{
		this->stergere(id);
	}

}

void UserService::update(int id, string nume, string mail)
{
	//try
	{
		User u(id, nume, mail);
		this->repo.update_user(u);
	}
}

bool UserService::find(int id)
{
	return this->repo.find(id);
}

int UserService::number_of_users()
{
	return this->number_of_users();
}

Multimap<int, User> UserService::get_all()
{
	return this->repo.get_all();
}

void UserService::display_all_users()
{
	this->repo.display_all_users();
}

User UserService::get_user(int key)
{
	return this->repo.get_user(key);
}
