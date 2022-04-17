#include "entitate.h"
#include "string.h"

Entitate::Entitate()
{
	this->ziua = 1;
	this->suma = 0;
	this->tip = nullptr;
}

Entitate::Entitate(int z, int s, const char* t)
{
	this->ziua = z;
	this->suma = s;
	this->tip = new char[strlen(t) + 1];
	strcpy_s(this->tip, strlen(t) + 1, t);
}

Entitate::Entitate(const Entitate& e)
{
	this->ziua = e.ziua;
	this->suma = e.suma;
	if (this->tip != nullptr)
	{
		delete[] this->tip;
		this->tip = nullptr;
	}
	this->tip = new char[strlen(e.tip) + 1];
	strcpy_s(this->tip, strlen(e.tip) + 1, e.tip);
}

void Entitate::setZiua(int z)
{
	this->ziua = z;
}

void Entitate::setSuma(int s)
{
	this->suma = s;
}

void Entitate::setTip(const char* t)
{
	this->tip = new char[strlen(t) + 1];
	strcpy_s(this->tip, strlen(t) + 1, t);
}

int Entitate::getZiua()
{
	return this->ziua;
}

int Entitate::getSuma()
{
	return this->suma;
}

const char* Entitate::getTip()
{
	return this->tip;
}

Entitate& Entitate::operator=(const Entitate& e)
{
	if (this != &e)
	{
		this->ziua = e.ziua;
		this->suma = e.suma;
		this->tip = new char[strlen(e.tip) + 1];
		strcpy_s(this->tip, strlen(e.tip) + 1, e.tip);
	}
	return *this;
}

bool Entitate::operator==(const Entitate& e)
{
	return (this->ziua == e.ziua) && (this->suma = e.suma) && (strcmp(this->tip, e.tip) == 0);
}

ostream& operator<<(ostream& os, const Entitate& e)
{
	os << "Cheltuiala( ziua: " << e.ziua << "; suma: " << e.suma << "; tipul: " << e.tip << " )";
	return os;
}
