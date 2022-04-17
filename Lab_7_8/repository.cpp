#include "repository.h"

void Repository::resize()
{
	Entitate* v = new Entitate[capacitate * 2];
	for (int i = 0; i < this->nr_entitati; i++)
		v[i] = this->entitati[i];
	delete[] this->entitati;
	this->capacitate *= 2;
	this->entitati = v;
}

Repository::Repository()
{
	this->capacitate = 10;
	this->nr_entitati = 0;
	this->entitati = new Entitate[this->capacitate];
}

Repository::Repository(const Repository& r)
{
	this->capacitate = r.capacitate;
	this->nr_entitati = r.nr_entitati;
	if (this->entitati != nullptr)
	{
		delete[] this->entitati;
		this->entitati = nullptr;
	}
	this->entitati = new Entitate[this->capacitate];
	for (int i = 0; i < this->nr_entitati; i++)
		this->entitati[i] = r.entitati[i];
}

void Repository::add(const Entitate& e)
{
	if (this->nr_entitati == this->capacitate) this->resize();
	this->entitati[nr_entitati++] = e;
}

int Repository::remove(const Entitate& e)
{
	int poz = this->find(e);
	if (poz != -1)
	{
		for (int i = poz; i < this->nr_entitati - 1; i++)
			entitati[i] = entitati[i + 1];
		this->nr_entitati--;
		return 1;
	}
	return 0;
}

int Repository::update(const Entitate& veche, const Entitate& noua)
{
	int poz = this->find(veche);
	if (poz != -1)
	{
		entitati[poz] = noua;
		return 1;
	}
	return 0;
}

bool Repository::exists(const Entitate& e)
{
	for (int i = 0; i < this->nr_entitati; i++)
		if (entitati[i] == e) return true;
	return false;
}

int Repository::find(const Entitate& e)
{
	if (!this->exists(e)) return -1;
	for (int i = 0; i < this->nr_entitati; i++)
		if (this->entitati[i] == e) return i;
}

Entitate* Repository::getAll()
{
	return this->entitati;
}

int Repository::getSize()
{
	return this->nr_entitati;
}

bool Repository::operator==(const Repository& r)
{
	if (this->nr_entitati != r.nr_entitati) return 0;
	for (int i = 0; i < this->nr_entitati; i++)
		if (!(this->entitati[i] == r.entitati[i])) return 0;
	return 1;
}

Repository& Repository::operator=(const Repository& r)
{
	if (this != &r)
	{
		if (this->entitati != nullptr)
		{
			delete[] this->entitati;
			this->entitati = nullptr;
		}
		this->entitati = new Entitate[r.nr_entitati];
		for (int i = 0; i < r.nr_entitati; i++)
			this->entitati[i] = r.entitati[i];
		this->nr_entitati = r.nr_entitati;
	}
	return *this;
}
