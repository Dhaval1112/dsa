#include <iostream>
#include <math.h>

using namespace std;

void printArray(int arr[], int n, int index)
{
    // Base condition
    if (index >= n)
    {
        return;
    }

    // Processing part
    cout << arr[index] << " ";

    // Recursive call
    printArray(arr, n, index + 1);
}

int findElementFromArray(int arr[], int n, int index, int target)
{
    // Base condition
    if (index >= n)
    {
        return -1;
    }

    // Proccessing part
    if (arr[index] == target)
    {
        return index;
    }

    // Recursive Relation
    return findElementFromArray(arr, n, index + 1, target);
}

int maxInArray(int arr[], int n, int index, int maxNum)
{
    // Base condition
    if (index >= n)
    {
        return maxNum;
    }

    // Processing
    maxNum = max(maxNum, arr[index]);

    // Recursive relation
    return maxInArray(arr, n, index + 1, maxNum);
}

int minInArray(int arr[], int n, int index, int minNum)
{
    // Base condition
    if (index >= n)
    {
        return minNum;
    }

    // Processing
    minNum = min(minNum, arr[index]);

    // Recursive relation
    return minInArray(arr, n, index + 1, minNum);
}

void printAllEvens(int arr[], int n, int index)
{
    // Base
    if (index >= n)
    {
        return;
    }

    // Processing
    if (!(arr[index] & 1))
    {
        cout << arr[index] << " ";
    }

    // Recursive relation
    printAllEvens(arr, n, index + 1);
}

int binarySearch(int arr[], int s, int e, int target)
{
    // Base condition
    if (s > e)
    {
        return -1;
    }

    int mid = (s + e) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        e = mid - 1;
    }
    else
    {
        s = mid + 1;
    }
    return binarySearch(arr, s, e, target);
}

void printNum(int num)
{
    // Base condition
    if (num <= 0)
    {
        return;
    }

    // Recursive call
    int rem = num % 10;
    printNum(num / 10);
    cout << rem << " ";
}

bool checkSorted(int arr[], int n, int index)
{
    // Base condition
    if (index + 1 >= n)
    {
        return true;
    }

    // Processing
    if (arr[index] > arr[index + 1])
    {
        return false;
    }

    // Recursive relation
    return checkSorted(arr, n, index + 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    // printArray(arr, size, 0);
    // cout << "find 10 from an array :: " << binarySearch(arr, 0, size, 60);
    // printAllEvens(arr, size, 0);

    cout << "check that provided array is sorted :: " << checkSorted(arr, size, 0);

    return 0;
}