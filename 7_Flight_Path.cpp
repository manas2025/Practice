#include <iostream>
using namespace std;

struct node
{
	string data;
	int fuel;
	node *next;
};

class graph1
{
public:
	node *Head[10];
	int v, e;
	void create();
	void display();
	void edge();
};

void graph1::create()
{
	cout << "How many Vertices : ";
	cin >> v;
	cout << "Enter Name of Cities : \n ";
	for (int i = 0; i < v; i++)
	{
		Head[i] = new node;
		cout << "Enter Name of City " << i + 1 << " : \n ";
		cin >> Head[i]->data;
		Head[i]->next = NULL;
	}
}

void graph1::display()
{
	node *n2;
	for (int i = 0; i < v; i++)

	{
		cout << "\nSource :" << Head[i]->data;
		n2 = Head[i]->next;
		while (n2 != NULL)
		{
			cout << "   Dest : " << n2->data;
			cout << "   Fuel Required : " << n2->fuel;
			n2 = n2->next;
		}
	}
}

void graph1::edge()

{
	int i, j;
	string s, d;
	node *n1, *temp;
	cout << "How many Edges : ";
	cin >> e;
	for (i = 0; i < e; i++)
	{
		cout << "Enter Source n Dest :";
		cin >> s >> d;
		for (j = 0; j < v; j++)
		{
			if (s == Head[j]->data)
				break;
		}
		n1 = new node;
		n1->data = d;
		cout << "\n Enter Fuel Required : ";
		cin >> n1->fuel;
		n1->next = NULL;
		temp = Head[j];

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n1;
	}
}

int main()
{
	graph1 g1;
	g1.create();
	g1.edge();
	g1.display();
	return 0;
}
