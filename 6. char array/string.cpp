#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string removeDuplicates(string s)
{
    // Initialize ans string as empty string
    string ans = "";
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char currchar = s[i];
        if (ans.empty())
        {
            ans.push_back(currchar);
        }
        else if (currchar == ans.back())
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(currchar);
        }
    }
    return ans;
}

string removeOccurences(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

bool checkPalindrome(string str, int s, int e)
{
    while (s < e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e++;
    }
    return true;
}
bool validPalindrome(string s)
{
    int n = s.length();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        // Both are equal
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            // If we remove left character from the string
            bool rightSide = checkPalindrome(s, left + 1, right);
            // If we remove right character from the string
            bool leftSide = checkPalindrome(s, left, right - 1);
            return leftSide || rightSide;
        }
    }
    return true;
}

int expandAroundCenter(string str, int s, int e)
{
    int count = 0;
    while (s < e)
    {
        if (str[s] == str[e])
        {
            count++;
        }
        s++;
        e--;
    }
    return count;
}

// 647 - Palindromic substring
int countSubStrings(string s)
{
    int totalCount = 0;
    for (int center = 0; center < s.length(); center++)
    {
        // For odd
        int i = center;
        int j = center;
        int oddPalindromeCount = expandAroundCenter(s, i, j);

        // Even
        i = center;
        j = center + 1;
        int evenPalindromeCount = expandAroundCenter(s, i, j);
        totalCount = totalCount + oddPalindromeCount + evenPalindromeCount;
    }
    return totalCount;
}

int main()
{
    cout << "remove occurance :: " << countSubStrings("abcashjdshjdabcasjdkajabc", "abc");
    return 0;
}