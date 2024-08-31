#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Program 1 : Print all subsequances
void printAllSubsequances(string &str, int index, string &output)
{
    // Base case
    if (index >= str.size())
    {
        cout << output << endl;
        return;
    }

    // Processing & RC
    output.push_back(str[index]);
    printAllSubsequances(str, index + 1, output);
    output.pop_back();
    printAllSubsequances(str, index + 1, output);
}

// Q2 - Hours robbery
int houseRob(vector<int> &nums, int index)
{
    // Base case
    if (index >= nums.size())
    {
        return 0;
    }

    // Processing
    int incSum = nums[index] + houseRob(nums, index + 2);
    int exSum = 0 + houseRob(nums, index + 1);

    return max(incSum, exSum);
}

// Best time to buy sell stock
void buySellStock(vector<int> &prices, int bday, int sday, int &mPrice)
{
    // Base condition
    if (sday >= prices.size())
    {
        return;
    }

    // Processing
    if (prices[bday] < prices[sday])
    {
        mPrice = max(mPrice, prices[sday] - prices[bday]);
    }
    else
    {
        bday = sday;
    }
    sday++;
    buySellStock(prices, bday, sday, mPrice);
}

// 273. Integer to English Words approach 2 and optimised
static const vector<pair<int, string>> wordLevel = {
    {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string getNumDetails(int num)
{
    if (num == 0)
        return "Zero";

    for (auto i : wordLevel)
    {
        if (num >= i.first)
        {
            cout << i.first << " " << i.second << endl;
            cout << i.first << endl;
            string first = "";
            if (num >= 100)
            {
                first = getNumDetails((num / i.first)) + " ";
            }
            string second = i.second;

            string third = "";
            if ((num % i.first) != 0)
            {
                third = " " + getNumDetails(num % i.first);
            }

            return first + second + third;
        }
    }
    return "";
}

// 273. Integer to English Words approach 1
// string inttoword(int number, int level, string &ans)
// {
//     // Base condition
//     if (number == 0)
//     {
//         return ans;
//     }

//     string space = ans == "" ? "" : " ";
//     if (level == 2 || level == 5)
//     {
//         int tempNum = number % 10;
//         if (tempNum != 0)
//             ans = getNumDetails(tempNum, level) + space + ans;
//         number = number / 10;
//     }

//     if (level == 1 || level == 3 || level == 4)
//     {
//         int tempNum = number % 100;

//         ans = isSafe(getNumDetails(tempNum, level)) + space + ans;
//         number = number / 100;

//         if (level == 3 || level == 4 && (number > 0))
//         {
//             int tempNum = number % 10;
//             string result = getNumDetails(tempNum, 2);

//             if (result != "")
//             {
//                 ans = result + space + ans;
//             }
//             number = number / 10;
//         }
//     }
//     return inttoword(number, level + 1, ans);
// }

bool isMatchHelper(string &s, string &p, int pi, int si)
{
    // Base condition
    if (pi == p.size() && si == s.size())
    {
        return true;
    }
    if (si == s.size() && pi < p.size())
    {
        while (pi != p.size())
        {
            if (p[pi] != '*')
            {
                return false;
            }
            pi++;
        }
        return true;
    }

    if (s[si] == p[pi] || '?' == p[pi])
    {
        return isMatchHelper(s, p, pi + 1, si + 1);
    }

    if (p[pi] == '*')
    {
        // To check when we found * in pattern so if we do not exclude
        // anything
        bool checkWithoutInclue = isMatchHelper(s, p, pi + 1, si);

        // This will skip the current character from the string
        bool checkWhenInclude = isMatchHelper(s, p, pi, si + 1);

        return checkWithoutInclue || checkWhenInclude;
    }

    return false;
}

// 44. Wildcard Matching
bool isMatch(string s, string p)
{
    cout << "result of " << isMatchHelper(s, p, 0, 0);
}

bool canPartitionHelper(vector<int> &nums, int index, int amount)
{
    // Base conditions
    // I. When we get amount == 0
    if (amount == 0)
    {
        return true;
    }

    // When index out of bound
    if (index >= nums.size() || amount < 0)
    {
        return false;
    }

    // Recursive relation
    // Including current element into the amount means reducing that value from the amount value
    bool includeAns = canPartitionHelper(nums, index + 1, amount - nums[index]);

    // II. Exclude means not consideringn removing this value from the amount
    bool excludeAns = canPartitionHelper(nums, index + 1, amount);

    return includeAns || excludeAns;
}

static bool desc(int a, int b)
{
    return a > b;
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    int amount = 0;

    sort(nums.begin(), nums.end(), desc);

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    amount = sum / 2;

    return canPartitionHelper(nums, 0, amount);
}

// 1981. Minimize the Difference Between Target and Chosen Elements
void minimizeDifferenceHelper(vector<vector<int>> &mat, int row, int target, int total, int &mini)
{
    // Base conditions
    if (row >= mat.size())
    {
        mini = min(abs(target - total), mini);
        return;
    }

    // Processing
    for (int i = 0; i < mat[row].size(); i++)
    {
        // Checking when perticular column's value we can reduce from the target or not
        minimizeDifferenceHelper(mat, row + 1, target, total + mat[row][i], mini);
    }
}

// 55. Jump Game
// This function will help to take jump from the current index to all possibilities
bool canJumpHelper(vector<int> &nums, int index, int lastIndex)
{
    // Base condition When
    if (index >= lastIndex)
    {
        return true;
    }

    // Processing
    if (nums[index] == 0)
    {
        return false;
    }

    bool reachedLastIndex = false;
    for (int i = index + 1; i <= (index + nums[index]); i++)
    {
        reachedLastIndex = reachedLastIndex || canJumpHelper(nums, i, lastIndex);
    }

    return reachedLastIndex;
}

// 45. Jump game II
void jumpHelper(vector<int> &nums, int index, int lastIndex, int totalJump, int &mini)
{
    // Base condition
    if (index >= lastIndex)
    {
        mini = min(totalJump, mini);
        return;
    }

    if (nums[index] == 0)
    {
        return;
    }

    for (int i = 1; i <= nums[index]; i++)
    {
        jumpHelper(nums, index + i, lastIndex, totalJump + 1, mini);
    }
}

void program(int num)
{

    switch (num)
    {
    case 1:
    {
        string str = "wxyz";
        string output = "";
        printAllSubsequances(str, 0, output);
    }
    case 2:
    {
        vector<int> nums = {1, 2, 3, 1};
        cout << "houserob ans is " << houseRob(nums, 0);
    }
    case 3:
    {

        int number = 12312;
        int level = 1;
        string ans = "";
        cout << "int to word is  ::>" << getNumDetails(number);
    }
    break;
    case 4:
    {

        string str = "abc";
        string pattern = "a?c";
        cout << "int to word is  ::>" << isMatch(str, pattern);
    }
    break;

    default:
        break;
    }
}

int main()
{

    // cout << "Hellow";
    // program(2);
    // cout << getNumDetails(52, 2) << endl;
    program(3);
    return 0;
}