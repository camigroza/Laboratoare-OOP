#include "user_interface.h"
#include "entitate.h"
#include "repository.h"
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
			cout << "Dati numarul complex de sters" << endl;
			e.readEntitate();
			repo.remove(e);
		}
		else if (optiune == 3)
		{
			if (repo.getNrEntitati() != 0)
				for (int i = 0; i < repo.getNrEntitati(); i++)
					repo.elemAt(i).writeEntitate();
			else cout << "Nu exista entitati in repository!\n";
		}
		else if (optiune == 4)
		{
			if (repo.getNrEntitati() != 0)
			{
				cout << "Cea mai mare entitate este: ";
				e = repo.biggestEntity();
				e.writeEntitate();
			}
			else cout << "Nu exista entitati in repository!\n";
		}
		//else if (optiune == 5)

		//if(optiune == 6)
		//if(optiune == 7)
	}
}