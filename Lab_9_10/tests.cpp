#include "entity.h"
#include "tests.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include "repository.h"
using namespace std;

void testEntity()
{
	Entity e1;
	e1.setCod(123);
	e1.setNume("aaa");
	e1.setPret(10);
	assert(e1.getCod() == 123);
	assert(e1.getNume() == "aaa");
	assert(e1.getPret() == 10);

	Entity e2(456, "bbb", 20);
	assert(e2.getCod() == 456);
	assert(e2.getNume() == "bbb");
	assert(e2.getPret() == 20);

	Entity e3(e1);
	assert(e3 == e1);
	e3 = e2;
	assert(!(e3 == e1));
	assert(e3 == e2);
}

void test_repository()
{
	Entity e1(123, "aaa", 10);
	Entity e2(456, "bbb", 20);
	Entity e3(789, "ccc", 30);
	Repository r1;
	r1.add(e1);
	r1.add(e2);
	assert(r1.findByCode(123) == e1);
	assert(r1.findByCode(456) == e2);
	assert(r1.searchByCode(123) == true);
	assert(r1.searchByCode(456) == true);
	assert(r1.searchByCode(777) == false);
	assert(r1.getAll()[0] == e1);
	assert(r1.getAll()[1] == e2);
	assert(r1.search(e1) == 0);
	assert(r1.search(e2) == 1);
	assert(r1.search(e3) == -1);
	r1.add(e3);
	assert(r1.searchByCode(789) == true);
	assert(r1.search(e3) == 2);
	Repository r2(r1);
	assert(r1 == r2);
	Repository r3;
	r3 = r1;
	assert(r3 == r1);
	r1.remove(e1);
	assert(r1.search(e1) == -1);
	assert(r1.search(e2) == 0);
	assert(r1.search(e3) == 1);
	r1.update(e3, e1);
	assert(r1.search(e2) == 0);
	assert(r1.search(e3) == -1);
	assert(r1.search(e1) == 1);
}

void allTests()
{
	testEntity();
	test_repository();
	cout << "Toate testele au trecut cu succes!\n";
}