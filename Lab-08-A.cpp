#include <iostream>
using namespace std;

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
    void merge_list(LinkList &obj1, LinkList &obj2);
};

int main()
{
    /*
    Create 2 Singly LinkedLists and Merge them and display them.
    */

    cout << "\n***** LAB 08 (1) *****\n";
    cout << "Create 2 Singly LinkedLists and Merge them and display them!\n\n";

    LinkList list01, list02;

    list01.insert_at_start(10);
    list01.insert_at_end(100);
    list01.insert_at_start(30);
    list01.insert_at_end(200);
    list01.insert_at_pos(400, 2);

    cout << "Link List : ";
    list01.display();

    list02.insert_at_start(1000);
    list02.insert_at_start(3000);
    list02.insert_at_pos(4000, 2);

    cout << "Link List : ";
    list02.display();

    cout << "Merge Link List : ";
    list01.merge_list(list01, list02);
    list01.display();

    return 0;
}

void LinkList::insert_at_start(int d)
{
    Node *newNode = new Node(d);

    newNode->next = head;
    head = newNode;
}

void LinkList::display()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Link List is Empty!";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n\n";
    }
}

void LinkList::insert_at_end(int d)
{
    Node *newNode = new Node(d);
    Node *temp = head;

    if (temp == NULL)
    {
        head = newNode;
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

void LinkList::insert_at_pos(int d, int pos)
{
    Node *newNode = new Node(d);
    Node *temp = head;

    if (temp == NULL)
    {
        head = newNode;
    }
    else
    {
        if (pos < 1)
        {
            cout << "\nInvalid Position!";
            return;
        }
        else if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;

                if (temp == NULL)
                {
                    cout << "\nInvalid Position!";
                    return;
                }
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void LinkList::merge_list(LinkList &list01, LinkList &list02)
{
    Node *temp = list01.head;

    if (list02.head == NULL)
    {
        return;
    }

    if (temp == NULL)
    {
        list01.head = list02.head;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = list02.head;
    }

    list02.head = nullptr;
}