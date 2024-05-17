#include <iostream>

using namespace std;

void printSquare(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return;
}

void printRectangle()
{
    int rows;
    int columns;

    cout << "Enter rows ::";
    cin >> rows;

    cout << "Enter columns ::";
    cin >> columns;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void hollowRectangle(int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return;
}

void hollowSquare(int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == 0 || i == length - 1 || j == 0 || j == length - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void printPyramid(int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void reversePyramid(int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void hollowPyramid(int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i == 0 || i == row - 1 || j == 0 || j == i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return;
}

void hollowReversePyramid(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            if (i == 0 || i == rows - 1 || j == 0 || j == (rows - (i + 1)))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return;
}

void numaricPyramid(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void reverseNumaricPyramid(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Program 1
    /*
     * * * *
     * * * *
     * * * *
     * * * *
     */
    // printSquare(3, 5);

    // Program 2 take user input and print it
    /*
     * * * * *
     * * * * *
     * * * * *
     */
    // printRectangle();

    // Program 3 print hollow rectangle
    /*
     * * * * *
     *       *
     * * * * *
     */
    // hollowRectangle(10, 10);

    // Program 4 hollow square
    /*
     * * * * *
     *       *
     *       *
     * * * * *
     */
    // hollowSquare(50);

    // Progeam 5 pyramid
    /*
     *
     * *
     * * *
     * * * *
     */
    // printPyramid(10);

    // Progeam 5 reverse pyramid
    /*
     * * * *
     * * *
     * *
     *
     */
    // Normal loop
    // start from n - i to > 0 i --
    // reversePyramid(10);

    // Progeam 5 Hollow Pyramid
    /*
     *
     * *
     *   *
     * * * *
     */
    // hollowPyramid(10);

    // Progeam 6 reverse hollow reverse pyramid
    /*
     * * * *
     *   *
     * *
     *
     */
    // hollowReversePyramid(10);

    // Progeam 7 Numaric pyramid
    /*
    1
    1 2
    1 2 3
    1 2 3 4
    */
    // numaricPyramid(10);

    // Progeam 8 reverse pyramid
    /*
    1 2 3 4
    1 2 3
    1 2
    1
    */
    reverseNumaricPyramid(10);
    return 0;
}