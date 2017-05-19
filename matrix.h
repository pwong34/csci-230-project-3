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
		Elem* e = new Elem(i, j, val);
		inserthelp(e);
	}
	Elem* find(int x, int y)
	{
		Header* col = NULL;
		column->moveToStart();
		for (int i = 0; i < column->length(); i++)
		{
			if (index(column) == y)
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

		for (int i = 0; i <= column->length(); i++)
		{
			if (column->length() == 0 || i == column->length() || index(column) > n->column())
			{
				Header head('c', n->column(), n);
				column->insert(head);
				column->moveToStart();
				break;
			}
			else if (index(column) == n->column())
			{
				column->getValue().add(n);
				column->moveToStart();
				break;
			}
			column->next();
		}

		for (int j = 0; j <= row->length(); j++)
		{
			if (row->length() == 0 || j == column->length() || index(row) > n->row())
			{
				Header head('r', n->row(), n);
				row->insert(head);
				row->moveToStart();
				break;
			}
			else if (index(row) == n->row())
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
		Header* header = NULL;
		bool cRemove = false, rRemove = false;
		column->moveToStart();
		for (int a = 0; a < column->length(); a++)
		{
			if (index(column) == j)
			{
				header = &column->getValue();
				break;
			}
			column->next();
		}
		if (e->up == NULL && e->down == NULL)
		{
			cRemove = true;
		}
		else if (e->up == NULL)
		{
			e->down->up = NULL;
			header->setHead(e->down);
		}
		else if (e->down == NULL)
		{
			e->up->down = NULL;
		}
		else
		{
			e->up->down = e->down;
			e->down->up = e->up;
		}
		//Delete for Rows
		row->moveToStart();
		for (int a = 0; a < row->length(); a++)
		{
			if (index(row) == i)
			{
				header = &row->getValue();
				break;
			}
			row->next();
		}
		if (e->left == NULL && e->right == NULL)
		{
			rRemove = true;
		}
		else if (e->left == NULL)
		{
			e->right->left = NULL;
			header->setHead(e->right);
		}
		else if (e->right == NULL)
		{
			e->left->right = NULL;
		}
		else
		{
			e->left->right = e->right;
			e->right->left = e->left;
		}
		if (cRemove) { column->remove(); }
		if (rRemove) { row->remove(); }
		if (!cRemove && !rRemove)
		{
			delete[] e;
		}
		return;
	}
	void transpose()
	{

	}

	inline int index(LList<Header>*l)
	{
		return l->getValue().index();
	}

	void print()
	{
		column->print();
		std::cout << std::endl;
		row->print();
	}
};