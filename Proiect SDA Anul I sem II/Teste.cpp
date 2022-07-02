
#include "Teste.h"
#include "Multimap.h"
#include "User.h"
#include <assert.h>
#include "UserRepositoryFile.h"
#include "FriendsRepositoryFile.h"
#include "Friends.h"
#include "Multime.h"
#include "MessageRepoFile.h"
#include "Message.h"
#include "UserService.h"
#include "FriendsService.h"
#include "MessageService.h"

void user_tests()
{
	UserRepoFile repo("UserTest.csv");
	UserService service(repo);
	repo.display_all_users();
	cout << endl;
	User u(1, "ion", "mail"), u2(2, "andrei", "mail2"), u3(3, "luca", "mail3");
	repo.add_user(u);
	repo.add_user(u2);
	service.add_user(3, "luca", "mail3");
	//assert(repo.get_number_of_users() == 3);
	repo.display_all_users();
	cout << endl;
}

void friends_tests()
{
	FriendsRepoFile repo("FriendsTest.csv");
	//FriendsService service(repo);
	//repo.display_all_friendships();
	Friends fr(1, 1, 2), fr2(2, 2, 1), fr3(3, 1, 1);
	repo.update_friend(fr, fr3);
	repo.delete_friend(fr2);
	repo.display_all_friendships();
	assert(repo.numar_prietenii() == 1);
}

void messages_tests()
{
	RepoMessageFile repo("MessageTest.csv");
	Message m(1, 1, 2, "salut"), m2(2, 2, 1, "buna"), m3(2, 2, 1, "buna ziua");
	if (repo.number_messages() == 0)
	{
		repo.add_message(m);
		repo.add_message(m2);
	}
	repo.display_all_messages();
	assert(repo.number_messages() == 2);
	cout << repo.find(m3);
}
 