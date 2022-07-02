#include "Friends.h"

Friends::Friends()
{
	this->id = 0;
	this->id_user1 = 0;
	this->id_user2 = 0;
}

Friends::Friends(int id, int id_user1, int id_user2)
{
	this->id = id;
	this->id_user1 = id_user1;
	this->id_user2 = id_user2;
}

Friends::Friends(const Friends& f)
{
	this->id = f.id;
	this->id_user1 = f.id_user1;
	this->id_user2 = f.id_user2;
}

Friends::~Friends()
{
}

int Friends::get_id()
{
	return this->id;
}

int Friends::get_id_user1()
{
	return this->id_user1;
}

int Friends::get_id_user2()
{
	return this->id_user2;
}


Friends& Friends::operator=(const Friends& f)
{
	this->id = f.id;
	this->id_user1 = f.id_user1;
	this->id_user2 = f.id_user2;
	return *this;
}

bool Friends::operator==(const Friends& fr)
{
	if (this->id == fr.id)
	{
		if (this->id_user1 == fr.id_user1 && this->id_user2 == fr.id_user2)
			return true;
		else if (this->id_user1 == fr.id_user2 && this->id_user2 == fr.id_user1)
			return true;
	}
	return false;
}

ostream& operator<<(ostream& out, const Friends& f)
{
	out << "Prietenie Id: " << f.id << " Id utilizator mesager: " << f.id_user1 << " Id utilizator destinatar: " << f.id_user2 << endl;
	return out;
}
