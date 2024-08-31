#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    // Attributes
    int id;
    int age;
    string name;
    int nos;

    int *gpa;
    string gf;

public:
    // ctor: default - c++ default add one constructor if we do not add any constructure in our class
    Student()
    {
        cout << "Student's default constructor" << endl;
    }

    // Parameterised constructor
    Student(int id, string name, int age, int nos, int gpa, string gf)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->nos = nos;
        this->gpa = new int(gpa);
        this->gf = gf;
    }

    // Coppy constructor
    Student(const Student &srcobj)
    {
        this->id = srcobj.id;
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->nos = srcobj.nos;
    }

    // Behaviours
    void study()
    {
        cout << this->name << " studying" << endl;
    }

    void sleep()
    {
        cout << this->name << " Sleeping " << endl;
    }

    void bunk()
    {
        cout << this->name << " Bunking" << endl;
    }

    // destructor
    ~Student()
    {
        cout << "Destructor of the student class" << endl;
        delete gpa;
    }

private:
    void gbchatting()
    {
        cout << "chatting with :: " << gf;
    }
};

int main()
{
    Student a(1, "Dhaval", 23, 6, 9, "shradhdha");

    // Coppy constructor example
    // Student b(a);
    // cout << a.name << " " << a.age << endl;
    // cout << b.name << " " << b.age << endl;
    // a.study();

    // Store object in heap storage
    // Student *b = new Student(1, "Raj", 23, 6, 8);
    // cout << b->name;
    // delete b;

    cout << a.name << endl;

    return 0;
}