#include "user_interface.h"
#include "entitate.h"
#include "repository.h"
#include "operations.h"
#include <iostream>
using namespace std;

void run_menu()
{
	int optiune;
	Entitate e;
	Repository repo;
	while(true)
	{
		cout << "1. Adauga entitate\n";
		cout << "2. Sterge entitate\n";
		cout << "3. Afiseaza entitati\n";
		cout << "4. Afiseaza cea mai mare entitate\n";
		cout << "5. Afiseaza toate entitatile situate complet in cadranul 1 de pe cercul geometric\n";
		cout << "6. Afiseaza cea mai lunga secventa de entitati egale\n";
		cout << "7. Iesire\n";
		cout << "Dati optiunea: ";
		cin >> optiune;
		
		if (optiune == 1)
		{
			e.readEntitate();
			repo.add(e);
		}
		else if (optiune == 2)
		{
			cout << "\tDati numarul complex de sters:" << endl;
			e.readEntitate();
			repo.remove(e);
		}
		else if (optiune == 3)
		{
			if (repo.getNrEntitati() != 0)
				for (int i = 0; i < repo.getNrEntitati(); i++)
					repo.elemAt(i).writeEntitate();
			else cout << "\tNu exista entitati in repository!\n";
		}
		else if (optiune == 4)
		{
			if (repo.getNrEntitati() != 0)
			{
				cout << "\tCea mai mare entitate este: ";
				e = repo.biggestEntity();
				e.writeEntitate();
			}
			else cout << "\tNu exista entitati in repository!\n";
		}
		else if (optiune == 5)
		{
			Entitate* v = new Entitate[repo.getNrEntitati()];
			int len = 0;
			all_in_first_quadrant(repo, v, len);
			if (len == 0) cout << "\tNu exista entitati situate in primul cadran!\n";
			else
			{
				cout << "\tEntitatile situate in primul cadran sunt:\n";
				for (int i = 0; i < len; i++)
					v[i].writeEntitate();
			}
			delete[] v;
		}
		else if (optiune == 6)
		{
			int start, end;
			max_secv_entitati_egale(repo, start, end);
			cout << "\tCea mai lunga secventa de entitati egale este formata din:\n";
			for (int i = start; i <= end; i++)
				repo.elemAt(i).writeEntitate();
		}
		else if (optiune == 7) break;
		else cout << "\tOptiune gresita! Reincercati:\n";
	}
}