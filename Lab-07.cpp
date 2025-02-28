#include <iostream>
using namespace std;

class Node;
Node *head = nullptr;

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

    friend void insert_at_start(int d);
    friend void display();
    friend void insert_at_end(int d);
    friend void insert_at_pos(int d, int pos);
    friend void insert_at_mid(int d);
    friend void display_reverse();
};

void insert_at_start(int d)
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

void display()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        cout << "\nLink List: \nNULL";
        while (temp != NULL)
        {
            cout << " <-" << temp->data << "->";
            temp = temp->next;
        }
        cout << " NULL";
    }
}

void insert_at_end(int d)
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

void insert_at_pos(int d, int pos)
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

void display_reverse()
{
    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    if (head == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        cout << "\n\nReverse Link List : \nNULL";
        while (temp != NULL)
        {
            cout << " <-" << temp->data << "->";
            temp = temp->prev;
        }
        cout << " NULL";
    }
}

void insert_at_mid(int d)
{
    Node *newNode = new Node(d);
    Node *temp = head;

    if (temp == NULL)
    {
        insert_at_start(d);
    }
    else
    {
        int count = 0;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        int middleNode = (count + 1) / 2;
        temp = head;

        for (int i = 1; i < middleNode; i++)
        {
            temp = temp->next;
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

int main()
{
    /*
    Implement functions to insert node at first, last, Nth location, and centre of a doubly linked list. And display in order and display in reverse order.
    */

    cout << "\n***** LAB 07 *****\n";
    cout << "Functions to insert node at first, last, Nth location, and centre of a doubly linked list And display in order and display in reverse order!\n\n";

    insert_at_start(10);
    insert_at_start(20);
    insert_at_start(40);
    insert_at_end(100);
    insert_at_end(200);
    insert_at_pos(400, 4);
    insert_at_start(30);
    insert_at_pos(600, 6);
    insert_at_mid(1000);
    insert_at_mid(2000);
    insert_at_mid(3000);
    insert_at_mid(4000);
    insert_at_mid(5000);

    display();
    display_reverse();

    return 0;
}