#include <iostream>
using namespace std;

class Node;
Node *head = NULL;

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
    friend void insert_at_pos(int d, int pos);
    friend void insert_at_center(int d);
    friend void display_reverse();
};

void insert_at_start(int d)
{
    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head;
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        head = newNode;
    }
}

void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "Link List is Empty!\n\n";
    }
    else
    {
        cout << "Link List : ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        Node *check = head;
        while (check->next != head)
        {
            check = check->next;
        }
        cout << check->next->data << "\n";
    }
}

void insert_at_last(int d)
{
    Node *newNode = new Node(d);
    Node *temp = head;

    if (temp == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insert_at_pos(int d, int pos)
{
    Node *newNode = new Node(d);
    Node *temp = head;
    if (pos < 1)
    {
        cout << "Invalid Position!\n";
        return;
    }
    else if (pos == 1)
    {
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            newNode->next = head;
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            last->next = newNode;
            head = newNode;
        }
    }
    else
    {
        if (head == NULL)
        {
            cout << "Invalid Position! List is empty.\n";
            return;
        }

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                cout << "Invalid Position!\n";
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insert_at_center(int d)
{
    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *temp = head;
        int count = 0;

        while (temp->next != head)
        {
            temp = temp->next;
            count++;
        }

        int mid = (count + 1) / 2;
        temp = head;

        for (int i = 1; i < mid; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display_reverse()
{
    if (head == NULL || head->next == head)
    {
        cout << "Less Nodes to Reverse\n";
        return;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = NULL;

    do
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    head->next = prev;
    head = prev;

    cout << "\nLink List in Reverse Order: ";
    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    Node *check = head;
    while (check->next != head)
    {
        check = check->next;
    }
    cout << check->next->data << "\n\n";

    prev = NULL;
    curr = head;
    nextNode = NULL;

    do
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    head->next = prev;
    head = prev;
}

int main()
{

    /*
    Implement functions to insert node at first, last, Nth location, and centre of a circular linked list. And display in order and display in reverse order.
    */

    cout << "\n***** LAB 09 *****\n";
    cout << "Circular Linked List (Insert & Display Nodes)!\n\n";

    insert_at_start(10);
    insert_at_pos(1000, 1);
    insert_at_start(20);
    insert_at_start(50);
    insert_at_pos(6000, 12);
    insert_at_last(1500);
    insert_at_center(3000);

    display();
    display_reverse();
    display();

    return 0;
}