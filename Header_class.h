#include "m_elem.h"

class Header
{
private:
	char c;
	int pos;
	Elem* head;
public:
	Header() {}
	Header(char a, int p, Elem* h) { head = h; c = a; pos = p; }
	~Header(){}

	Elem* header(){return head;}
	char type() {return c;}
	int index(){return pos;}
	void setHead(Elem * h)
	{
		head = h;
	}
	void print()
	{
		Elem* temp = head;
		while (temp != NULL)
		{
			temp->print();
			if (c == 'c')
			{
				temp = temp->down;
			}
			else
			{
				temp = temp->right;
			}
		}
		std::cout << std::endl;
	}
	void add(Elem* e)
	{
		head = head->add(c, e);
	}
	void transpose()
	{
		Elem* temp = head;
		while (temp != NULL)
		{
			temp->transpose();
			if (c == 'c')
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->down;
			}
		}
		if (c == 'c') { c = 'r'; }
		else { c = 'c'; }
	}
};