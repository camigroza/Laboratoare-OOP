#include "UI.h"
#include <iostream>
#include <algorithm>
using namespace std;

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

int currentDay()
{
	time_t rawtime;
	time(&rawtime);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	return timeinfo.tm_mday;
}

void UI::addCheltuiala()
{
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	int ziua;
	cout << "--> ziua: ";
	char s[10];
	cin >> s;
	if (strcmp(s, "-") == 0) ziua = currentDay();
	else ziua = atoi(s);
	int suma;
	cout << "--> suma: ";
	cin >> suma;
	char* tip = new char[20];
	cout << "--> tipul: ";
	cin >> tip;
	string xx;
	xx = convertToString(tip, 20);
	Entitate e(ziua, suma, tip);
	this->list_undo.push_back("remove");
	this->zile.push_back(ziua);
	this->sume.push_back(suma);
	this->tipuri.push_back(xx);
	this->how_many.push_back(1);
	int poz = -1;
	for (int i = 0; i < size && poz == -1; i++)
		if (all[i].getZiua() == ziua && strcmp(all[i].getTip(), tip) == 0) poz = i;
	if (poz != -1)
	{
		all[poz].setSuma(all[poz].getSuma() + suma);
		cout << "\tCheltuiala este deja inregistrata si s-a modificat cu succes!\n";
		cout << "\t" << all[poz] << endl;
	}
	else
	{
		this->service.addEntity(ziua, suma, tip);
		Entitate e(ziua, suma, tip);
		cout << "\tCheltuiala a fost inregistrata cu succes!\n";
		cout << "\t" << e << endl;
	}
	delete[] tip;
}

void UI::insertCheltuiala()
{
	int ziua;
	int suma;
	char* tip = new char[20];
	char s[10];
	cout << "--> ziua: ";
	cin >> s;
	if (strcmp(s, "-") == 0) ziua = currentDay();
	else ziua = atoi(s);
	cout << "--> suma: ";
	cin >> suma;
	cout << "--> tipul: ";
	cin >> tip;
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	int gasit = 0;
	for (int i = 0; i < size && gasit == 0; i++)
		if (all[i].getZiua() == ziua && strcmp(all[i].getTip(), tip) == 0)
		{
			gasit = 1;
			all[i].setSuma(all[i].getSuma() + suma);
			cout << "\tCheltuiala a fost gasita si modificata cu succes!\n";
			cout << "\t" << all[i] << endl;
		}
	if (gasit == 0)
	{
		this->service.addEntity(ziua, suma, tip);
		Entitate e(ziua, suma, tip);
		cout << "\tCheltuiala nu a fost gasita si s-a creat una noua!\n";
		cout << "\t" << e << endl;
	}
	delete[] tip;
}

