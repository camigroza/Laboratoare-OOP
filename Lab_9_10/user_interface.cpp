#include "user_interface.h"
#include <iostream>
using namespace std;

void UI::adauga_produs()
{
	cout << "Dati codul produsului: ";
	int cod;
	cin >> cod;
	cin.get();
	cout << "Dati numele produsului: ";
	string nume;
	getline(cin, nume);
	cout << "Dati pretul produsului: ";
	double pret;
	cin >> pret;
	this->service.addEntity(cod, nume, pret);
	cout<<"\tProdusul a fost adaugat cu succes!\n";
}

void UI::sterge_produs()
{
	cout << "Dati codul produsului de sters: ";
	int cod;
	cin >> cod;
	int ok = this->service.removeEntity(cod);
	if (ok == 1) cout << "\tProdusul a fost sters cu succes!\n";
	else cout << "\tProdusul nu a fost gasit!\n";
}

void UI::modifica_produs()
{
	cout << "Dati codul produsului de modificat: ";
	int cod;
	cin >> cod;
	cin.get();
	cout << "Dati noul nume al produsului: ";
	string nume_nou;
	getline(cin, nume_nou);
	cout << "Dati noul pret al produsului: ";
	double pret_nou;
	cin >> pret_nou;
	if (this->service.getRepo().searchByCode(cod) == false)
		cout << "\tNu exista nici un produs cu codul dat!\n";
	else
	{
		Entity e = this->service.getRepo().findByCode(cod);
		int ok = this->service.updateEntity(cod, e.getNume(), e.getPret(), nume_nou, pret_nou);
		if (ok == 1) cout << "\tProdusul a fost modificat cu succes!\n";
	}
}

void UI::afiseaza_produse()
{
	vector<Entity> all = this->service.getAll();
	if (all.size() == 0)
		cout << "\tNu exista produse!\n";
	else
	{
		cout << "\tProdusele sunt:\n";
		for (Entity e : all)
			cout << "\t" << e << "\n";
	}
}

UI::UI()
{
}

UI::UI(const Service& s)
{
	this->service = s;
}

void UI::runMenu()
{
	char optiune;
	while (true)
	{
		cout << "1. Adauga produs\n";
		cout << "2. Elimina produs\n";
		cout << "3. Modifica produs\n";
		cout << "a. Afiseaza toate produsele\n";
		cout << "x. Iesire\n";

		cout << "Dati optiunea: ";
		cin >> optiune;

		if (optiune == '1')
			this->adauga_produs();
		else if (optiune == '2')
			this->sterge_produs();
		else if (optiune == '3')
			this->modifica_produs();
		else if (optiune == 'a')
			this->afiseaza_produse();
		else if (optiune == 'x')
			break;
		else cout << "\tOptiune gresita! Reincercati:\n";
	}
}
