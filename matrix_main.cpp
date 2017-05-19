
#include "matrix.h"
#include <iostream>


int main()
{
	/*Elem* a = new Elem(0, 3, 3);
	Elem *b = new Elem(1, 3, 5);
	Elem *c = new Elem(5, 3, 0);
	Elem *e = new Elem(2, 3, 2);
	Header* d = new Header('c', 3, a);
	d->add(e);
	d->print();
	d->add(b);
	d->print();
	d->add(c);
	d->print();
	d->transpose();
	d->print();*/

	matrix* a = new matrix();
	a->insert(2, 2, 4);
	a->insert(10, 2, 12);
	a->insert(4, 2, 6);
	a->insert(4, 3, 7);
	a->insert(10, 10, 20);
	a->insert(9, 9, 18);
	a->insert(9, 8, 17);
	a->insert(10, 9, 19);
	a->insert(7, 7, 14);
	std::cout << "test" << std::endl;
	a->print();
	std::cout << "test----------------------" << std::endl;
	a->transpose();
	a->print();
	
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