#pragma once
#include "service.h"
#include <string.h>

class UI {
private:
	Service service;
	vector<string> list_undo;
	vector<int> zile;
	vector<int> sume;
	vector<string> tipuri;
	vector<int> how_many;
	void addCheltuiala();
	void insertCheltuiala();
	void removeCheltuiala();
	void listCheltuieli();
	void sumCheltuieli();
	void maxCheltuieli();
	void sortCheltuieli();
	void filterCheltuieli();
	void undo();

public:
	UI();
	UI(const Service& s);
	~UI() = default;
	void setService(const Service& s);
	Service& getService();
	UI& operator=(const UI& u);
	bool operator==(const UI& u);
	void runMenu();
};