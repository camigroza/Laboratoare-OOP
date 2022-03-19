#pragma once
#include "entitate.h"

class Repository {
private:
	Entitate* entitati;
	int nr_entitati;
	int capacitate;
	void resize();

public:
	//constructor
	Repository();

	//destructor
	~Repository();

	//get-eri
	int getNrEntitati();
	int getCapacitate();

	/// <summary>
	/// Adauga o entitate 
	/// </summary>
	/// <param name="e"> entitatea de adaugat </param>
	void add(Entitate& e);

	/// <summary>
	/// Sterge o entitate
	/// </summary>
	/// <param name="e"> entitatea de sters </param>
	void remove(Entitate& e);

	/// <summary>
	/// Indica entitatea de pe o anumita pozitie
	/// </summary>
	/// <param name="poz"> pozitia entitatii </param>
	/// <returns> entitatea care se afla pe pozitia 'poz' </returns>
	Entitate elemAt(int poz);

	/// <summary>
	/// Indica pozitia entitatii 'e' in vector
	/// </summary>
	/// <param name="e"> entitatea a carui pozitie o dorim </param>
	/// <returns> -1 daca entitatea nu exista, altfel pozitia ei in vectorul de entitati </returns>
	int search(Entitate& e);

	/// <summary>
	/// Indica toate entitatile
	/// </summary>
	/// <returns> pointer-ul vectorului cu toate entitati </returns>
	Entitate* getAll();

	/// <summary>
	/// Indica cea mai mare entitate
	/// </summary>
	/// <returns> cel mai mare numar complex din repository </returns>
	Entitate& biggestEntity();


};