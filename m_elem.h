#include <iostream>
class Elem
{
private:
	int i;
	int j;
	int val;
	
public:
	Elem* up;
	Elem* down;
	Elem* right;
	Elem* left;

	Elem(int a, int b, int c)
	{
		i = a;
		j = b;
		val = c;
		up = NULL;
		down = NULL;
		right = NULL;
		left = NULL;
	}
	~Elem(){}
	int data(){return val;}
	int row(){return i;}
	int column(){return j;}
	void setData(int n)
	{
		val = n;
	}

	Elem* add(char c, Elem* elem) 
	{
		Elem* temp = this;
		Elem* temp2 = this;
		if(c=='c')
		{
			while(true)
			{
				
				if (temp == NULL || elem->row() < temp->row())
				{
					elem->down = temp;
					if (elem->row() < this->row())
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
			while (true)
			{
				if (temp == NULL || elem->column() < temp->column())
				{
					elem->right = temp;
					if (elem->column() < this->column())
					{
						temp->left = elem;
						return elem;
					}
					if (temp != NULL)
					{
						elem->left = temp->left;
						temp2->right = elem;
						temp->left = elem;
					}
					else
					{
						elem->left = temp2;
						temp2->right = elem;
					}
					return this;
				}
				temp2 = temp;
				temp = temp->right;
			}

		}
	}

	void transpose()
	{
		int temp = i; 
		i = j;
		j = temp;
		Elem* temp2 = up;
		up = left;
		left = temp2;
		temp2 = down;
		down = right;
		right = temp2;
	}
	void print()
	{
		std::cout << val << " at (" << i << ", " << j << ")" << std::endl;
	}
};