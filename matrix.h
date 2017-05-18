#include "Header_class.h"
#include "LList.h"
#include <iostream>

class matrix
{
private:
	LList<Header>* column;
	LList<Header>* row;
public:
	matrix()
	{
		column = new LList<Header>();
		row = new LList<Header>();
	}
	void insert(int i, int j, int val)
	{
		Elem* e = new Elem(i,j,val);
		Elem elem = *e;
		inserthelp(elem);
		
	}
	LList<Header>* c() { return column; }
	LList<Header>* r() { return row; }
	void inserthelp(Elem &n)
	{
		Elem* temp = &n;
		for( int i = 0; i < n.column(); i++)
		{
			if (column->length() == 0 || column->getValue().index() < n.column())
			{
				 Header head('c', n.column(), temp);
				head.print();
				column->insert(head);
				std::cout << " New Header" << std::endl;
				column->print();
				break;
			}
			else if (column->getValue().index() == n.column())
			{
				std::cout << "Same Header" << std::endl;
				column->getValue().add(n);
				column->print();
				break;
			}
			column->next();
			std::cout << " Column next" << std::endl;
		}
		return;
	}

	void print()
	{
		column->print();
		std::cout << std::endl;
	}
};