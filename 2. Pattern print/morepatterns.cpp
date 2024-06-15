#include <iostream>

using namespace std;

// Program 1. Full pyramid
void fullPyramid(int n)
{
    for (int row = 0; row < n; row++)
    {
        // For adding space
        for (int column = 0; column < n - row - 1; column++)
            cout << " ";

        // For adding star
        for (int column = 0; column < row + 1; column++)
            cout << "* ";

        cout << endl;
    }
}

// Program 2. Inverted pyramid
void invertedPyramid(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row; col++)
            cout << " ";

        for (int col = 0; col < n - row; col++)
            cout << "* ";
        cout << endl;
    }
}

// Program 3 : Diamond
void diamond(int n)
{
    fullPyramid(n);
    invertedPyramid(n);
}

// Program 4: Hollow pyramid
void hollowPyramid(int n)
{
    for (int row = 0; row < n; row++)
    {
        // For adding space
        for (int column = 0; column < n - row - 1; column++)
            cout << " ";

        // For adding star
        for (int column = 0; column < row + 1; column++)
        {
            if (row == 0 || row == n - 1 || column == 0 || column == (row + 1) - 1)
                cout << "* ";
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }
}

// Program 5 : Inverted Pyramid hollow
void invertedHollowPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // For Space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // For Star
        for (int k = 0; k < n - i; k++)
        {
            if (i == 0 || i == n - 1 || k == 0 || k == n - i - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

// Program 6 : Hollow Diamond
void hollowDiamond(int n)
{
    hollowPyramid(5);
    invertedHollowPyramid(5);
}

// Program 7 : Mix pattern
void mixDiagram(int n)
{
    // ------------
    // PART I
    // ------------
    for (int i = 0; i < n; i++)
    {
        // For printing *
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }

        // For printing +
        for (int k = 0; k < (i * 2) + 1; k++)
            cout << "  ";

        // For printing *
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // ------------
    // PART II
    // ------------
    for (int i = 0; i < n; i++)
    {
        // For printing *
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        // For printing +
        for (int k = 0; k < (n - i) * 2 - 1; k++)
            cout << "  ";

        // For printing *
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// Program 8 Fancy 12 pattern
void fancyPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + 1;
            if (j != i)
            {
                cout << " * ";
            }
        }
        cout << endl;
    }
}

// Program 9 : Full fancy pattern
void fullFancyPattern(int n)
{
    fancyPattern(n);
    n = n - 1;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
            if (j != i - 1)
                cout << " * ";
        }
        // I many of times forget to add this line
        cout << endl;
    }
}

// Program 10 : Write a program to print aba pattern
void abaPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = 'A';
        for (int j = 0; j < i + 1; j++)
        {
            cout << c;
            c += 1;
        }
        c -= 2;
        while (c >= 65)
        {
            cout << char(c);
            c--;
        }
        cout << endl;
    }
}

int main()
{
    abaPattern(6);

    return 0;
}