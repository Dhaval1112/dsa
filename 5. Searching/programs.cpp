#include <iostream>
#include <vector>

using namespace std;

// Approach 1 and probebely the best approach
vector<int> withtwopointers(vector<int> &arr, int k, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    vector<int> ans;

    while (high - low >= k)
    {
        if (arr[high] - x >= x - arr[low])
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}

// Second approach
int bsElement(vector<int> vec, int x)
{
    int left = 0;
    int right = vec.size() - 1;
    int ans = right;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (vec[mid] >= x)
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

vector<int> kthClosestElementsBS(vector<int> arr, int k, int x)
{
    int right = bsElement(arr, x);
    int left = right - 1;

    while (right - left < k)
    {
        if (left < 0)
        {
            right++;
        }
        else if (right >= arr.size())
        {
            left--;
        }
        else if (x - arr[left] > arr[right] - x)
        {
            right++;
        }
        else
        {
            left--;
        }
    }

    return vector<int>(arr.begin() + left, arr.begin() + right);
}

void exponentialArraySearch(vector<int> arr, int x, int n)
{
    int i = 0;
    int j = 1;
    if (arr[i] == x)
    {
        cout << i << "  " << j << endl;
    }
    else
    {
        while (arr[j] < x && j <= n)
        {
            i = j;
            j = j * 2;
        }
    }

    j = min(j, n);
    cout << arr[i] << " <-> " << arr[j];
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 8, 22, 66, 99, 105, 202, 302, 406, 602, 852, 922};

    cout << bsElement(arr, 1) << endl;
    // vector<int> ans = kthClosestElements(arr, 4, 3);
    exponentialArraySearch(arr, 202, arr.size() - 1);
    cout
        << endl
        << endl
        << " below are the element :: ";

    return 0;
}