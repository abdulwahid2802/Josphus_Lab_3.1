#include "Josephus.h"

List::List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

void List::insert(int data)
{
	createNode(data);
}

void List::createNode(int data)
{
	Nptr n = new Node();
	n->data = data;
	n->next = NULL;

	addNode_linear(head, n);
	//addNode_iterative(head, n);
	//addNode_recursive(head, n);
}

void List::addNode_linear(Nptr &Ptr, Nptr n)
{
	if (isEmpty())
	{
		Ptr = n;
		tail = n;
		n->next = head;
		count++;
	}
	else
	{
		tail->next = n;
		tail = n;
		n->next = head;
		count++;
	}
}

void List::addNode_iterative(Nptr &Ptr, Nptr n)
{
	Nptr curr;
	if(isEmpty())
	{
		Ptr = n;
		tail = n;
		n->next = head;
		count++;
	}
	else
	{
		curr = Ptr;
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = n;
		tail = n;
		n->next = head;

		count++;
	}
}

void List::addNode_recursive(Nptr &Ptr, Nptr n)
{
	if (Ptr || (Ptr->next != head))
	{
		addNode_recursive(Ptr->next, n);
	}
	else
	{
		Ptr = n;
		tail = n;
		n->next = head;
		count++;
	}
}

bool List::isEmpty()const
{
	return (head == NULL) || (count == 0);
}

void List::print()const
{
	Nptr curr = head;
	if (!isEmpty())
	{
		do
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		while (curr != head);
	}
}

void List::josephus(int step)
{
	if (!isEmpty())
		findVictim(step);
	else
		cout << "List is empty"<<endl;
}

void List::findVictim(int step)
{
	Nptr curr = head;

	while (count > 1)
	{
		int i = step - 1;
			
		while (i--)
			curr = curr->next;

		killVictim(curr, curr->next);
		curr = curr->next;
	}

	// print the last element surviving
	cout<< endl << head->data<<endl;
}

void List::killVictim(Nptr &prev, Nptr victim)
{
	if (victim == head)
	{
		head = victim->next;
		prev->next = head;
		delete victim; // could be bug cuz victim is reference
		count--;
	}
	else
	{
		prev->next = victim->next;
		delete victim; // could be bug cuz victim is reference
		count--;
	}
}