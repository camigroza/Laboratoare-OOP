#include "user_interface.h"
#include "my_exception.h"
#include <iostream>
using namespace std;

void UI::adauga_produs()
{
	try
	{
		cout << "Dati codul produsului: ";
		int cod;
		cin >> cod;
		if (this->service.getRepo().searchByCode(cod) == true)
			throw string("Exista deja un produs cu codul dat! Codurile trebuie sa fie unice!\n");
		cin.get();
		cout << "Dati numele produsului: ";
		string nume;
		getline(cin, nume);
		cout << "Dati pretul produsului: ";
		double pret;
		cin >> pret;
		this->service.addEntity(cod, nume, pret);
		cout << "\tProdusul a fost adaugat cu succes!\n";
	}
	catch (MyException& exc)
	{
		cout << "\tErori:\n";
		exc.printErori();
	}
	catch (string& exc)
	{
		cout << "\terror: " << exc;
	}
}

void UI::sterge_produs()
{
	try
	{
		cout << "Dati codul produsului de sters: ";
		int cod;
		cin >> cod;
		this->service.removeEntity(cod);
		cout << "\tProdusul a fost sters cu succes!\n";
	}
	catch (string& exc)
	{
		cout << "\terror: " << exc;
	}
}

void UI::modifica_produs()
{
	try
	{
		cout << "Dati codul produsului de modificat: ";
		int cod;
		cin >> cod;
		if (this->service.getRepo().searchByCode(cod) == false)
			throw string("Nu exista nici un produs cu codul dat!\n");
		cout << "Dati noul cod al produsului: ";
		int cod_nou;
		cin >> cod_nou;
		if (this->service.getRepo().searchByCode(cod_nou) == true)
			throw string("Exista deja un produs cu codul dat! Codurile trebuie sa fie unice!\n");
		cin.get();
		cout << "Dati noul nume al produsului: ";
		string nume_nou;
		getline(cin, nume_nou);
		cout << "Dati noul pret al produsului: ";
		double pret_nou;
		cin >> pret_nou;
		Entity e = this->service.getRepo().findByCode(cod);
		this->service.updateEntity(cod, e.getNume(), e.getPret(), cod_nou, nume_nou, pret_nou);
		cout << "\tProdusul a fost modificat cu succes!\n";
	}
	catch (MyException& exc)
	{
		cout << "\tErori:\n";
		exc.printErori();
	}
	catch (string& exc)
	{
		cout << "\terror: " << exc;
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

void UI::afiseaza_bani()
{
	map<int, int>::iterator it;
	map<int, int> all = this->service.getCoins();
	if (all.size() == 0)
		cout << "\tNu sunt bani in tonomat!\n";
	for (it = all.begin(); it != all.end(); ++it)
		cout << "\t" << it->first << ": " << it->second << endl;
}

void UI::achizitioneaza_produs()
{
	try
	{
		cout << "Dati codul produsului pe care doriti sa il achizitionati: ";
		int cod;
		cin >> cod;
		if (this->service.getRepo().searchByCode(cod) == false)
			throw string("Nu exista nici un produs cu codul dat!\n");
		int pret_produs = this->service.getRepo().findByCode(cod).getPret();
		cout << "Introduceti bancnota: ";
		int valoare_bancnota_introdusa;
		cin >> valoare_bancnota_introdusa;
		if (valoare_bancnota_introdusa < pret_produs)
			throw string("Nu ati introdus suficienti bani!\n");
		int rest = valoare_bancnota_introdusa - pret_produs;
		map<int, int> M;
		if (this->service.enoughMoneyToGiveBack(rest, M) == false)
			cout << "\tNe pare rau, dar nu putem sa va dam rest. Va primiti banii inapoi!\n";
		else
		{
			this->service.removeEntity(cod);
			this->service.addCoins(valoare_bancnota_introdusa, 1);
			map<int, int>::iterator it;
			for (it = M.begin(); it != M.end(); it++)
				this->service.removeCoins(it->first, it->second);
			cout << "\tMultumim pentru achizitie! :)\n";
		}
	}
	catch (string& exc)
	{
		cout << "\terror: " << exc;
	}
}

void UI::sort_by_price()
{
	try
	{
		string s;
		cout << "--> crescator/descrescator: ";
		cin >> s;
		if (s == "crescator")
		{
			vector<Entity> all = this->service.sortAscendentByPrice();
			if (all.size() == 0)
				cout << "\tNu exista produse!\n";
			else
			{
				cout << "\tProdusele ordonate crescator dupa pret sunt:\n";
				for (Entity& e : all)
					cout << "\t" << e << endl;
			}
		}
		else if (s == "descrescator")
		{
			vector<Entity> all = this->service.sortDescendentByPrice();
			if (all.size() == 0)
				cout << "\tNu exista produse!\n";
			else
			{
				cout << "\tProdusele ordonate descrescator dupa pret sunt:\n";
				for (Entity& e : all)
					cout << "\t" << e << endl;
			}
		}
		else throw string("\tVa rog aveti grija la scrierea cuvintelor!\n");
	}
	catch (string& exc)
	{
		cout << "\terror: " << exc;
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
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(5, 5));
	m.insert(pair<int, int>(10, 10));
	m.insert(pair<int, int>(50, 2));
	m.insert(pair<int, int>(100, 1));
	this->service.setCoins(m);
	this->service.addEntity(1, "corn", 5);
	this->service.addEntity(2, "ciocolata", 8);
	this->service.addEntity(3, "jeleu", 3);
	char optiune;
	while (true)
	{
		cout << "1. Adauga produs\n";
		cout << "2. Elimina produs\n";
		cout << "3. Modifica produs\n";
		cout << "4. Achizitioneaza produs\n";
		cout << "5. Sorteaza produsele dupa pret\n";
		cout << "a. Afiseaza toate produsele\n";
		cout << "A. Afiseaza banii disponibili in tonomat\n";
		cout << "x. Iesire\n";

		cout << "Dati optiunea: ";
		cin >> optiune;

		if (optiune == '1')
			this->adauga_produs();
		else if (optiune == '2')
			this->sterge_produs();
		else if (optiune == '3')
			this->modifica_produs();
		else if (optiune == '4')
			this->achizitioneaza_produs();
		else if (optiune == '5')
			this->sort_by_price();
		else if (optiune == 'a')
			this->afiseaza_produse();
		else if (optiune == 'A')
			this->afiseaza_bani();
		else if (optiune == 'x')
			break;
		else cout << "\tOptiune gresita! Reincercati:\n";
	}
}
