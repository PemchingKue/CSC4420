#include <iostream>
#include <cstdlib>

using namespace std;

struct node{

	int size;
	char a_Process;
	node *next;

};

node *getNodeSize(int size)
{

	node *temp = (node *) malloc (sizeof(node));
	temp->size = size;
	temp->a_Process = '\0';
	temp->next = NULL;
	return temp;

}

void a_Memory(node *head, int size, char process)
{

	node *temp = head;
	bool solu_Found = false;
	while(temp!=NULL)
	{

		if(temp->a_Process == '\0' )
		{
		if(temp->size == size)
		{

		temp->a_Process = process;
		solu_Found = true;
		break;

		}
		else if(temp->size > size)
		{

		node *newNode = getNodeSize(temp->size - size);
		temp->size = size;
		newNode->next = temp->next;
		temp->next = newNode;
		temp->a_Process = process;
		solu_Found = true;
		break;

			}

		}

		temp = temp->next;

	}

	if(solu_Found == false)
	{
	cout << "\nError, Block unable to accommodate current process " << process << endl;
	return;
	}

}



void f_Memory(node *head, char process)
{

	node *temp = head;

		while(temp != NULL)
		{
			if(temp->a_Process == process)
			{
			temp->a_Process = '\0';
			break;
			}
		temp=temp->next;
		}

}

void p_Memory(node *head)
{

	cout<<endl;
	node *temp = head;

		while(temp != NULL)
		{
		if(temp->a_Process == '\0')
		cout << "Free units: " << temp->size <<" ";
		else
		cout << temp->a_Process << ": "<< temp->size << " units, ";
		temp = temp->next;
		}

}

int main() {

node *head = getNodeSize(10);

p_Memory(head);
a_Memory(head, 2, 'A');

p_Memory(head);
a_Memory(head, 3, 'B');

p_Memory(head);
a_Memory(head, 4, 'C');

p_Memory(head);
f_Memory(head, 'B');

p_Memory(head);
a_Memory(head, 1, 'E');

p_Memory(head);
f_Memory(head, 'C');

p_Memory(head);
f_Memory(head, 'A');

p_Memory(head);
a_Memory(head, 5, 'H');

return 0;
}