void UI::removeCheltuiala()
{
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	char s[10];
	int ziua1, ziua2;
	int gasit;
	char* tip = new char[20];
	cout << "--> prima zi: ";
	cin >> s;
	int cate;
	if (strcmp(s, "-") == 0)
	{
		gasit = 0;
		cout << "--> tipul: ";
		cin >> tip;
		cate = 0;
		for (int i = 0; i < size; i++)
			if (strcmp(all[i].getTip(), tip) == 0)
			{
				gasit = 1;
				cate++;
				this->list_undo.push_back("add");
				this->zile.push_back(all[i].getZiua());
				this->sume.push_back(all[i].getSuma());
				string xx;
				xx = convertToString(all[i].getTip(), 20);
				this->tipuri.push_back(xx);
				this->how_many.push_back(1);
				this->service.removeEntity(all[i].getZiua(), all[i].getSuma(), all[i].getTip());
			}
		if (gasit == 1)
		{
			this->how_many.push_back(cate);
			cout << "\tToate cheltuielile pentru '" << tip << "' au fost sterse cu succes!\n";
		}
		else cout << "\tNu s-au gasit cheltuieli pentru '" << tip << "'!\n";
	}
	else
	{
		gasit = 0;
		cate = 0;
		ziua1 = atoi(s);
		cout << "--> ultima zi: ";
		cin >> s;
		if (strcmp(s, "-") == 0)
		{
			for (int i = 0; i < size; i++)
				if (all[i].getZiua() == ziua1)
				{
					gasit = 1;
					cate++;
					this->list_undo.push_back("add");
					this->zile.push_back(all[i].getZiua());
					this->sume.push_back(all[i].getSuma());
					string xx;
					xx = convertToString(all[i].getTip(), 20);
					this->tipuri.push_back(xx);
					this->service.removeEntity(all[i].getZiua(), all[i].getSuma(), all[i].getTip());
				}
			if (gasit == 1)
			{
				this->how_many.push_back(cate);
				cout << "\tToate cheltuielile din ziua " << ziua1 << " au fost sterse cu succes!\n";
			}
			else cout << "\tNu s-au gasit cheltuieli pentru ziua " << ziua1 << "!\n";
		}
		else
		{
			ziua2 = atoi(s);
			if (ziua1 > ziua2) swap(ziua1, ziua2);
			gasit = 0;
			cate = 0;
			for (int i = 0; i < size; i++)
				if (all[i].getZiua() >= ziua1 && all[i].getZiua() <= ziua2)
				{
					gasit = 1;
					cate++;
					this->list_undo.push_back("add");
					this->zile.push_back(all[i].getZiua());
					this->sume.push_back(all[i].getSuma());
					string xx;
					xx = convertToString(all[i].getTip(), 20);
					this->tipuri.push_back(xx);
					this->service.removeEntity(all[i].getZiua(), all[i].getSuma(), all[i].getTip());
				}
			if (gasit == 1)
			{
				this->how_many.push_back(cate);
				cout << "\tToate cheltuielile din zilele " << ziua1 << ",...," << ziua2 << " au fost sterse cu succes!\n";
			}
			else cout << "\tNu au fost gasite cheltuieli pentru zilele " << ziua1 << ",...," << ziua2 << " !\n";
		}
	}
	delete[] tip;
}

void UI::listCheltuieli()
{
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	char s[10];
	int gasit, suma;
	char* tip = new char[20];
	cout << "--> tipul: ";
	cin >> s;
	if (strcmp(s, "-") == 0)
	{
		if (size == 0)
			cout << "\t Nu exista cheltuieli inregistrate!\n";
		else
		{
			cout << "\tCheltuielile inregistrate sunt:\n";
			for (int i = 0; i < size; i++)
				cout << "\t" << all[i] << endl;
		}
	}
	else
	{
		strcpy_s(tip, 20, s);
		cout << "--> >/=: ";
		cin >> s;
		if (strcmp(s, "-") == 0)
		{
			gasit = 0;
			for (int i = 0; i < size; i++)
				if (strcmp(all[i].getTip(), tip) == 0)
				{
					gasit++;
					if (gasit == 1) cout << "\tCheltuielile pentru '" << tip << "' sunt:\n";
					cout << "\t" << all[i] << endl;
				}
			if (gasit == 0) cout << "\tNu exista cheltuieli inregistrate pentru '" << tip << "'!\n";
		}
		else
		{
			cout << "--> valoarea: ";
			cin >> suma;
			if (strcmp(s, ">") == 0)
			{
				gasit = 0;
				for (int i = 0; i < size; i++)
					if (all[i].getSuma() > suma && strcmp(tip, all[i].getTip()) == 0)
					{
						gasit++;
						if (gasit == 1) cout << "\tCheltuielile pentru '" << tip << "' mai mari de " << suma << " RON sunt:\n";
						cout << "\t" << all[i] << endl;
					}
				if (gasit == 0) cout << "\tNu exista cheltuieli inregistrate pentru '" << tip << "' mai mari de " << suma << " RON!\n";
			}
			else if (strcmp(s, "=") == 0)
			{
				gasit = 0;
				for (int i = 0; i < size; i++)
					if (all[i].getSuma() == suma && strcmp(tip, all[i].getTip()) == 0)
					{
						gasit++;
						if (gasit == 1) cout << "\tCheltuielile pentru '" << tip << "' in valoare de " << suma << " RON sunt:\n";
						cout << "\t" << all[i] << endl;
					}
				if (gasit == 0) cout << "\tNu exista cheltuieli inregistrate pentru '" << tip << "' in valoare de " << suma << " RON!\n";
			}
		}
	}
	delete[] tip;
}

