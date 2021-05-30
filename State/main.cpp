#include <iostream>

using namespace std;

class Zarowka;

class State
{
public:
    virtual void wlacz(Zarowka *z) = 0;
    virtual void wylacz(Zarowka *z) = 0;
};

class Zarowka
{
public:
    State *stan;
    void wlacz()
    {
        stan->wlacz(this);
    }
    void wylacz()
    {
        stan->wylacz(this);
    }
};

class Wylaczone : public State
{
public:
    void wlacz(Zarowka *z);
    void wylacz(Zarowka *z)
    {
        cout << "Światło jest już wyłączone!\n";
    }
};

class Wlaczone : public State
{
public:
    void wlacz(Zarowka *z)
    {
        cout << "Światło jest już włączone!\n";
    }
    void wylacz(Zarowka *z)
    {
        cout << "Wyłaczono żarówke!\n";
        z->stan = new Wylaczone();
    }
};
void Wylaczone::wlacz(Zarowka *z)
{
    cout << "Włączono żarówke!\n";
    z->stan = new Wlaczone();
}

int main()
{
    Zarowka zarowka;
    zarowka.stan = new Wylaczone();

    int new_state = 0;
    for (int i = 0; i < 100; ++i)
    {
        cin >> new_state;
        if (new_state)
        {
            zarowka.wlacz();
        }
        else
        {
            zarowka.wylacz();
        }
    }

    return 0;
}