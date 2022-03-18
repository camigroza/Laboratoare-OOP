#include <iostream>
#include "tests.h"
#include "numar_complex.h"
#include "assert.h"
using namespace std;

void test_constructori()
{
	Complex c1;
	assert(c1.get_parte_reala() == 0);
	assert(c1.get_parte_imaginara() == 0);
	Complex c2(2,3);
	assert(c2.get_parte_reala() == 2);
	assert(c2.get_parte_imaginara() == 3);
	Complex c3(5);
	assert(c3.get_parte_reala() == 5);
	assert(c3.get_parte_imaginara() == 0);
	Complex c4(c2);
	assert(c4.get_parte_reala() == 2);
	assert(c4.get_parte_imaginara() == 3);

	Complex* pc1;
	pc1 = new Complex();
	assert(pc1->get_parte_reala() == 0);
	assert(pc1->get_parte_imaginara() == 0);
	Complex* pc2;
	pc2 = new Complex(2, 3);
	assert(pc2->get_parte_reala() == 2);
	assert(pc2->get_parte_imaginara() == 3);
	Complex* pc3;
	pc3 = new Complex(5);
	assert(pc3->get_parte_reala() == 5);
	assert(pc3->get_parte_imaginara() == 0);
	Complex* pc4;
	pc4 = new Complex(c2);
	assert(pc4->get_parte_reala() == 2);
	assert(pc4->get_parte_imaginara() == 3);
	if (pc4 != NULL) { delete pc4; pc4 = NULL; }
	if (pc3 != NULL) { delete pc3; pc3 = NULL; }
	if (pc2 != NULL) { delete pc2; pc2 = NULL; }
	if (pc1 != NULL) { delete pc1; pc1 = NULL; }
}

void test_set_get()
{
	Complex c;
	c.set_parte_reala(1);
	c.set_parte_imaginara(3);
	assert(c.get_parte_reala() == 1);
	assert(c.get_parte_imaginara() == 3);

	Complex* pc;
	pc = new Complex();
	pc->set_parte_reala(1);
	pc->set_parte_imaginara(3);
	assert(pc->get_parte_reala() == 1);
	assert(pc->get_parte_imaginara() == 3);
	if (pc != NULL) { delete pc; pc = NULL; }
}

void test_operators()
{
	Complex c1(2, 3);
	Complex c2;
	Complex c3(2);
	c2 = c1;
	assert(c2.get_parte_reala() == 2);
	assert(c2.get_parte_imaginara() == 3);
	assert(c1 == c2);
	assert(!(c1 == c3));
	c1 = +c1;
	assert(c1.get_parte_reala() == 2);
	assert(c1.get_parte_imaginara() == 3);
	c1 = -c1;
	assert(c1.get_parte_reala() == -2);
	assert(c1.get_parte_imaginara() == -3);
	Complex c4(1, -3);
	c4 = -c4;
	assert(c4.get_parte_reala() == -1);
	assert(c4.get_parte_imaginara() == 3);
	Complex c5(1, 2);
	Complex c6(2, 2);
	assert(!(c5 > c6));
	assert(c6 > c5);
}

void test_arithmetic_operators()
{
	Complex c1(6, 5);
	Complex c2(1, 2);
	Complex c3;
	c3 = c1 + c2;
	assert(c3.get_parte_reala() == 7);
	assert(c3.get_parte_imaginara() == 7);
	c3 = c1 - c2;
	assert(c3.get_parte_reala() == 5);
	assert(c3.get_parte_imaginara() == 3);
	c3 = c1 * c2;
	assert(c3.get_parte_reala() == -4);
	assert(c3.get_parte_imaginara() == 17);
	c3 = c1 / c2;
	assert(c3.get_parte_reala() == 3);
	assert(c3.get_parte_imaginara() == -1);
}

void my_tests()
{
	test_constructori();
	test_set_get();
	test_operators();
	test_arithmetic_operators();
	cout << "Toate testele au trecut cu succes!" << endl;
}