void UI::sumCheltuieli()
{
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	char s[10];
	char* tip = new char[20];
	int suma;
	cout << "--> tipul: ";
	cin >> s;
	if (strcmp(s, "-") == 0)
	{
		suma = 0;
		for (int i = 0; i < size; i++)
			suma += all[i].getSuma();
		cout << "\tSuma tuturor cheltuielilor inregistrate este egala cu " << suma << " RON!\n";
	}
	else
	{
		strcpy_s(tip, 20, s);
		suma = 0;
		for (int i = 0; i < size; i++)
			if (strcmp(all[i].getTip(), tip) == 0) suma += all[i].getSuma();
		cout << "\tSuma tuturor cheltuielilor din categoria '" << tip << "' este egala cu " << suma << " RON!\n";
	}
	delete[] tip;
}

void UI::maxCheltuieli()
{
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	char s[10];
	int maxim, ziua;
	char* tip = new char[20];
	int v[35] = { 0 };
	cout << "--> zi/tip: ";
	cin >> s;
	if (strcmp(s, "zi") == 0)
	{
		maxim = 0; ziua = 1;
		for (int i = 0; i < size; i++)
			v[all[i].getZiua()] += all[i].getSuma();
		for (int i = 1; i <= 31; i++)
			if (v[i] > maxim) { maxim = v[i]; ziua = i; }
		cout << "\tZiua cu cele mai mari cheltuieli este cea din data de " << ziua << " a lunii, in valoare de " << maxim << " RON!\n";
	}
	else if (strcmp(s, "tip") == 0)
	{
		maxim = 0;
		int menaj, mancare, transport, haine, internet, altele;
		menaj = mancare = transport = haine = internet = altele = 0;
		strcpy_s(tip, 20, "");
		for (int i = 0; i < size; i++)
		{
			if (strcmp(all[i].getTip(), "menaj") == 0) menaj += all[i].getSuma();
			else if (strcmp(all[i].getTip(), "mancare") == 0) mancare += all[i].getSuma();
			else if (strcmp(all[i].getTip(), "transport") == 0) transport += all[i].getSuma();
			else if (strcmp(all[i].getTip(), "haine") == 0) haine += all[i].getSuma();
			else if (strcmp(all[i].getTip(), "internet") == 0) internet += all[i].getSuma();
			else if (strcmp(all[i].getTip(), "altele") == 0) altele += all[i].getSuma();
		}
		if (menaj > maxim) { maxim = menaj; strcpy_s(tip, 20, "menaj"); }
		if (mancare > maxim) { maxim = mancare; strcpy_s(tip, 20, "mancare"); }
		if (transport > maxim) { maxim = transport; strcpy_s(tip, 20, "transport"); }
		if (haine > maxim) { maxim = haine; strcpy_s(tip, 20, "haine"); }
		if (internet > maxim) { maxim = internet; strcpy_s(tip, 20, "internet"); }
		if (altele > maxim) { maxim = altele; strcpy_s(tip, 20, "altele"); }
		cout << "\tCele mai mari cheltuieli au fost efectuate pentru categoria '" << tip << "', in valoare de " << maxim << " RON!\n";
	}
	delete[] tip;
}

