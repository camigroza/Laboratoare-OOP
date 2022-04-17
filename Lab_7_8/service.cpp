#include "service.h"
#include <iostream>
using namespace std;

Service::Service()
{
}

Service::Service(const Repository& r)
{
	this->repo = r;
}

Entitate& Service::readEntity()
{
	int ziua, suma;
	char* tip;
	cout << "Dati ziua din luna in care a fost efectuata cheltuiala: ";
	cin >> ziua;
	cout << "Dati suma de bani: ";
	cin >> suma;
	cout << "Dati tipul cheltuielii (menaj/mancare/transport/haine/internet/altele): ";
	tip = new char[20];
	cin >> tip;
	Entitate e(ziua, suma, tip);
	delete[] tip;
	return e;
}

void Service::addEntity(int ziua, int suma, const char* tip)
{
	Entitate e(ziua, suma, tip);
	this->repo.add(e);
}

int Service::removeEntity(int ziua, int suma, const char* tip)
{
	Entitate e(ziua, suma, tip);
	int rez = this->repo.remove(e);
	if (rez == 1) return 1;
	return 0;
}

int Service::updateEntity(int ziua_veche, int suma_veche, const char* tipul_vechi, int ziua_noua, int suma_noua, const char* tipul_nou)
{
	Entitate ev(ziua_veche, suma_veche, tipul_vechi);
	Entitate en(ziua_noua, suma_noua, tipul_nou);
	int rez = this->repo.update(ev, en);
	if (rez == 1) return 1;
	return 0;
}

void Service::setRepo(const Repository& r)
{
	this->repo = r;
}

Repository& Service::getRepo()
{
	return this->repo;
}

bool Service::operator==(const Service& s)
{
	return this->repo == s.repo;
}

Service& Service::operator=(const Service& s)
{
	if (this != &s)
		this->repo = s.repo;
	return *this;
}
