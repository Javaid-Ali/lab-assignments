#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[10];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int d)
    {
        if (rear == 9)
        {
            cout << "Queue is Full";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        arr[rear] = d;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!";
            return;
        }
        else if (front <= rear)
        {
            arr[front] = 0;
            front++;
        }
    }

    void display()
    {
		cout << "----- Queue -----\n\n";
		
        cout << "Front Index = " << front;
        cout << "\nRear Index  = " << rear << "\n\n";
		
        if (front == -1)
        {
            cout << "Queue is Empty!";
            return;
        }

        int i = front;
		
		cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " -> ";
        }
        cout << "END";
    }
};

int main()
{

    Queue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    q1.dequeue();
    q1.display();

    return 0;
}