#include <iostream>

using namespace std;

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
int main()
{
    hollowPyramid(10);

    return 0;
}