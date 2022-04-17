#pragma once
#include "repository.h"

class Service {
private:
	Repository repo;

public:
	//constructori
	Service();
	Service(const Repository& r);

	//destructor
	~Service() = default;

	//operatii CRUD
	Entitate& readEntity();
	void addEntity(int ziua, int suma, const char* tip);
	int removeEntity(int ziua, int suma, const char* tip);
	int updateEntity(int ziua_veche, int suma_veche, const char* tipul_vechi,
		int ziua_noua, int suma_noua, const char* tipul_nou);

	//setter si getter
	void setRepo(const Repository& r);
	Repository& getRepo();

	//overload la operatori
	bool operator==(const Service& s);
	Service& operator=(const Service& s);
};