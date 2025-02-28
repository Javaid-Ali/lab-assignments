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
        next = nullptr;
    }

    friend void insert_at_start(int d);
    friend void display();
    friend void insert_at_last(int d);
    friend void insert_at_pos(int d, int pos);
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

void insert_at_pos(int d, int pos)
{
    Node *newNode = new Node(d);
    Node *temp = head;

    if (temp == NULL)
    {
        temp = newNode;
    }
    else
    {
        if (pos < 1)
        {
            cout << "Invalid Position!\n";
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
                    cout << "Invalid Position!\n";
                    return;
                }
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

int main()
{

    /*
    Write a function to insert a node at a specific position in a singly linked list, ensuring valid position handling.
    */

    cout << "\n***** LAB 04 *****\n";
    cout << "Insert at any Position with Valid Position Handling!\n\n";

    insert_at_start(10);
    insert_at_last(100);
    insert_at_start(20);
    insert_at_last(200);
    insert_at_last(300);
    insert_at_start(30);
    insert_at_pos(99, 4);

    cout << "Link List : ";
    display();
    cout << "\n\n";

    return 0;
}