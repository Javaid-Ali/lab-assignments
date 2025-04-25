#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[10];  
    int top;      

public:
    Stack()
    {
        top = -1; 
    }

    void push(int d)
    {
        if (top == 9)
        {
            cout << "Stack is Full";
            return;
        }
        top++;
        arr[top] = d;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!";
            return;
        }
        top--;
    }

    void push_at_start(int d)
    {
        if (top == 9)
        {
            cout << "Stack is Full";
            return;
        }
        
        for (int i = top; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        top++;
        arr[0] = d;
    }

    void pop_at_start()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!";
            return;
        }
        
        for (int i = 0; i < top; i++)
        {
            arr[i] = arr[i + 1];
        }
        top--;
    }

    void display()
    {
        cout << "----- STACK -----\n\n";
        cout << "Top Index = " << top << "\n\n";

        if (top == -1)
        {
            cout << "Stack is Empty!";
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << "| " << arr[i] << " |\n";
        }
        cout << "------";
    }
};

int main()
{
    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    s1.pop_at_start();
    s1.push_at_start(80);

    s1.pop();

    s1.display();

    return 0;
}