#include <iostream>
#include <vector>

using namespace std;

class Unit
{
public:
    virtual void move(int x, int y) = 0;
    virtual void attack() = 0;
};

class Zealot : public Unit
{
public:
    int demage;
    void move(int x, int y)
    {
        cout << "Honor guides me.\n";
    }
    void attack()
    {
        cout << "We strike as one.\n";
    }
};

class Stalker : public Unit
{
public:
    int demage;
    void move(int x, int y)
    {
        cout << "It shall be as you say.\n";
    }
    void attack()
    {
        cout << "Death comes to all!\n";
    }
};

class Army : public Unit
{
public:
    vector<Unit *> units;
    void move(int x, int y)
    {
        for (int i = 0; i < units.size(); ++i)
        {
            units[i]->move(x, y);
        }

        cout << "Moved army to " << x << " " << y << '\n';
    }
    void attack()
    {
        for (int i = 0; i < units.size(); ++i)
        {
            units[i]->attack();
        }
        cout << "Attacking\n";
    }
};

int main()
{
    Army main_army;
    Unit *z1 = new Zealot();
    Unit *z2 = new Zealot();
    Unit *s1 = new Stalker();
    Unit *s2 = new Stalker();

    main_army.units.push_back(z1);
    main_army.units.push_back(z2);
    main_army.units.push_back(s1);
    main_army.units.push_back(s2);

    main_army.move(100, 20);
    main_army.attack();

    return 0;
}
