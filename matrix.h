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
		inserthelp('c',column,j,e);
		inserthelp('r', row, i, e);
	}
	void transpose()
	{
		for (int i = 0; i < row->length(); i++)
		{
			row->getValue().transpose();
			row->next();
		}
		LList<Header>* temp = column;
		column = row;
		row = temp;
	}
	/*void iterator(LList<Header>* L, void(Header::*function) ())
	{
		for (int i = 0; i < L->length(); i++)
		{
			L->getValue().function();
		}
		L->next();
	}*/
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
	void inserthelp(char c,  LList<Header>* headers, int elemIndex, Elem* n)
	{

		for (int i = 0; i <= headers->length(); i++)
		{
			if (headers->length() == 0 || i == headers->length() || index(headers) > elemIndex)
			{
				Header head(c, elemIndex, n);
				headers->insert(head);
				headers->moveToStart();
				break;
			}
			else if (index(headers) == elemIndex)
			{
				headers->getValue().add(n);
				headers->moveToStart();
				break;
			}
			headers->next();
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