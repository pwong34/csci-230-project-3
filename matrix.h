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
	Elem* find(int x, int y)
	{
		Header* col = NULL;
		column->moveToStart();
		for (int i = 0; i < column->length(); i++)
		{
			if (column->getValue().index() == y)
			{
				col = &column->getValue();
				break;
			}
			column->next();
		}
		column->moveToStart();
		if (col == NULL) { return NULL; }
		Elem* node = col->header();
		for (int j = 0; j < row->length(); j++)
		{
			if (node->row() == x)
			{
				node->print();
				return node;
			}
			node = node->down;
		}
		return NULL;
	}
	LList<Header>* c() { return column; }
	LList<Header>* r() { return row; }
	void inserthelp(Elem* n)
	{
		
		for( int i = 0; i <=column->length(); i++)
		{
			if (column->length() == 0 || i == column->length()|| column->getValue().index() > n->column())
			{
				 Header head('c', n->column(), n);
				column->insert(head);
				column->moveToStart();
				break;
			}
			else if (column->getValue().index() == n->column())
			{
				column->getValue().add(n);
				column->moveToStart();
				break;
			}
			column->next();
		}

		for (int j = 0; j <=row->length(); j++)
		{
			if (row->length() == 0 || j == column->length() || row->getValue().index() > n->row())
			{
				Header head('r', n->row(), n);
				row->insert(head);
				row->moveToStart();
				break;
			}
			else if (row->getValue().index() == n->row())
			{
				row->getValue().add(n);
				row->moveToStart();
				break;
			}
			row->next();
		}
		return;
	}

	void del(int i, int j)
	{
		Elem* e = find(i, j);
		if (e == NULL) { return; }
		if (e->up == NULL && e->down == NULL)
		{
			Header* head;
			column->moveToStart();
			for (int i = 0; i < column->length(); i++)
			{
				if (column->getValue().index() == j)
				{
					head = &column->getValue();
					break;
				}
			}
			delete[] head;
			delete[] e;
		}
		else if (e->up == NULL)
		{

		}
		else if (e->down == NULL)
		{

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