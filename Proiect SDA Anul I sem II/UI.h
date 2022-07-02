#pragma once
#include "FriendsService.h"
#include "MessageService.h"
#include "UserService.h"

class UI
{
private:
	FriendsService friends_service;
	MessageService message_service;
	UserService user_service;
	void adauga_user();
	void sterge_user();
	void modifica_user();
	void adauga_mesaj();
	void sterge_mesaj();
	void modifica_mesaj();
	void adauga_prietenie();
	void sterge_prietenie();
	void modifica_prietenie();
	void afisare_conversatie_intre_2useri();
	void log_in();
	void inregistrare();
	void user_menu();
	void god_mode();
	void afisare_conversatiile_unui_user();
	void afisare_useri();
	void afisare_mesaje();
	void afisare_frumoasa_prieteni();
public:
	UI(FriendsService& friends_service, MessageService& message_service, UserService& user_service); 
	UI();
	~UI();
	void show_menu();
};