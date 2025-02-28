#include <iostream>
using namespace std;

int findMaxValue(int arr[], int n){
    int maxValue = arr[0];

    for(int i=0; i<n; i++){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }

    return maxValue;
}

int main(){

    /*
    Implement a function that finds the maximum value in an array of size n. Determine its time complexity and explain why it is O(n).
    */

    cout << "\n***** LAB 02 *****\n";
    cout << "Find Max value from n Size Array using Function\n\n";

    int arr[] = {12, 412, 52, -123, 32, 42, 77, 235, -3456, 234};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array = {";
    for(int i=0; i<n; i++){
        cout << arr[i];
        if(i != n-1){
            cout << ", ";
        }
    }
    cout << "}\n\n";

    int maxValue = findMaxValue(arr, n);

    cout << "Max Value in the Array = " << maxValue << "\n\n";

    return 0;
}