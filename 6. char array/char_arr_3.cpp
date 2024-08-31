#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

string decodeMessage(string key, string message)
{

    // Step 1: create mapping
    unordered_map<char, char> mapping;
    mapping[' '] = ' ';
    char start = 'a';
    int index = 0;

    while (start <= 'z' && index < key.length())
    {
        char currentKeyChar = key[index];
        if (mapping[currentKeyChar])
        {
            index++;
        }
        else
        {
            mapping[currentKeyChar] = start;
            start++;
            index++;
        }
    }

    // use mapping and decode message
    string ans = "";
    for (int i = 0; i < message.length(); i++)
    {
        /* code */
        char mappedChar = mapping[message[i]];
        ans.push_back(mappedChar);
    }
    return ans;
}

int main()
{

    return 0;
}