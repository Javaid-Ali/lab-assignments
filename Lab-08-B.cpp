#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node *next;
	Node *prev;

public:
	Node(int d)
	{
		this->data = d;
		this->next = nullptr;
		this->prev = nullptr;
	}

	friend class LinkList;
};

class LinkList
{
private:
	Node *head;

public:
	LinkList()
	{
		head = nullptr;
	}

	~LinkList()
	{
		Node *current = head;
		while (current != NULL)
		{
			Node *nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	void insert_at_start(int);
	void display();
	void insert_at_end(int);
	void insert_at_pos(int, int);
	void merge_list(LinkList& l01, LinkList& l02);
};

int main()
{
	/*
	Create 2 Doubly LinkedLists and Merge them and display them.
	*/

	cout << "\n***** LAB 08 (2) *****\n";
	cout << "Create 2 Doubly LinkedLists and Merge them and display them!\n";

	LinkList list01, list02;

	list01.insert_at_start(10);
	list01.insert_at_start(20);
	list01.insert_at_pos(200, 2);
	list01.insert_at_end(30);

	cout << "\nLink List: NULL";
	list01.display();

	list02.insert_at_start(100);
	list02.insert_at_start(200);
	list02.insert_at_pos(2000, 2);
	list02.insert_at_end(300);

	cout << "\nLink List: NULL";
	list02.display();

	cout << "\n\nMerge Link List : ";
	list01.merge_list(list01, list02);
	list01.display();


	return 0;
}

void LinkList::insert_at_start(int d)
{
	Node *newNode = new Node(d);
	Node *temp = head;

	if (head != NULL)
	{
		head->prev = newNode;
	}

	newNode->next = head;
	head = newNode;
}

void LinkList::display()
{
	Node *temp = head;

	if (temp == NULL)
	{
		cout << "\nLink List is Empty!\n";
	}
	else
	{
		while (temp != NULL)
		{
			cout << " <-" << temp->data << "->";
			temp = temp->next;
		}
		cout << " NULL";
	}
}

void LinkList::insert_at_end(int d)
{
	Node *newNode = new Node(d);
	Node *temp = head;

	if (temp == NULL)
	{
		insert_at_start(d);
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
	}
}

void LinkList::insert_at_pos(int d, int pos)
{
	Node *newNode = new Node(d);
	Node *temp = head;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		if (pos < 1)
		{
			cout << "\nInvalid Position!\n";
			return;
		}
		else if (pos == 1)
		{
			insert_at_start(d);
		}
		else
		{
			for (int i = 1; i < pos - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
				{
					cout << "\nInvalid Position!\n";
					return;
				}
			}

			newNode->next = temp->next;

			if (temp->next != NULL)
			{
				temp->next->prev = newNode;
			}

			temp->next = newNode;
			newNode->prev = temp;
		}
	}
}

void LinkList::merge_list(LinkList& list01, LinkList& list02){
	Node* temp = list01.head;

	if(list02.head == NULL){
		return;
	}

	if(temp == NULL){
		list01.head = list02.head;
	} else {
		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = list02.head;
		list02.head->prev = temp;
	}

	list02.head = nullptr;
}