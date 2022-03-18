#pragma once

class Complex {
private:
	int parte_reala;
	int parte_imaginara;

public:
	/// <summary>
	/// Constructor fara parametri
	/// </summary>
	Complex();

	/// <summary>
	/// Constructor cu doi parametri
	/// </summary>
	/// <param name="val_pr"> valoarea partii reale a numarului complex </param>
	/// <param name="val_pi"> valoarea partii imaginare a numarului complex </param>
	Complex(int val_pr, int val_pi);

	/// <summary>
	/// Constructor cu un singur parametru, implicit valoarea partii imaginare fiind 0
	/// </summary>
	/// <param name="nr"> valoarea partii reale a numarului complex </param>
	Complex(int nr);

	/// <summary>
	/// Constructor de copiere
	/// </summary>
	/// <param name="c"> numarul complex a carui valoare vrem sa o copiem </param>
	Complex(const Complex& c);

	///destructor
	~Complex();

	/// <summary>
	/// set-er pentru partea reala a numarului complex
	/// </summary>
	/// <param name="val_pr"> valoarea partii reale </param>
	void set_parte_reala(int val_pr);

	/// <summary>
	/// set-er pentru partea imaginara a numarului complex
	/// </summary>
	/// <param name="val_pi"> valoarea partii imaginare </param>
	void set_parte_imaginara(int val_pi);

	/// <summary>
	/// get-er pentru partea reala a numarului complex
	/// </summary>
	/// <returns> valoarea partii reale </returns>
	int get_parte_reala();

	/// <summary>
	/// get-er pentru partea imaginara a numarului complex
	/// </summary>
	/// <returns> valoarea partii imaginare </returns>
	int get_parte_imaginara();

	/// <summary>
	/// Operator de copiere
	/// </summary>
	/// <param name="c"> numarul complex a carui valoare vrem sa o copiem </param>
	/// <returns> numarul complex copiat </returns>
	Complex& operator=(const Complex& c);

	/// <summary>
	/// Indica daca doua numere complexe sunt egale
	/// </summary>
	/// <param name="c"> numarul complex cu care se compara </param>
	/// <returns> true, daca cele doua numere sunt egale, false in caz contrar </returns>
	bool operator==(const Complex& c);

	/// <summary>
	/// Afiseaza numarul complex sub forma de text
	/// </summary>
	void write_complex();

	//operatori de semn
	const Complex& operator+();
	const Complex operator-();

	//supraincarcarea operatorilor aritmetici
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	/// <summary>
	/// Indica daca un numar complex este mai mare ca altul
	/// </summary>
	/// <param name="c"> numarul complex cu care se face compararea </param>
	/// <returns> true, daca numarul din stanga este mai mare ca cel din dreapta, false in caz contrar </returns>
	bool operator>(const Complex& c);
};