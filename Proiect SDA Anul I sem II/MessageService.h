#pragma once

#include "MessageRepoFile.h"
#include "UserService.h"
#include <iostream>

using namespace std;

class MessageService
{
private:
	RepoMessageFile repo;
	UserService user_service;
public:
	MessageService();
	MessageService(RepoMessageFile& repo, UserService& user_service);
	~MessageService();
	bool find(int id, int id_sender, int id_receiver, string content);
	void add_message(int id, int id_sender, int id_receiver, string content);
	void del_message(int id, int id_sender, int id_receiver, string content);
	void update_message(int id, int id_sender, int id_receiver, string content, int id_new, int id_sender_new, int id_receiver_new, string content_new);
	void display_chat(int key_user1, int key_user2);
	int numer_of_mesasges();
}; 