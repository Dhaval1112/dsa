#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> desk_map; // roll_no, desk_no;
    desk_map[1] = 53;
    desk_map[2] = 52;
    desk_map[4] = 51;
    desk_map[5] = 50;

    // cout << desk_map[5];

    // Iterator one way
    // unordered_map<int, int>::iterator it;

    // for (it = desk_map.begin(); it != desk_map.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // Second way to map key value
    // for (auto it : desk_map)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    if (desk_map.find(2) != desk_map.end())
    {
        cout << "Found element";
    }
    else
    {
        cout << "NOt found element";
    }

    // Erase element from key
    desk_map.erase(2);

    for (auto it : desk_map)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}