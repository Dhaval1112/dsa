#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printSubSequences(string str, int index, int n, string output, vector<string> &ans)
{
    // Base condition
    if (index >= n)
    {
        ans.push_back(output);
        return;
    }

    // Recursive relation
    // Processing part
    // Include
    printSubSequences(str, index + 1, n, output + str[index], ans);
    // Exclude
    printSubSequences(str, index + 1, n, output, ans);
}

int main()
{
    string str = "abc";
    int lengths = str.length();
    cout << lengths << endl
         << endl;
    vector<string> subseq;
    printSubSequences(str, 0, lengths, "", subseq);

    for (auto s : subseq)
    {
        cout << s << endl;
    }

    return 0;
}