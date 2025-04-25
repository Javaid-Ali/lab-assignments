#include <iostream>
using namespace std;

class Queue;
Queue *front = nullptr;
Queue *rear = nullptr;

class Queue
{
private:
    int data;
    Queue *next;

public:
    Queue(int d)
    {
        data = d;
        next = nullptr;
    }

    friend void enqueue(int d);
    friend void dequeue();
    friend void display();
};

void enqueue(int d)
{
    Queue *newNode = new Queue(d);

    if (rear == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    Queue *temp = front;
    front = front->next;

    if (front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;
    temp = nullptr;
}

void display()
{
    Queue *temp = front;

    cout << "----- Queue -----\n\n";
    
    cout << "Queue: ";
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    dequeue();
    dequeue();

    display();

    return 0;
}