
/*
Stefania Ascencio
Linked list Chapter 16
Print single list backwards using functions and class
PE 4
COSC2412
*/
#include <iostream>
using namespace std;
struct node//structure definition
{
	int data;
	node* next;
};
class linkedListType// Base Class
{
private:
	node* head, * tail;
public:
	linkedListType()// constructor for the class
	{
		head = NULL;//
		tail = NULL;
	}
	void newNode(int n)
	{
		node* temp = new node;
		temp->data = n;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}
	void reversePrint()
	{
		struct node* ptr = head;
		struct node* last, * current;
		last = NULL;
		cout << "\n";
		while (ptr != last)
		{
			current = ptr;
			while (current->next != last)
			{
				current = current->next;
			}
			cout << current->data << " ";
			last = current;
		}
		cout << "\n";
	}
	void ReversePrintRecursiveU(struct node* head)
	{
		if (head == NULL)
			return;
		ReversePrintRecursiveU(head->next);
		cout << head->data << " ";
	}
	void recursiveReversePrint()// recurrsive reverse print function for a linked list.
	{
		ReversePrintRecursiveU(head);
	}
};
int main()
{
	linkedListType a;
	struct node* head;
	a.newNode(1);
	a.newNode(2);
	a.newNode(3);
	a.newNode(4);
	a.newNode(5);
	cout << "The linked list printed backwards :";
	a.reversePrint();
	cout << "The linked list printed backwards using recursive :" <<
		endl;
	a.recursiveReversePrint();
	system("pause");
	return 0;
}
