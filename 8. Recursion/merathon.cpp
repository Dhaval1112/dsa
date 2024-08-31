// TODO: HW - check catlon numer

#include <iostream>
#include <vector>

using namespace std;

int findMaxNonAdjecent(vector<int> arr, int index, int n)
{
    // Base condition
    if (index >= n)
    {
        return 0;
    }

    // Processing
    int inclusion = 0 + findMaxNonAdjecent(arr, index + 1, n);
    int exclusion = arr[index] + findMaxNonAdjecent(arr, index + 2, n);
    return max(inclusion, exclusion);
}

int houserober2(vector<int> arr)
{
    if (arr.size() == 1)
    {
        return arr[0];
    }
    // When we include first element
    int includefirst = findMaxNonAdjecent(arr, 0, arr.size() - 2);
    // when we do not include first element
    int excludefirst = findMaxNonAdjecent(arr, 1, arr.size() - 1);

    return max(includefirst, excludefirst);
}

int lastOccurenceOfChar(string s, char c, int index, int lastoc)
{
    // Base condition
    if (index >= s.size())
    {
        return lastoc;
    }

    // Processing part
    if (s[index] == c)
    {
        lastoc = index;
    }

    // Recursive call
    return lastOccurenceOfChar(s, c, index + 1, lastoc);
}

// Using backtracking
string reverseString(string &str, int index, int n, string &ans)
{
    // Base condition when index out of string length
    if (index >= n)
    {
        return "";
    }

    // Recursive relation
    reverseString(str, index + 1, n, ans);

    // processing to strore characters into the ans string
    ans = ans + str[index];
    return ans;
}

// reverse using one iteration
string reverseStringOneIt(string &str, int index, string &ans)
{
    // Base condition
    if (index < 0)
    {
        return ans;
    }

    // Processing part
    ans += str[index];

    // Recursive relation
    return reverseStringOneIt(str, index - 1, ans);
}

// add two strings -- TIME :- 44.12.91 Minutes
string addstrings(string &nums1, string &nums2, string &ans, int n1, int n2, int rem)
{
    // base condition
    if (n1 < 0 && n2 < 0 && rem == 0)
    {
        return ans;
    }

    // Processing part
    int num1 = 0;
    int num2 = 0;

    // To convert num1 and num2 into int
    if (n1 >= 0)
    {
        num1 = nums1[n1] - '0';
    }
    if (n2 >= 0)
    {
        num2 = nums2[n2] - '0';
    }

    // To do some and find reminder for the current sum
    int sum = num2 + num1 + rem;
    rem = 0;

    if (sum > 9)
    {
        int temp = sum % 10;
        rem = sum / 10;
        sum = temp;
    }

    ans = to_string(sum) + ans;

    // Recursive relation
    return addstrings(nums1, nums2, ans, n1 - 1, n2 - 1, rem);
}

// Check palindrom
bool checkPalindrome(string &str, int s, int e)
{
    // Base condition
    if (s > e)
    {
        return true;
    }
    // Processing part
    if (str[s] != str[e])
    {
        return false;
    }

    // Recursive relation
    return checkPalindrome(str, s + 1, e - 1);
}

// Print all the subarray
void printSubArray(vector<int> &arr, int s, int e)
{
    // Base case when e is length of arr
    if (e >= arr.size())
    {
        return;
    }

    // Processing
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Recursive call
    printSubArray(arr, s, e + 1);
}

void printAllSubArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        printSubArray(arr, i, i);
    }
}

bool removeOccurence(string &str, int index, string &oc)
{
    for (int i = 0; i < oc.size(); i++)
    {
        if (str[index + i] != oc[i])
            return false;
    }
    return true;
}

string removeAllOccurences(string &str, int index, string &occ)
{
    // Base condition when index reaches to the end
    if (index >= str.size())
    {
        return str;
    }

    // Processing part
    if (str[index] == occ[0] && removeOccurence(str, index, occ))
    {
        str.erase(index, occ.size());
        removeAllOccurences(str, 0, occ);
    }

    // Recursive call
    return removeAllOccurences(str, index + 1, occ);
}


int main()
{
    // cout << "hello ";
    string s = "abk1ba";
    char c = 'k';
    string ans = "";
    int lastoc = -1;
    int index = 0;

    // cout << "Last occurence of :: " << s << " at index :: " << lastOccurenceOfChar(s, c, index, lastoc);

    // reverseStringOneIt(s, s.size() - 1, ans);

    // cout << "Revers of :: " << s << " is :: " << ans;
    string nums1 = "99";
    string nums2 = "9";

    // int n1 = nums1.size() - 1;
    // int n2 = nums2.size() - 1;

    // cout << "The sum of the two numbers is :: " << addstrings(nums1, nums2, ans, n1, n2, 0);

    // cout << "check paindrom for " << s << " and answer for it is :: " << checkPalindrome(s, 0, s.size() - 1);
    vector<int> arr = {1, 2, 3, 4};

    // printAllSubArray(arr);

    // REmove all the occurence of the given string
    string str = "dhavalvaghela";
    string occ = "va";
    string answer = "";
    removeAllOccurences(str, 0, occ);

    cout << "if remove occurences :: " << occ << " from the :: " << str << " then it would become :: " << answer;
    return 0;
}