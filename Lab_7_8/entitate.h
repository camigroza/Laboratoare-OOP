#pragma once
#include <ostream>
using namespace std;

class Entitate {
private:
	int ziua;
	int suma;
	char* tip;

public:
	//constructori
	Entitate();
	Entitate(int z, int s, const char* t);
	Entitate(const Entitate& e);

	//destructor
	~Entitate() = default;

	//setteri
	void setZiua(int z);
	void setSuma(int s);
	void setTip(const char* t);

	//getteri
	int getZiua();
	int getSuma();
	char* getTip();

	//overload la operatori
	Entitate& operator=(const Entitate& e);
	bool operator==(const Entitate& e);

	friend ostream& operator<<(ostream& os, const Entitate& e);
};