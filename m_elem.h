#include <iostream>
class Elem
{
private:
	int i;
	int j;
	int dat;
	
public:
	Elem* up;
	Elem* down;
	Elem* left;
	Elem* right;

	Elem(int a, int b, int c)
	{
		i = a;
		j = b;
		dat = c;
		up = NULL;
		down = NULL;
		left = NULL;
		right = NULL;
	}
	~Elem(){}
	int data(){return dat;}
	int row(){return i;}
	int column(){return j;}

	Elem* add(char c, Elem& e) 
	{
		Elem* elem = &e;
		Elem* temp = this;
		Elem* temp2 = this;
		if(c=='c')
		{
			while(true)
			{
				if (temp == NULL || elem->row() < temp->row())
				{
					elem->down = temp;
					if (e.row() < this->row())
					{
						temp->up = elem;
						return elem;
					}
					if (temp != NULL)
					{
						elem->up = temp->up;
						temp2->down = elem;
						temp->up = elem;
					}
					else 
					{
						elem->up = temp2;
						temp2->down = elem;
					}
					return this;
				}
				temp2 = temp;
				temp = temp->down;
			}
		}
		else
		{

		}
	}
	void print()
	{
		std::cout << dat << " at (" << i << ", " << j << ")" << std::endl;
	}
};