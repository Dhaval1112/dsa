#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 5;
    int *ptr = &a;

    cout << sizeof(ptr);
    int *ptr2;
    // cout << *ptr2;
    // using with an array

    int arr[] = {1, 2, 3, 4};
    int *ptr4 = arr;

    // Below expression is not possibles
    // arr = arr+1;

    // cout << ptr << endl;

    char ch[100] = "dhaval";
    char *chptr = ch;

    cout << &ch;

    // multi pointers

    vector<int> v;
    return 0;
}