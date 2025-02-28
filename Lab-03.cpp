#include <iostream>
using namespace std;

class Node;

Node *head = nullptr;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }

    friend void insert_at_start(int d);
    friend void display();
    friend void insert_at_last(int d);
};

void insert_at_start(int d)
{
    Node *newNode = new Node(d);

    newNode->next = head;
    head = newNode;
}

void display()
{
    if (head == NULL)
    {
        cout << "Link List is Empty!";
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
}

void insert_at_last(int d)
{
    Node *newNode = new Node(d);
    Node *temp = head;

    if (temp == NULL)
    {
        temp = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

int main()
{
    /*
    Implement a singly linked list with functions to insert a node at the start and at the end. Display the list after each insertion.
    */

    cout << "\n***** LAB 03 *****\n";
    cout << "Insert at Start and End\n\n";

    insert_at_start(10);
    insert_at_start(20);
    insert_at_last(100);
    insert_at_start(30);
    insert_at_last(200);

    cout << "Link List : ";
    display();
    cout << "\n\n";

    return 0;
}