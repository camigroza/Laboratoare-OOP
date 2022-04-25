#pragma once
#include "repository.h"

class Service {
private:
	Repository repo;

public:
	Service();
	Service(const Repository& r);
	~Service() = default;

	Repository& getRepo();
	void addEntity(int cod, string nume, double pret);
	int removeEntity(int cod);
	int updateEntity(int cod, string nume_vechi, double pret_vechi, string nume_nou, double pret_nou);
	vector<Entity> getAll();
	Service& operator=(const Service& s);
};