#include <iostream>
#include "tests.h"
#include "entitate.h"
#include "assert.h"
#include "repository.h"
using namespace std;

void test_constructori()
{
	Entitate c1;
	assert(c1.getParteReala() == 0);
	assert(c1.getParteImaginara() == 0);
	Entitate c2(2, 3);
	assert(c2.getParteReala() == 2);
	assert(c2.getParteImaginara() == 3);
	Entitate c3(5);
	assert(c3.getParteReala() == 5);
	assert(c3.getParteImaginara() == 0);
	Entitate c4(c2);
	assert(c4.getParteReala() == 2);
	assert(c4.getParteImaginara() == 3);

	Entitate* pc1;
	pc1 = new Entitate();
	assert(pc1->getParteReala() == 0);
	assert(pc1->getParteImaginara() == 0);
	Entitate* pc2;
	pc2 = new Entitate(2, 3);
	assert(pc2->getParteReala() == 2);
	assert(pc2->getParteImaginara() == 3);
	Entitate* pc3;
	pc3 = new Entitate(5);
	assert(pc3->getParteReala() == 5);
	assert(pc3->getParteImaginara() == 0);
	Entitate* pc4;
	pc4 = new Entitate(c2);
	assert(pc4->getParteReala() == 2);
	assert(pc4->getParteImaginara() == 3);
	if (pc4 != NULL) { delete pc4; pc4 = NULL; }
	if (pc3 != NULL) { delete pc3; pc3 = NULL; }
	if (pc2 != NULL) { delete pc2; pc2 = NULL; }
	if (pc1 != NULL) { delete pc1; pc1 = NULL; }
}

void test_set_get()
{
	Entitate c;
	c.setParteReala(1);
	c.setParteImaginara(3);
	assert(c.getParteReala() == 1);
	assert(c.getParteImaginara() == 3);

	Entitate* pc;
	pc = new Entitate();
	pc->setParteReala(1);
	pc->setParteImaginara(3);
	assert(pc->getParteReala() == 1);
	assert(pc->getParteImaginara() == 3);
	if (pc != NULL) { delete pc; pc = NULL; }
}

void test_operators()
{
	Entitate c1(2, 3);
	Entitate c2;
	Entitate c3(2);
	c2 = c1;
	assert(c2.getParteReala() == 2);
	assert(c2.getParteImaginara() == 3);
	assert(c1 == c2);
	assert(!(c1 == c3));
	c1 = +c1;
	assert(c1.getParteReala() == 2);
	assert(c1.getParteImaginara() == 3);
	c1 = -c1;
	assert(c1.getParteReala() == -2);
	assert(c1.getParteImaginara() == -3);
	Entitate c4(1, -3);
	c4 = -c4;
	assert(c4.getParteReala() == -1);
	assert(c4.getParteImaginara() == 3);
	Entitate c5(1, 2);
	Entitate c6(2, 2);
	assert(!(c5 > c6));
	assert(c6 > c5);
}

void test_arithmetic_operators()
{
	Entitate c1(6, 5);
	Entitate c2(1, 2);
	Entitate c3;
	c3 = c1 + c2;
	assert(c3.getParteReala() == 7);
	assert(c3.getParteImaginara() == 7);
	c3 = c1 - c2;
	assert(c3.getParteReala() == 5);
	assert(c3.getParteImaginara() == 3);
	c3 = c1 * c2;
	assert(c3.getParteReala() == -4);
	assert(c3.getParteImaginara() == 17);
	c3 = c1 / c2;
	assert(c3.getParteReala() == 3);
	assert(c3.getParteImaginara() == -1);
}

void test_repo()
{
	Repository repo;
	Entitate c1(2, 3);
	Entitate c2(4, 5);
	Entitate c3(6, 7);
	repo.add(c1);
	repo.add(c2);
	repo.add(c3);
	assert(repo.search(c3) == 2);
	assert(repo.getNrEntitati() == 3);
	assert(repo.elemAt(0) == c1);
	assert(repo.elemAt(1) == c2);
	assert(repo.elemAt(2) == c3);
	repo.remove(c2);
	assert(repo.getNrEntitati() == 2);
	assert(repo.elemAt(0) == c1);
	assert(repo.elemAt(1) == c3);
	repo.remove(c3);
	assert(repo.getNrEntitati() == 1);
	assert(repo.elemAt(0) == c1);
}

void test_biggestEntity()
{
	Entitate e1(1,2);
	Entitate e2(4,5);
	Entitate e3(4,5);
	Entitate e4(2,3);
	Repository repo;
	repo.add(e1);
	repo.add(e2);
	repo.add(e3);
	repo.add(e4);
	assert(repo.biggestEntity() == e2);
}

void test_allInFirstQuadrant()
{
	
}

void my_tests()
{
	test_constructori();
	test_set_get();
	test_operators();
	test_arithmetic_operators();
	test_repo();
	test_biggestEntity();
	//test_allInFirstQuadrant();
	cout << "Toate testele au trecut cu succes!" << endl;
}