void UI::sortCheltuieli()
{
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	char s[10];
	char* tip = new char[20];
	cout << "--> zi/tip: ";
	cin >> s;
	if (strcmp(s, "zi") == 0)
	{
		int v[35] = { 0 };
		int x[35] = { 0 };
		int stop;
		char ss[20];
		cout << "--> crescator/descrescator: ";
		cin >> ss;
		for (int i = 0; i < size; i++)
		{
			v[all[i].getZiua()] += all[i].getSuma();
			x[all[i].getZiua()] += all[i].getSuma();
		}
		sort(v + 1, v + 34);
		if (strcmp(ss, "crescator") == 0)
		{
			for (int i = 1; i <= 34; i++)
			{
				stop = 0;
				for (int j = 1; j <= 31 && stop == 0; j++)
					if (x[j] > 0 && x[j] == v[i])
					{
						x[j] = -1; stop = 1;
						cout << "\t" << "ziua: " << j << "; suma: " << v[i] << endl;
					}
			}
		}
		else if (strcmp(ss, "descrescator") == 0)
		{
			for (int i = 34; i >= 1; i--)
			{
				stop = 0;
				for (int j = 1; j <= 31 && stop == 0; j++)
					if (x[j] > 0 && x[j] == v[i])
					{
						x[j] = -1; stop = 1;
						cout << "\t" << "ziua: " << j << "; suma: " << v[i] << endl;
					}
			}
		}
	}
	else if (strcmp(s, "tip") == 0)
	{
		cout << "--> tipul: ";
		cin >> tip;
		int v[35] = { 0 };
		int x[35] = { 0 };
		char ss[20];
		int stop;
		cout << "--> crescator/descrescator: ";
		cin >> ss;
		for (int i = 0; i < size; i++)
			if (strcmp(all[i].getTip(), tip) == 0)
			{
				v[all[i].getZiua()] += all[i].getSuma();
				x[all[i].getZiua()] += all[i].getSuma();
			}
		sort(v + 1, v + 34);
		if (strcmp(ss, "crescator") == 0)
		{
			for (int i = 1; i <= 34; i++)
			{
				stop = 0;
				for (int j = 1; j <= 31 && stop == 0; j++)
					if (x[j] > 0 && x[j] == v[i])
					{
						x[j] = -1; stop = 1;
						cout << "\t" << "ziua: " << j << "; suma: " << v[i] << endl;
					}
			}
		}
		else if (strcmp(ss, "descrescator") == 0)
		{
			for (int i = 34; i >= 1; i--)
			{
				stop = 0;
				for (int j = 1; j <= 31 && stop == 0; j++)
					if (x[j] > 0 && x[j] == v[i])
					{
						x[j] = -1; stop = 1;
						cout << "\t" << "ziua: " << j << "; suma: " << v[i] << endl;
					}
			}
		}
	}
	delete[] tip;
}

void UI::filterCheltuieli()
{
	Entitate* all = this->service.getRepo().getAll();
	int size = this->service.getRepo().getSize();
	char s[10];
	int suma;
	char* tip = new char[20];
	cout << "--> tipul: ";
	cin >> tip;
	cout << "--> </=: ";
	cin >> s;
	int cate;
	if (strcmp(s, "-") == 0)
	{
		cate = 0;
		for (int i = 0; i < size; i++)
			if (strcmp(all[i].getTip(), tip) != 0)
			{
				cate++;
				this->list_undo.push_back("add");
				this->zile.push_back(all[i].getZiua());
				this->sume.push_back(all[i].getSuma());
				string xx;
				xx = convertToString(all[i].getTip(), 20);
				this->tipuri.push_back(xx);
				this->service.getRepo().remove(all[i]);
			}
		if (cate != 0)
			this->how_many.push_back(cate);
		Entitate* all_after = this->service.getRepo().getAll();
		int size_after = this->service.getRepo().getSize();
		if (size_after == 0)
			cout << "\tNu au mai ramas cheltuieli inregistrate!\n";
		else
		{
			cout << "\tCheltuielile ramase sunt:\n";
			for (int i = 0; i < size_after; i++)
				cout << "\t" << all_after[i] << endl;
		}

	}
	else
	{
		cout << "--> valoarea: ";
		cin >> suma;
		if (strcmp(s, "<") == 0)
		{
			cate = 0;
			for (int i = 0; i < size; i++)
				if (!(all[i].getSuma() < suma && strcmp(tip, all[i].getTip()) == 0))
				{
					cate++;
					this->list_undo.push_back("add");
					this->zile.push_back(all[i].getZiua());
					this->sume.push_back(all[i].getSuma());
					string xx;
					xx = convertToString(all[i].getTip(), 20);
					this->tipuri.push_back(xx);
					this->service.getRepo().remove(all[i]);
				}
			if (cate != 0)
				this->how_many.push_back(cate);
			Entitate* all_after = this->service.getRepo().getAll();
			int size_after = this->service.getRepo().getSize();
			if (size_after == 0)
				cout << "\tNu au mai ramas cheltuieli inregistrate!\n";
			else
			{
				cout << "\tCheltuielile ramase sunt:\n";
				for (int i = 0; i < size_after; i++)
					cout << "\t" << all_after[i] << endl;
			}
		}
		else if (strcmp(s, "=") == 0)
		{
			cate = 0;
			for (int i = 0; i < size; i++)
				if (!(all[i].getSuma() == suma && strcmp(tip, all[i].getTip()) == 0))
				{
					cate++;
					this->list_undo.push_back("add");
					this->zile.push_back(all[i].getZiua());
					this->sume.push_back(all[i].getSuma());
					string xx;
					xx = convertToString(all[i].getTip(), 20);
					this->tipuri.push_back(xx);
					this->service.getRepo().remove(all[i]);
				}
			if (cate != 0)
				this->how_many.push_back(cate);
			Entitate* all_after = this->service.getRepo().getAll();
			int size_after = this->service.getRepo().getSize();
			if (size_after == 0)
				cout << "\tNu au mai ramas cheltuieli inregistrate!\n";
			else
			{
				cout << "\tCheltuielile ramase sunt:\n";
				for (int i = 0; i < size_after; i++)
					cout << "\t" << all_after[i] << endl;
			}
		}
	}
	delete[] tip;
}

