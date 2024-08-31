#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int getlength(char arr[])
{
    int count = 0;
    int index = 0;

    while (arr[index] != '\0')
    {
        count++;
        index++;
    }
    return count;
}

// convert upper lower conversion
void convertintolowercase(char arr[])
{
    int n = getlength(arr);
    for (int i = 0; i < n; i++)
    {
        char ch = arr[i];
        if (ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A') + 'a';
        arr[i] = ch;
    }
}

// convert upper case conversion
void convertintouppercase(char arr[])
{
    int n = getlength(arr);
    for (int i = 0; i < n; i++)
    {
        char ch = arr[i];
        if (ch >= 'a' && ch <= 'z')
            ch = (ch - 'a') + 'A';
        arr[i] = ch;
    }
}

// Reverse character array
void reversestring(char arr[])
{
    int left = 0;
    int right = getlength(arr);
    cout << right;

    while (left <= right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main()
{
    char arr[100];

    cout << "Enter your name :: ";
    // cin >> arr;
    // 100 is max size of characters get line function will store in an array
    // '\t' is delementer and till the \t input will read details after characters w  ill get ignored by the program
    cin.getline(arr, 100, '\n');

    cout << "Your name is :: " << arr << endl;

    char arr2[100];
    cin >> arr2;

    // to concate strings
    cout << strcat(arr, arr2);

    // to get lenght of the string
    cout << strlen(arr);

    // convertintolowercase(arr);
    // cout << arr << endl;
    // convertintouppercase(arr);
    // cout << arr << endl;

    reversestring(arr);
    cout << arr << endl;

    return 0;
}