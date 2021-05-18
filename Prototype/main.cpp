#include <iostream>

using namespace std;

class Car
{
public:
    virtual Car *clone() = 0;
};

class BMW : public Car
{
public:
    string producent;
    string engine_model;
    float max_speed;
    Car *clone()
    {
        return new BMW(this->producent, this->engine_model, this->max_speed);
    }
    BMW(string prod, string e_mod, float maxspd)
    {
        this->producent = prod;
        this->engine_model = e_mod;
        this->max_speed = maxspd;
    }
};

int main()
{
    BMW bmw = BMW("bmw", "v8", 220.0);
    Car *cloned_car = bmw.clone();
    return 0;
}