void UI::undo()
{
	if (this->list_undo.size() != 0)
	{
		int ziua;
		int suma;
		char tip[20];
		int n_lu = this->list_undo.size();
		int n_hm = this->how_many.size();
		int n = this->how_many[n_hm - 1];
		for (int i = 1; i <= n; i++)
		{
			ziua = this->zile[n_lu - i];
			suma = this->sume[n_lu - i];
			strcpy_s(tip, this->tipuri[n_lu - i].c_str());
			Entitate e(ziua, suma, tip);

			if (this->list_undo[n_lu - i] == "add")
			{	
				this->service.getRepo().add(e);
				this->list_undo.pop_back();
				this->zile.pop_back();
				this->sume.pop_back();
				this->tipuri.pop_back();
			}
			else if (this->list_undo[n_lu - 1] == "remove")
			{
				this->service.getRepo().remove(e);
				this->list_undo.pop_back();
				this->zile.pop_back();
				this->sume.pop_back();
				this->tipuri.pop_back();
			}
		}
		this->how_many.pop_back();
	}
	else cout << "\tNu se poate face undo!\n";
}

UI::UI()
{
}

UI::UI(const Service& s)
{
	this->service = s;
}

void UI::setService(const Service& s)
{
	this->service = s;
}

Service& UI::getService()
{
	return this->service;
}

UI& UI::operator=(const UI& u)
{
	if (this != &u)
		this->service = u.service;
	return *this;
}

bool UI::operator==(const UI& u)
{
	return this->service == u.service;
}

void UI::runMenu()
{
	char optiune;
	while (true)
	{
		cout << "1. Adaugarea unei cheltuieli in lista (add, insert)\n";
		cout << "2. Modificarea cheltuielilor din lista\n";
		cout << "3. Stabilirea cheltuielilor cu anumite proprietati\n";
		cout << "4. Obtinerea unor proprietati a diferitelor subliste\n";
		cout << "5. Filtrarea listei de cheltuieli\n";
		cout << "a. Afisarea tuturor cheltuielilor\n";
		cout << "u. Undo\n";
		cout << "x. Iesire\n";

		cout << "Dati optiunea: ";
		cin >> optiune;

		if (optiune == '1')
		{
			char s[20];
			cout << "--> adauga/insereaza: ";
			cin >> s;
			if (strcmp(s, "adauga") == 0) this->addCheltuiala();
			else if (strcmp(s, "insereaza") == 0) this->insertCheltuiala();
		}
		else if (optiune == '2')
		{
			cout << "--> elimina\n";
			this->removeCheltuiala();
		}
		else if (optiune == '3')
		{
			cout << "--> listeaza\n";
			this->listCheltuieli();
		}
		else if (optiune == '4')
		{
			char s[20];
			cout << "--> suma/max/sortare: ";
			cin >> s;
			if (strcmp(s, "suma") == 0) this->sumCheltuieli();
			else if (strcmp(s, "max") == 0) this->maxCheltuieli();
			else if (strcmp(s, "sortare") == 0) this->sortCheltuieli();
		}
		else if (optiune == '5')
		{
			cout << "--> filtrare\n";
			this->filterCheltuieli();
		}
		else if (optiune == 'a')
		{
			Entitate* all = this->service.getRepo().getAll();
			int size = this->service.getRepo().getSize();
			if (size == 0)
				cout << "\t Nu exista cheltuieli inregistrate!\n";
			else
			{
				cout << "\tCheltuielile inregistrate sunt:\n";
				for (int i = 0; i < size; i++)
					cout << "\t" << all[i] << endl;
			}
		}
		else if (optiune == 'u')
		{
			this->undo();
		}
		else if (optiune == 'x') break;
		else cout << "\tOptiune gresita! Reincercati: \n";
	}
}
