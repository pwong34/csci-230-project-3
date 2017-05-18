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
		inserthelp(e);
		
	}
	LList<Header>* c() { return column; }
	LList<Header>* r() { return row; }
	void inserthelp(Elem* n)
	{
		
		for( int i = 0; i < n->column(); i++)
		{
			if (column->length() == 0 || column->getValue().index() < n->column())
			{
				 Header head('c', n->column(), n);
				column->insert(head);
				break;
			}
			else if (column->getValue().index() == n->column())
			{
				column->getValue().add(n);
				break;
			}
			column->next();
		}

		for (int i = 0; i < n->row(); i++)
		{
			if (row->length() == 0 || row->getValue().index() < n->row())
			{
				Header head('r', n->row(), n);
				row->insert(head);
				break;
			}
			else if (row->getValue().index() == n->row())
			{
				row->getValue().add(n);
				break;
			}
			row->next();
		}
		return;
	}

	void print()
	{
		column->print();
		std::cout << std::endl;
		row->print();
	}
};