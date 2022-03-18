#include <iostream>
#include "tests.h"
#include "numar_complex.h"
using namespace std;

int main()
{
	my_tests();
	Complex c(10, 10);
	c.write_complex();
	return 0;
}