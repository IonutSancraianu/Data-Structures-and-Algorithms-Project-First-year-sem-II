#pragma once
#include "Friends.h"
#include "Exeption.h"
#include "Message.h"
#include "User.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Validator
{
public:
	static bool isNumber(const string& str)
	{
		for (int i = 0; i <= str.length() - 1; i++)
		{
			if (isdigit(str[i]) == 0) return false;
		}
		return true;
	}
	static void user_validator(string id, string nume, string mail)
	{
		try
		{
			if (!isNumber(id) || stoi(id)<=0)
				throw(Exception("Id-ul utilizatorului trebuie sa fie un numar intreg strict pozitiv."));
			if (isNumber(mail))
				throw(Exception("Mailul unui utilizator nu poate fi format doar din cifre."));
		}
		catch (Exception(e))
		{
			cout << "Exception: " << e.getMessage() << endl;
		}
	}
	static void friend_validator(string id, string id_user1, string id_user2)
	{
		try
		{
			if (!isNumber(id) || stoi(id) <= 0)
				throw(Exception("Id-ul prieteniei trebuie sa fie un numar intreg strict pozitiv."));
			if (!isNumber(id_user1) || stoi(id_user1) <= 0)
				throw(Exception("Id-ul utilizatorului trebuie sa fie un numar intreg string pozitiv."));
			if (!isNumber(id_user2) || stoi(id_user2) <= 0)
				throw(Exception("Id-ul utilizatorului trebuie sa fie un numar intreg string pozitiv."));
			if (stoi(id_user1) == stoi(id_user2))
				throw(Exception("Id-urile utilizatorilor prieteniei nu pot fi egale."));
		}
		catch (Exception(e))
		{
			cout << "Exception: " << e.getMessage() << endl;
		}
	}
	static void message_validator(string id, string id_sender, string id_receiver, string content)
	{
		try
		{
			if (!isNumber(id) || stoi(id) <= 0)
				throw(Exception("Id-ul mesajului trebuie sa fie un numar intreg strict pozitiv."));
			if (!isNumber(id_sender) || stoi(id) <= 0)
				throw(Exception("Id-ul utilizatorului care trimite mesajul trebuie sa fie un numar intreg string pozitiv."));
			if (!isNumber(id_receiver) || stoi(id) <= 0)
				throw(Exception("Id-ul utilizatorului care primeste mesajul trebuie sa fie un numar intreg string pozitiv."));
			if (stoi(id_receiver) == stoi(id_sender))
				throw(Exception("Id-urile utilizatorilor mesajului nu pot fi egale."));
		}
		catch (Exception(e))
		{
			cout << "Exception: " << e.getMessage() << endl;
		}
	}
};