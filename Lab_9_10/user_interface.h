#pragma once
#include "service.h"

class UI {
private:
	Service service;
	void adauga_produs();
	void sterge_produs();
	void modifica_produs();
	void afiseaza_produse();

public:
	UI();
	UI(const Service& s);
	~UI() = default;

	void runMenu();
};