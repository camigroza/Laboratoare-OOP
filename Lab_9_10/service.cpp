#include "service.h"

Service::Service()
{
}

Service::Service(const Repository& r)
{
	this->repo = r;
}

Repository& Service::getRepo()
{
	return this->repo;
}

void Service::addEntity(int cod, string nume, double pret)
{
	Entity e(cod, nume, pret);	
	this->repo.add(e);
}

int Service::removeEntity(int cod)
{
	Entity e = this->repo.findByCode(cod);
	return this->repo.remove(e);
}

int Service::updateEntity(int cod, string nume_vechi, double pret_vechi, string nume_nou, double pret_nou)
{
	Entity ev(cod, nume_vechi, pret_vechi);
	Entity en(cod, nume_nou, pret_nou);
	return this->repo.update(ev, en);
}

vector<Entity> Service::getAll()
{
	return this->repo.getAll();
}

Service& Service::operator=(const Service& s)
{
	if (this != &s)
		this->repo = s.repo;
	return *this;
}
