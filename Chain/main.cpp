#include <iostream>
#include <vector>

using namespace std;

class Warunek
{
public:
    virtual int handle(int n) = 0;
};

class ifNieparzysta : public Warunek
{
public:
    int handle(int n)
    {
        if (n % 2 == 1)
        {
            cout << "if nieparzysta " << n - 1 << "\n";
            return n - 1;
        }
        else
            return n;
    }
};

class ifParzysta : public Warunek
{
public:
    int handle(int n)
    {
        if (n % 2 == 0)
        {
            cout << "if parzysta " << n + 1 << "\n";
            return n + 1;
        }
        else
            return n;
    }
};

class Operator
{
public:
    int value;
    vector<Warunek *> operations;
    void walk()
    {
        for (int i = 0; i < operations.size(); ++i)
        {
            value = operations[i]->handle(value);
        }
    }
};

int main()
{
    Operator *o = new Operator();
    o->value = 20;
    o->operations.push_back(new ifParzysta());
    o->operations.push_back(new ifNieparzysta());
    o->operations.push_back(new ifNieparzysta());
    o->operations.push_back(new ifParzysta());
    o->walk();

    return 0;
}