#include "tests.h"
#include "entitate.h"
#include <assert.h>
#include <iostream>
#include "repository.h"
#include "service.h"
#include "UI.h"
using namespace std;

void test_entitate()
{
	Entitate e1(1, 100, "aaa");
	Entitate e2(2, 200, "bbb");
	assert(e1.getZiua() == 1);
	assert(e1.getSuma() == 100);
	assert(strcmp(e1.getTip(), "aaa") == 0);
	assert(e2.getZiua() == 2);
	assert(e2.getSuma() == 200);
	assert(strcmp(e2.getTip(), "bbb") == 0);

	Entitate e3(e1);
	assert(e3 == e1);

	e3 = e2;
	assert(e3 == e2);

	e1.setZiua(5);
	e1.setSuma(500);
	e1.setTip("eee");
	assert(e1.getZiua() == 5);
	assert(e1.getSuma() == 500);
	assert(strcmp(e1.getTip(), "eee") == 0);

}

void test_repository()
{
	Repository r;
	Entitate e1(1, 100, "aaa");
	Entitate e2(2, 200, "bbb");
	Entitate e3(3, 300, "ccc");
	r.add(e1);
	r.add(e2);
	assert(r.getSize() == 2);
	assert(r.getAll()[0] == e1);
	assert(r.getAll()[1] == e2);

	Repository r1(r);
	assert(r1 == r);
	r1.update(e2, e3);
	assert(r1.exists(e2) == false);
	assert(r1.exists(e3) == true);
	assert(r1.find(e3) == 1);

	Repository r2;
	r2 = r;
	assert(r2 == r);
	r2.add(Entitate(3, 300, "c"));
	assert(!(r2 == r));

	assert(r.exists(e1) == true);
	assert(r.exists(e2) == true);
	assert(r.find(e1) == 0);
	assert(r.find(e2) == 1);
	r.remove(e1);
	assert(r.exists(e1) == false);
	assert(r.find(e2) == 0);
}

void test_service()
{
	Service s1, s2;
	Repository r;
	Entitate e1(1, 100, "aaa");
	Entitate e2(2, 200, "bbb");
	Entitate e3(3, 300, "ccc");
	r.add(e1);
	r.add(e2);
	r.add(e3);
	s1.setRepo(r);
	s2 = s1;
	Service s3(s1);
	assert(s2 == s1);
	assert(s3 == s1);
	s2.addEntity(4, 400, "ddd");
	assert(s2.getRepo().getSize() == 4);
	s1.removeEntity(1, 100, "aaa");
	s1.removeEntity(1, 100, "a");
	assert(s1.getRepo().getSize() == 2);
	s3.updateEntity(1, 100, "aaa", 2, 200, "bbb");
	s3.updateEntity(1, 100, "a", 2, 200, "bbb");
	assert(s3.getRepo().getAll()[0] == e2);
}

void test_UI()
{
	Repository r;
	Entitate e1(1, 100, "aaa");
	Entitate e2(2, 200, "bbb");
	Entitate e3(3, 300, "ccc");
	r.add(e1);
	r.add(e2);
	r.add(e3);
	Service s(r);
	UI u1(s);
	UI u2 = u1;
	assert(u1 == u2);
	assert(u1.getService() == s);
	Service s1 = s;
	s1.addEntity(4, 400, "ddd");
	u2.setService(s1);
	assert(!(u2.getService() == s));
	assert(u2.getService() == s1);
}

void my_tests()
{
	test_entitate();
	test_repository();
	test_service();
	test_UI();
	cout << "Toate testele au trecut cu succes!" << endl;
}