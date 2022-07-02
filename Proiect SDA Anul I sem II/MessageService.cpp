#include "MessageService.h"
#include "UserService.h"
#include "Exeption.h"
#include "Message.h"
#include <iostream>
#include<string.h>
#include <string>
#include "Message.h"

using namespace std;

MessageService::MessageService()
{
}

MessageService::MessageService(RepoMessageFile& repo, UserService& user_service)
{
	this->repo = repo;
	this->user_service = user_service;
}

MessageService::~MessageService()
{
}

bool MessageService::find(int id, int id_sender, int id_receiver, string content)
{
	Message m(id, id_sender, id_receiver, content);
	return repo.find(m);
}

void MessageService::add_message(int id, int id_sender, int id_receiver, string content)
{
	try
	{
		
		if (!this->user_service.find(id_sender))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_sender) + " nu exista"));
		if (!this->user_service.find(id_receiver))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_receiver) + " nu exista"));
		Message m(id, id_sender, id_receiver, content);
		repo.add_message(m);
	}
	catch (Exception(e))
	{
		cout << "Exceptio: " << e.getMessage() << endl;
	}
}

void MessageService::del_message(int id, int id_sender, int id_receiver, string content)
{
	try
	{
		if (!this->user_service.find(id_sender))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_sender) + " nu exista"));
		if (!this->user_service.find(id_receiver))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_receiver) + " nu exista"));
		Message m(id, id_sender, id_receiver, content);
		repo.del_message(m);
	}
	catch (Exception(e))
	{
		cout << "Exceptio: " << e.getMessage() << endl;
	}
}

void MessageService::update_message(int id, int id_sender, int id_receiver, string content, int id_new, int id_sender_new, int id_receiver_new, string content_new)
{
	try
	{
		if (!this->user_service.find(id_sender))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_sender) + " nu exista"));
		if (!this->user_service.find(id_receiver))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_receiver) + " nu exista"));
		if (!this->user_service.find(id_sender_new))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_sender_new) + " nu exista"));
		if (!this->user_service.find(id_receiver_new))
			throw(Exception("Utilizatorul cu id-ul " + to_string(id_receiver_new) + " nu exista"));
		Message m(id, id_sender, id_receiver, content), m_new(id_new, id_sender_new, id_receiver_new, content_new);
		this->repo.update_message(m, m_new);
	}
	catch (Exception(e))
	{
		cout << "Exceptio: " << e.getMessage() << endl;
	}
}

void MessageService::display_chat(int key_user1, int key_user2)
{
	//ordine mesaje: de jos is sus
	if (this->user_service.find(key_user1))
	{
		if (this->user_service.find(key_user2))
		{
			auto first = this->repo.get_first().get_first();
			while (first->next != nullptr)
			{
				User user1(this->user_service.get_user(key_user1)), user2(this->user_service.get_user(key_user2));
				if (first->info.get_id_receiver() == key_user2 && first->info.get_id_sender() == key_user1)
					cout << user1.get_nume() << ":  " << first->info.get_content();
				else if(first->info.get_id_receiver() == key_user1 && first->info.get_id_sender() == key_user2)
					cout << user2.get_nume() << ":  " << first->info.get_content();
				first = first->next;
			}
		}
		else
			cout << "Utilizatorul cu id-ul: " << key_user2 << " nu exista" << endl;
	}
	else
		cout << "Utilizatorul cu id-ul: " << key_user1 << " nu exista" << endl;
}

int MessageService::numer_of_mesasges()
{
	return this->repo.number_messages();
}
