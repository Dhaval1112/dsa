#include <iostream>

using namespace std;

int getFactorial(int n)
{
    // Base condition
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Recursive call
    // fact (n) = n * fac(n-1)
    int finalAns = n * getFactorial(n - 1);
    return finalAns;
    // Processing part
}

void printCounting(int n)
{
    // Base case
    if (n == 0)
    {
        return;
    }
    // Processing
    cout << n << " ";
    printCounting(n - 1);
}

int power(int n)
{
    // Base case
    if (n == 0)
    {
        return 1;
    }

    // Processing

    return 2 * power(n - 1);
}

int fib(int n)
{
    // Base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    // Recursive call
    // fib(n)  = fib(n-1)+fib(n-2)
    // Processing
    return fib(n - 1) + fib(n - 2);
}

int getSum(int n)
{
    // Base case
    if (n == 1)
        return 1;

    // Recursive relation
    return n + getSum(n - 1);
}

int main()
{

    int n;
    // cout << "Enter Number for which you want to get factorial :: ";
    // cin >> n;
    // cout << "Factirial of " << n << " is : "
    //      << getFactorial(n) << endl;

    cout << "sum of 5 is :: " << getSum(5);

    return 0;
}