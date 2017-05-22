
#include "matrix.h"
#include <iostream>


int main()
{
	/*Elem* a = new Elem(0, 3, 3);
	Elem *b = new Elem(3, 0, 5);
	Elem *c = new Elem(5, 0, 10);
	Elem *e = new Elem(0, 5, 2);
	Header* d = new Header('c', 3, a);
	Header* f = new Header('r', 3, b);
	d->add(c);
	f->add(e);
	std::cout << f->mul(d);*/

	matrix* a = new matrix();
	matrix* b = new matrix();
	b->insert(0, 0, 1);
	b->insert(0, 1, 2);
	b->insert(1, 0, 3);
	b->insert(1, 1, 4);
	a->insert(0, 0, 1);
	a->insert(0, 1, 2);
	a->insert(1, 0, 3);
	a->insert(1, 1, 4);
	a->insert(2, 2, 65);
	/*b->insert(25, 25, 5);
	a->insert(2, 2, 4);
	a->insert(10, 2, 12);
	a->insert(4, 2, 6);
	a->insert(4, 3, 7);
	a->insert(10, 10, 20);
	a->insert(9, 9, 18);
	a->insert(9, 8, 17);
	a->insert(10, 9, 19);
	a->insert(7, 7, 14);
	a->insert(7, 7, 10);*/
	/*std::cout << "test" << std::endl;
	b->print();
	a->print();
	std::cout << "test----------------------" << std::endl;
	a->print();*/
	matrix* m = a->mul(b);
	delete m;
	std::cout << "test----------------------" << std::endl;
	LList<int>* k = new LList<int>();
	k->insert(10);
	k->insert(200);
	std::cout << k->getValue();
	k->reverse();
	std::cout << k->getValue();
	//m->print();
	/*Elem  a(1, 3, 2);
	Elem* b = new Elem(1, 1, 1);
	a.right = b;
	a.transpose();
	a.print();
	a.down->print();*/
	

	/*LList<Header> z;
	z.insert(f);
	z.insert(f);
	z.print();*/
}
