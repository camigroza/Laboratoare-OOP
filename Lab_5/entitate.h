#pragma once

class Entitate {
private:
	int parte_reala;
	int parte_imaginara;

public:
	/// <summary>
	/// Constructor fara parametri
	/// </summary>
	Entitate();

	/// <summary>
	/// Constructor cu doi parametri
	/// </summary>
	/// <param name="val_pr"> valoarea partii reale a numarului complex </param>
	/// <param name="val_pi"> valoarea partii imaginare a numarului complex </param>
	Entitate(int val_pr, int val_pi);

	/// <summary>
	/// Constructor cu un singur parametru, implicit valoarea partii imaginare fiind 0
	/// </summary>
	/// <param name="nr"> valoarea partii reale a numarului complex </param>
	Entitate(int nr);

	/// <summary>
	/// Constructor de copiere
	/// </summary>
	/// <param name="c"> numarul complex a carui valoare vrem sa o copiem </param>
	Entitate(const Entitate& c);

	///destructor
	~Entitate();

	/// <summary>
	/// set-er pentru partea reala a numarului complex
	/// </summary>
	/// <param name="val_pr"> valoarea partii reale </param>
	void setParteReala(int val_pr);

	/// <summary>
	/// set-er pentru partea imaginara a numarului complex
	/// </summary>
	/// <param name="val_pi"> valoarea partii imaginare </param>
	void setParteImaginara(int val_pi);

	/// <summary>
	/// get-er pentru partea reala a numarului complex
	/// </summary>
	/// <returns> valoarea partii reale </returns>
	int getParteReala();

	/// <summary>
	/// get-er pentru partea imaginara a numarului complex
	/// </summary>
	/// <returns> valoarea partii imaginare </returns>
	int getParteImaginara();

	/// <summary>
	/// Operator de copiere
	/// </summary>
	/// <param name="c"> numarul complex a carui valoare vrem sa o copiem </param>
	/// <returns> numarul complex copiat </returns>
	Entitate& operator=(const Entitate& c);

	/// <summary>
	/// Indica daca doua numere complexe sunt egale
	/// </summary>
	/// <param name="c"> numarul complex cu care se compara </param>
	/// <returns> true, daca cele doua numere sunt egale, false in caz contrar </returns>
	bool operator==(const Entitate& c);

	//operatori de semn
	const Entitate& operator+();
	const Entitate operator-();

	//supraincarcarea operatorilor aritmetici
	Entitate operator+(const Entitate& c);
	Entitate operator-(const Entitate& c);
	Entitate operator*(const Entitate& c);
	Entitate operator/(const Entitate& c);

	/// <summary>
	/// Indica daca un numar complex este mai mare ca altul
	/// </summary>
	/// <param name="c"> numarul complex cu care se face compararea </param>
	/// <returns> true, daca numarul din stanga este mai mare ca cel din dreapta, false in caz contrar </returns>
	bool operator>(const Entitate& c);

	//citire si afisare
	void readEntitate();
	void writeEntitate();
};