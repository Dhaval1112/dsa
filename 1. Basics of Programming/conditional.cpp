#include <iostream>
#include <string>

using namespace std;

int main()
{
    int salary;
    cout << "Enter your salary :: ";
    cin >> salary;

    if (salary > 200000)
    {
        cout << "You can buy a scorpio .. !";
    }
    else
    {
        cout << "YOu can't buy scorpio car ";
    }
    return 0;
}