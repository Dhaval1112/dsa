#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

// Need to find pairs which sum equals to the target
vector<int> twoSum(vector<int> &nums, int target)
{
    int first = 0;
    int second = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                first = i;
                second = j;
            }
        }
    }
    return {first, second};
}

// Program 2 : Pivote index - 724
int pivoteIndex(vector<int> &nums)
{
    int n = nums.size();
    int leftSum = 0;
    int rightSum = 0;

    for (int i = 0; i < n; i++)
    {
        // Keeping track of left sum
        if (i != 0)
            leftSum += nums[i - 1];
        rightSum = 0;

        // Calculating right sum
        for (int j = i + 1; j < n; j++)
        {
            rightSum += nums[j];
        }

        // Checking current index's left and right sums are same
        if (leftSum == rightSum)
        {
            return i;
        }
    }
    return -1;
}

// Program 3 : 268. Missing Number
int missingNumber(vector<int> &nums)
{
    int missingNumber = 0;
    for (int i = 0; i < nums.size(); i++)
        missingNumber = missingNumber ^ nums[i];

    for (int j = 0; j <= nums.size(); j++)
        missingNumber = missingNumber ^ j;

    return missingNumber;
}

// Program : 26. Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &nums)
{
    int left = 0;
    int current = 1;
    int n = nums.size();

    while (current < n)
    {
        // Checking if current and left elements are same
        if (nums[current] != nums[left])
        {
            left++;
            nums[left] = nums[current];
        }
        current++;
    }
    return left + 1;
}

// Program : 643. Maximum Average Subarray I
double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0;
    int right = k;
    int sum = 0;
    int maxSum = 0;

    // For getting first elements sum
    for (int i = left; i < right; i++)
        sum += nums[i];

    maxSum = sum;
    right;

    while (right < n)
    {
        sum -= nums[left++];
        sum += nums[right++];
        maxSum = max(maxSum, sum);
    }
    return (double)maxSum / k;
}

// Program : Switch all the nagative numbers to the left side
void switchNumsApproach1(vector<int> &nums)
{
    int left = 0;
    int right = 1;
    int n = nums.size();

    while (right < n && left < right)
    {
        if (nums[left] < 0)
        {
            left++;
        }
        if (nums[right] > 0 || (nums[right] < 0 && nums[left] < 0))
        {
            right++;
        }
        if (nums[right] < 0 && nums[left] > 0)
        {
            swap(nums[left], nums[right]);
            left++;
            right++;
        }
    }
}

// Solution of above problem with ALGO: "National Dutch Algorithm" to bifergate array in two categories left side and right side, xero and 1ns etc
void switchNumsApproach2(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] < 0)
        {
            left++;
        }
        else if (nums[right] > 0)
        {
            right--;
        }
        else
        {
            swap(nums[left], nums[right]);
        }
    }
}

// Program : 287. Find the Duplicate Number
// ALGO: for duplicate numbers
int findDuplicate(vector<int> &nums)
{
    while (nums[0] != nums[nums[0]])
        swap(nums[0], nums[nums[0]]);

    return nums[0];
}

// Program : Missing numbers from an array
void missingNumbers(vector<int> &nums)
{
    // ALGO: Shorting and swaping method
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        int index = nums[i] - 1;
        if (nums[index] != nums[i])
        {
            swap(nums[index], nums[i]);
        }
        else
        {
            i++;
        }
    }

    cout << endl
         << "These are missing elements :: ";
    for (int i = 0; i < n; i++)
    {
        if (nums[i] - 1 != i)
        {
            cout << i + 1 << " ";
        }
    }
}

// First position of  repeated element in an array
int firstRepeatedElementIndex(vector<int> &nums)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int ithElement = nums[i];
        if (map[ithElement])
        {
            return map[ithElement] + 1;
        }
        else
        {
            map[ithElement] = i;
        }
    }
    return -1;
}

int main()
{

    vector<int> arr = {1, 3, 3, 4, 6, 7};
    // For pivote index
    // missingNumbers(arr);

    cout << "Find first occurance of an element from an array :: " << firstRepeatedElementIndex(arr);
    // cout << "remove element's end index is : " << ans << endl;
    // cout << "missing number :: " <<
    // for (int num : arr)
    // {
    //     cout << num << endl;
    // }
    return 0;
}