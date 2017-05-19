
#include "matrix.h"
#include <iostream>


int main()
{
	/*Elem* a = new Elem(0, 3, 3);
	Elem b (1, 3, 5);
	Elem c(5, 3, 0);
	Elem e(2, 3, 2);
	Header* d = new Header('c', 3, a);
	d->add(e);
	d->print();
	d->add(b);
	d->print();
	d->add(c);
	d->print();*/

	/*matrix* a = new matrix();
	a->insert(2, 2, 5);
	a->insert(10, 2, 3);
	a->insert(4, 2, 4);
	a->insert(4, 3, 4);
	a->insert(10, 10, 10);
	a->insert(9, 9, 9);
	a->insert(9, 8, 7);
	a->insert(10, 9, 6);
	a->insert(7, 7, 7);
	a->find(2, 2);
	a->find(4, 2);
	a->find(10, 2);
	a->find(4, 4);
	std::cout << "test" << std::endl;
	a->print();
	a->del(4, 3);
	a->del(7, 7);
	std::cout << "test----------------------" << std::endl;
	a->print();*/
	
	Elem  a(1, 3, 2);
	Elem* b = new Elem(1, 1, 1);
	a.right = b;
	a.transpose();
	a.print();
	a.down->print();
	

	/*LList<Header> z;
	z.insert(f);
	z.insert(f);
	z.print();*/


}