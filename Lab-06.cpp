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
    friend void display_first_node();
    friend void display_last_node();
    friend void display_node_pos(int pos);
    friend void display_center_node();
    friend void delete_first_node();
    friend void delete_last_node();
    friend void delete_node_pos(int pos);
    friend void delete_center_node();
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

void display_first_node()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        cout << "\nFirst Node = " << temp->data << "\n";
    }
}

void display_last_node()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "Last  Node = " << temp->data << "\n";
    }
}

void display_node_pos(int pos)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        if (pos < 1)
        {
            cout << "\nInvalid Position!";
        }
        else if (pos == 1)
        {
            display_first_node();
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    cout << "\nInvalid Position!";
                }
            }

            cout << "Node at Position " << pos << " = " << temp->next->data << "\n";
        }
    }
}

void display_center_node()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        int count = 0;

        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        int middleNode = count / 2;
        temp = head;

        for (int i = 0; i < middleNode; i++)
        {
            temp = temp->next;
        }

        cout << "Middle Node = " << temp->data;
    }
}

void delete_first_node()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Link List is Empty!";
    }
    else
    {
        head = head->next;
        cout << "\nFirst Deleted Node = " << temp->data << "\n";
        temp = nullptr;
        delete temp;
    }
}

void delete_last_node()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Link List is Empty!";
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        cout << "Last  Deleted Node = " << temp->next->data << "\n";

        temp->next = nullptr;
        delete temp->next;
    }
}

void delete_node_pos(int pos)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        if (pos < 1)
        {
            cout << "\nInvalid Position!";
        }
        else if (pos == 1)
        {
            delete_first_node();
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    cout << "\nInvalid Position!";
                }
            }

            cout << "Node Deleted at Position " << pos << " = " << temp->next->data << "\n";

            Node *temp2 = temp->next;
            temp->next = temp->next->next;

            temp2 = nullptr;
            delete temp2;
        }
    }
}

void delete_center_node()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "\nLink List is Empty!\n";
    }
    else
    {
        int count = 0;

        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        int middleNode = count / 2;
        temp = head;

        for (int i = 1; i < middleNode; i++)
        {
            temp = temp->next;
        }

        cout << "Middle Deleted Node = " << temp->next->data << "\n";

        Node *temp2 = temp->next;
        temp->next = temp->next->next;

        temp2 = nullptr;
        delete temp2;
    }
}

int main()
{

    /*
    Implement functions to delete the first node, last node, Nth node, and centre node of a singly linked list.
    */

    cout << "\n***** LAB 06 *****\n";
    cout << "Functions to delete the first node, last node, Nth node, and centre node!\n\n";

    insert_at_start(10);
    insert_at_last(100);
    insert_at_start(20);
    insert_at_last(200);
    insert_at_last(300);
    insert_at_start(30);
    insert_at_pos(99, 4);
    insert_at_start(50);
    insert_at_last(500);

    cout << "Link List : ";
    display();
    cout << "\n";

    delete_first_node();
    delete_last_node();
    delete_node_pos(4);
    delete_center_node();
    cout << "\n";

    cout << "----- After Delete Functions Call -----\n\n";
    cout << "Link List : ";
    display();
    cout << "\n\n";

    return 0;
}