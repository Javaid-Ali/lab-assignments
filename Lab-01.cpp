#include <iostream>
using namespace std;

int main()
{

    /*
    Create a program that declares an integer variable and a pointer to it. Modify the value of the variable using the pointer and display both the variable and pointer values.
    */

    cout << "\n***** LAB 01 *****\n";
    cout << "Pointers Value assigning Concept\n\n";

    int num = 29;
    int *ptr = new int;

    ptr = &num;

    cout << "Value of the num = " << num;
    cout << "\nAddress of the num = " << &num;
    cout << "\nAddress store in the ptr = " << ptr;

    *ptr = 50;

    cout << "\n\n----- After Updating Variables! -----\n\n";
    cout << "Updated value of the num = " << num;
    cout << "\nAddress stored in the ptr = " << ptr;
    cout << "\nAddress of the ptr = " << &ptr << "\n\n";

    return 0;
}