#pragma once

#include "FriendsRepositoryFile.h"
#include "UserService.h"
#include "Friends.h"
#include <iostream>

using namespace std;

class FriendsService
{
private:
	FriendsRepoFile repo;
	UserService user_service;
public:
	FriendsService();
	FriendsService(FriendsRepoFile& repo, UserService& user_service);
	~FriendsService();
	void add_friend(int id, int id_user_1, int id_user_2);
	void del_friend(int id, int id_user_1, int id_user_2);
	void update_friend(int id, int id_user_1, int id_user_2, int id_new, int id_user1_new, int id_user2_new);
	int number_of_friendships();
	bool find(int id, int id_user_1, int id_user_2);
	void friends_of_a_user(int id_user);
	bool vector_check(int n, vector<int> a);
	void nice_friends_display();
};
