#include "repository.h"
#include <iostream>
using namespace std;

void Repository::resize()
{
	Entitate* v = new Entitate[capacitate * 2];
	for (int i = 0; i < nr_entitati; i++) 
		v[i] = entitati[i];
	delete[] entitati;
	entitati = v;
	capacitate *= 2;
}

Repository::Repository()
{
	this->capacitate = 10;
	this->entitati = new Entitate[capacitate];
	this->nr_entitati = 0;
}

Repository::~Repository()
{
	if (entitati) 
		delete[] this->entitati;
}

int Repository::getNrEntitati()
{
	return this->nr_entitati;
}

int Repository::getCapacitate()
{
	return this->capacitate;
}

void Repository::add(Entitate& e)
{
	if (capacitate == nr_entitati) resize();
	entitati[nr_entitati++] = e;
}

void Repository::remove(Entitate& e)
{
	int poz = search(e);
	if (poz != -1)
	{
		for (int i = poz; i < nr_entitati - 1; i++)
			entitati[i] = entitati[i + 1];
		nr_entitati--;
	}
	else cout << "Nu exista numarul complex dat!\n";
}

Entitate Repository::elemAt(int poz)
{
	return entitati[poz];
}

int Repository::search(Entitate& e)
{
	for (int i = 0; i < nr_entitati; i++)
		if (entitati[i] == e) return i;
	return -1;
}

Entitate* Repository::getAll()
{
	return entitati;
}

Entitate& Repository::biggestEntity()
{
	Entitate maxim;
	for (int i = 0; i < this->getNrEntitati(); i++)
		if (this->elemAt(i) > maxim) maxim = this->elemAt(i);
	return maxim;
}