#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world" << endl;

    int age;
    cout << "Enter your age :: " << endl;
    cin >> age;
    cin.ignore();

    cout << "Your age is :: " << age << endl;
    string name;
    cout << "Enter your  name :: " << endl;
    getline(cin, name);

    // This will be used to clear input statement buffer from the dhavacin
    cout << "Your name is :: " << name << endl;
    getline(cin, name);
    cout << "Input taken from the newline :: " << name;

    return 0;
}
