#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

// 532. K-diff Pairs in an Array
int kthDifferentElements(vector<int> &nums, int k)
{

    sort(nums.begin(), nums.end());
    int left = 0;
    int right = 1;
    int n = nums.size();
    set<pair<int, int>> uniquePairs;

    while (right < n)
    {
        int diff = nums[right] - nums[left];

        if (diff == k)
        {
            uniquePairs.insert({nums[left], nums[right]});
            left++;
            right++;
        }
        else if (diff < k)
        {
            right++;
        }
        else
        {
            left++;
            if (right - left == 1)
            {
                right++;
            }
        }
    }

    return uniquePairs.size();
}
void printVector(vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl
         << endl;
}

// 724. Find Pivot Index
int pivotIndex(vector<int> &nums)
{

    vector<int> leftSum(nums.size(), 0);
    vector<int> rightSum(nums.size(), 0);

    // To calculate leftsum elements
    for (int i = 1; i < nums.size(); i++)
    {
        leftSum[i] = nums[i - 1] + leftSum[i - 1];
    }
    printVector(leftSum);
    // To calculate right sum of an array
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        rightSum[i] = nums[i + 1] + rightSum[i + 1];
    }

    printVector(rightSum);
    // To find pivotindex
    for (int i = 0; i < nums.size(); i++)
    {
        if (leftSum[i] == rightSum[i])
            return i;
    }
    return -1;

    // Approach 2
    // int left = 0;
    // int right = nums.size() - 1;
    // int leftSum = 0;
    // int rightSum = 0;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     leftSum = 0;
    //     rightSum = 0;
    //     for (int j = 0; j < i; j++)
    //     {
    //         leftSum += nums[j];
    //     }
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         rightSum += nums[j];
    //     }

    //     if (leftSum == rightSum)
    //     {
    //         return i;
    //     }
    // }
    // return -1;
    // Approach 2 which is not working in all cases
    // while (left < right)
    // {
    //     cout << leftSum << " " << rightSum << "  " << left << "<->" << right << endl;
    //     if (leftSum + nums[left] < rightSum + nums[right])
    //     {
    //         leftSum += nums[left++];
    //     }
    //     else
    //     {
    //         rightSum += nums[right--];
    //     }
    // }
    // if (leftSum == rightSum)
    // {
    //     return left;
    // }
    // else
    // {
    //     return -1;
}

// 26. Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = 1;
    int count = 1;

    while (left < right && right < n)
    {
        if (nums[left] != nums[right])
        {
            cout << nums[left] << "  " << nums[right] << endl;
            nums[++left] = nums[right];
            count++;
        }
        right++;
    }
    return count;
}

// 643. Maximum Average Subarray I
double findMaximumAverage(vector<int> &nums, int k)
{
    double sum = 0;
    int left = 0;
    double maxAverage = INT32_MIN;

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    maxAverage = sum / k;

    // to find max from rest
    for (int i = k; i < nums.size(); i++)
    {
        sum -= nums[left++];
        sum += nums[i];
        // maxAverage = sum / k;
        maxAverage = max(maxAverage, (sum / k));
    }

    return maxAverage;
}

// 75. Sort Colors
void sortColors(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int current = 0;

    while (current <= right)
    {
        if (nums[current] == 0)
        {
            swap(nums[left], nums[current]);
            left++;
            current++;
        }
        else if (nums[current] == 2)
        {
            swap(nums[right], nums[current]);
            right--;
        }
        else
        {
            current++;
        }
    }
}

void swapNagativeNumbersAtBegining(vector<int> &nums)
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
            right--;
            left++;
        }
    }
}

// 268. Missing Number
int missingNumber(vector<int> &nums)
{
    vector<int> ans(nums.size() + 1, -1);

    for (int i = 0; i < nums.size(); i++)
    {
        ans[nums[i]] = 1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
        {
            return i;
        }
    }

    return nums.size();
}

// 287. Find the Duplicate Number
int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map[nums[i]])
        {
            return nums[i];
        }
        else
        {
            map[nums[i]] = 1;
        }
    }
    return -1;
}

int missingNumberm2(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] == n)
        {
            i++;
        }
        else if (nums[i] != i)
        {
            swap(nums[i], nums[nums[i]]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return n;
}

// find the first occurance of the element in an array
int findFirstOccurance(vector<int> nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = map.find(nums[i]);

        if (it != map.end())
        {
            return it->second;
        }
        else
        {
            map[nums[i]] = i;
        }
    }
    return -1;
}

// to find common element in 3 array
bool findCommonElement(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
    // find all the arrays size
    int s1, s2, s3, i, j, k;

    i = j = k = 0;

    s1 = v1.size();
    s2 = v2.size();
    s3 = v3.size();

    // cout << i << " " << j << " " << k << " " << v1[i] << " " << v2[j] << " " << v3[k] << endl;
    while (i < s1 && j < s2 && k < s3)
    {
        if (v1[i] == v2[j] && v2[j] == v3[k])
        {
            return true;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else if (v2[j] < v3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return false;
}

int binarySearch(int s, int e, vector<int> &nums, int target)
{
    int m = 0;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (nums[m] == target)
        {
            return m;
        }
        else if (nums[m] > target)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return -1;
}
// Find kth difference elements
int kthDifferentWithBinarySearch(vector<int> &nums, int k)
{
    if (nums.size() < 2)
    {
        return 0;
    }

    set<pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int bsresult = binarySearch(i + 1, nums.size() - 1, nums, nums[i] + k);
        if (bsresult != -1)
        {
            ans.insert({nums[i], nums[bsresult]});
        }
    }
    return ans.size();
}

int main()
{
    cout << "hello world ";

    vector<int> arr = {3, 1, 4, 1, 5};
    vector<int> arr2 = {3, 4, 7, 52};
    vector<int> arr3 = {3, 5, 6, 35, 52};
    int k = 2;
    // missingNumberm2(arr);
    // cout << "kth difference of elements is :: " << missingNumberm2(arr) << endl;
    cout << "Find element from an array :: " << kthDifferentWithBinarySearch(arr, 2) << endl;

    // printVector(arr);

    return 0;
}