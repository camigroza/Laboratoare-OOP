#pragma once
#include "entitate.h"
#include <vector>
using namespace std;

class Repository {
private:
	Entitate* entitati = nullptr;
	int capacitate;
	int nr_entitati;
	void resize();

public:
	//constructori
	Repository();
	Repository(const Repository& r);

	//destructor
	~Repository() = default;

	/// <summary>
	/// Adauga o entitate in repository
	/// </summary>
	/// <param name="e"> entitatea de adaugat </param>
	void add(const Entitate& e);

	/// <summary>
	/// Sterge o entitate din repository
	/// </summary>
	/// <param name="e"> entitatea de sters </param>
	int remove(const Entitate& e);

	/// <summary>
	/// Modifica o entitate
	/// </summary>
	/// <param name="veche"> entitatea de modificat </param>
	/// <param name="noua"> entitatea cu care se modifica </param>
	int update(const Entitate& veche, const Entitate& noua);

	/// <summary>
	/// Indica daca o entitate se afla in repository sau nu
	/// </summary>
	/// <param name="e"> entitatea cautata </param>
	/// <returns> true, daca entitatea de afla in repository, false in caz contrar </returns>
	bool exists(const Entitate& e);

	/// <summary>
	/// Indica pozitia unei entittai in repository
	/// </summary>
	/// <param name="e"> entitatea cautata </param>
	/// <returns> pozitia entitatii in repository, daca aceasta exista, -1 in caz contrar </returns>
	int find(const Entitate& e);

	/// <summary>
	/// Indica toate entitatile din repository
	/// </summary>
	/// <returns> un vector cu toate entitatile </returns>
	Entitate* getAll();

	/// <summary>
	/// Indica dimensiunea repository-ului
	/// </summary>
	/// <returns> numarul de entitati din repository </returns>
	int getSize();

	//overload operatori
	bool operator==(const Repository& r);
	Repository& operator=(const Repository& r);
};