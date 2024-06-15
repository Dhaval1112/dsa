#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findUniqueNumber(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

void sortZeroOne(int arr[], int n)
{
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    // Approach 1
    // int i = 0;
    // for (; i < zeroCount; i++)
    // {
    //     arr[i] = 0;
    // }
    // for (; i < n; i++)
    // {
    //     arr[i] = 1;
    // }

    // Approach 2
    // fill(arr, arr + zeroCount, 0);
    // fill(arr + zeroCount, arr + n, 1);

    // Approach 3
    sort(arr, arr + n);
}

void printAllPairs(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}

pair<int, int> checkTwoSum(int arr[], int n, int target)
{
    pair<int, int> ans = make_pair(-1, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.first = arr[i];
                ans.second = arr[j];
                return ans;
            }
        }
    }

    return ans;
}

// Sort 0 and 1ns
void sortXandOs(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int temp = 0;

    while (left < right)
    {
        if (arr[left] == 1 && arr[right] == 0)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        if (arr[left] == 0)
        {
            left++;
        }
        if (arr[right] == 1)
        {
            right--;
        }
    }
}

// Dutch national problem
void sortColours(vector<int> &nums)
{
    int low = 0;
    int current = 0;
    int high = nums.size() - 1;
    int temp = 0;

    while (current < high)
    {
        if (nums[current] == 0)
        {
            temp = nums[current];
            nums[current] = nums[low];
            nums[low] = temp;
            low++;
            current++;
        }
        else if (nums[current] == 2)
        {
            temp = nums[current];
            nums[current] = nums[high];
            nums[high] = temp;
            high--;
        }
        else
        {
            current++;
        }
    }
}

void PrintPairs(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            cout << nums[i] << " " << nums[j] << endl;
        }
    }
}

// Shift an elements of an array with n number
void shiftAnArray(int n, vector<int> &nums)
{
    int last_index = nums.size() - 1;

    for (int i = 0; i < n; i++)
    {
        int poped_element = nums.at(last_index);
        nums.pop_back();
        nums.insert(nums.begin(), poped_element);
    }
}

// Rotate an array with n nums of iteration
void rotateAnArray_A1(int n, vector<int> &nums)
{
    // Approach 1
    // Step 1 : create coppy of an array
    vector<int> coppy(nums);
    int size = nums.size() - 1;
    int k = 0;
    // [1,2,3,4,5]
    // [4,5,1,2,3]

    // step 2 : n -> size elements into an array
    for (int i = n - 1; i >= 0; i--)
    {
        nums[i] = coppy[size - k++];
    }

    k = 0;
    // Step 3 : add first 0 -> n elements in last of an array
    for (int j = n; j <= size; j++)
    {
        nums[j] = coppy[k++];
    }
}

void reverseAnArray(vector<int> &nums, int start, int end)
{
    int temp = 0;
    while (start < end)
    {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
// Rotate an array with n nums of iteration
void rotateAnArray_A2(int k, vector<int> &nums)
{
    int n = nums.size();
    // 1. Reverse first n-k to n elements in an array
    reverseAnArray(nums, (n - k), n - 1);

    // 2. Revserse 0 to n-k elements in an array
    reverseAnArray(nums, 0, n - k - 1);

    // 3. Reverse whole array
    reverseAnArray(nums, 0, n - 1);
    return;
}

int main()
{
    int arr[] = {10, 20, 30, 40};

    int size = 4;

    vector<int> vect = {1, 2, 3, 4, 5};

    // rotateAnArray_A1(3, vect);
    rotateAnArray_A2(2, vect);
    for (int num : vect)
    {
        cout << num << endl;
    }

    return 0;
}