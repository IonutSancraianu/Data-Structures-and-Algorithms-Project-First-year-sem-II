#pragma once

#include <fstream>
#include <string>

using namespace std;

class Friends
{
private:
	int id;
	int id_user1;
	int id_user2;

public:
	Friends();
	Friends(int id, int id_user1, int id_user2);
	Friends(const Friends&);
	~Friends();
	int get_id();
	int get_id_user1();
	int get_id_user2();
	Friends& operator=(const Friends&);
	bool operator==(const Friends& fr);
	friend ostream& operator<<(ostream& out, const Friends& f);
};
