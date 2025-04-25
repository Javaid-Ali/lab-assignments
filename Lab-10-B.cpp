#include <iostream>
using namespace std;

class Stack;
Stack *top = nullptr;

class Stack
{
private:
    int data;
    Stack *next;

public:
    Stack(int d)
    {
        data = d;
        next = nullptr;
    }

    friend void push(int d);
    friend void pop();
    friend void display();
    friend void push_at_start(int d);
    friend void pop_at_start();
};

void push(int d)
{
    Stack *newNode = new Stack(d);

    newNode->next = top;
    top = newNode;
}

void display()
{
    cout << "----- STACK -----\n\n";
    Stack *temp = top;
    cout << "Top Index = " << temp->data << "\n\n";

    while (temp != nullptr)
    {
        cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }
    cout << "------";
}

void pop()
{
    Stack *temp = top;

    top = top->next;
    delete temp;
    temp = nullptr;
}

void push_at_start(int d)
{
    Stack *newNode = new Stack(d);

    Stack *temp = top;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void pop_at_start()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow! Cannot pop from an empty stack.\n";
        return;
    }

    if (top->next == nullptr)
    {
        delete top;
        top = nullptr;
        return;
    }

    Stack *temp = top;
    Stack *prev = nullptr;

    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    delete temp;
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    pop_at_start();
    push_at_start(80);

    pop();
	push(70);
    display();

    return 0;
}