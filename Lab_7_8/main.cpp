#include <iostream>
#include "entitate.h"
#include "tests.h"
#include "UI.h"
using namespace std;

int main()
{
	my_tests();

	Repository repo;
	Service service;
	UI ui;
	ui.runMenu();

	return 0;
}