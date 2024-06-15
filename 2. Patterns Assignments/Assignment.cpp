#include <iostream>
using namespace std;

// Program 1 : Half numaric hollow pyramid
void numaricHollowPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == i)
            {
                cout << j + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// Program 2 : Half numaric hollow inverted pyramid
void numaricInvertedPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == i || j == n - 1)
                cout << j + 1 << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// Program 3 : Numaric Palindrom Equiliteral Pyramid
void numaricPalindromEquDiagram(int n)
{
    for (int i = 0; i < n; i++)
    {
        // For printing space
        for (int s = 0; s < n - i - 1; s++)
        {
            cout << "  ";
        }

        // For printing first numaric increment
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }

        // For printing space
        for (int k = i; k > 0; k--)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}

// Program 4 : Solid Half Diagram
void solidHalfDiagram(int n)
{
    // for printing Half Diagram
    for (int i = 0; i < n; i++)
    {
        // For printing half pyramid
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    { // For printing inverted half pyramid
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// Program 5 :
void fancyPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "****";
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }

        for (int k = 0; k < i + 1; k++)
        {
            cout << i + 1;
            if (k != i)
            {
                cout << "*";
            }
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        cout << "****";
        cout << endl;
    }
}

int main()
{
    fancyPattern(5);
    return 1;
}