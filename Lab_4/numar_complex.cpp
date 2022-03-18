#include <iostream>
#include "numar_complex.h"
using namespace std;

Complex::Complex()
{
	this->parte_reala = 0;
	this->parte_imaginara = 0;
}

Complex::Complex(int val_pr, int val_pi)
{
	this->parte_reala = val_pr;
	this->parte_imaginara = val_pi;
}

Complex::Complex(int nr)
{
	this->parte_reala = nr;
	this->parte_imaginara = 0;
}

Complex::Complex(const Complex& c)
{
	this->parte_reala = c.parte_reala;
	this->parte_imaginara = c.parte_imaginara;
}

Complex::~Complex()
{
	cout << "Destructor Complex for " << this->parte_reala << " + " << this->parte_imaginara << "i" << endl;
}

void Complex::set_parte_reala(int val_pr)
{
	this->parte_reala = val_pr;
}

void Complex::set_parte_imaginara(int val_pi)
{
	this->parte_imaginara = val_pi;
}

int Complex::get_parte_reala()
{
	return this->parte_reala;
}

int Complex::get_parte_imaginara()
{
	return this->parte_imaginara;
}

Complex& Complex::operator=(const Complex& c)
{
	if (this != &c)
	{
		this->parte_reala = c.parte_reala;
		this->parte_imaginara = c.parte_imaginara;
	}
	return *this;
}

bool Complex::operator==(const Complex& c)
{
	if (this->parte_reala == c.parte_reala &&
		this->parte_imaginara == c.parte_imaginara) return true;
	return false;
}

void Complex::write_complex()
{
	cout << "Numarul complex este: ";
	cout << this->parte_reala;
	if (this->parte_imaginara != 0)
		cout << " + " << this->parte_imaginara << "i" << endl;
	else cout << endl;
}

const Complex& Complex::operator+()
{
	return *this;
}

const Complex Complex::operator-()
{
	return Complex(-this->parte_reala, -this->parte_imaginara);
}

Complex Complex::operator+(const Complex& c)
{
	return Complex(this->parte_reala + c.parte_reala, this->parte_imaginara + c.parte_imaginara);
}

Complex Complex::operator-(const Complex& c)
{
	return Complex(this->parte_reala - c.parte_reala, this->parte_imaginara - c.parte_imaginara);
}

Complex Complex::operator*(const Complex& c)
{
	return Complex(this->parte_reala * c.parte_reala - this->parte_imaginara * c.parte_imaginara,
		this->parte_reala * c.parte_imaginara + this->parte_imaginara * c.parte_reala);
}

Complex Complex::operator/(const Complex& c)
{
	return Complex((this->parte_reala * c.parte_reala + this->parte_imaginara * c.parte_imaginara) /
		(c.parte_reala * c.parte_reala + c.parte_imaginara * c.parte_imaginara),
		(this->parte_imaginara * c.parte_reala - this->parte_reala * c.parte_imaginara) /
		(c.parte_reala * c.parte_reala + c.parte_imaginara * c.parte_imaginara));
}

bool Complex::operator>(const Complex& c)
{
	int modul_this = this->parte_reala * this->parte_reala + this->parte_imaginara * this->parte_imaginara;
	int modul_c = c.parte_reala * c.parte_reala + c.parte_imaginara * c.parte_imaginara;
	return modul_this > modul_c;
}
