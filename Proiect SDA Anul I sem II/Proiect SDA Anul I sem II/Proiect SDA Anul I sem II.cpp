
#include <iostream>
#include "Exeption.h"
#include "Multimap.h"
#include "User.h"
#include "UserRepositoryFile.h"
#include "UserService.h"
#include "Message.h"
#include "MessageRepoFile.h"
#include "MessageService.h"
#include "Friends.h"
#include "FriendsRepositoryFile.h"
#include "FriendsService.h"
#include "Teste.h"
#include "Multime.h"
#include "UI.h"

int main()
{
	//user_tests();
	//friends_tests();
	messages_tests();
	UserRepoFile user_repo("UserTest.csv");
	RepoMessageFile message_repo("MessageTest.csv");
	FriendsRepoFile friends_repo("FriendsTest.csv");
	UserService user_service(user_repo);
	MessageService message_service(message_repo, user_service);
	FriendsService friends_service(friends_repo, user_service);
	UI ui(friends_service, message_service, user_service);
}
