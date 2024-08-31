#include <iostream>

using namespace std;

class Vehicle
{
protected:
    string name;
    string model;
    int noOfTyre;

public:
    Vehicle(string name, string model, int nooftyre)
    {
        cout << "I am inside vehicle ctor" << endl;
        this->name = name;
        this->model = model;
        this->noOfTyre = nooftyre;
    }

    void start_engine()
    {
        cout << "Engine is starting :: " << name << " " << model << endl;
    }

    void stop_engine()
    {
        cout << "Engine is stop " << name << " " << model << endl;
    }
};

class Car : public Vehicle
{
public:
    int noOfDoors;
    string transmissionType;

    Car(string name, string model, int nooftyre, int noofdoors, string transmissiontype) : Vehicle(name, model, noofdoors)
    {
        cout << "I am inside car ctor" << endl;
        this->noOfDoors = noofdoors;
        this->transmissionType = transmissiontype;
    }

    void startAC()
    {
        cout << "Ac has started of " << name << endl;
    }
};

class MotorCycle : public Vehicle
{
protected:
    string handleBarStyle;
    string suspensionType;

public:
    MotorCycle(string name, string model, int nooftyre, string handlebarstyle, string suspensiontype) : Vehicle(name, model, nooftyre)
    {
        this->handleBarStyle = handlebarstyle;
        this->suspensionType = suspensiontype;
    }
    void wheeling()
    {
        cout << "wheeling kar rahi hai :: " << name << endl;
    }
};

int main()
{

    Car a("Maruti 800", "LXI", 4, 4, "Manual");

    MotorCycle v("BMW", "VXI", 2, "U", "HARD");

    v.start_engine();
    v.wheeling();
    v.stop_engine();
    return 0;
}