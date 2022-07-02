#include "UI.h"
#include "Validator.h"
#include <iostream>
#include <string>
using namespace std;

UI::UI(FriendsService& friends_service, MessageService& message_service, UserService& user_service)
{
	this->friends_service = friends_service;
	this->message_service = message_service;
	this->user_service = user_service;
}

UI::UI()
{
}

UI::~UI()
{
}

void UI::adauga_user()
{
	string id, nume, mail;
	cout << "Introduceti detaliile utilizatorului nou: " << endl;
	cout << "    Id (numar natural > 0) -> "; cin >> id;
	cout << endl;
	cout << "    Nume -> "; cin >> nume;
	cout << endl;
	cout << "    Mail -> "; cin >> mail;
	cout << endl;
	Validator::user_validator(id, nume, mail);
	this->user_service.add_user(stoi(id), nume, mail);
}

void UI::sterge_user()
{
	string id, nume, mail;
	cout << "Introduceti id-ul utilizatorului pe care vreti sa il stergeti: " << endl;
	cout << "    Id (numar natural > 0) -> ";
	cin >> id;
	Validator::user_validator(id, nume, mail);
	this->user_service.stergere(stoi(id));
}

void UI::modifica_user()
{
	string id, nume, mail;
	cout << "Introduceti id-ul utilizatorului pe care vreti sa il modificati: " << endl;
	cout << "    Id (numar natural > 0) -> "; cin >> id;
	cout << endl;
	cout << "Introduceti numele si mailul nou: ";
	cout << endl;
	cout << "    Nume -> "; cin >> nume;
	cout << endl;
	cout << "    Mail -> "; cin >> mail;
	cout << endl;
	Validator::user_validator(id, nume, mail);
	this->user_service.update(stoi(id), nume, mail);
}

void UI::adauga_mesaj()
{
	string id, id_sender, id_receiver, string, content;
	cout << "Introduceti detaliile mesajului nou: " << endl;
	cout << "    Id (numar natural > 0v) -> "; cin >> id;
	cout << endl;
	cout << "    Id-ul expeditorului (numar natural > 0) -> "; cin >> id_sender;
	cout << endl;
	cout << "    Id-ul destinatarului (numar natural > 0) -> "; cin >> id_receiver;
	cout << endl;
	cout << "Scrie-ti mesajul -> "; cin >> content;
	cout << endl;
	Validator::message_validator(id, id_sender, id_receiver, content);
	this->message_service.add_message(stoi(id), stoi(id_sender), stoi(id_receiver), content);
}

void UI::sterge_mesaj()
{
	string id, id_sender, id_receiver, string, content;
	cout << "Introduceti detaliile mesajului pe care vreti sa il stergeti: " << endl;
	cout << "    Id (numar natural > 0) -> "; cin >> id;
	cout << endl;
	cout << "    Id-ul expeditorului (numar natural > 0) -> "; cin >> id_sender;
	cout << endl;
	cout << "    Id-ul destinatarului (numar natural > 0) -> "; cin >> id_receiver;
	cout << endl;
	cout << "Scrie-ti mesajul -> "; cin >> content;
	cout << endl;
	Validator::message_validator(id, id_sender, id_receiver, content);
	this->message_service.del_message(stoi(id), stoi(id_sender), stoi(id_receiver), content);
}

void UI::modifica_mesaj()
{
	string id, id_sender, id_receiver, string, content, id_nou, id_sender_nou, id_receiver_nou, content_nou;
	cout << "Introduceti detaliile mesajului pe care doriti sa il modificati: " << endl;
	cout << "    Id (numar natural > 0) -> "; cin >> id;
	cout << endl;
	cout << "    Id-ul expeditorului (numar natural > 0) -> "; cin >> id_sender;
	cout << endl;
	cout << "    Id-ul destinatarului (numar natural > 0) -> "; cin >> id_receiver;
	cout << endl;
	cout << "Scrie-ti mesajul -> "; cin >> content;
	cout << endl;
	Validator::message_validator(id, id_sender, id_receiver, content);

	cout << "Introduceti detaliile mesajului nou: " << endl;
	cout << "    Id nou (numar natural > 0) -> "; cin >> id_nou;
	cout << endl;
	cout << "    Id-ul expeditorului nou (numar natural > 0) -> "; cin >> id_sender_nou;
	cout << endl;
	cout << "    Id-ul destinatarului nou (numar natural > 0) -> "; cin >> id_receiver_nou;
	cout << endl;
	cout << "Scrie-ti mesajul -> "; cin >> content_nou;
	cout << endl;
	Validator::message_validator(id_nou, id_sender_nou, id_receiver_nou, content_nou);
	this->message_service.update_message(stoi(id), stoi(id_sender), stoi(id_receiver), content, stoi(id_nou),
		stoi(id_sender_nou), stoi (id_receiver_nou), content_nou);
}

void UI::adauga_prietenie()
{
	string id, id_user1, id_user2;
	cout << "Introduceti datele relatiei de prietenie: "; 
	cout << "    Id-ul prieteniei (numar natural > 0) -> ";  cin >> id;
	cout << endl;
	cout << ""; cin >> id_user1;
}
