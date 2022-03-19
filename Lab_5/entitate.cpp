#include <iostream>
#include "entitate.h"
using namespace std;

Entitate::Entitate()
{
	this->parte_reala = 0;
	this->parte_imaginara = 0;
}

Entitate::Entitate(int val_pr, int val_pi)
{
	this->parte_reala = val_pr;
	this->parte_imaginara = val_pi;
}

Entitate::Entitate(int nr)
{
	this->parte_reala = nr;
	this->parte_imaginara = 0;
}

Entitate::Entitate(const Entitate& c)
{
	this->parte_reala = c.parte_reala;
	this->parte_imaginara = c.parte_imaginara;
}

Entitate::~Entitate()
{
	//cout << "Destructor Complex for " << this->parte_reala << " + " << this->parte_imaginara << "i" << endl;
}

void Entitate::setParteReala(int val_pr)
{
	this->parte_reala = val_pr;
}

void Entitate::setParteImaginara(int val_pi)
{
	this->parte_imaginara = val_pi;
}

int Entitate::getParteReala()
{
	return this->parte_reala;
}

int Entitate::getParteImaginara()
{
	return this->parte_imaginara;
}

Entitate& Entitate::operator=(const Entitate& c)
{
	if (this != &c)
	{
		this->parte_reala = c.parte_reala;
		this->parte_imaginara = c.parte_imaginara;
	}
	return *this;
}

bool Entitate::operator==(const Entitate& c)
{
	if (this->parte_reala == c.parte_reala &&
		this->parte_imaginara == c.parte_imaginara) return true;
	return false;
}

const Entitate& Entitate::operator+()
{
	return *this;
}

const Entitate Entitate::operator-()
{
	return Entitate(-this->parte_reala, -this->parte_imaginara);
}

Entitate Entitate::operator+(const Entitate& c)
{
	return Entitate(this->parte_reala + c.parte_reala, this->parte_imaginara + c.parte_imaginara);
}

Entitate Entitate::operator-(const Entitate& c)
{
	return Entitate(this->parte_reala - c.parte_reala, this->parte_imaginara - c.parte_imaginara);
}

Entitate Entitate::operator*(const Entitate& c)
{
	return Entitate(this->parte_reala * c.parte_reala - this->parte_imaginara * c.parte_imaginara,
		this->parte_reala * c.parte_imaginara + this->parte_imaginara * c.parte_reala);
}

Entitate Entitate::operator/(const Entitate& c)
{
	return Entitate((this->parte_reala * c.parte_reala + this->parte_imaginara * c.parte_imaginara) /
		(c.parte_reala * c.parte_reala + c.parte_imaginara * c.parte_imaginara),
		(this->parte_imaginara * c.parte_reala - this->parte_reala * c.parte_imaginara) /
		(c.parte_reala * c.parte_reala + c.parte_imaginara * c.parte_imaginara));
}

bool Entitate::operator>(const Entitate& c)
{
	int modul_this = this->parte_reala * this->parte_reala + this->parte_imaginara * this->parte_imaginara;
	int modul_c = c.parte_reala * c.parte_reala + c.parte_imaginara * c.parte_imaginara;
	return modul_this > modul_c;
}

void Entitate::readEntitate()
{
	cout << "Dati valoarea partii reale: ";
	cin >> this->parte_reala;
	cout << "Dati valoarea partii imaginare: ";
	cin >> this->parte_imaginara;
}

void Entitate::writeEntitate()
{
	cout << "Numarul complex este: ";
	if (this->parte_imaginara != 0)
		cout << this->parte_reala << " + " << this->parte_imaginara << "i" << endl;
	else cout << this->parte_reala << endl;
}
